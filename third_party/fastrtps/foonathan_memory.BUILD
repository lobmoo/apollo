load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "foonathan_memory",
    includes = [
        ".",
    ],
    linkopts = select({
        "@platforms//cpu:x86_64":  ["-Lthird_party/fastrtps/x86_64_lib", "-lfoonathan_memory-0.7.3"],
        "@platforms//cpu:aarch64": ["-Lthird_party/fastrtps/aarch64_lib", "-lfoonathan_memory-0.7.3"],
    }),
    visibility = ["//visibility:public"],
)
