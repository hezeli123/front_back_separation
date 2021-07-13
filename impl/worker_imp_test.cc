#include <unistd.h>
#include <fstream>
#include "api/worker.h"
#include "gtest/gtest.h"

namespace worker {

class WorkerTest : public testing::Test {
 public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(WorkerTest, GetWorker) {
    Worker* worker = GetWorker("master");
    Worker* worker1 = GetWorker("master");
    std::cout << "master worker:" << worker << " == worker1:" << worker1 << std::endl;
    if (worker) {
        int num;
        bool bret = worker->Init(&num);
        bret = worker->Init(&num);
        std::cout << "init ret code:" << bret << std::endl;
        worker->Run(&num);
        worker->UnInit();
    }
    worker = GetWorker("");
    std::cout << "worker:" << worker << std::endl;
    if (worker) {
        int num;
        bool bret = worker->Init(&num);
        bret = worker->Init(&num);
        std::cout << "init ret code:" << bret << std::endl;
        worker->Run(&num);
        worker->UnInit();
    }
    ReleaseWorker(worker);
}

}  // namespace worker

