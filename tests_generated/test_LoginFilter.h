```cpp
#include <gtest/gtest.h>
#include "LoginFilter.h"

TEST(LoginFilterTest, DoFilterOverride) {
    LoginFilter filter;
    EXPECT_NO_THROW(filter.doFilter(HttpRequestPtr(), [](auto, auto){}, [](auto, auto){}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogle(&argc, argv);
    return RUN_ALL_TESTS();
}
```

