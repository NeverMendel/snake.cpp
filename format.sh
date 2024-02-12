#!/bin/bash
find -type f \( -iname "*.h" -o -iname "*.cpp" \) | xargs clang-format-18 -i -style=file
