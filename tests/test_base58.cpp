#include <gtest/gtest.h>
#include "../base58/base58.h"

TEST(Base58Test, EncodeBasic) {
    EXPECT_EQ(base58_encode("Hello"), "9Ajdvzr");
}

TEST(Base58Test, DecodeBasic) {
    EXPECT_EQ(base58_decode("9Ajdvzr"), "Hello");
}

TEST(Base58Test, EmptyString) {
    EXPECT_EQ(base58_encode(""), "");
    EXPECT_EQ(base58_decode(""), "");
}

TEST(Base58Test, RoundTrip) {
    std::string text = "Hello World!";
    EXPECT_EQ(base58_decode(base58_encode(text)), text);
}

TEST(Base58Test, InvalidCharacter) {
    EXPECT_THROW(base58_decode("0OIl"), std::runtime_error);
}
