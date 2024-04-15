load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "fastrtps",
    includes = [
        "third_party/fastrtps/include",
    ],
    hdrs = glob(["third_party/fastrtps/include/**/*"]),

    linkopts = select({
        "@platforms//cpu:x86_64": ["-Lthird_party/fastrtps/x86_64_lib", "-lfastrtps"],
        "@platforms//cpu:aarch64": ["-Lthird_party/fastrtps/aarch64_lib", "-lfastrtps"],
        "@platforms//cpu:x86_64": ["-Lthird_party/fastrtps/x86_64_lib", "-lfoonathan_memory-0.7.3"],
        "@platforms//cpu:aarch64": ["-Lthird_party/fastrtps/aarch64_lib", "-lfoonathan_memory-0.7.3"],
        "@platforms//cpu:x86_64": ["-Lthird_party/fastrtps/x86_64_lib", "-lfastcdr"],
        "@platforms//cpu:aarch64": ["-Lthird_party/fastrtps/aarch64_lib", "-lfastcdr"],

    }),
     
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

