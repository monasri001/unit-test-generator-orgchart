Here is the unit test file using Google Test framework:
```cpp
#include "gtest/gtest.h"
#include "../controllers/PersonsController.h"

TEST(PersonsControllerTest, GetDefault) {
  PersonsController controller;
  auto req = drogon::HttpRequestPtr(new drogon::HttpRequest());
  auto callback = std::function<void(const HttpResponsePtr&)>([] (const HttpResponsePtr& response) { });
  controller.get(req, callback);
  // Add assertions here
}

TEST(PersonsControllerTest, GetOneDefault) {
  PersonsController controller;
  auto req = drogon::HttpRequestPtr(new drogon::HttpRequest());
  int pPersonId = 1;
  auto callback = std::function<void(const HttpResponsePtr&)>([] (const HttpResponsePtr& response) { });
  controller.getOne(req, callback, pPersonId);
  // Add assertions here
}

TEST(PersonsControllerTest, CreateOneDefault) {
  PersonsController controller;
  auto req = drogon::HttpRequestPtr(new drogon::HttpRequest());
  Person person;
  auto callback = std::function<void(const HttpResponsePtr&)>([] (const HttpResponsePtr& response) { });
  controller.createOne(req, callback, person);
  // Add assertions here
}

TEST(PersonsControllerTest, UpdateOneDefault) {
  PersonsController controller;
  auto req = drogon::HttpRequestPtr(new drogon::HttpRequest());
  int pPersonId = 1;
  Person person;
  auto callback = std::function<void(const HttpResponsePtr&)>([] (const HttpResponsePtr& response) { });
  controller.updateOne(req, callback, pPersonId, person);
  // Add assertions here
}

TEST(PersonsControllerTest, DeleteOneDefault) {
  PersonsController controller;
  auto req = drogon::HttpRequestPtr(new drogon::HttpRequest());
  int pPersonId = 1;
  auto callback = std::function<void(const HttpResponsePtr&)>([] (const HttpResponsePtr& response) { });
  controller.deleteOne(req, callback, pPersonId);
  // Add assertions here
}

TEST(PersonsControllerTest, GetDirectReportsDefault) {
  PersonsController controller;
  auto req = drogon::HttpRequestPtr(new drogon::HttpRequest());
  int pPersonId = 1;
  auto callback = std::function<void(const HttpResponsePtr&)>([] (const HttpResponsePtr& response) { });
  controller.getDirectReports(req, callback, pPersonId);
  // Add assertions here
}
```

