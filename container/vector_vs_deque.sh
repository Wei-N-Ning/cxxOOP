#!/usr/bin/env bash

# source
# more exception item 7 P48
# see vector_vs_deque_pp.cpp (expanded C++11 deque<int>)

# see also
# https://www.evernote.com/shard/s386/nl/65817914/a1315734-d266-4452-a281-dae18f0d2ce8?title=An%20In-Depth%20Study%20of%20the%20STL%20Deque%20Container%20-%20CodeProject
# (original post: https://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container)
# UPDATE:
# it is being documented in std_deque.cpp!!

# there are a couple of oversimplified versions of the above analysis:
# http://cpp-tip-of-the-day.blogspot.com/2013/11/how-is-stddeque-implemented.html
# https://stackoverflow.com/questions/6292332/what-really-is-a-deque-in-stl

# from cpp reference:
# https://en.cppreference.com/w/cpp/container/deque
# As opposed to std::vector, the elements of a deque are not stored contiguously: typical implementations use a
# sequence of individually allocated fixed-size arrays, with additional bookkeeping, which means indexed access to
# deque must perform two pointer dereferences, compared to vector's indexed access which performs only one.

# note the terminology used in GNU's implementation:
# iterator, node (is the chunk?), node iterator, allocator

###########
# the code project article leads to another important concept of
# time-tracking (essential technique in profiling and performance testing)
# see system/perf_timer.cpp
###########

CC=${CC-gcc}
CXX=${CXX-g++}
DBG=${DBG-gdb}

set -e

TEMPDIR=/tmp/sut

tearDown() {
    rm -rf ${TEMPDIR} /tmp/_ /tmp/_.* /tmp/__*
}

setUp() {
    tearDown
    mkdir -p ${TEMPDIR}
}

# this subroutine expand the std::deque,
# the full source can be in the next file: vector_vs_deque_pp.cpp
#
# pay attention to these constructs:
#
# struct _Deque_iterator
# class _Deque_base
# class deque : protected _Deque_base<_Tp, _Alloc>
#
buildSUT() {
    cat > ${TEMPDIR}/_.cpp << "EOF"
#include <deque>

void _SOURCE_BEGIN_() {}
typedef std::deque<int> TT;
void _SOURCE_END_() {}

int main() {
    return 0;
}
EOF
    # preprocessor technique
    ${CXX} -E -o ${TEMPDIR}/_.pp.cpp ${TEMPDIR}/_.cpp
    ls ${TEMPDIR}/_.pp.cpp
}


setUp
buildSUT

