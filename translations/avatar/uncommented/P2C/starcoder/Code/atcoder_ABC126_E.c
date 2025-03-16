#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define sz(v) (int)(v).size()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvii vector<vector<pii>>
#define vvll vector<vector<pll>>
#define vvvii vector<vector<vector<pii>>>
#define vvvll vector<vector<vector<pll>>>
#define vvvvi vector<vector<vector<vector<int>>>>
#define vvvvl vector<vector<vector<vector<ll>>>>
#define vvvvii vector<vector<vector<vector<pii>>>>
#define vvvvll vector<vector<vector<vector<pll>>>>
#define vvvvvii vector<vector<vector<vector<vector<pii>>>>>
#define vvvvvll vector<vector<vector<vector<vector<pll>>>>>
#define vvvvvvi vector<vector<vector<vector<vector<vector<int>>>>>>
#define vvvvvvl vector<vector<vector<vector<vector<vector<ll>>>>>>
#define vvvvvvii vector<vector<vector<vector<vector<vector<vector<pii>>>>>>>
#define vvvvvvll vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>
#define vvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<pii>>>>>>>>>
#define vvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>
#define vvvvvvvvi vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>
#define vvvvvvvvl vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>
#define vvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>>>>>>>>
#define vvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>
#define vvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>>>>>>>>>
#define vvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>>
#define vvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>>>>>>>>
#define vvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>>
#define vvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>>>>>>>
#define vvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>>
#define vvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>>>>>>
#define vvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>>>
#define vvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>>>>
#define vvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>>>
#define vvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>>
#define vvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>>
#define vvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pll>
#define vvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvll vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvii vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvll 