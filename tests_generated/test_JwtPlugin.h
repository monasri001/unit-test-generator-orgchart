```cpp
#include <gtest/gtest.h>

class JwtMock {
 public:
    MOCK_METHOD(auto, init, (), (return));
};

TEST(JwtPluginTest, Init) {
    JwtPlugin plugin;
    EXPECT_CALL(plugin, init()).Times(1);
    plugin.initAndStart(Json::Value());
}

TEST(JwtPluginTest, Shutdown) {
    JwtPlugin plugin;
    plugin.shutdown();
}

TEST(JwtPluginTest, InitReturn) {
    JwtMock mock;
    JwtPlugin plugin;
    WHEN_CALLS_TO((Jwt), plugin, init()).ThenReturn(mock);
    auto jwt = plugin.init();
    EXPECT_EQ(&mock, &jwt);
}

int main(int argc, char **argv) {
    ::testing::InitGoogle(&argc, argv);
    return RUN_MAIN;
}
```

