
package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

func main() {
 var n int
 var a []int
 var s map[int]int

 set()
 solve()

 fmt.Println(n)
 fmt.Println(a)
 fmt.Println(s)
}

func set() {
 var br = bufio.NewReader(os.Stdin)
 var line string
 var err error

 line, err = br.ReadString('\n')
 if err != nil {
 fmt.Println(err)
 }
 n, err = strconv.Atoi(line)
 if err != nil {
 fmt.Println(err)
 }

 line, err = br.ReadString('\n')
 if err != nil {
 fmt.Println(err)
 }
 a = strings.Split(line, " ")
 for i := 0; i < len(a); i++ {
 a[i], err = strconv.Atoi(a[i])
 if err != nil {
 fmt.Println(err)
 }
 }

 s = make(map[int]int)
}

func solve() {
 var ng int = 0
 var ok int = n

 for ok-ng > 1 {
 var k int = (ng + ok) / 2
 if isPossible(k) {
 ok = k
 } else {
 ng = k
 }
 }
}

func isPossible(k int) bool {
 s = make(map[int]int)
 var current int = 0

 for _, ai := range a {
 if ai <= current {
 if k == 1 {
 return false
 }

 for s[ai-1] >= k {
 s[ai-1]--
 }

 var p int = ai - 1
 for {
 if p < 0 {
 return false
 }

 s[p]++
 if s[p] == k {
 s[p]--
 p--
 } else {
 break
 }
 }
 }
 current = ai
 }

 return true
}

