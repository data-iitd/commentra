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
var s string
fmt.Fscanln(reader, &s)
a := make(map[rune]int)
for _, v := range s {
a[v]++
}
ans := 0
for _, v := range a {
ans += v * 2
}
fmt.Println(ans)
}
