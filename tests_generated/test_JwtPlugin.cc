```cpp
#include <gtest/gtest.h>
#include "JwtPlugin.h"

TEST(JwtPluginTest, InitAndStart) {
    JwtPlugin plugin;
    Json::Value config;
    config["secret"] = "secret";
    config["sessionTime"] = 3600;
    config["issuer"] = "auth0";
    plugin.initAndStart(config);
    EXPECT_NE(plugin.config, Json::nullValue);
}

TEST(JwtPluginTest, Shutdown) {
    JwtPlugin plugin;
    plugin.shutdown();
    EXPECT_TRUE(true); // todo
}

TEST(JwtPluginTest, Init) {
    JwtPlugin plugin;
    auto jwt = plugin.init();
    EXPECT_NE(jwt.secret, "");
    EXPECT_GE(jwt.sessionTime, 0);
    EXPECT_NE(jwt.issuer, "");
}
```

