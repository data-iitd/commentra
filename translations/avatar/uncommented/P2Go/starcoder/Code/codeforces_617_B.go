package main
import (
"fmt"
"strings"
)
func main() {
a := strings.TrimSpace(fmt.Scanln())
if strings.Count(a, "1") == 0 {
fmt.Println(0)
} else {
fmt.Println(prod(strings.Split(strings.Trim(a, "0"), "1")))
}
}
func prod(a []string) int {
p := 1
for _, v := range a {
p *= len(v) + 1
}
return p
}
