#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ll long long

def swap(x, y):
  temp = x
  x = y
  y = temp

  return


def gcd(a, b):
  c = 0

  while b > 0:
    c = a % b
    a = b
    b = c

  return a


def upll(a, b):
  return (ll)a < (ll)b and -1 or (ll)a > (ll)b and 1 or 0


def downll(a, b):
  return (ll)a < (ll)b and 1 or (ll)a > (ll)b and -1 or 0


def sortup(a, n):
  a.sort(key=upll)


def sortdown(a, n):
  a.sort(key=downll)


def modpow(a, n, mod):
  ans = 1
  while n > 0:
    if n & 1:
      ans = ans * a % mod
    a = a * a % mod
    n //= 2
  return ans


def modinv(a, mod):
  return modpow(a, mod - 2, mod)


def max(a, b):
  if a < b:
    return b
  else:
    return a


def min(a, b):
  if a < b:
    return a
  else:
    return b


def chmax(a, b):
  if a < b:
    a = b

  return


def chmin(a, b):
  if a > b:
    a = b

  return


def main():
  n = 0
  scanf("%d", &n)
  sum = 0
  m = n
  for i in range(9):
    sum += n % 10
    n //= 10
  if m % sum == 0:
    printf("Yes\n")
  else:
    printf("No\n")
  return 0


if __name__ == "__main__":
  main()

