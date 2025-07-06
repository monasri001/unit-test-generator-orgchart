```cpp
#include "gtest/gtest.h"
#include "your_header_file.h"  // Include the header file where Jwt class is declared

class MockJwt : public Jwt {
 public:
  MockJwt(const std::string& secret, const int sessionTime, const std::string& issuer)
      : Jwt(secret, sessionTime, issuer) {}
};

TEST(JwtTest, EncodeFunctionTest) {
  MockJwt jwt("secret", 3600, "example.com");
  EXPECT_EQ(jwt.encode("field", 1), "encoded_token");  // Add your expected token value
}

TEST(JwtTest, DecodeFunctionTest) {
  MockJwt jwt("secret", 3600, "example.com");
  jwt.decode("token");  // Add your test data
  EXPECT_TRUE(true);  // Add your assertion
}

int main(int argc, char **argv) {
  ::testing::InitGoogle(&argc, argv);
  return RUN_ALL_TESTS();
}
```

