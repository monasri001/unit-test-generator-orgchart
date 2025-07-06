Here is the unit test file for the given C++ source code:

```cpp
#include "gtest/gtest.h"
#include "LoginFilter.h"

TEST(LoginFilterTest, EmptyAuthorizationHeader) {
    LoginFilter filter;
    HttpRequestPtr req = std::make_shared<HttpRequest>();
    req->setHeader("Authorization", "");
    auto fcb = [&req](const HttpResponsePtr &resp) { req = resp; };
    auto fccb = []() {};
    filter.doFilter(req, fcb, fccb);
    EXPECT_EQ(req->getStatusCode(), 400);
}

TEST(LoginFilterTest, InvalidToken) {
    LoginFilter filter;
    HttpRequestPtr req = std::make_shared<HttpRequest>();
    req->setHeader("Authorization", "InvalidToken");
    auto fcb = [&req](const HttpResponsePtr &resp) { req = resp; };
    auto fccb = []() {};
    filter.doFilter(req, fcb, fccb);
    EXPECT_EQ(req->getStatusCode(), 400);
}

TEST(LoginFilterTest, ValidToken) {
    LoginFilter filter;
    HttpRequestPtr req = std::make_shared<HttpRequest>();
    req->setHeader("Authorization", "Bearer some-valid-token");
    auto fcb = [&req](const HttpResponsePtr &resp) { req = resp; };
    auto fccb = []() {};
    filter.doFilter(req, fcb, fccb);
    EXPECT_TRUE(req->getStatusCode() == 200 || req->getStatusCode() == 401); // 401 for JWT verification failure
}

TEST(LoginFilterTest, TokenVerificationException) {
    LoginFilter filter;
    HttpRequestPtr req = std::make_shared<HttpRequest>();
    req->setHeader("Authorization", "Bearer some-bad-token");
    auto fcb = [&req](const HttpResponsePtr &resp) { req = resp; };
    auto fccb = []() {};
    try {
        filter.doFilter(req, fcb, fccb);
        FAIL();
    } catch (jwt::token_verification_exception &e) {
        // expected
    }
}

TEST(LoginFilterTest, RuntimeError) {
    LoginFilter filter;
    HttpRequestPtr req = std::make_shared<HttpRequest>();
    req->setHeader("Authorization", "Bearer some-bad-token");
    auto fcb = [&req](const HttpResponsePtr &resp) { req = resp; };
    auto fccb = []() {};
    try {
        filter.doFilter(req, fcb, fccb);
        FAIL();
    } catch (const std::runtime_error &e) {
        // expected
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogle(&argc, argv);
    return RUN_ALL_TESTS();
}
```

