Here is the unit test file using Google Test framework:
```
#include "Jwt.h"
#include "gtest/gtest.h"

TEST(JwtTest, EncodeTest) {
  Jwt jwt("secret", 3600, "issuer");
  std::string token = jwt.encode("field", 123);
  EXPECT_NE(token.size(), 0);
}

TEST(JwtTest, DecodeTest) {
  Jwt jwt("secret", 3600, "issuer");
  std::string token = jwt.encode("field", 123);
  jwt::decoded_jwt<jwt::traits::kazuho_picojson> decoded = jwt.decode(token);
  EXPECT_EQ(decoded.payload()["field"], "123");
}

TEST(JwtTest, DecodeInvalidToken) {
  Jwt jwt("secret", 3600, "issuer");
  std::string token = "invalid_token";
  EXPECT_THROW(jwt.decode(token), jwt::verification_exception);
}
```

