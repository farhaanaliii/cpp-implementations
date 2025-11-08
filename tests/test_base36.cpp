#include <gtest/gtest.h>
#include "../base36/base36.h"

TEST(Base36Test, EncodeBasic) {
    EXPECT_EQ(base36_encode("Hi"), "20 2X");
}

TEST(Base36Test, DecodeBasic) {
    EXPECT_EQ(base36_decode("20 2X"), "Hi");
}

TEST(Base36Test, CaseInsensitive) {
    EXPECT_EQ(base36_decode("20 2x"), "Hi");
}

TEST(Base36Test, EmptyString) {
    EXPECT_EQ(base36_encode(""), "");
    EXPECT_EQ(base36_decode(""), "");
}

TEST(Base36Test, RoundTrip) {
    std::string text = "Hello";
    EXPECT_EQ(base36_decode(base36_encode(text)), text);
}

TEST(Base36Test, InvalidCharacter) {
    EXPECT_THROW(base36_decode("@#$"), std::runtime_error);
}
