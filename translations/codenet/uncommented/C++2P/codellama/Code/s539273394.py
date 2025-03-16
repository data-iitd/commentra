#include <iostream>
#include <string>
using namespace std;
int kekka[2];
int prime_or_not[1001];
int prime_list[1001];
int prime_num[1001];
int prime_counter = 0;
void sosuubunnpu(){
    for (int i = 1; i <= 1000; ++i)
    {
        prime_or_not[i] = 0;
    }
    for (int i = 2; i <= 1000; ++i)
    {
        for (int j = 2; j <= 1000/i; ++j)
        {
            if(prime_or_not[i]==0){
                prime_or_not[i*j] = 1;
            }
        }
    }
    for (int i = 2; i <= 1000; ++i)
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

def main():
    sosuubunnpu()
    N = int(input())
    innsuu = [0]*11
    A = [[0]*11 for i in range(N+1)]
    for i in range(0,1000):
        prime_num[i] = 0
    result = 1
    for current_num in range(2,N+1):
        kekka[1] = current_num
        for i in range(0,prime_counter):
            innsuubunnkai(kekka[1],prime_list[i])
            prime_num[i]+=kekka[0]
    for current_num in range(2,N+1):
        for i in range(0,11):
            innsuu[i] += A[current_num][i]
    for i in range(0,prime_counter):
        result = (result*(prime_num[i]+1))%1000000007
    print(result)

