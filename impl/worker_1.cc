#include "impl/worker_1.h"
#include <mutex>
#include "impl/worker_factory.h"
#include <iostream>

namespace worker {

bool Worker1::Init(void* arg) {
    if (nullptr == arg) return false;
    if (!inited_) {
        inited_ = true;
        // ...
    }
    return true;
}

bool Worker1::UnInit() {
    if (!inited_) {
        return true;
    }
    inited_ = false;
    return true;
}

bool Worker1::Run(void* arg) {
    if (nullptr == arg) return false;
    // ...
    std::cout << "worker1 runs ok." << std::endl;
    return true;
}

class Worker1Factory : public WorkerFactory {
 public:
    Worker1Factory() {}

    bool AcceptsOptions(const std::string& option) override {
        return option == "master";
    }

    Worker* NewWorker(const std::string& options) override {
        if (nullptr == worker_) {
            std::lock_guard<std::mutex> lock(lock_);
            worker_ = new (std::nothrow) Worker1();
        }
        return worker_;
    }

 private:
    Worker *worker_ = nullptr;
    std::mutex lock_;
};

class Worker1Register {
 public:
    Worker1Register() {
        WorkerFactory::Register("MASTER_WORKER", new Worker1Factory());
    }
};
static Worker1Register register_;

}  // namespace worker
