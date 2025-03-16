#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

#define int long long

#define pw pw

#define mn mn

#define LIM LIM

#define N N

#define get get

#define init init

#define Sp Sp

#define l l

#define r r

#define val val

#define l_ l_

#define r_ r_

#define val_ val_

#define t t

#define i i

#define j j

#define p p

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define pw pw

#define 