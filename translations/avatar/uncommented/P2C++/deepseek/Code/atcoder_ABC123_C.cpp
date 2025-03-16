#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <memory>
#include <functional>
#include <bitset>
#include <stack>
#include <ctime>
#include <list>
#include <tuple>
#include <cassert>
#include <deque>
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(5);
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
    }
    int minA = *min_element(A.begin(), A.end());
    int result = (N + minA - 1) / minA + 4;
    cout << result << endl;
    return 0;
}
