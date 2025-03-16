

package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

func main() {
 reader := bufio.NewReader(os.Stdin)
 var n int
 var err error
 var a, b []int
 var temp, q, w, e int
 var f bool

 str, _ := reader.ReadString('\n')
 n, err = strconv.Atoi(strings.TrimSpace(str))
 a = make([]int, n)
 b = make([]int, n)

 for i := 0; i < n; i++ {
 str, _ = reader.ReadString('\n')
 str = strings.TrimSpace(str)
 a[i], _ = strconv.Atoi(strings.Split(str, " ")[0])
 b[i], _ = strconv.Atoi(strings.Split(str, " ")[1])

 if temp < a[i] {
 if q > b[i] {
 f = true
 }
 q = b[i]
 temp = a[i]
 }

 if temp > a[i] {
 if q < b[i] {
 f = true
 }
 q = b[i]
 temp = a[i]
 }

 if a[i] > w {
 w = a[i]
 if b[i] < e {
 f = true
 }
 }

 if a[i] < w {
 if b[i] > e {
 f = true
 }
 }
 }

 if f == true {
 fmt.Println("Happy Alex")
 } else {
 fmt.Println("Poor Alex")
 }
}

