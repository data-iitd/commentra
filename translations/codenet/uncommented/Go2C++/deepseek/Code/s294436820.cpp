#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <array>
#include <iomanip>

using namespace std;

const bool DEBUG = false;

// -----------------------------------------------------------------------------

// IO helper functions

// Returns next token from input.  It must be initialized by SetInput()
// before the first call.
function<string()> nextToken;
function<string()> nextLine;

// Holds a buffer for output.  It must be initialized by SetOutput().
// All IO functions (read*() and [e]print*()) should write to OutputWriter
// instead of this.
string OutputBuffer;

// Holds an ostream.  It must be initialized by SetOutput().
ostream* OutputWriter;

// Set IO functions for interactive input/output.
void SetInteractive(ostream& w, istream& r) {
    SetUnbufferedInput(r);
    OutputBuffer = "";
    OutputWriter = &w;
}

// Setup OutputBuffer and OutputWriter.
void SetOutput(ostream& w) {
    OutputWriter = &w;
}

void Flush() {
    if (!OutputBuffer.empty()) {
        *OutputWriter << OutputBuffer;
        OutputBuffer.clear();
    }
}

// Returns true if c is a white space
bool IsSpace(char c) {
    switch (c) {
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
        case ' ':
            return true;
    }
    return false;
}

bool IsNewLine(char c) {
    switch (c) {
        case '\n':
        case '\r':
            return true;
    }
    return false;
}

// Setup nextToken with input buffer.
void SetInput(istream& r) {
    stringstream buffer;
    string b;

    auto rest = [&]() -> string {
        string result;
        while (!buffer.eof() && IsSpace(buffer.peek())) {
            buffer.get();
        }
        while (!buffer.eof() && !IsSpace(buffer.peek())) {
            result += buffer.get();
        }
        return result;
    };

    auto initial = [&]() -> string {
        buffer << r.rdbuf();
        b = buffer.str();
        nextToken = rest;
        return rest();
    };

    nextToken = initial;

    auto restLn = [&]() -> string {
        string result;
        while (!buffer.eof() && IsNewLine(buffer.peek())) {
            buffer.get();
        }
        while (!buffer.eof() && !IsNewLine(buffer.peek())) {
            result += buffer.get();
        }
        return result;
    };

    auto initialLn = [&]() -> string {
        buffer << r.rdbuf();
        b = buffer.str();
        nextLine = restLn;
        return restLn();
    };

    nextLine = initialLn;
}

// Setup nextToken without input buffer.
void SetUnbufferedInput(istream& r) {
    auto rest = [&]() -> string {
        string result;
        while (!r.eof() && IsSpace(r.peek())) {
            r.get();
        }
        while (!r.eof() && !IsSpace(r.peek())) {
            result += r.get();
        }
        return result;
    };

    nextToken = rest;
}

// -----------------------------------------------------------------------------

// IO functions

// Reads next token and return it as string
string readb() {
    string b = nextToken();
    if (b.empty()) {
        throw runtime_error("Unexpected EOF");
    }
    return b;
}

// Reads next token and return it as string
string reads() {
    return readb();
}

// Read next line as string.  Trailing '\n' will not be included.
// See also comments on readb()
string readbln() {
    string b = nextLine();
    if (b.empty()) {
        throw runtime_error("Unexpected EOF");
    }
    return b;
}

// Read next line as string
string readsln() {
    return readbln();
}

// Reads next token and return it as int64
int64_t readll() {
    int64_t i = stoll(reads());
    if (i == 0 && reads() != "0") {
        throw runtime_error("Invalid number format");
    }
    return i;
}

// Reads next token and return it as int
int readi() {
    return static_cast<int>(readll());
}

// Reads next token and return it as float64
double readf() {
    double f = stod(reads());
    if (f == 0.0 && reads() != "0") {
        throw runtime_error("Invalid number format");
    }
    return f;
}

// Write args to OutputWriter with the format f
template<typename... Args>
void printf(const string& f, Args&&... args) {
    *OutputWriter <<