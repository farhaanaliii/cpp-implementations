#include <gtest/gtest.h>
#include "../base2/base2.h"

TEST(Base2Test, EncodeBasic) {
    EXPECT_EQ(base2_encode("Hi"), "0100100001101001");
    EXPECT_EQ(base2_encode("A"), "01000001");
}

TEST(Base2Test, DecodeBasic) {
    EXPECT_EQ(base2_decode("0100100001101001"), "Hi");
    EXPECT_EQ(base2_decode("01000001"), "A");
}

TEST(Base2Test, EmptyString) {
    EXPECT_EQ(base2_encode(""), "");
    EXPECT_EQ(base2_decode(""), "");
}

TEST(Base2Test, RoundTrip) {
    std::string text = "Hello World!";
    EXPECT_EQ(base2_decode(base2_encode(text)), text);
}
