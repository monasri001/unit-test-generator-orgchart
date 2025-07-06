Here is the generated test file:
```cpp
#include <gtest/gtest.h>
#include "AuthController.h"
#include "BCrypt.hpp"

namespace {

TEST(AuthControllerTest, RegisterUserValidInput) {
  auto req = HttpRequestPtr();
  auto pUser = User("test", "test_password");
  auto callback = [&](const HttpResponsePtr &response) {
    // ignored
  };
  AuthController auth;
  auto resp = auth.registerUser(req, callback, pUser);
  EXPECT_EQ(HttpStatusCode::k201Created, resp->getStatusCode());
}

TEST(AuthControllerTest, RegisterUserInvalidInputMissingFields) {
  auto req = HttpRequestPtr();
  auto pUser = User("test", "");
  auto callback = [&](const HttpResponsePtr &response) {
    // ignored
  };
  AuthController auth;
  auto resp = auth.registerUser(req, callback, pUser);
  EXPECT_EQ(HttpStatusCode::k400BadRequest, resp->getStatusCode());
}

TEST(AuthControllerTest, RegisterUserInvalidInputUsernameTaken) {
  auto req = HttpRequestPtr();
  auto pUser = User("existing_user", "test_password");
  auto callback = [&](const HttpResponsePtr &response) {
    // ignored
  };
  AuthController auth;
  auto resp = auth.registerUser(req, callback, pUser);
  EXPECT_EQ(HttpStatusCode::k400BadRequest, resp->getStatusCode());
}

TEST(AuthControllerTest, RegisterUserDatabaseError) {
  auto req = HttpRequestPtr();
  auto pUser = User("test", "test_password");
  auto callback = [&](const HttpResponsePtr &response) {
    // ignored
  };
  AuthController auth;
  auto dbException = std::make_exception_ptr(DrogonDbException());
  auth.registerUser(req, callback, pUser);
}

TEST(AuthControllerTest, LoginUserValidInput) {
  auto req = HttpRequestPtr();
  auto pUser = User("test", "test_password");
  auto callback = [&](const HttpResponsePtr &response) {
    // ignored
  };
  AuthController auth;
  auto resp = auth.loginUser(req, callback, pUser);
  EXPECT_EQ(HttpStatusCode::k200OK, resp->getStatusCode());
}

TEST(AuthControllerTest, LoginUserInvalidInputMissingFields) {
  auto req = HttpRequestPtr();
  auto pUser = User("test", "");
  auto callback = [&](const HttpResponsePtr &response) {
    // ignored
  };
  AuthController auth;
  auto resp = auth.loginUser(req, callback, pUser);
  EXPECT_EQ(HttpStatusCode::k400BadRequest, resp->getStatusCode());
}

TEST(AuthControllerTest, LoginUserInvalidInputUsernameNotfound) {
  auto req = HttpRequestPtr();
  auto pUser = User("non_existent_user", "test_password");
  auto callback = [&](const HttpResponsePtr &response) {
    // ignored
  };
  AuthController auth;
  auto resp = auth.loginUser(req, callback, pUser);
  EXPECT_EQ(HttpStatusCode::k400BadRequest, resp->getStatusCode());
}

TEST(AuthControllerTest, LoginUserInvalidInputIncorrectPassword) {
  auto req = HttpRequestPtr();
  auto pUser = User("test", "wrong_password");
  auto callback = [&](const HttpResponsePtr &response) {
    // ignored
  };
  AuthController auth;
  auto resp = auth.loginUser(req, callback, pUser);
  EXPECT_EQ(HttpStatusCode::k401Unauthorized, resp->getStatusCode());
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogle(&argc, argv);
  return RUN_ALL_TESTS();
}
```

