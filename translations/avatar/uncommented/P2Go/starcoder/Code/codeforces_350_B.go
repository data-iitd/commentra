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
fmt.Println("Enter the number of elements in the array")
n, _ := strconv.Atoi(reader.ReadString('\n'))
fmt.Println("Enter the elements of the array")
a := make([]int, n+1)
for i := 1; i <= n; i++ {
a[i], _ = strconv.Atoi(reader.ReadString('\n'))
}
fmt.Println("Enter the number of elements in the array")
t, _ := strconv.Atoi(reader.ReadString('\n'))
fmt.Println("Enter the elements of the array")
b := make([]int, t+1)
for i := 1; i <= t; i++ {
b[i], _ = strconv.Atoi(reader.ReadString('\n'))
}
ans := make([]int, 0)
cnt := make([]int, t+1)
for i := 1; i <= n; i++ {
cnt[a[i]]++
}
for i := 1; i <= n; i++ {
if b[i] == 1 {
crt := make([]int, 0)
x := a[i]
for cnt[x] == 1 {
crt = append(crt, x)
x = a[x]
}
if len(crt) > len(ans) {
ans = crt
}
}
}
fmt.Println(len(ans))
fmt.Println(strings.Trim(fmt.Sprint(ans), "[]"))
}
