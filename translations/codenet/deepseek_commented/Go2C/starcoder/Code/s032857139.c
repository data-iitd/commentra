
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>
#include <float.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>
#include <float.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define MAX(a, b) ((a) > (b)? (a) : (b))
#define MIN(a, b) ((a) < (b)? (a) : (b))
#define ABS(a) ((a) < 0? -(a) : (a))
#define SGN(a) ((a) < 0? -1 : (a) > 0)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define FOREACH(i, c) for (typeof((c).begin()) i = (c).begin(); i!= (c).end(); i++)
#define REVERSE(i, c) for (typeof((c).rbegin()) i = (c).rbegin(); i!= (c).rend(); i++)
#define SORT(c) sort((c).begin(), (c).end())
#define UNIQUE(c) SORT(c); (c).erase(unique((c).begin(), (c).end()), (c).end())
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define INF ((int)1e9)
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define MAX_N 1000000
#define MAX_M 1000000
#define MAX_K 1000000
#define MAX_L 1000000
#define MAX_Q 1000000
#define MAX_W 1000000
#define MAX_H 1000000
#define MAX_D 1000000
#define MAX_R 1000000
#define MAX_C 1000000
#define MAX_V 1000000
#define MAX_T 1000000
#define MAX_O 1000000
#define MAX_I 1000000
#define MAX_F 1000000
#define MAX_S 1000000
#define MAX_U 1000000
#define MAX_X 1000000
#define MAX_Y 1000000
#define MAX_Z 1000000
#define MAX_AA 1000000
#define MAX_BB 1000000
#define MAX_CC 1000000
#define MAX_DD 1000000
#define MAX_EE 1000000
#define MAX_FF 1000000
#define MAX_GG 1000000
#define MAX_HH 1000000
#define MAX_II 1000000
#define MAX_JJ 1000000
#define MAX_KK 1000000
#define MAX_LL 1000000
#define MAX_MM 1000000
#define MAX_NN 1000000
#define MAX_OO 1000000
#define MAX_PP 1000000
#define MAX_QQ 1000000
#define MAX_RR 1000000
#define MAX_SS 1000000
#define MAX_TT 1000000
#define MAX_UU 1000000
#define MAX_VV 1000000
#define MAX_WW 1000000
#define MAX_XX 1000000
#define MAX_YY 1000000
#define MAX_ZZ 1000000
#define MAX_AAA 1000000
#define MAX_BBB 1000000
#define MAX_CCC 1000000
#define MAX_DDD 1000000
#define MAX_EEE 1000000
#define MAX_FFF 1000000
#define MAX_GGG 1000000
#define MAX_HHH 1000000
#define MAX_III 1000000
#define MAX_JJJ 1000000
#define MAX_KKK 1000000
#define MAX_LLL 1000000
#define MAX_MMM 1000000
#define MAX_NNN 1000000
#define MAX_OOO 1000000
#define MAX_PPP 1000000
#define MAX_QQQ 1000000
#define MAX_RRR 1000000
#define MAX_SSS 1000000
#define MAX_TTT 1000000
#define MAX_UUU 1000000
#define MAX_VVV 1000000
#define MAX_WWW 1000000
#define MAX_XXX 1000000
#define MAX_YYY 1000000
#define MAX_ZZZ 1000000
#define MAX_AAAA 1000000
#define MAX_BBBB 1000000
#define MAX_CCCC 1000000
#define MAX_DDDD 1000000
#define MAX_EEEE 1000000
#define MAX_FFFF 1000000
#define MAX_GGGG 1000000
#define MAX_HHHH 1000000
#define MAX_IIII 1000000
#define MAX_JJJJ 1000000
#define MAX_KKKK 1000000
#define MAX_LLLL 1000000
#define MAX_MMMM 1000000
#define MAX_NNNN 1000000
#define MAX_OOOO 1000000
#define MAX_PPPP 1000000
#define MAX_QQQQ 1000000
#define MAX_RRRR 1000000
#define MAX_SSSS 1000000
#define MAX_TTTT 1000000
#define MAX_UUUU 1000000
#define MAX_VVVV 1000000
#define MAX_WWWW 1000000
#define MAX_XXXX 1000000
#define MAX_YYYY 1000000
#define MAX_ZZZZ 1000000
#define MAX_AAAAA 1000000
#define MAX_BBBBB 1000000
#define MAX_CCCCC 1000000
#define MAX_DDDDD 1000000
#define MAX_EEEEE 1000000
#define MAX_FFFFF 1000000
#define MAX_GGGGG 1000000
#define MAX_HHHHH 1000000
#define MAX_IIIII 1000000
#define MAX_JJJJJ 1000000
#define MAX_KKKKK 1000000
#define MAX_LLLLL 1000000
#define MAX_MMMMM 1000000
#define MAX_NNNNN 1000000
#define MAX_OOOOO 1000000
#define MAX_PPPPP 1000000
#define MAX_QQQQQ 1000000
#define MAX_RRRRR 1000000
#define MAX_SSSSS 1000000
#define MAX_TTTTT 1000000
#define MAX_UUUUU 1000000
#define MAX_VVVVV 1000000
#define MAX_WWWWW 1000000
#define MAX_XXXXX 1000000
#define MAX_YYYYY 1000000
#define MAX_ZZZZZ 1000000
#define MAX_AAAAAB 1000000
#define MAX_BBBBB 1000000
#define MAX_CCCCCC 1000000
#define MAX_DDDDDD 1000000
#define MAX_EEEEE 1000000
#define MAX_FFFFF 1000000
#define MAX_GGGGG 1000000
#define MAX_HHHHH 1000000
#define MAX_IIIII 1000000
#define MAX_JJJJJ 1000000
#define MAX_KKKKK 1000000
#define MAX_LLLLL 1000000
#define MAX_MMMMM 1000000
#define MAX_NNNNN 1000000
#define MAX_OOOOO 1000000
#define MAX_PPPPP 1000000
#define MAX_QQQQQ 1000000
#define MAX_RRRRR 1000000
#define MAX_SSSSS 1000000
#define MAX_TTTTT 1000000
#define MAX_UUUUU 1000000
#define MAX_VVVVV 1000000
#define MAX_WWWWW 1000000
#define MAX_XXXXX 1000000
#define MAX_YYYYY 1000000
#define MAX_ZZZZZ 1000000
#define MAX_AAAAAB 1000000
#define MAX_BBBBB 1000000
#define MAX_CCCCCC 1000000
#define MAX_DDDDDD 1000000
#define MAX_EEEEE 1000000
#define MAX_FFFFF 1000000
#define MAX_GGGGG 1000000
#define MAX_HHHHH 1000000
#define MAX_IIIII 1000000
#define MAX_JJJJJ 1000000
#define MAX_KKKKK 1000000
#define MAX_LLLLL 1000000
#define MAX_MMMMM 1000000
#define MAX_NNNNN 1000000
#define MAX_OOOOO 1000000
#define MAX_PPPPP 1000000
#define MAX_QQQQQ 1000000
#define MAX_RRRRR 1000000
#define MAX_SSSSS 1000000
#define MAX_TTTTT 1000000
#define MAX_UUUUU 1000000
#define MAX_VVVVV 1000000
#define MAX_WWWWW 1000000
#define MAX_XXXXX 1000000
#define MAX_YYYYY 1000000
#define MAX_ZZZZZ 1000000
#define MAX_AAAAAB 1000000
#define MAX_BBBBB 1000000
#define MAX_CCCCCC 1000000
#define MAX_DDDDDD 1000000
#define MAX_EEEEE 1000000
#define MAX_FFFFF 1000000
#define MAX_GGGGG 1000000
#define MAX_HHHHH 1000000
#define MAX_IIIII 1000000
#define MAX_JJJJJ 1000000
#define MAX_KKKKK 1000000
#define MAX_LLLLL 1000000
#define MAX_MMMMM 1000000
#define MAX_NNNNN 1000000
#define MAX_OOOOO 1000000
#define MAX_PPPPP 1000000
#define MAX_QQQQQ 1000000
#define MAX_RRRRR 1000000
#define MAX_SSSSS 1000000
#define MAX_TTTTT 1000000
#define MAX_UUUUU 1000000
#define MAX_VVVVV 1000000
#define MAX_WWWWW 1000000
#define MAX_XXXXX 1000000
#define MAX_YYYYY 1000000
#define MAX_ZZZZZ 1000000
#define MAX_AAAAAB 1000000
#define MAX_BBBBB 1000000
#define MAX_CCCCCC 1000000
#define MAX_DDDDDD 1000000
#define MAX_EEEEE 1000000
#define MAX_FFFFF 1000000
#define MAX_GGGGG 1000000
#define MAX_HHHHH 1000000
#define MAX_IIIII 1000000
#define MAX_JJJJJ 1000000
#define MAX_KKKKK 1000000
#define MAX_LLLLL 1000000
#define MAX_MMMMM 1000000
#define MAX_NNNNN 1000000
#define MAX_OOOOO 1000000
#define MAX_PPPPP 1000000
#define MAX_QQQQQ 1000000
#define MAX_RRRRR 1000000
#define MAX_SSSSS 1000000
#define MAX_TTTTT 1000000
#define MAX_UUUUU 1000000
#define MAX_VVVVV 1000000
#define MAX_WWWWW 1000000
#define MAX_XXXXX 1000000
#define MAX_YYYYY 1000000
#define MAX_ZZZZZ 1000000
#define MAX_AAAAAB 1000000
#define MAX_BBBBB 1000000
#define MAX_CCCCCC 1000000
#define MAX_DDDDDD 1000000
#define MAX_EEEEE 1000000
#define MAX_FFFFF 1000000
#define MAX_GGGGG 1000000
#define MAX_HHHHH 1000000
#define MAX_IIIII 1000000
#define MAX_JJJJJ 1000000
#define MAX_KKKKK 1000000
#define MAX_LLLLL 1000000
#define MAX_MMMMM 1000000
#define MAX_NNNNN 1000000
#define MAX_OOOOO 1000000
#define MAX_PPPPP 1000000
#define MAX_QQQQQ 1000000
#define MAX_RRRRR 1000000
#define MAX_SSSSS 1000000
#define MAX_TTTTT 1000000
#define MAX_UUUUU 1000000
#define MAX_VVVVV 1000000
#define MAX_WWWWW 1000000
#define MAX_XXXXX 1000000
#define MAX_YYYYY 1000000
#define MAX_ZZZZZ 1000000
#define MAX_AAAAAB 1000000
#define MAX_BBBBB 1000000
#define MAX_CCCCCC 1000000
#define MAX_DDDDDD 1000000
#define MAX_EEEEE 1000000
#define MAX_FFFFF 1000000
#define MAX_GGGGG 1000000
#define MAX_HHHHH 1000000
#define MAX_IIIII 1000000
#define MAX_JJJJJ 1000000
#define MAX_KKKKK 1000000
#define MAX_LLLLL 1000000
#define MAX_MMMMM 1000000
#define MAX_NNNNN 1000000
#define MAX_OOOOO 1000000
#define MAX_PPPPP 1000000
#define MAX_QQQQQ 1000000
#define MAX_RRRRR 1000000
#define MAX_SSSSS 1000000
#define MAX_TTTTT 1000000
#define MAX_UUUUU 1000000
#define MAX_VVVVV 1000000
#define MAX_WWWWW 1000000
#define MAX_XXXXX 1000000
#define MAX_YYYYY 1000000
#define MAX_ZZZZZ 1000000
#define MAX_AAAAAB 1000000
#