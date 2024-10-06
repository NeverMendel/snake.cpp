load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_foreign_cc",
    sha256 = "a2e6fb56e649c1ee79703e99aa0c9d13c6cc53c8d7a0cbb8797ab2888bbc99a3",
    strip_prefix = "rules_foreign_cc-0.12.0",
    url = "https://github.com/bazelbuild/rules_foreign_cc/releases/download/0.12.0/rules_foreign_cc-0.12.0.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

# This sets up some common toolchains for building targets. For more details, please see
# https://bazelbuild.github.io/rules_foreign_cc/0.12.0/flatten.html#rules_foreign_cc_dependencies
rules_foreign_cc_dependencies()

load("@bazel_features//:deps.bzl", "bazel_features_deps")

bazel_features_deps()

all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

http_archive(
    name = "ncurses_sources",
    build_file_content = all_content,
    sha256 = "85edd252024caf4c394a1ac67a30632fd2e03d8cf635c66d3b05f5d158bca80f",
    strip_prefix = "ncurses-snapshots-6_5_20240928",
    urls = ["https://github.com/ThomasDickey/ncurses-snapshots/archive/refs/tags/v6_5_20240928.tar.gz"],
)
