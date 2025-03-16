#include <bits/stdc++.h>
using namespace std;

// Step 2: Define the Scanner and PrintWriter for input and output operations.
#define in std::cin
#define out std::cout

// Step 3: Implement the solve method to find the position of a given value in a sequence.
void solve() {
    long position = in.nextLong();
    long nrstSeqStartIndx = 1;

    // Step 4: Find the starting index of the sequence where the position might be located.
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }

    // Step 4: Find the exact position within the sequence.
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }

    long startIndex = getValueAtIndex(nrstSeqStartIndx);
    out << (position - startIndex) + 1;
}

// Step 4: Implement the getValueAtIndex method to calculate the value at a specific index in the sequence.
long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2);
}

// Step 5: Implement the main method to initialize the input and call the solve method.
int main() {
    // Step 7: Initialize the input reader for the in class.
    in.init(std::cin);
    solve();
    out.close();
    return 0;
}

// Step 7: Implement the in class to handle input operations.
namespace in {
    std::istream *stream;
    std::istream &init(std::istream &stream) {
        in::stream = &stream;
        return *stream;
    }
    std::istream &operator>>(std::istream &stream, int &value) {
        return stream >> value;
    }
    std::istream &operator>>(std::istream &stream, long long &value) {
        return stream >> value;
    }
    std::istream &operator>>(std::istream &stream, double &value) {
        return stream >> value;
    }
    std::istream &operator>>(std::istream &stream, std::string &value) {
        return stream >> value;
    }
    std::istream &operator>>(std::istream &stream, std::string *value) {
        return stream >> *value;
    }
    std::istream &operator>>(std::istream &stream, char *value) {
        return stream >> value;
    }
    std::istream &operator>>(std::istream &stream, char &value) {
        return stream >> value;
    }
    std::istream &operator>>(std::istream &stream, bool &value) {
        return stream >> value;
    }
    std::istream &operator>>(std::istream &stream, std::istream &(*pf)(std::istream &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *& &(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base & &(*pf)(std::ios_base &)) {
        return stream >> pf;
    }
    std::istream &operator>>(std::istream &stream, std::ios_base *&(*pf)(std::ios_base *)) {
        return stream >> pf;
    }
    std::istream &