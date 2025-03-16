
#include <stdio.h>

int main() {
 long long pandu, vundu, urdu, c = 0;
 scanf("%lld %lld %lld", &pandu, &vundu, &urdu);
 for (int i = 1; i <= urdu; i++) {
 c += i * pandu;
 }
 if (c < vundu) {
 printf("0");
 } else {
 printf("%lld", c - vundu);
 }
 return 0;
}
//END-OF-CODE