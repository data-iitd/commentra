#include <stdio.h>
#include <string.h>

int mul(char *str, int *idx){
    int res = str[*idx]-'0';
    while(str[*idx+1]=='*'){
        (*idx)++;
        res *= str[*idx]-'0';
    }
    return res;
}

int add(char *str, int *idx){
    int res = mul(str, idx);
    while(str[*idx+1] == '+'){
        (*idx)++;
        res += mul(str, idx);
    }
    return res;
}

int bob(char *str, int *idx){
    int res = str[*idx]-'0';
    while(str[*idx+1] == '+' || str[*idx+1] == '*'){
        if(str[*idx+1] == '+')
            res += str[*idx+2]-'0';
        else
            res *= str[*idx+2]-'0';
        (*idx)++;
    }
    return res;
}

int main(){
    char s[1000];
    int d;
    while(scanf("%s %d", s, &d)!= EOF){
        int idx = 0;
        int a = add(s, &idx);
        idx = 0;
        int b = bob(s, &idx);
        if(a == d){
            printf("%c\n", b == d? 'U' : 'M');
        } else {
            printf("%c\n", b == d? 'L' : 'I');
        }
    }
}

