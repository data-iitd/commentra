package main
import (
"fmt"
)
func main() {
var n int
var s string
fmt.Scanf("%d\n", &n)
fmt.Scanf("%s\n", &s)
if n%2!= 0 {
fmt.Println("No")
} else if s[:n/2] == s[n/2:] {
fmt.Println("Yes")
} else {
fmt.Println("No")
}
}
