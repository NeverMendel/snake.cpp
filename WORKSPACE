load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_foreign_cc",
    sha256 = "476303bd0f1b04cc311fc258f1708a5f6ef82d3091e53fd1977fa20383425a6a",
    strip_prefix = "rules_foreign_cc-0.10.1",
    url = "https://github.com/bazelbuild/rules_foreign_cc/releases/download/0.10.1/rules_foreign_cc-0.10.1.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

# This sets up some common toolchains for building targets. For more details, please see
# https://bazelbuild.github.io/rules_foreign_cc/0.10.1/flatten.html#rules_foreign_cc_dependencies
rules_foreign_cc_dependencies()

all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

http_archive(
    name = "ncurses_sources",
    build_file_content = all_content,
    sha256 = "39893846139518e6c2d00ac1d354d4889f0f394acd44885d70b14eaef4e23e8e",
    strip_prefix = "ncurses-6.4",
    urls = ["https://github.com/mirror/ncurses/archive/refs/tags/v6.4.tar.gz"],
)
