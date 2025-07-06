Here is an example of how you could write unit tests for this code using Google Test:

```cpp
#include <gtest/gtest.h>
#include <drogon/drogon_test.h>
#include <drogon/drogon.h>

TEST(RemoteAPITest, SendRequestOk)
{
    auto client = drogon::HttpClient::newHttpClient("http://localhost:3000");
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setPath("/jobs");
    client->sendRequest(req, [](drogon::ReqResult res, const drogon::HttpResponsePtr& resp) {
        REQUIRE(res == drogon::ReqResult::Ok);
        REQUIRE(resp != nullptr);

        CHECK(resp->getStatusCode() == drogon::k200OK);
        CHECK(resp->contentType() == drogon::CT_APPLICATION_JSON);
    });
}

int main(int argc, char** argv)
{
    ::testing::InitGoogle(&argc, argv);
    return ::gtest::RUN_ALL_TESTS();
}
```

