#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

double AbsDiffFloat64(double n1, double n2) {
    return fabs(n1 - n2);
}

class IO {
public:
    IO() : cin(cin.rdbuf()), cout(cout.rdbuf()) {}

    int ScanInt() {
        int x;
        cin >> x;
        return x;
    }

    double ScanFloat64() {
        double x;
        cin >> x;
        return x;
    }

    vector<double> ScanFloat64s(int n) {
        vector<double> floats(n);
        for (int i = 0; i < n; i++) {
            cin >> floats[i];
        }
        return floats;
    }

    void Println(double a) {
        cout << a << endl;
    }

private:
    istream& cin;
    ostream& cout;
};

int main() {
    IO io;

    int n = io.ScanInt();
    double t = io.ScanFloat64();
    double a = io.ScanFloat64();
    vector<double> heights = io.ScanFloat64s(n);

    double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }
    io.Println(minIdx + 1);

    return 0;
}
