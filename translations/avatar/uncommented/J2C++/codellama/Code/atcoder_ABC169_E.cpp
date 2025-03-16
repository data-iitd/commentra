#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <ctime>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <functional>
#include <iomanip>
#include <cassert>
using namespace std;

int main()
{
    int num = 998244353;
    ifstream bf("input.txt");
    ofstream out("output.txt");
    int n;
    bf >> n;
    vector<int> ai;
    vector<int> bi;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        bf >> a >> b;
        ai.push_back(a);
        bi.push_back(b);
    }
    sort(ai.begin(), ai.end());
    sort(bi.begin(), bi.end());
    if (n % 2 == 1)
    {
        out << bi[bi.size() / 2] - ai[ai.size() / 2] + 1 << endl;
    }
    else
    {
        double b = (ai[ai.size() / 2] + ai[ai.size() / 2 - 1] + 0.0) / 2;
        double c = (bi[bi.size() / 2] + bi[bi.size() / 2 - 1] + 0.0) / 2;
        out << (int)(2 * (c - b) + 1) << endl;
    }
    return 0;
}

