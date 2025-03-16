#include<stdio.h>
#include<stdlib.h>
#include<math.h>

type int64 int64

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

func digit(n int64) int {
  res := 0
  for n > 0 {
    res++
    n /= 10
  }
  return res
}

func run() {
  var n int64
  fmt.Scanf("%d", &n)
  min := digit(n)
  for i := 1; int64(i)*int64(i) <= n; i++ {
    if n%i != 0 {
      continue
    }
    a := i
    b := n / i
    min = MIN(min, MAX(digit(a), digit(b)))
  }
  fmt.Println(min)
}

func main() {
  run()
}

