load("@rules_foreign_cc//foreign_cc:defs.bzl", "configure_make")

configure_make(
    name = "ncurses",
    configure_command = "configure",
    configure_options = [
        "--prefix $$INSTALLDIR",
        "--with-terminfo-dirs=/usr/share/terminfo:/lib/terminfo:/usr/share/misc/terminfo",
    ] + select({
        "@platforms//os:osx": [],
        "//conditions:default": [
            "ARFLAGS=-curvU",
        ],
    }),
    env = {
        "AR": "ar",
    },
    lib_source = "@ncurses_sources//:all",
    out_static_libs = [
        "libformw.a",
        "libmenuw.a",
        "libncurses++w.a",
        "libncursesw.a",
        "libpanelw.a",
    ],
    visibility = ["//visibility:public"],
)
