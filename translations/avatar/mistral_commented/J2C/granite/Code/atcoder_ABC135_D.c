

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 100000007

int main() {
 char s[100001];
 scanf("%s", s);
 int n = strlen(s);
 long dp[n][13];
 memset(dp, 0, sizeof(dp));
 int base = 1;
 for (int i = n - 1; i >= 0; --i) {
 if (s[i] == '?') {
 for (int pre = 0; pre < 13; ++pre) {
 for (int next = 0; next < 10; ++next) {
 dp[i][(base * next + pre) % 13] += (i < n - 1? dp[i + 1][pre] : (pre == 0? 1 : 0));
 dp[i][(base * next + pre) % 13] %= MOD;
 }
 }
 } else {
 int next = s[i] - '0';
 for (int pre = 0; pre < 13; ++pre) {
 dp[i][(base * next + pre) % 13] += (i < n - 1? dp[i + 1][pre] : (pre == 0? 1 : 0));
 dp[i][(base * next + pre) % 13] %= MOD;
 }
 }
 base = base * 10 % 13;
 }
 printf("%ld\n", dp[0][5]);
 return 0;
}

