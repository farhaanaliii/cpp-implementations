#include <gtest/gtest.h>
#include "../base64/base64.h"

TEST(Base64Test, EncodeBasic) {
    EXPECT_EQ(base64_encode("Hello"), "SGVsbG8=");
}

TEST(Base64Test, DecodeBasic) {
    EXPECT_EQ(base64_decode("SGVsbG8="), "Hello");
}

TEST(Base64Test, WithPadding) {
    EXPECT_EQ(base64_encode("Hi"), "SGk=");
    EXPECT_EQ(base64_decode("SGk="), "Hi");
}

TEST(Base64Test, EmptyString) {
    EXPECT_EQ(base64_encode(""), "");
    EXPECT_EQ(base64_decode(""), "");
}

TEST(Base64Test, RoundTrip) {
    std::string text = "Hello World!";
    EXPECT_EQ(base64_decode(base64_encode(text)), text);
}

TEST(Base64Test, InvalidCharacter) {
    EXPECT_THROW(base64_decode("@#$%"), std::runtime_error);
}
