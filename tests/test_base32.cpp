#include <gtest/gtest.h>
#include "../base32/base32.h"

TEST(Base32Test, EncodeBasic) {
    EXPECT_EQ(base32_encode("Hello"), "JBSWY3DP");
}

TEST(Base32Test, DecodeBasic) {
    EXPECT_EQ(base32_decode("JBSWY3DP"), "Hello");
}

TEST(Base32Test, WithPadding) {
    EXPECT_EQ(base32_encode("Hi"), "JBUQ====");
    EXPECT_EQ(base32_decode("JBUQ===="), "Hi");
}

TEST(Base32Test, EmptyString) {
    EXPECT_EQ(base32_encode(""), "");
    EXPECT_EQ(base32_decode(""), "");
}

TEST(Base32Test, RoundTrip) {
    std::string text = "Hello World!";
    EXPECT_EQ(base32_decode(base32_encode(text)), text);
}

TEST(Base32Test, InvalidCharacter) {
    EXPECT_THROW(base32_decode("123"), std::runtime_error);
}
