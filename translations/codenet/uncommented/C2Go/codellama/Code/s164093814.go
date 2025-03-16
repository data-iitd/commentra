#include<stdio.h>
#include<string.h>

#define M 1046527/* your task*/
#define L 14

var H [M][L]string /* Hash Table */

func getChar(ch byte) int {
  if ch == 'A' {
    return 1
  } else if ch == 'C' {
    return 2
  } else if ch == 'G' {
    return 3
  } else if ch == 'T' {
    return 4
  }
  return 0
}

/* convert a string into an integer value */
func getKey(str string) int {
  var sum int = 0
  var p int = 1
  for i := 0; i < len(str); i++ {
    sum += p * getChar(str[i])
    p *= 5
  }
  return sum
}

func h1(key int) int {
  return key % M
}
func h2(key int) int {
  return 1 + (key % (M - 1))
}

func find(str string) bool {
  var i int = 0
  var hash int
  var key int = getKey(str)
  for {
    hash = (h1(key) + i*h2(key))%M
    if H[hash] == str {
      return true
    } else if len(H[hash]) == 0 {
      return false
    }
    i++
  }
  return false
}

func insert(str string) bool {
  var i int = 0
  var hash int
  var key int = getKey(str)
  for {
    hash = (h1(key) + i*h2(key))%M
    if H[hash] == str {
      return true
    } else if len(H[hash]) == 0 {
      H[hash] = str
      return false
    }
    i++
  }
  return false
  /* your task */

}

func main() {
  var i int = 0
  var n int
  var str string
  var com string
  for i = 0; i < M; i++ {
    H[i] = ""
  }

  fmt.Scanf("%d", &n)

  for i = 0; i < n; i++ {
    fmt.Scanf("%s %s", &com, &str)

    if com[0] == 'i' {
      insert(str)
    } else {
      if find(str) {
        fmt.Println("yes")
      } else {
        fmt.Println("no")
      }
    }
  }

  return
}

