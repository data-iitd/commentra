package main
import (
"fmt"
"strings"
)
func main() {
s := strings.Split(strings.TrimSpace(input()), "")
even := make(map[string]int)
odd := make(map[string]int)
for _, v := range s[0:len(s):2] {
even[v]++
}
for _, v := range s[1:len(s):2] {
odd[v]++
}
fmt.Println(min(len(s)-even["0"]-odd["1"], len(s)-even["1"]-odd["0"]))
}
func min(a, b int) int {
if a < b {
return a
}
return b
}
