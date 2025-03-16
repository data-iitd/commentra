#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    scanf("%d", &n);

    int cnt[26] = {1};
    char s[n];
    scanf("%s", s);

    for(int i = 0; i < n; ++i){
        cnt[s[i] - 'a']++;
    }

    long long ans = cnt[0];
    for(int i = 1; i < 26; ++i){
        ans *= cnt[i];
        ans %= 1000000007;
    }

    printf("%lld\n", ans - 1);
    return 0;
}

