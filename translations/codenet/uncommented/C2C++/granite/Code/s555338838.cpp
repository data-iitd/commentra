
#include <iostream>

int main(){
  int key, i, j, len, a[101];
  std::cin >> len;
  for(i = 0;i < len;i++) std::cin >> a[i];

  for(j = 1;j < len;j++){
    for(i = 0;i < len;i++) std::cout << (i!= 0? " " : "") << a[i];
    std::cout << std::endl;
    key = a[j];
    for(i = j - 1;i >= 0 && a[i] > key;i--) a[i + 1] = a[i];
    a[i + 1] = key;
  }

  for(i = 0;i < len;i++) std::cout << (i!= 0? " " : "") << a[i];
  std::cout << std::endl;
  return 0;
}
