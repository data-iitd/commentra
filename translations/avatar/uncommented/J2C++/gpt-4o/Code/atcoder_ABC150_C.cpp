#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void permutation(vector<string>& list, string target, string ans) {
    if (target.length() <= 1) {
        list.push_back(ans + target);
    } else {
        for (size_t i = 0; i < target.length(); i++) {
            permutation(list, target.substr(0, i) + target.substr(i + 1), ans + target[i]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> line(2, "");
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            string input;
            cin >> input;
            line[i] += input;
        }
    }
    
    string number = "";
    for (int i = 1; i <= n; i++) {
        number += to_string(i);
    }
    
    vector<string> listA;
    permutation(listA, number, "");
    
    int sum = 0;
    for (size_t j = 0; j < line.size(); j++) {
        for (size_t i = 0; i < listA.size(); i++) {
            if (listA[i] == line[j]) {
                if (sum == 0) {
                    sum += i;
                } else {
                    sum -= i;
                }
            }
        }
    }
    
    cout << abs(sum) << endl;
    return 0;
}

// <END-OF-CODE>
