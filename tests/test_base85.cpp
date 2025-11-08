#include <gtest/gtest.h>
#include "../base85/base85.h"

TEST(Base85Test, EncodeBasic) {
    std::string encoded = base85_encode("Hello");
    EXPECT_TRUE(encoded.substr(0, 2) == "<~");
    EXPECT_TRUE(encoded.substr(encoded.length() - 2) == "~>");
}

TEST(Base85Test, DecodeBasic) {
    std::string text = "Hello World!";
    std::string encoded = base85_encode(text);
    EXPECT_EQ(base85_decode(encoded), text);
}

TEST(Base85Test, EmptyString) {
    EXPECT_EQ(base85_encode(""), "");
}

TEST(Base85Test, RoundTrip) {
    std::string text = "Hello World!";
    EXPECT_EQ(base85_decode(base85_encode(text)), text);
}

TEST(Base85Test, ZeroCompression) {
    std::string text(4, '\0');
    std::string encoded = base85_encode(text);
    EXPECT_TRUE(encoded.find('z') != std::string::npos);
}
