#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

const long long MOD = 1000000007;
const int IO_BUFFER_SIZE = 1 * 1024 * 1024;

class Scanner {
public:
    Scanner(std::istream& is) : is_(is) {
        buffer_ = new char[IO_BUFFER_SIZE];
        bufferSize_ = IO_BUFFER_SIZE;
        bufferPointer_ = buffer_;
        bufferEnd_ = buffer_;
    }

    ~Scanner() {
        delete[] buffer_;
    }

    std::string next() {
        while (bufferPointer_ == bufferEnd_ && !refill())
            ;
        std::string result(bufferPointer_, bufferEnd_);
        bufferPointer_ = bufferEnd_;
        return result;
    }

    int nextInt() {
        return std::stoi(next());
    }

private:
    bool refill() {
        bufferEnd_ = buffer_ + is_.rdbuf()->in_avail();
        if (bufferEnd_ == buffer_)
            return false;
        is_.read(buffer_, bufferEnd_ - buffer_);
        bufferPointer_ = buffer_;
        return true;
    }

    std::istream& is_;
    char* buffer_;
    int bufferSize_;
    char* bufferPointer_;
    char* bufferEnd_;
};

int main() {
    Scanner sc(std::cin);
    long long h = sc.nextInt();
    int n = sc.nextInt();

    long long a = 0;

    for (int i = 0; i < n; ++i) {
        a += sc.nextInt();
    }

    if (h > a) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}
