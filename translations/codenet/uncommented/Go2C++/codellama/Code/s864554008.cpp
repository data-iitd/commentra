#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Data {
    int n, m;
    vector<string> nImg, mImg;
};

Data newData() {
    int n, m;
    cin >> n >> m;
    vector<string> nImg(n);
    for (int i = 0; i < n; i++) {
        cin >> nImg[i];
    }
    vector<string> mImg(m);
    for (int i = 0; i < m; i++) {
        cin >> mImg[i];
    }

    return Data{n, m, nImg, mImg};
}

bool exist(Data d) {
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            if (match(d, i, j)) {
                return true;
            }
        }
    }

    return false;
}

bool match(Data d, int x, int y) {
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            if (d.nImg[x+i][y+j] != d.mImg[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    Data d = newData();
    if (exist(d)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

