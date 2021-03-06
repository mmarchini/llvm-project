// RUN: rm -rf %t
// RUN: %clang_cc1 -fmodules -fmodule-format=obj -fmodule-name=F \
// RUN:     -debug-info-kind=limited -dwarf-ext-refs \
// RUN:     -fimplicit-module-maps -x c -fmodules-cache-path=%t -F %S/Inputs \
// RUN:     %s -S -emit-llvm -debugger-tuning=lldb -o - | FileCheck %s

#include "F/F.h"

// CHECK: !DICompileUnit
// CHECK-NOT: dwoId:

// We still want the import, but no skeleton CU, since no PCM was built.

// CHECK: !DIModule({{.*}}, name: "F"
// CHECK-NOT: !DICompileUnit
// CHECK-NOT: dwoId:
