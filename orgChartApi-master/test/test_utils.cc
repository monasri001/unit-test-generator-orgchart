Here is the generated unit test file using Google Test framework:

```cpp
#include "gtest/gtest.h"
#include "utils.h"

TEST(utils_test, BadRequestTest) {
    auto callback = [](const drogon::HttpResponsePtr &){};
    std::string err = "test error";
    drogon::HttpStatusCode code = drogon::HttpStatusCode::BadRequest;

    badRequest(callback, err, code);

    Json::Value expectedRet;
    expectedRet["error"] = err;

    // TO DO: implement actual assertion
}

TEST(utils_test, MakeErrRespTest) {
    std::string err = "test error";
    Json::Value ret = makeErrResp(err);
    EXPECT_EQ(ret["error"], err);

    // TO DO: implement additional assertions if needed
}

int main(int argc, char **argv) {
    ::testing::InitGoogle(&argc, argv);
    return RUN_MAIN;
}
```

