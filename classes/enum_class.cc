
// source
// https://en.cppreference.com/w/cpp/language/enum
// note the use of : type after the class keyword
// each member should be named in lowercase 
// callsite should take enum class member by value 

enum class Compression : char {
    no = 0,
    fast = 1,
    good = 2,
};

void compress(Compression option) {
    ;
}

int main() {
    compress(Compression::no);
    return 0;
}
