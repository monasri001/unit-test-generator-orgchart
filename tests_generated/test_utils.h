```cpp
#include <gtest/gtest.h>
#include "your_file.h" // replace with the actual header name

TEST(BadRequestTest, CallbackIsCalled) {
    auto callback = [](const drogon::HttpResponsePtr &){};
    std::string err;
    badRequest(std::move(callback), err);
    // your expected result goes here
}

TEST(MakeErrRespTest, EmptyError) {
    std::string err;
    Json::Value resp = makeErrResp(err);
    // your expected result goes here
}

TEST(BadRequestTest, CodeIsSet) {
    auto callback = [](const drogon::HttpResponsePtr &){};
    std::string err;
    badRequest(std::move(callback), err, drogon::k401Unauthorized);
    // your expected result goes here
}
```

