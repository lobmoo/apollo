load("@rules_cc//cc:defs.bzl", "cc_library")



cc_library(
    name = "fastrtps",
    includes = [
        ".",
    ],
   
    linkopts = select({
        "@platforms//cpu:x86_64": ["-L/apollo/third_party/fastrtps/x86_64_lib", "-lfastrtps"],
        "@platforms//cpu:aarch64": ["-L/apollo/third_party/fastrtps/aarch64_lib", "-lfastrtps"],
    }),

    visibility = ["//visibility:public"],
    deps = [
        "@fastcdr",
        "@foonathan_memory",
    ],
)


