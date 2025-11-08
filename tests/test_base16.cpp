#include <gtest/gtest.h>
#include "../base16/base16.h"

TEST(Base16Test, EncodeBasic) {
    EXPECT_EQ(base16_encode("Hello"), "48656C6C6F");
}

TEST(Base16Test, DecodeBasic) {
    EXPECT_EQ(base16_decode("48656C6C6F"), "Hello");
}

TEST(Base16Test, CaseInsensitive) {
    EXPECT_EQ(base16_decode("48656c6c6f"), "Hello");
    EXPECT_EQ(base16_decode("48656C6C6F"), "Hello");
}

TEST(Base16Test, EmptyString) {
    EXPECT_EQ(base16_encode(""), "");
    EXPECT_EQ(base16_decode(""), "");
}

TEST(Base16Test, RoundTrip) {
    std::string text = "Hello World!";
    EXPECT_EQ(base16_decode(base16_encode(text)), text);
}

TEST(Base16Test, InvalidCharacter) {
    EXPECT_THROW(base16_decode("XYZ"), std::runtime_error);
}

TEST(Base16Test, InvalidLength) {
    EXPECT_THROW(base16_decode("123"), std::runtime_error);
}
