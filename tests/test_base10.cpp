#include <gtest/gtest.h>
#include "../base10/base10.h"

TEST(Base10Test, EncodeBasic) {
    EXPECT_EQ(base10_encode("Hi"), "72 105");
}

TEST(Base10Test, DecodeBasic) {
    EXPECT_EQ(base10_decode("72 105"), "Hi");
}

TEST(Base10Test, EmptyString) {
    EXPECT_EQ(base10_encode(""), "");
    EXPECT_EQ(base10_decode(""), "");
}

TEST(Base10Test, RoundTrip) {
    std::string text = "Hello World!";
    EXPECT_EQ(base10_decode(base10_encode(text)), text);
}
