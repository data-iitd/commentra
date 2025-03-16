
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long x;
    vector<long> srimeList;
    vector<vector<long>> costList;
    vector<long> result;

    cin >> N >> x;

    for (int i = 0; i < N; i++) {
        long temp;
        cin >> temp;
        srimeList.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        vector<long> temp;
        for (int j = 0; j < N; j++) {
            long temp2;
            cin >> temp2;
            temp.push_back(temp2);
        }
        costList.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        long temp = i * x;
        for (int j = 0; j < N; j++) {
            temp += costList[i][j];
        }
        result.push_back(temp);
    }

    cout << *min_element(result.begin(), result.end()) << endl;

    return 0;
}

