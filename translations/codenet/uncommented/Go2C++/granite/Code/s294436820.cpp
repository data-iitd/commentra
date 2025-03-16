

```cpp
#include <bits/stdc++.h>
using namespace std;

// IO helper functions

// Returns next token from input.  It must be initialized by SetInput()
// before the first call.
auto nextToken = []() {
    string buf;
    getline(cin, buf);
    istringstream iss(buf);
    return [&iss]() mutable {
        string token;
        iss >> token;
        return token;
    };
}();

// Holds a buffer for output.  It must be initialized by SetOutput().
// All IO functions (read*() and [e]print*()) should write to OutputWriter
// instead of this.
auto OutputBuffer = new ostringstream();

// Holds an ostream.  It must be initialized by SetOutput()
auto OutputWriter = OutputBuffer;

// Set IO functions for interactive input/output.
void SetInteractive(ostream &w, istream &r) {
    setbuf(OutputBuffer, nullptr);
    OutputWriter = &w;
}

// Setup OutputBuffer and OutputWriter.
void SetOutput(ostream &w) {
    OutputBuffer = new ostringstream();
    OutputWriter = OutputBuffer;
}

// Flushes OutputBuffer
void Flush() {
    *OutputWriter << OutputBuffer->str();
    OutputBuffer->str("");
    OutputBuffer->clear();
}

// Returns true if c is a white space
bool IsSpace(char c) {
    switch (c) {
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
        case'':
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
void SetInput(istream &r) {
    string buf;
    auto rest = [&buf]() mutable {
        buf.clear();
        getline(r, buf);
        int i = 0;
        while (i < buf.size() && IsSpace(buf[i])) {
            i++;
        }
        if (i == buf.size()) {
            throw runtime_error("unexpected end of input");
        }
        int j = i;
        while (i < buf.size() &&!IsSpace(buf[i])) {
            i++;
        }
        return buf.substr(j, i - j);
    };
    auto initial = [&rest]() mutable {
        buf.clear();
        getline(r, buf);
        return rest();
    };
    nextToken = initial;

    auto restLn = [&buf]() mutable {
        buf.clear();
        getline(r, buf);
        int i = 0;
        while (i < buf.size() && IsNewLine(buf[i])) {
            i++;
        }
        if (i == buf.size()) {
            throw runtime_error("unexpected end of input");
        }
        int j = i;
        while (i < buf.size() &&!IsNewLine(buf[i])) {
            i++;
        }
        return buf.substr(j, i - j);
    };

    auto initialLn = [&restLn]() mutable {
        buf.clear();
        getline(r, buf);
        return restLn();
    };
    nextToken = initialLn;
}

// Setup nextToken without input buffer.
void SetUnbufferedInput(istream &r) {
    auto buf = new string();
    auto rest = [&buf]() mutable {
        buf->clear();
        getline(r, *buf);
        int i = 0;
        while (i < buf->size() && IsSpace((*buf)[i])) {
            i++;
        }
        if (i == buf->size()) {
            throw runtime_error("unexpected end of input");
        }
        int j = i;
        while (i < buf->size() &&!IsSpace((*buf)[i])) {
            i++;
        }
        if (i == j) {
            throw runtime_error("unexpected end of input");
        }
        return (*buf).substr(j, i - j);
    };
    auto initial = [&rest]() mutable {
        buf->clear();
        getline(r, *buf);
        return rest();
    };
    nextToken = initial;
}

// -----------------------------------------------------------------------------

// IO functions

// Reads next token and return it as []byte
string readb() {
    return nextToken();
}

// Reads next token and return it as string
string reads() {
    return nextToken();
}

// Read next line as []byte.  Trailing '\n' will not be included.
// See also comments on readb()
string readbln() {
    return nextToken();
}

// Read next line as string
string readsln() {
    return nextToken();
}

// Reads next token and return it as int64
int64_t readll() {
    string s = nextToken();
    char *end;
    auto res = strtoll(s.c_str(), &end, 10);
    if (end == s.c_str()) {
        throw runtime_error("invalid integer literal");
    }
    return res;
}

// Reads next token and return it as int
int readi() {
    return static_cast<int>(readll());
}

// Reads next token and return it as float64
double readf() {
    string s = nextToken();
    char *end;
    auto res = strtod(s.c_str(), &end);
    if (end == s.c_str()) {
        throw runtime_error("invalid floating point literal");
    }
    return res;
}

// Write args to OutputWriter with the format f
void printf(const string &f,...) {
    va_list args;
    va_start(args, f);
    vfprintf(OutputWriter, f.c_str(), args);
    va_end(args);
}

// Write args to OutputWriter without format
void println(const vector<string> &args) {
    for (const auto &arg : args) {
        *OutputWriter << arg << " ";
    }
    *OutputWriter << endl;
}

// Write args to stderr with the format f
void eprintf(const string &f,...) {
    va_list args;
    va_start(args, f);
    vfprintf(stderr, f.c_str(), args);
    va_end(args);
}

// Write args to stderr without format
void eprintln(const vector<string> &args) {
    for (const auto &arg : args) {
        *OutputWriter << arg << " ";
    }
    *OutputWriter << endl;
}

void debugf(const string &f,...) {
    if (!DEBUG) {
        return;
    }
    va_list args;
    va_start(args, f);
    vfprintf(stderr, f.c_str(), args);
    va_end(args);
}

void debug(const vector<string> &args) {
    if (!DEBUG) {
        return;
    }
    for (const auto &arg : args) {
        *OutputWriter << arg << " ";
    }
    *OutputWriter << endl;
}

// -----------------------------------------------------------------------------

// Utilities

const int64_t INF = 10000000007;
const int64_t INF2 = 10000000009;
const int64_t INF3 = 998244353;

int64_t sumSlice(const vector<int64_t> &a) {
    int64_t res = 0;
    for (const auto &v : a) {
        res += v;
    }
    return res;
}
int64_t sumSlicell(const vector<int64_t> &a) {
    int64_t res = 0;
    for (const auto &v : a) {
        res += v;
    }
    return res;
}
int64_t readInts(int N, vector<int64_t> &a) {
    if (N == 0 {
        N = readi();
    }
    for i := 0; i < N; i++ {
        a[i] = readi();
    }
    return a;
}

int64_t readIntsll(int N, vector<int64_t> &a) {
    if (N == 0 {
        N = readi();
    }
    for i := 0; i < N; i++ {
        a[i] = readi();
    }
    return a;
}

// -----------------------------------------------------------------------------

// Simple math functions

const int64_t DEBUG = false;

int64_t min(int64_t a, int64_t b) {
    if a < b {
        return a
    }
    return b
}

int64_t minll(int64_t a, int64_t b) {
    if a < b {
        return a
    }
    return b
}

int64_t minf(float64_t a, float64_t b) {
    if a < b {
        return a
    }
    return b
}

int64_t gcd(int64_t a, int64_t b) {
    if a < b {
        return a
    }
    return b
}

int64_t gcdll(int64_t a, int64_t b) {
    if a < b {
        return a
    }
    return b
}

// Set up IO functions

func init() {
    // for non-interactive
    SetInput(os.Stdin)
    SetOutput(os.Stdout)

    // Enable below when interactive.  Its ok to leave above intact.
}

func SetInteractive(io.Writer, io.Reader) {
    SetInteractive(os.Stdout, os.Stdin)
    SetOutput(os.Stdout)

    // Set up IO functions

func SetInput(r io.Reader) {
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.Stdin)
    SetOutput(os.Stdout)
    SetInput(os.S