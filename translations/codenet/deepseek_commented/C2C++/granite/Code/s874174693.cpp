
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

// Function to swap two integers
void swap (int *x, int *y) {
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;

  return;
}

// Function to calculate the greatest common divisor (GCD)
long int gcd(long int a, long int b){
  long int c;

  while (b > 0){
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}

// Function to compare long long integers for ascending order in sorting
int upll(const void*a, const void*b){
  return*(long long*)a<*(long long*)b?-1:*(long long*)a>*(long long*)b?1:0;
}

// Function to compare long long integers for descending order in sorting
int downll(const void*a, const void*b){
  return*(long long*)a<*(long long*)b?1:*(long long*)a>*(long long*)b?-1:0;
}

// Function to sort an array of long long integers in ascending order
void sortup(long long*a,int n){
  qsort(a,n,sizeof(long long),upll);
}

// Function to sort an array of long long integers in descending order
void sortdown(long long*a,int n){
  qsort(a,n,sizeof(long long),downll);
}

// Function to calculate (a^n) % mod using modular exponentiation
long long modpow(long long a,long long n,long long mod){
  long long ans=1;
  while(n>0){
    if(n & 1){
      ans=ans*a%mod;
    }
    a=a*a%mod;
    n/=2;
  }
  return ans;
}

// Function to calculate modular multiplicative inverse
long long modinv(long long a,long long mod){
  return modpow(a,mod-2,mod);
}

// Function to find the maximum of two integers
int max(int a,int b){
  if(a<b){
    return b;
  }
  else{
    return a;
  }
}

// Function to find the minimum of two integers
int min(int a,int b){
  if(a<b){
    return a;
  }
  else{
    return b;
  }
}

// Function to update a variable if it is smaller
void chmax(int *a,int b){
  if(*a < b){
    *a = b;
  }

  return;
}

// Function to update a variable if it is larger
void chmin(int *a,int b){
  if(*a > b){
    *a =b;
  }

  return;
}

// Main function
int main(void){
  int n;
  cin >> n;
  int sum=0;
  int m=n;
  for(int i=0;i<9;i++){
    sum+=n%10;
    n/=10;
  }
  if(m%sum==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}

