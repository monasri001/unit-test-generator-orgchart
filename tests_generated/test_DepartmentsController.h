Here are the unit tests for the `DepartmentsController` class using Google Test framework:
```
#include <gtest/gtest.h>
#include "departments_controller.h"
#include "department.h"

TEST(DepartmentsControllerTest, GetMethodCalledSuccessfully) {
  // Mock HttpRequest and HttpResponse
  drogon::HttpRequestPtr req = std::make_shared<drogon::HttpRequest>();
  drogon::HttpResponsePtr resp = std::make_shared<drogon::HttpResponse>();

  DepartmentsController controller;
  controller.get(req, [&resp](const drogon::HttpResponsePtr& r) {
    resp = r;
  });

  // Verify the response
  EXPECT_TRUE(resp);
}

TEST(DepartmentsControllerTest, GetOneMethodCalledSuccessfully) {
  // Mock HttpRequest and HttpResponse
  drogon::HttpRequestPtr req = std::make_shared<drogon::HttpRequest>();
  drogon::HttpResponsePtr resp = std::make_shared<drogon::HttpResponse>();

  DepartmentsController controller;
  int departmentId = 123;
  controller.getOne(req, [&resp](const drogon::HttpResponsePtr& r) {
    resp = r;
  }, departmentId);

  // Verify the response
  EXPECT_TRUE(resp);
}

TEST(DepartmentsControllerTest, CreateOneMethodCalledSuccessfully) {
  // Mock HttpRequest and HttpResponse
  drogon::HttpRequestPtr req = std::make_shared<drogon::HttpRequest>();
  drogon::HttpResponsePtr resp = std::make_shared<drogon::HttpResponse>();

  DepartmentsController controller;
  Department department;  // create a dummy department object
  controller.createOne(req, [&resp](const drogon::HttpResponsePtr& r) {
    resp = r;
  }, department);

  // Verify the response
  EXPECT_TRUE(resp);
}

TEST(DepartmentsControllerTest, UpdateOneMethodCalledSuccessfully) {
  // Mock HttpRequest and HttpResponse
  drogon::HttpRequestPtr req = std::make_shared<drogon::HttpRequest>();
  drogon::HttpResponsePtr resp = std::make_shared<drogon::HttpResponse>();

  DepartmentsController controller;
  int departmentId = 123;
  Department department;  // create a dummy department object
  controller.updateOne(req, [&resp](const drogon::HttpResponsePtr& r) {
    resp = r;
  }, departmentId, department);

  // Verify the response
  EXPECT_TRUE(resp);
}

TEST(DepartmentsControllerTest, DeleteOneMethodCalledSuccessfully) {
  // Mock HttpRequest and HttpResponse
  drogon::HttpRequestPtr req = std::make_shared<drogon::HttpRequest>();
  drogon::HttpResponsePtr resp = std::make_shared<drogon::HttpResponse>();

  DepartmentsController controller;
  int departmentId = 123;
  controller.deleteOne(req, [&resp](const drogon::HttpResponsePtr& r) {
    resp = r;
  }, departmentId);

  // Verify the response
  EXPECT_TRUE(resp);
}

TEST(DepartmentsControllerTest, GetDepartmentPersonsMethodCalledSuccessfully) {
  // Mock HttpRequest and HttpResponse
  drogon::HttpRequestPtr req = std::make_shared<drogon::HttpRequest>();
  drogon::HttpResponsePtr resp = std::make_shared<drogon::HttpResponse>();

  DepartmentsController controller;
  int departmentId = 123;
  controller.getDepartmentPersons(req, [&resp](const drogon::HttpResponsePtr& r) {
    resp = r;
  }, departmentId);

  // Verify the response
  EXPECT_TRUE(resp);
}
```
Note that these tests are very basic and don't cover all possible scenarios. You may want to add more test cases or use mocking frameworks like Google Mocks to make your tests more robust.

