#!/usr/bin/env bash

# to study the instantiated STL vector class
# use preprocessor technique to extract the source lines
# this can be followed by a call to clang-format

CXX=c++
CXXARGS="-std=c++14"

createSUT() {
    cat > /tmp/vec.cc <<"EOF"
#include <vector>
void SOURCE_BEGIN() {}

using SUT = std::vector<int>;

void SOURCE_END() {}
int main() {
    return 0;
}
EOF
}

# $1: input file
# $2: output file
run_preprocessor() {
    ${CXX} ${CXXARGS} ${1} -E -o ${2}
}

# $1: file path
extractSourceLines() {
    cat ${1} | perl -lne 'BEGIN {$s=1,$l=0}; $s-- if /SOURCE_BEGIN/; $s++ if /SOURCE_END/; print if $s == $l && length; $l = $s' > /tmp/vec.cc.pp
}

createSUT
run_preprocessor /tmp/vec.cc /tmp/vec.cc.out
extractSourceLines /tmp/vec.cc.out

