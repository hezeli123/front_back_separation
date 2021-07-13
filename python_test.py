#!/bin/python
import worker
type_str = u"master"
print type(type_str)
print type(str(type_str))
# master = worker.GetWorker(type_str.encode('utf-8'))
master = worker.GetWorker(str(type_str))
print "master:", master

wk = worker.GetWorker(str(""))
print "worker:", wk
config = worker.new_intp()
master.Init(config)
wk.Init(config)
context = worker.new_intp()
master.Run(context)
wk.Run(context)

# struc test
config = worker.Config()
print config.num
print config.fd
config.num = 11
config.fd = True
print config.num
print config.fd
#pconf = worker.new_Configp()
master.Run(config)

