#!/usr/bin/env bash

setUp() {
    set -e
}

buildSUTCXX98() {
    g++ -Wall -DCXX_STANDARD_98=1 -std=c++98 -o /tmp/_ $( dirname ${0} )/explicitBoolConv.cpp
}

buildSUTCXX11() {
    g++ -Wall -std=c++11 -o /tmp/_ $( dirname ${0} )/explicitBoolConv.cpp
}

runSUT() {
    /tmp/_
}

setUp
buildSUTCXX98
runSUT
buildSUTCXX11
runSUT
