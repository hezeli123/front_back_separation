cc_library(
    name = "worker",
    hdrs = glob(["*.h"]),
    srcs = glob(["*.cc"], exclude=["*_test.cc"]),
    deps = [
        "//api:api",
    ],
    alwayslink = 1,
    visibility = [
        "//visibility:public",
    ],
    linkstatic = 1,
)

cc_test(
    name = "test",
    srcs = glob(["*.cc", "*.h"]),
    deps = [
        "@com_google_googletest//:gtest_main",
        "//api:api",
    ],
)

cc_binary(
     name = "_worker.so",
     srcs = glob(["*.h", "*.cc", "worker_wrap.cxx"], exclude=["*_test.cc"]),
     deps = [
         "//api:api",
     ],
     visibility = [
         "//visibility:public",
     ],
     copts = ["-I/usr/include/python2.7"],
     linkshared = True,
 )
