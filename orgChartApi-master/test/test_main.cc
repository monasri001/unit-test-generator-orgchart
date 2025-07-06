```cpp
#include <gtest/gtest.h>

class DrogonTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up your test fixture here.
    }

    void TearDown() override {
        // Tear down your test fixture here.
    }
};

TEST_F(DrogonTest, LoadConfigFile) {
    drogon::app app;
    EXPECT_EQ(app.loadConfigFile(""), -1);
}

TEST_F(DrogonTest, RunOnLocalhost) {
    drogon::app app;
    EXPECT_EQ(app.run(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogle(&argc, argv);
    ::gtest::TestEventListeners &listeners = ::gtest::GetEventListeners();
    listeners.Append(new ::gtest::InternalTestEventListener());
    testing::InitGoogleAndInstances(&argc, argv);

    ::testing::TestRegistry& registry = ::testing::TestRegistry::Get();
    auto tests = registry.AllTests();

    for (const auto& test : tests) {
        (void)test.Run(&argc, &argv);
    }

    return ::gtest::RunMain(argc, argv, false);
}
```

