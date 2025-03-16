
#include <stdio.h>
#include <string.h>

// Array to store the result of prime factorization
int kekka[2];

// Array to determine if a number is prime or not (0 for prime, 1 for not prime)
int prime_or_not[1001];

// Array to store prime numbers
int prime_list[1001];

// Array to store the power of each prime factor
int prime_num[1001];

// Counter to keep track of the number of prime numbers found
int prime_counter = 0;

// Function to find all prime numbers up to 1000
void sosuubunnpu(){
    // Initialize the prime_or_not array to 0 (indicating all numbers are potential primes)
    for (int i = 1; i <= 1000; ++i)
    {
        prime_or_not[i] = 0;
    }

    // Mark non-prime numbers using the Sieve of Eratosthenes algorithm
    for (int i = 2; i <= 1000; ++i)
    {
        for (int j = 2; j <= 1000/i; ++j)
        {
            if(prime_or_not[i]==0){
                prime_or_not[i*j] = 1;
            }
        }
    }

    // Collect all prime numbers into the prime_list array
    for (int i = 2; i <= 1000; ++i)
    {
        if(prime_or_not[i]==0){
            prime_list[prime_counter] = i;
            prime_counter+=1;
        }
    }
}

// Function to find the power of a prime factor in the factorization of a number
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
    // Call the function to find all prime numbers up to 1000
    sosuubunnpu();

    // Read the integer N
    int N;
    scanf("%d",&N);

    // Initialize arrays to store the prime factorization of numbers up to N
    int innsuu[11];
    int A[N+1][11];
    for (int i = 0; i <= 1000; ++i)
    {
        prime_num[i] = 0;
    }

    // Calculate the prime factorization of each number up to N
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

    // Sum the powers of each prime factor for all numbers up to N
    for (int current_num = 2; current_num <= N; ++current_num){
        for (int i = 0; i < 11; ++i){
            innsuu[i] += A[current_num][i];
        }
    }

    // Calculate the result using the formula for the number of divisors
    for (int i = 0; i < prime_counter; ++i){
        result = (result*(prime_num[i]+1))%1000000007;
    }

    // Print the final result
    printf("%llu\n",result);
    
    return 0;
}
