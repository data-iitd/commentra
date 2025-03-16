#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    char **ss = new char*[n];
    for (int i = 0; i < n; i++) {
        ss[i] = new char[1000000];
        cin >> ss[i];
    }
    char *cc = new char[1000000];
    cin >> cc;
    int m = strlen(cc);
    char c;
    cin >> c;
    char c_ = toupper(c);
    char a = c == 'a'? 'b' : 'a';
    char a_ = toupper(a);
    bool *lucky = new bool[m];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int l = strlen(ss[i]);
            if (m - j >= l && strcmp(cc + j, ss[i]) == 0) {
                for (int h = 0; h < l; h++) {
                    lucky[j + h] = true;
                }
            }
        }
    }
    for (int j = 0; j < m; j++) {
        if (lucky[j]) {
            if (tolower(cc[j]) == c) {
                cc[j] = isupper(cc[j])? a_ : a;
            } else {
                cc[j] = isupper(cc[j])? c_ : c;
            }
        }
    }
    cout << cc << endl;
    return 0;
}

