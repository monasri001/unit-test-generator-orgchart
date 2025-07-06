Here's an example of unit tests using Google Test framework for the given C++ source file:

```cpp
#include <gtest/gtest.h>

#include "AuthController.h"
#include "User.h"

class AuthControllerMock : public AuthController {
public:
    MOCK_METHOD(void, registerUser, (const HttpRequestPtr &, std::function<void(const HttpResponsePtr &)> &&, User &&), (override));
    MOCK_METHOD(void, loginUser, (const HttpRequestPtr &, std::function<void(const HttpResponsePtr &)> &&, User &&), (override));
};

TEST(AuthControllerTest, RegisterUser_Succeeds) {
    AuthControllerMock authController;
    User user("test", "test");

    auto callback = [](const HttpResponsePtr &) {};
    EXPECT_CALL(authController, registerUser(_, _, _)).WillOnce([](const HttpRequestPtr &, std::function<void(const HttpResponsePtr &)> &&callback, User &&user) {
        callback(HttpResponsePtr());
    });

    authController.registerUser({}, std::move(callback), user);
}

TEST(AuthControllerTest, LoginUser_Succeeds) {
    AuthControllerMock authController;
    User user("test", "test");

    auto callback = [](const HttpResponsePtr &) {};
    EXPECT_CALL(authController, loginUser(_, _, _)).WillOnce([](const HttpRequestPtr &, std::function<void(const HttpResponsePtr &)> &&callback, User &&user) {
        callback(HttpResponsePtr());
    });

    authController.loginUser({}, std::move(callback), user);
}

int main(int argc, char **argv) {
    ::testing::InitGoogle(&argc, argv);
    return RUN_ALL_TESTS();
}
```

