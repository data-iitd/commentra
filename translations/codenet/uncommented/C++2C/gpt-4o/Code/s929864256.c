#include <stdio.h>

<<<<<<< HEAD
typedef long long ll;

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    
    ll sum = a + b;
    ll diff = a - b;
    ll prod = a * b;

    ll max_value = sum > diff ? (sum > prod ? sum : prod) : (diff > prod ? diff : prod);
    
    printf("%lld\n", max_value);
=======
int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    
    long long sum = a + b;
    long long diff = a - b;
    long long prod = a * b;

    long long result = sum > diff ? (sum > prod ? sum : prod) : (diff > prod ? diff : prod);
    
    printf("%lld\n", result);
>>>>>>> 98c87cb78a (data updated)

    return 0;
}

<<<<<<< HEAD
// <END-OF-CODE>
=======
//<END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
