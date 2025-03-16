
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Scanner {
public:
    Scanner(istream& is) : is(is) {
    }

    string ReadLine() {
        string s;
        getline(is, s);
        return s;
    }

    vector<string> ReadLines(int n) {
        vector<string> a;
        for (int i = 0; i < n; i++) {
            a.push_back(ReadLine());
        }
        return a;
    }

private:
    istream& is;
};

class Value {
public:
    Value(string s) : s(s) {
    }

    string String() {
        return s;
    }

    int Int() {
        int n;
        stringstream ss(s);
        ss >> n;
        return n;
    }

    float Float64() {
        float f;
        stringstream ss(s);
        ss >> f;
        return f;
    }

    vector<string> Strings() {
        vector<string> a;
        stringstream ss(s);
        string t;
        while (ss >> t) {
            a.push_back(t);
        }
        return a;
    }

    vector<int> Ints() {
        vector<int> a;
        stringstream ss(s);
        string t;
        while (ss >> t) {
            a.push_back(stoi(t));
        }
        return a;
    }

    vector<float> Float64s() {
        vector<float> a;
        stringstream ss(s);
        string t;
        while (ss >> t) {
            a.push_back(stof(t));
        }
        return a;
    }

    vector<rune> Runes() {
        vector<rune> a;
        for (auto c : s) {
            a.push_back(c);
        }
        return a;
    }

private:
    string s;
};

class Values {
public:
    Values(vector<Value> v) : v(v) {
    }

    vector<vector<string>> Strings() {
        vector<vector<string>> a;
        for (auto value : v) {
            a.push_back(value.Strings());
        }
        return a;
    }

    vector<vector<int>> Ints() {
        vector<vector<int>> a;
        for (auto value : v) {
            a.push_back(value.Ints());
        }
        return a;
    }

    vector<vector<float>> Float64s() {
        vector<vector<float>> a;
        for (auto value : v) {
            a.push_back(value.Float64s());
        }
        return a;
    }

    vector<vector<rune>> Runes() {
        vector<vector<rune>> a;
        for (auto value : v) {
            a.push_back(value.Runes());
        }
        return a;
    }

private:
    vector<Value> v;
};

void Run(istream& is, ostream& os) {
    Scanner sc(is);

    vector<int> a = sc.ReadLine().Ints();
    int N = a[0], D = a[1];

    vector<vector<int>> lines = sc.ReadLines(N).Ints();

    int count = 0;
    for (auto line : lines) {
        float d = sqrt(line[0] * line[0] + line[1] * line[1]);
        if (D >= d) {
            count++;
        }
    }
    os << count << endl;
}

int main() {
    Run(cin, cout);
    return 0;
}

