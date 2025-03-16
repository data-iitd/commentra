
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string getNextString(ifstream *fp) {
    string s;
    getline(*fp, s);
    return s;
}

int getNextInt(ifstream *fp) {
    int i;
    *fp >> i;
    return i;
}

int64_t getNextInt64(ifstream *fp) {
    int64_t i;
    *fp >> i;
    return i;
}

uint64_t getNextUint64(ifstream *fp) {
    uint64_t i;
    *fp >> i;
    return i;
}

double getNextFloat64(ifstream *fp) {
    double i;
    *fp >> i;
    return i;
}

int main() {
    ifstream *fp = &cin;
    ofstream *wfp = &cout;

    if (argc > 1) {
        fp = new ifstream(argv[1]);
        if (argc > 2) {
            wfp = new ofstream(argv[2]);
        }
    }

    string ans = "second";
    int n = getNextInt(fp);
    for (int i = 0; i < n; i++) {
        int a = getNextInt(fp);
        if (a % 2 == 1) {
            ans = "first";
            break;
        }
    }
    *wfp << ans << endl;
    wfp->flush();

    if (argc > 1) {
        delete fp;
        delete wfp;
    }

    return 0;
}

