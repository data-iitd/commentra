#include <iostream>

int main() {
  long long  n,a,m,M,c,b,i;
  c = 0;
  m = 100000000;
  M =-100000000;
  std::cin >> n;

  for(i=1; i<=n; i++){
    std::cin >> a;
    if(a>M) {
      M = a;
    } 
    if(a < m){
      m = a;
    }
    c = c+a;
  }
    std::cout << m << " " << M << " " << c << std::endl;

  return 0;
}

