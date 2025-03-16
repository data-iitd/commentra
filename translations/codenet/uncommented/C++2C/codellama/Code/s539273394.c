#include <stdio.h>
#include <string.h>
#define MAX 1001
int kekka[2];
int prime_or_not[MAX];
int prime_list[MAX];
int prime_num[MAX];
int prime_counter = 0;
void sosuubunnpu(){
    for (int i = 1; i <= MAX; ++i)
    {
        prime_or_not[i] = 0;
    }
    for (int i = 2; i <= MAX; ++i)
    {
        for (int j = 2; j <= MAX/i; ++j)
        {
            if(prime_or_not[i]==0){
                prime_or_not[i*j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAX; ++i)
    {
        if(prime_or_not[i]==0){
            prime_list[prime_counter] = i;
            prime_counter+=1;
        }
    }
}
void innsuubunnkai(int N,int n){
    int time = 0;
    while(1){
        if(N%n == 0){
            N = N/n;
            time++;
        }else{
            break;
        }
    }
    kekka[0] = time;
    kekka[1] = N;
}

int main()
{
    sosuubunnpu();
    int N;
    scanf("%d",&N);
    int innsuu[11];
    int A[N+1][11];
    for (int i = 0; i <= MAX; ++i)
    {
        prime_num[i] = 0;
    }
    unsigned long long result = 1;
    for (int current_num = 2; current_num <= N; ++current_num)
    {
        kekka[1] = current_num;
        for (int i = 0; i < prime_counter; ++i)
        {
            innsuubunnkai(kekka[1],prime_list[i]);
            prime_num[i]+=kekka[0];
        }
    }
    for (int current_num = 2; current_num <= N; ++current_num){
        for (int i = 0; i < 11; ++i){
            innsuu[i] += A[current_num][i];
        }
    }
    for (int i = 0; i < prime_counter; ++i){
        result = (result*(prime_num[i]+1))%1000000007;
    }
    printf("%llu\n",result);
    
    return 0;
}
