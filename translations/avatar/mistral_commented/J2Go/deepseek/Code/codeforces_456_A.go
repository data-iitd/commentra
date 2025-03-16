package main

import (
 "bufio"
 "fmt"
 "os"
)

func main() {
 scanner := bufio.NewScanner(os.Stdin)
 scanner.Scan()
 n := 0
 fmt.Sscanf(scanner.Text(), "%d", &n)
 
 a := make([]int, n)
 b := make([]int, n)
 
 for i := 0; i < n; i++ {
 scanner.Scan()
 fmt.Sscanf(scanner.Text(), "%d %d", &a[i], &b[i])
 }
 
 happy := false
 
 for i := 0; i < n; i++ {
 for j := 0; j < n; j++ {
 if a[i] < a[j] && b[i] > b[j] {
 happy = true
 break
 }
 }
 if happy {
 break
 }
 }
 
 if happy {
 fmt.Println("Happy Alex")
 } else {
 fmt.Println("Poor Alex")
 }
}

