
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cassert>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string v_temp_temp;
    getline(cin, v_temp_temp);

    vector<string> v_temp = split_string(v_temp_temp);

    vector<int> v(n);

    for (int v_itr = 0; v_itr < n; v_itr++) {
        int v_item = stoi(v_temp[v_itr]);

        v[v_itr] = v_item;
    }

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int c_itr = 0; c_itr < n; c_itr++) {
        int c_item = stoi(c_temp[c_itr]);

        c[c_itr] = c_item;
    }

    int max = 0;

    for (int i = 0; i < n; i++) {
        int profit = v[i] - c[i];
        if (profit > 0) {
            max += profit;
        }
    }

    cout << max << endl;

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x =='';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] =='') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter ='';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos!= string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

