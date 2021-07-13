#include "api/worker.h"

namespace worker {

class Worker2 : public Worker {
 public:
    virtual ~Worker2() {}
    virtual bool Run(void* arg);
};

}  // namespace worker
