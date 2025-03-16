#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

void swap (int &x, int &y) {
  int temp;

  temp = x;
  x = y;
  y = temp;

  return;
}

long int gcd(long int a, long int b){
  long int c;

  while (b > 0){
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}

bool upll(const void*a, const void*b){
  return *(ll*)a < *(ll*)b ? -1 : *(ll*)a > *(ll*)b ? 1 : 0;
}

bool downll(const void*a, const void*b){
  return *(ll*)a < *(ll*)b ? 1 : *(ll*)a > *(ll*)b ? -1 : 0;
}

void sortup(ll*a,int n){
  qsort(a,n,sizeof(ll),upll);
}

void sortdown(ll*a,int n){
  qsort(a,n,sizeof(ll),downll);
}

long int modpow(long int a, long int n, long int mod){
  long int ans = 1;
  while(n > 0){
    if(n & 1){
      ans = ans * a % mod;
    }
    a = a * a % mod;
    n /= 2;
  }
  return ans;
}

long int modinv(long int a, long int mod){
  return modpow(a, mod - 2, mod);
}

int max(int a, int b){
  return a < b ? b : a;
}

int min(int a, int b){
  return a < b ? a : b;
}

void chmax(int &a, int b){
  if(a < b){
    a = b;
  }

  return;
}

void chmin(int &a, int b){
  if(a > b){
    a = b;
  }

  return;
}

int main(void){
  int n;
  cin >> n;
  int sum = 0;
  int m = n;
  for(int i = 0; i < 9; i++){
    sum += n % 10;
    n /= 10;
  }
  if(m % sum == 0){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

