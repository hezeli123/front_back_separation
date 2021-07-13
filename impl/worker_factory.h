#include <string>

namespace worker {

class Worker;

class WorkerFactory {
 public:
    virtual ~WorkerFactory() {}
    virtual Worker* NewWorker(const std::string& worker_type) = 0;
    virtual bool AcceptsOptions(const std::string& worker_type) = 0;
    static void Register(const std::string& worker_type, WorkerFactory* factory);
    static int GetFactory(const std::string& worker_type, WorkerFactory** out_factory);
    static std::string RegisteredFactories();
};

}  // namespace worker
