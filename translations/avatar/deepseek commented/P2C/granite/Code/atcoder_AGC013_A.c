
#include <stdio.h>  // Including necessary header files
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <complex>
#include <numeric>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <complex>
#include <numeric>
#include <functional>
#include <iterator>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans++;
        }
    }

    cout << ans + 1 << endl;

    return 0;
}

