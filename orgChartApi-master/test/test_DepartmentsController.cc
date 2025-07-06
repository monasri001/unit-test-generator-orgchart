Here is the test file content for the provided code:

```cpp
#include <gtest/gtest.h>

class DepartmentsControllerTest : public ::testing::Test {
public:
    void SetUp() override {
        // Set up any necessary dependencies or state.
    }

    void TearDown() override {
        // Clean up any necessary dependencies or state.
    }
};

TEST_F(DepartmentsControllerTest, TestGetDepartments) {
    // Create a test request
    auto req = new HttpRequest();
    // Set the department ID
    int departmentId = 1;
    req->setQueryParameter("departmentId", std::to_string(departmentId));

    // Simulate the database query response
    auto resp = new HttpResponse();
    Json::Value json;
    json["departements"] = "[{\"id\": 1, \"name\": \"Department A\"}, {\"id\": 2, \"name\": \"Department B\"}]";
    resp->setContent(json.toString());

    // Call the DepartmentsController's getDepartments method
    auto departmentsController = new DepartmentsController();
    departmentsController->getDepartments(req, [&](const HttpResponse& response) {
        EXPECT_EQ(resp->getContent(), response.getContent());
    });
}

TEST_F(DepartmentsControllerTest, TestGetDepartmentPersons) {
    // Create a test request
    auto req = new HttpRequest();
    // Set the department ID
    int departmentId = 1;
    req->setQueryParameter("departmentId", std::to_string(departmentId));

    // Simulate the database query response
    auto resp = new HttpResponse();
    Json::Value json;
    json["persons"] = "[{\"id\": 1, \"name\": \"Person A\"}, {\"id\": 2, \"name\": \"Person B\"}]";
    resp->setContent(json.toString());

    // Call the DepartmentsController's getDepartmentPersons method
    auto departmentsController = new DepartmentsController();
    departmentsController->getDepartmentPersons(req, [&](const HttpResponse& response) {
        EXPECT_EQ(resp->getContent(), response.getContent());
    });
}

int main(int argc, char **argv) {
    ::testing::InitGoogle(&argc, argv);
    return RUN_ALL_TESTS();
}
```

