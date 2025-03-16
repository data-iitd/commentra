
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Scanner {
private:
    string buf;
    int p;
    istringstream iss;

public:
    Scanner() {
        getline(cin, buf);
        p = 0;
    }

    string next() {
        iss.clear();
        iss.str(buf.substr(p));
        string result;
        iss >> result;
        p += result.length() + 1;
        return result;
    }

    string nextLine() {
        iss.clear();
        iss.str(buf.substr(p));
        string result;
        getline(iss, result);
        p = buf.length();
        return result;
    }

    int nextInt() {
        int result;
        iss.clear();
        iss.str(buf.substr(p));
        iss >> result;
        p += to_string(result).length() + 1;
        return result;
    }

    vector<int> nextIntArray() {
        vector<int> result;
        string s = next();
        stringstream ss(s);
        int v;
        while (ss >> v) {
            result.push_back(v);
            if (ss.peek() =='') {
                ss.ignore();
            }
        }
        return result;
    }

    map<int, bool> nextMap() {
        map<int, bool> result;
        string s = next();
        stringstream ss(s);
        int v;
        while (ss >> v) {
            result[v] = true;
            if (ss.peek() =='') {
                ss.ignore();
            }
        }
        return result;
    }
};

int main() {
    Scanner sc;
    int n = sc.nextInt();
    vector<float> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = sc.nextInt();
    }
    sort(arr.begin(), arr.end());
    float prev = arr[0];
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }
    cout << prev << endl;
    return 0;
}

