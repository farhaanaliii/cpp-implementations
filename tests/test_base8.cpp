#include <gtest/gtest.h>
#include "../base8/base8.h"

TEST(Base8Test, EncodeBasic) {
    EXPECT_EQ(base8_encode("Hi"), "220644");
}

TEST(Base8Test, DecodeBasic) {
    EXPECT_EQ(base8_decode("220644"), "Hi");
}

TEST(Base8Test, EmptyString) {
    EXPECT_EQ(base8_encode(""), "");
    EXPECT_EQ(base8_decode(""), "");
}

TEST(Base8Test, RoundTrip) {
    std::string text = "Hello World!";
    EXPECT_EQ(base8_decode(base8_encode(text)), text);
}

TEST(Base8Test, InvalidCharacter) {
    EXPECT_THROW(base8_decode("8"), std::runtime_error);
    EXPECT_THROW(base8_decode("ABC"), std::runtime_error);
}
