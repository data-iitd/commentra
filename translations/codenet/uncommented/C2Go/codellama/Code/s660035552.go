#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

var low [200000]int
var high [200000]int
var a [200000]int

func part(a []int, b []int, l, r int) int {
  var i, j, x, t int

  i = l - 1
  j = r

  x = b[r]

  for {
    for i++; b[i] < x {
    }
    for i < j && x < b[j] {
      j--
    }

    if i >= j {
      break
    }

    t = a[i]
    a[i] = a[j]
    a[j] = t

    t = b[i]
    b[i] = b[j]
    b[j] = t
  }

  t = a[i]
  a[i] = a[r]
  a[r] = t

  t = b[i]
  b[i] = b[r]
  b[r] = t

  return i
}

func quicksort(a []int, b []int, n int) {
  var l, r, v int
  var sp int

  low[0] = 0
  high[0] = n - 1
  sp = 1

  for sp > 0 {
    sp--
    l = low[sp]
    r = high[sp]

    if l >= r {
    } else {
      v = part(a, b, l, r)

      if v-l < r-v {
        low[sp] = v + 1
        high[sp++] = r
        low[sp] = l
        high[sp++] = v - 1
      } else {
        low[sp] = l
        high[sp++] = v - 1
        low[sp] = v + 1
        high[sp++] = r
      }
    }
  }
}

func main() {
  var n, m int
  var i int
  var a [100006]int
  var b [100006]int
  var cnt int
  var t int

  fmt.Scanf("%d %d", &n, &m)

  for i = 0; i < m; i++ {
    fmt.Scanf("%d %d", &a[i], &b[i])
  }

  quicksort(a, b, m)

  t = 0
  for i = 0; i < m; i++ {
    if t <= a[i] {
      t = b[i]
      cnt++
    }
  }

  fmt.Printf("%d\n", cnt)
}

