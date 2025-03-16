
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int value;
  struct Element *next;
} Element;

typedef struct {
  Element *top;
  int size;
} Stack;

Stack *newStack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->top = NULL;
  s->size = 0;
  return s;
}

void push(Stack *s, int value) {
  Element *e = (Element *)malloc(sizeof(Element));
  e->value = value;
  e->next = s->top;
  s->top = e;
  s->size++;
}

int pop(Stack *s) {
  if (s->size > 0) {
    Element *e = s->top;
    int value = e->value;
    s->top = e->next;
    free(e);
    s->size--;
    return value;
  }
  return -1;
}

int len(Stack *s) {
  return s->size;
}

int powerInt(int n, int p) {
  int tmp = 1;
  for (int i = 0; i < n; i++) {
    tmp *= p;
  }
  return tmp;
}

void findDivisors(int n, int *a) {
  if (n == 1) {
    return;
  }

  int sqrt = sqrt(n);
  for (int i = 2; i <= sqrt; i++) {
    if (n % i == 0) {
      a[0]++;
      a[a[0]] = i;
      a[0]++;
      a[a[0]] = n / i;
    }
  }
  a[0]++;
  a[a[0]] = n;
}

int abs(int a) {
  if (a > 0) {
    return a;
  }
  return -a;
}

int gcd(int a, int b) {
  for (; b!= 0; ) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int power2mod(int n, int mod) {
  int res = 1, x = 2;
  for (; n > 0; n >>= 1) {
    if (n & 1) {
      res = (res * x) % mod;
    }
    x = (x * x) % mod;
  }
  return res;
}

int power2(int n) {
  return power2mod(n, 1000000007);
}

int main() {
  // Your C code here
  return 0;
}
// END-OF-CODE