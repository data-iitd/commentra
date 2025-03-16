
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We declare and initialize some variables and arrays here.
int kekka[2];
int prime_or_not[1001];
int prime_list[1001];
int prime_counter = 0;


// This function calculates prime numbers up to 1000 and stores them in prime_list[].
void sosuubunnpu(){
    // Initialize prime_or_not[] to all zeros.
    for (int i = 1; i <= 1000; ++i)
    {
        prime_or_not[i] = 0;
    }
    // Mark non-prime numbers as 1 in prime_or_not[].
    for (int i = 2; i <= 1000; ++i)
    {
        for (int j = 2; j <= 1000/i; ++j)
        {
            if(prime_or_not[i]==0){
                prime_or_not[i*j] = 1;
            }
        }
    }
    // Store prime numbers in prime_list[].
    for (int i = 2; i <= 1000; ++i)
    {
        if(prime_or_not[i]==0){
            prime_list[prime_counter] = i;
            prime_counter+=1;
        }
    }
}


// This function calculates the exponent of a prime number in a given number.
void innsuubunnkai(int N,int n){
    // Initialize time to 0.
    int time = 0;
    // Calculate the exponent of prime number n in N.
    while(1){
        if(N%n == 0){
            N = N/n;
            time++;
        }else{
            break;
        }
    }
    // Store the result in kekka[].
    kekka[0] = time;
    kekka[1] = N;
}


// This is the main function where we call sosuubunnpu() and perform the main calculation.
int main()
{
    // Call sosuubunnpu() to calculate prime numbers.
    sosuubunnpu();
    // Read the input N from the standard input.
    int N;
    scanf("%d",&N);
    // Initialize innsuu[] and A[] here.
    int innsuu[11];
    int A[N+1][11];
    // Initialize prime_num[] to zeros.
    for (int i = 0; i <= 1000; ++i)
    {
        prime_num[i] = 0;
    }
    // Calculate prime_num[] using innsuubunnkai().
    for (int current_num = 2; current_num <= N; ++current_num)
    {
        kekka[1] = current_num;
        for (int i = 0; i < prime_counter; ++i)
        {
            innsuubunnkai(kekka[1],prime_list[i]);
            prime_num[i]+=kekka[0];
        }
    }
    // Calculate the final result.
    unsigned long long result = 1;
    for (int current_num = 2; current_num <= N; ++current_num){
        for (int i = 0; i < 11; ++i){
            innsuu[i] += A[current_num][i];
        }
    }
    for (int i = 0; i < prime_counter; ++i){
        result = (result*(prime_num[i]+1))%1000000007;
    }
    // Output the final result.
    printf("%llu\n",result);
    
    return 0;
}

