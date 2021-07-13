#include <atomic>
#include <vector>
#include <string>
#include <map>
#include "api/worker.h"

namespace worker {

class Worker1 : public Worker {
 public:
    virtual ~Worker1() {}
    virtual bool Init(void* arg);
    virtual bool UnInit();
    virtual bool Run(void* arg);

 private:
    bool inited_ = false;
};

}  // namespace worker
