load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "fastcdr",
    includes = [
        ".",
    ],
    linkopts = select({
        "@platforms//cpu:x86_64": ["-Lthird_party/fastrtps/x86_64_lib", "-lfastcdr"],
        "@platforms//cpu:aarch64": ["-Lthird_party/fastrtps/aarch64_lib", "-lfastcdr"],
    }),
    visibility = ["//visibility:public"],
)
