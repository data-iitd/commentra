#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <bitset>
#include <cfloat>
#include <ciso646>
#include <fstream>
#include <functional>
#include <numeric>
#include <iterator>
#include <list>
#include <new>
#include <memory>
#include <thread>
#include <typeinfo>
#include <utility>
#include <limits>
#include <type_traits>
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a*b % 2!= 0) {
		cout << "Odd" << endl;
	} else {
		cout << "Even" << endl;
	}
	return 0;
}

