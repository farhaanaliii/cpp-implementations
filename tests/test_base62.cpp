#include <gtest/gtest.h>
#include "../base62/base62.h"

TEST(Base62Test, EncodeBasic) {
    EXPECT_EQ(base62_encode("Hi"), "1A 1h");
}

TEST(Base62Test, DecodeBasic) {
    EXPECT_EQ(base62_decode("1A 1h"), "Hi");
}

TEST(Base62Test, EmptyString) {
    EXPECT_EQ(base62_encode(""), "");
    EXPECT_EQ(base62_decode(""), "");
}

TEST(Base62Test, RoundTrip) {
    std::string text = "Hello";
    EXPECT_EQ(base62_decode(base62_encode(text)), text);
}

TEST(Base62Test, InvalidCharacter) {
    EXPECT_THROW(base62_decode("@#$"), std::runtime_error);
}
