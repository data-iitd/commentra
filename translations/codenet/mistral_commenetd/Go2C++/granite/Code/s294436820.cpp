

#include <bits/stdc++.h>
using namespace std;

// Constants for large prime numbers used in modular arithmetic.
const int64_t INF = 1000000007;
const int64_t INF2 = 1000000009;
const int64_t INF3 = 998244353;

// Global variable for debug mode.
bool DEBUG = false;

// -----------------------------------------------------------------------------
// IO helper functions

// Returns next token from input. It must be initialized by SetInput() before the first call.
auto nextToken = []() {
    string buf;
    getline(cin, buf);
    istringstream iss(buf);
    return [&iss]() {
        string tmp;
        iss >> tmp;
        return tmp;
    };
}();

// Holds a buffer for output. It must be initialized by SetOutput().
// All IO functions (read*() and [e]print*()) should write to OutputWriter instead of this.
string OutputBuffer;

// Holds an io.Writer. It must be initialized by SetOutput()
ostream OutputWriter(cout);

// Set IO functions for interactive input/output.
void SetInteractive(ostream& w, istream& r) {
    OutputBuffer = "";
    OutputWriter = w;
}

// Setup OutputBuffer and OutputWriter.
void SetOutput(ostream& w) {
    OutputBuffer = "";
    OutputWriter = w;
}

// Flushes OutputBuffer
void Flush() {
    if (!OutputBuffer.empty()) {
        OutputWriter << OutputBuffer;
        OutputBuffer = "";
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
void SetInput(istream& r) {
    string buf;
    char c;

    function<string()> rest = [&]() {
        buf.clear();
        while (r >> noskipws >> c) {
            if (IsSpace(c)) {
                break;
            }
            buf += c;
        }
        return buf;
    };

    function<string()> initial = [&]() {
        buf.clear();
        r >> noskipws;
        while (r >> noskipws >> c) {
            buf += c;
        }
        return rest();
    };

    nextToken = initial;

    function<string()> restLn = [&]() {
        buf.clear();
        while (r >> noskipws >> c) {
            if (IsNewLine(c)) {
                break;
            }
            buf += c;
        }
        return buf;
    };

    function<string()> initialLn = [&]() {
        buf.clear();
        r >> noskipws;
        while (r >> noskipws >> c) {
            if (IsNewLine(c)) {
                break;
            }
            buf += c;
        }
        return restLn();
    };

    nextToken = initialLn;
}

// Setup nextToken without input buffer.
void SetUnbufferedInput(istream& r) {
    bufstream buf(nullptr);
    char c;

    function<string()> rest = [&]() {
        buf.str("");
        while (r >> noskipws >> c) {
            if (IsSpace(c)) {
                break;
            }
            buf << c;
        }
        return buf.str();
    };

    function<string()> initial = [&]() {
        buf.str("");
        r >> noskipws;
        while (r >> noskipws >> c) {
            buf << c;
        }
        return rest();
    };

    nextToken = initial;

    function<string()> restLn = [&]() {
        buf.str("");
        while (r >> noskipws >> c) {
            if (IsNewLine(c)) {
                break;
            }
            buf << c;
        }
        return buf.str();
    };

    function<string()> initialLn = [&]() {
        buf.str("");
        r >> noskipws;
        while (r >> noskipws >> c) {
            if (IsNewLine(c)) {
                break;
            }
            buf << c;
        }
        return restLn();
    };

    nextToken = initialLn;
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

// Read next line as []byte. Trailing '\n' will not be included.
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
    int64_t i;
    istringstream iss(<fim_middle>
// Function to solve the problem.
int solve(int h, int w, int a, vector<vector<int>>& m) {
    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            vector<vector<int>> tmp = m;
            for (int j = 0; j < h; j++) {
                for (int l = 0; l < w; l++) {
                    tmp[j][l] = m[j][l];
                }
            }
            for (int j = 0; j < h; j++) {
                int hPainted = (1 << j & i);
                if (hPainted > 0) {
                    debug("painted ", j, 1 << j, i, hPainted);
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1;
                    }
                }
            }
            for (int j = 0; j < w; j++) {
                int wPainted = (1 << j & k);
                if (wPainted > 0) {
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1;
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) {
                result++;
            }
        }
    }
    return result;
}

// Constants for black cell representation.
const int Black = 35;

// -----------------------------------------------------------------------------
// Simple math functions

// min returns the minimum of two integers.
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

// max returns the maximum of two integers.
func max(a, b int) int {
    if a < b {
        return b
    }
    return a
}

// abs returns the absolute value of an integer.
func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

// absll returns the absolute value of an int64.
func absll(a int64) int64 {
    if a < 0 {
        return -a
    }
    return a
}

// maxf returns the maximum of two float64.
func maxf(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}

// minf returns the minimum of two float64.
func minf(a, b float64) float64 {
    if a < b {
        return a
    }
    return b
}

// maxll returns the maximum of two int64.
func maxll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxf returns the maximum of two float64.
func maxf(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}

// absll returns the absolute value of an int64.
func absll(a int64) int64 {
    if a < 0 {
        return -a
    }
    return a
}

// minll returns the minimum of two int64.
func minll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxll returns the maximum of two int64.
func maxll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxf returns the maximum of two float64.
func maxf(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}

// minf returns the minimum of two float64.
func minf(a, b float64) float64 {
    if a < b {
        return a
    }
    return b
}

// maxfll returns the maximum of two int64.
func maxfll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// minfll returns the minimum of two float64.
func minfll(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}

// maxfll returns the maximum of two int64.
func maxfll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxfll returns the maximum of two float64.
func maxfll(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}
// maxll returns the maximum of two int64.
func maxll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxf returns the maximum of two float64.
func maxf(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}
// maxll returns the maximum of two int64.
func maxll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxfll returns the maximum of two float64.
func maxfll(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}
// maxf returns the maximum of two float64.
func maxf(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}
// maxll returns the maximum of two int64.
func maxll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxf returns the maximum of two float64.
func maxf(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}

// maxll returns the maximum of two int64.
func maxll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxfll returns the maximum of two float64.
func maxfll(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}

// maxf returns the maximum of two float64.
func maxf(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}

// maxll returns the maximum of two int64.
func maxll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxfll returns the maximum of two float64.
func maxfll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxf returns the maximum of two float64.
func maxf(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}

// maxll returns the maximum of two int64.
func maxll(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

// maxfll returns the maximum of two float64.
func maxf(a, b float64) float64 {
    if a < b {
        return b
    }
    return a
}

// maxfll returns the maximum of two int64.
func maxfll(a, b int64) int64 {
    if a < b {
   