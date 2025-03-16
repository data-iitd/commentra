
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long min = 100000000000000000;
    for (int i = 0; i < 5; i++) {
        long long a;
        cin >> a;
        min = min < a? min : a;
    }
    cout << (long long)ceil((double)N / min) + 4 << endl;
    return 0;
}
// END-OF-CODE