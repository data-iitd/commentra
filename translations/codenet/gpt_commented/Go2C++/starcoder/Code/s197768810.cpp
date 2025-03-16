#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <cctype>
#include <bitset>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <cassert>
#include <typeinfo>
#include <stdexcept>
#include <new>
#include <memory>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include <initializer_list>
#include <climits>
#include <cfloat>
#include <cctype>
#include <bitset>
#include <cassert>
#include <typeinfo>
#include <stdexcept>
#include <new>
#include <memory>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include <initializer_list>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum > n) {
		cout << "-1" << endl;
		return 0;
	}
	cout << n - sum << endl;
	return 0;
}

