#include "impl/worker_2.h"
#include <iostream>
#include "impl/worker_factory.h"

namespace worker {

bool Worker2::Run(void* arg) {
    std::cout << "worker2 runs ok." << std::endl;
    return true;
}

class Worker2Factory : public WorkerFactory {
 public:
    Worker2Factory() {}

    bool AcceptsOptions(const std::string& option) override {
        return option.empty();
    }

    Worker* NewWorker(const std::string& options) override {
        Worker* worker = new (std::nothrow) Worker2();
        return worker;
    }
};

class Worker2Register {
 public:
    Worker2Register() {
        WorkerFactory::Register("WORKER_worker", new Worker2Factory());
    }
};
static Worker2Register register_;

}  // namespace worker
