#pragma once

#include <string>

extern "C" {

namespace worker {

class Worker;

Worker* GetWorker(const std::string& target);
void ReleaseWorker(Worker* client);

class Worker {
 public:
    virtual ~Worker() {}
    virtual bool Init(void* arg) { return true; }
    virtual bool UnInit() { return true; }
    virtual bool Run(void* arg) = 0;
};

}  // namespace worker
}

