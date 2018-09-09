//
// Created by wein on 11/24/17.
//

#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>
#include <iostream>
#include <vector>

using SamplesT = std::unordered_map<int, int>;
using IndicesT = std::set<int>;


std::string indicesToStr(const SamplesT &samples) {
    std::stringstream ss;
    for (const auto &idx : samples) {
        ss << idx.first << " ";
    }
    return ss.str();
}


template<typename T>
std::string sequenceToStr(const T &sequence) {
    std::stringstream ss;
    for (const auto &each : sequence) {
        ss << each << " ";
    }
    return ss.str();
}


std::set<int> getOrderedIndicesM(const SamplesT &samples) {
    IndicesT indices;
    for (const auto &idx : samples) {
        indices.emplace(idx.first);
    }
    return indices;
}


std::vector<int> getOrderedIndicesV(const SamplesT &samples) {
    std::vector<int> indices;
    for (SamplesT::const_iterator it = samples.cbegin(); it != samples.cend(); ++it) {
        indices.emplace_back(it->first);
    }
    std::sort(indices.begin(), indices.end());
    return indices;
}

/*
 * This function is to demonstrate how to sort the indices of an unordered map using C++98 and C++11 inspired by an
 * issue in Wt's AsfAmc project: ASFAMC-603
 *
 * */
void sortingDemo() {
    SamplesT samples{{10, 0xBEEF}, {-13, 0xBEEF}, {1, 0xBEEF}, {234, 0xBEEF}, {4, 0xBEEF}};

    std::cout << indicesToStr(samples) << std::endl;

    // C++11
    std::cout << sequenceToStr(getOrderedIndicesM(samples)) << std::endl;

    // C++98
    std::cout << sequenceToStr(getOrderedIndicesV(samples)) << std::endl;
}


int main(int argc, char** argv) {

    sortingDemo();

    return 0;
}
