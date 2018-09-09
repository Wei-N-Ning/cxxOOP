#include <vector>

// source
// more exception item 7, P48
// note:
// I had the same question when working on wt's kou
// C++11 standard requires that the storage of a vector is contiguous
// hence &vector[index] can be completely treated as an array of the 
// safe element type

// C function that requires C-style array
extern "C" size_t compress(const char* i_buffer, size_t i_buflen, 
        size_t i_outlen, char* o_buffer) {
    return 0;
}

int main() {
    using namespace std;
    vector<char> sut(100, 0);
    vector<char> compressed(50, 0);
    
    // use of cbegin() is not required (compiler converts it)
    // but for obvious reason I can not directly pass the iterator to 
    // the C function
    compress(&(*sut.cbegin()), sut.size(), 
            compressed.size(), &(*compressed.begin())); 
    return 0;
}
