Here is the unit test file content for the provided `PersonInfo` class using Google Test framework:
```cpp
#include <gtest/gtest.h>
#include "person_info.h"
#include "drogon/orm/Row.h"

TEST(PersonInfoTest, ConstructorWithRow) {
    drogon::orm::Row row;
    PersonInfo person(row);
    ASSERT_TRUE(person.id_.get() == nullptr);
    ASSERT_TRUE(person.jobId_.get() == nullptr);
    // ... more assertions
}

TEST(PersonInfoTest, GettersSetters) {
    PersonInfo person;
    person.setId(1);
    EXPECT_EQ(1, person.getValueOfId());
    EXPECT_EQ(std::shared_ptr<int32_t>(std::make_shared<int32_t>(1)), person.getId());

    person.setJobId(2);
    EXPECT_EQ(2, person.getValueOfJobId());
    EXPECT_EQ(std::shared_ptr<int32_t>(std::make_shared<int32_t>(2)), person.getJobId());

    // ... more getters and setters tests
}

TEST(PersonInfoTest, ToJson) {
    PersonInfo person;
    Json::Value expectedJson;
    // ... populate expectedJson with test data ...

    EXPECT_EQ(expectedJson, person.toJson());
}

int main(int argc, char **argv) {
    ::testing::InitGoogle(&argc, argv);
    return RUN_ALL_TESTS();
}
```

