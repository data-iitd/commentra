#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Data {
    int n, m;
    vector<string> nImg, mImg;

    bool exist() {
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                if (match(i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool match(int x, int y) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (nImg[x + i][y + j] != mImg[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

Data newData() {
    Data d;
    cin >> d.n >> d.m;
    d.nImg.resize(d.n);
    d.mImg.resize(d.m);
    load(d.nImg, d.n);
    load(d.mImg, d.m);
    return d;
}

void load(vector<string>& img, int cnt) {
    for (int i = 0; i < cnt; i++) {
        cin >> img[i];
    }
}

int main() {
    Data d = newData();
    if (d.exist()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

// <END-OF-CODE>
