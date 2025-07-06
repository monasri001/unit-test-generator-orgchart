Here is the unit test file for `JobsController` using Google Test framework:
```cpp
#include <gtest/gtest.h>

#include "JobsController.h"
#include "Job.h"

class JobsControllerTest : public ::testing::Test {
 protected:
    JobsController controller_;
};

TEST_F(JobsControllerTest, GetMethod) {
    // TO DO: implement test for get method
}

TEST_F(JobsControllerTest, GetOneMethod) {
    int pJobId = 1;
    HttpRequestPtr req = nullptr;
    HttpResponsePtr callbackResponse;

    controller_.getOne(req, [&callbackResponse](const HttpResponsePtr &response) { callbackResponse = response; }, pJobId);

    // TO DO: implement assertions for get one method
}

TEST_F(JobsControllerTest, CreateOneMethod) {
    Job job_;
    HttpRequestPtr req = nullptr;
    HttpResponsePtr callbackResponse;

    controller_.createOne(req, [&callbackResponse](const HttpResponsePtr &response) { callbackResponse = response; }, job_);

    // TO DO: implement assertions for create one method
}

TEST_F(JobsControllerTest, UpdateOneMethod) {
    int pJobId = 1;
    Job job_;
    HttpRequestPtr req = nullptr;
    HttpResponsePtr callbackResponse;

    controller_.updateOne(req, [&callbackResponse](const HttpResponsePtr &response) { callbackResponse = response; }, pJobId, job_);

    // TO DO: implement assertions for update one method
}

TEST_F(JobsControllerTest, DeleteOneMethod) {
    int pJobId = 1;
    HttpRequestPtr req = nullptr;
    HttpResponsePtr callbackResponse;

    controller_.deleteOne(req, [&callbackResponse](const HttpResponsePtr &response) { callbackResponse = response; }, pJobId);

    // TO DO: implement assertions for delete one method
}

TEST_F(JobsControllerTest, GetJobPersonsMethod) {
    int jobId = 1;
    HttpRequestPtr req = nullptr;
    HttpResponsePtr callbackResponse;

    controller_.getJobPersons(req, [&callbackResponse](const HttpResponsePtr &response) { callbackResponse = response; }, jobId);

    // TO DO: implement assertions for get job persons method
}

int main(int argc, char **argv) {
    ::testing::InitGoogle(&argc, argv);
    return RUN_ALL_TESTS();
}
```
Note that this is just a starting point, and you'll need to implement the actual test cases for each method.

