#include "api/worker.h"
#include "impl/worker_factory.h"

namespace worker {

Worker* GetWorker(const std::string& target) {
    WorkerFactory* factory;
    int nret = WorkerFactory::GetFactory(target, &factory);
    if (0 != nret) {
        return nullptr;
    }
    return factory->NewWorker(target);
}

void ReleaseWorker(Worker* worker) {
    if (worker) {
        worker->UnInit();
        delete worker;
    }
}

}  // namespace worker
