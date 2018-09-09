#!/usr/bin/env bash

set -e
g++ -std=c++11 -Wall -Werror -o /tmp/_ $( dirname ${0} )/constItersTest.cpp
/tmp/_
g++ -std=c++14 -Wall -Werror -o /tmp/_ $( dirname ${0} )/constItersTest.cpp
/tmp/_
