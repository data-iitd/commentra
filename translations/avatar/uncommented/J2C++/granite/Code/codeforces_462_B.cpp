
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <cctype>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;

const static int tx[] = {0, 1, 0, -1};
const static int ty[] = {-1, 0, 1, 0};

const static double EPS = 1e-8;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> cards(26, 0);
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        cards[s[i] - 'A']++;
    }
    ll ans = 0;
    for(int i = 0; i < k; i++){
        sort(cards.begin(), cards.end());
        int change = min(cards[25], k - i);
        ans += change * change;
        cards[25] -= change;
        i += change - 1;
    }
    cout << ans << endl;
    return 0;
}
//END-OF-CODE