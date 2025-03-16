
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <functional>
#include <cctype>
#include <cassert>
#include <climits>
#include <iomanip>
#include <cassert>
#include <random>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <climits>
#include <iomanip>
#include <cassert>
#include <random>
#include <complex>

using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Scanner {
    Scanner(std::istream& in) : buf(), ps(0), pe(0) {
        std::cin >> std::noskipws;
        buf.reserve(100000);
        for (char c = in.get(); c!= EOF; c = in.get()) {
            buf.push_back(c);
        }
    }
    inline std::string Next() {
        assert(ps < pe);
        const int begin = ps;
        int end = ps;
        while (end < pe && buf[end]!='') {
            end++;
        }
        ps = end + 1;
        return std::string(buf.begin() + begin, buf.begin() + end);
    }
    inline std::string NextLine() {
        assert(ps < pe);
        const int begin = ps;
        int end = ps;
        while (end < pe && (buf[end] == '\n' || buf[end] == '\r')) {
            end++;
        }
        ps = end + 1;
        return std::string(buf.begin() + begin, buf.begin() + end);
    }
    inline int NextInt() {
        std::string s = Next();
        int v;
        std::istringstream sin(s);
        sin >> v;
        return v;
    }
    inline ll NextInt64() {
        std::string s = Next();
        ll v;
        std::istringstream sin(s);
        sin >> v;
        return v;
    }
    inline double NextFloat() {
        std::string s = Next();
        double v;
        std::istringstream sin(s);
        sin >> v;
        return v;
    }
    inline std::vector<int> NextIntArray(int n) {
        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(NextInt());
        }
        return res;
    }
    inline std::vector<ll> NextInt64Array(int n) {
        std::vector<ll> res;
        for (int i = 0; i < n; i++) {
            res.push_back(NextInt64());
        }
        return res;
    }
    inline std::vector<std::string> NextStringArray(int n) {
        std::vector<std::string> res(n, "");
        for (int i = 0; i < n; i++) {
            res[i] = Next();
        }
        return res;
    }
    inline std::vector<double> NextFloatArray(int n) {
        std::vector<double> res;
        for (int i = 0; i < n; i++) {
            res.push_back(NextFloat());
        }
        return res;
    }
    inline std::vector<std::vector<int>> NextIntMatrix(int n, int m) {
        std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = NextInt();
            }
        }
        return res;
    }
    inline std::vector<std::vector<ll>> NextInt64Matrix(int n, int m) {
        std::vector<std::vector<ll>> res(n, std::vector<ll>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = NextInt64();
            }
        }
        return res;
    }
    inline std::vector<std::vector<double>> NextFloatMatrix(int n, int m) {
        std::vector<std::vector<double>> res(n, std::vector<double>(m, 0.0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = NextFloat();
            }
        }
        return res;
    }
    inline std::vector<std::vector<char>> NextCharMatrix(int n, int m) {
        std::vector<std::vector<char>> res(n, std::vector<char>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = NextChar();
            }
        }
        return res;
    }
    inline void ReadLine(char* buf, size_t size) {
        for (int i = 0; i < size; i++) {
            buf[i] = NextChar();
        }
    }
    inline std::string ReadLine() {
        const int MAX_SIZE = 1000000;
        char buf[MAX_SIZE];
        ReadLine(buf, MAX_SIZE);
        return std::string(buf);
    }
    inline std::vector<std::string> ReadLineToken() {
        std::vector<std::string> res;
        std::string s = ReadLine();
        std::string word = "";
        for (char c : s) {
            if (c =='') {
                res.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        if (!word.empty()) res.push_back(word);
        return res;
    }
    inline std::vector<std::string> ReadAllLinesToken() {
        std::vector<std::string> res;
        std::string s = ReadLine();
        while (!s.empty()) {
            std::vector<std::string> token = ReadLineToken();
            for (std::string t : token) {
                res.push_back(t);
            }
            s = ReadLine();
        }
        return res;
    }
    inline std::vector<std::string> ReadAllLines() {
        std::vector<std::string> res;
        std::string s = ReadLine();
        while (!s.empty()) {
            res.push_back(s);
            s = ReadLine();
        }
        return res;
    }
    inline void Shuffle(std::vector<int>& v) {
        int n = v.size();
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            std::swap(v[i], v[j]);
        }
    }
    inline void Shuffle(std::vector<ll>& v) {
        int n = v.size();
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            std::swap(v[i], v[j]);
        }
    }
    inline void Shuffle(std::vector<double>& v) {
        int n = v.size();
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            std::swap(v[i], v[j]);
        }
    }
    inline void Shuffle(std::vector<std::string>& v) {
        int n = v.size();
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            std::swap(v[i], v[j]);
        }
    }
    inline void Reverse(std::vector<int>& v) {
        std::reverse(v.begin(), v.end());
    }
    inline void Reverse(std::vector<ll>& v) {
        std::reverse(v.begin(), v.end());
    }
    inline void Reverse(std::vector<double>& v) {
        std::reverse(v.begin(), v.end());
    }
    inline void Reverse(std::vector<std::string>& v) {
        std::reverse(v.begin(), v.end());
    }
    inline void Reverse(std::vector<char>& v) {
        std::reverse(v.begin(), v.end());
    }
    inline void Reverse(std::string& s) {
        std::reverse(s.begin(), s.end());
    }
    inline bool NextPermutation(std::vector<int>& v) {
        int n = (int)v.size();
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                int j = n - 1;
                while (v[j] <= v[i]) {
                    j--;
                }
                std::swap(v[i], v[j]);
                std::reverse(v.begin() + i + 1, v.end());
                return true;
            }
        }
        return false;
    }
    inline bool NextPermutation(std::vector<ll>& v) {
        int n = (int)v.size();
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                int j = n - 1;
                while (v[j] <= v[i]) {
                    j--;
                }
                std::swap(v[i], v[j]);
                std::reverse(v.begin() + i + 1, v.end());
                return true;
            }
        }
        return false;
    }
    inline bool NextPermutation(std::vector<double>& v) {
        int n = (int)v.size();
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                int j = n - 1;
                while (v[j] <= v[i]) {
                    j--;
                }
                std::swap(v[i], v[j]);
                std::reverse(v.begin() + i + 1, v.end());
                return true;
            }
        }
        return false;
    }
    inline bool NextPermutation(std::vector<std::string>& v) {
        int n = (int)v.size();
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                int j = n - 1;
                while (v[j] <= v[i]) {
                    j--;
                }
                std::swap(v[i], v[j]);
                std::reverse(v.begin() + i + 1, v.end());
                return true;
            }
        }
        return false;
    }
    inline bool NextPermutation(std::vector<char>& v) {
        int n = (int)v.size();
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                int j = n - 1;
                while (v[j] <= v[i]) {
                    j--;
                }
                std::swap(v[i], v[j]);
                std::reverse(v.begin() + i + 1, v.end());
                return true;
            }
        }
        return false;
    }
    inline void Print() {
        std::cout << std::endl;
    }
    template <typename T>
    inline void Print(const T& t) {
        std::cout << t << std::endl;
    }
    template <typename T, typename... Args>
    inline void Print(const T& t, const Args&... args) {
        std::cout << t << " ";
        Print(args...);
    }
    template <typename... Args>
    inline void PrintLine(const Args&... args) {
        Print(args...);
        std::cout << std::endl;
    }
    inline void Read(int& n) {
        std::cin >> n;
    }
    inline void Read(ll& n) {
        std::cin >> n;
    }
    inline void Read(double& n) {
        std::cin >> n;
    }
    inline void Read(char& c) {
        std::cin >> c;
    }
    inline void Read(std::string& s) {
        std::cin >> s;
    }
    template <typename T>
    inline void Read(std::vector<T>& v) {
        for (int i = 0; i < v.size(); i++) {
            std::cin >> v[i];
     