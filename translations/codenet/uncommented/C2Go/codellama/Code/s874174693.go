#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ll long long

func swap(x, y *int) {
  temp := *x
  *x = *y
  *y = temp

  return
}


func gcd(a, b ll) ll {
  var c ll

  for b > 0 {
    c = a % b
    a = b
    b = c
  }

  return a
}

func upll(a, b unsafe.Pointer) int {
  return *(*ll)(a) < *(*ll)(b)
}

func downll(a, b unsafe.Pointer) int {
  return *(*ll)(a) < *(*ll)(b)
}

func sortup(a []ll, n int) {
  qsort(a, n, sizeof(ll), upll)
}

func sortdown(a []ll, n int) {
  qsort(a, n, sizeof(ll), downll)
}

func modpow(a, n, mod ll) ll {
  var ans ll = 1
  for n > 0 {
    if n & 1 {
      ans = ans*a%mod
    }
    a = a*a%mod
    n /= 2
  }
  return ans
}

func modinv(a, mod ll) ll {
  return modpow(a, mod-2, mod)
}

func max(a, b int) int {
  if a < b {
    return b
  }
  return a
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}

func chmax(a *int, b int) {
  if *a < b {
    *a = b
  }

  return
}

func chmin(a *int, b int) {
  if *a > b {
    *a = b
  }

  return
}


func main() {
  var n int
  fmt.Scan(&n)
  var sum int = 0
  var m = n
  for i := 0; i < 9; i++ {
    sum += n % 10
    n /= 10
  }
  if m%sum == 0 {
    fmt.Println("Yes")
  } else {
    fmt.Println("No")
  }
  return
}

