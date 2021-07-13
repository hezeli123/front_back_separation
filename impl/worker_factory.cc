#include "impl/worker_factory.h"
#include <map>
#include <mutex>
#include <vector>

namespace worker {

static std::mutex* get_factory_lock() {
    static std::mutex factory_lock;
    return &factory_lock;
}

typedef std::map<std::string, WorkerFactory*> WorkerFactories;
WorkerFactories* client_factories() {
    static WorkerFactories* factories = new WorkerFactories;
    return factories;
}

void WorkerFactory::Register(const std::string& worker_type, WorkerFactory* factory) {
    std::lock_guard<std::mutex> lock(*get_factory_lock());
    client_factories()->insert({worker_type, factory});
}

std::string WorkerFactory::RegisteredFactories() {
    std::string factory_types;
    for (const auto& client_factory : *client_factories()) {
        factory_types += client_factory.first + ",";
    }
    return factory_types;
}

int WorkerFactory::GetFactory(const std::string& worker_type, WorkerFactory** out_factory) {
    std::vector<std::pair<std::string, WorkerFactory*>> candidate_factories;
    {
        std::lock_guard<std::mutex> lock(*get_factory_lock());  // could use reader lock
        for (const auto& client_factory : *client_factories()) {
            if (client_factory.second->AcceptsOptions(worker_type)) {
                candidate_factories.push_back(client_factory);
            }
        }
    }
    if (candidate_factories.size() == 1) {
        *out_factory = candidate_factories[0].second;
        return 0;
    } else if (candidate_factories.size() > 1) {
        return 1;
    } else {
        return 2;
    }
}

}  // namespace worker
