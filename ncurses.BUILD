load("@rules_foreign_cc//foreign_cc:defs.bzl", "configure_make")

filegroup(
    name = "ncurses_srcs",
    srcs = glob(["**"]),
)

configure_make(
    name = "ncurses",
    configure_command = "configure",
    configure_options = [
        "--prefix $$INSTALLDIR",
        "--with-terminfo-dirs=/usr/share/terminfo:/lib/terminfo:/usr/share/misc/terminfo",
    ],
    lib_source = ":ncurses_srcs",
    out_static_libs = [
        "libform.a",
        "libmenu.a",
        "libncurses++.a",
        "libncurses.a",
        "libpanel.a",
    ],
    visibility = ["//visibility:public"],
)
