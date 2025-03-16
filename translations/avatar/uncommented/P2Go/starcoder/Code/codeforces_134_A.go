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
w := make([]int, n)
for i := 0; i < n; i++ {
w[i], _ = strconv.Atoi(reader.ReadString('\n'))
}
x := 0
for i := 0; i < n; i++ {
x += w[i]
}
d := make([]int, 0)
for i := 0; i < n; i++ {
if (x - w[i])/(n-1) == w[i] {
d = append(d, i+1)
}
}
fmt.Println("The number of subarrays with equal averages is", len(d))
fmt.Println("The indices of the subarrays with equal averages are", strings.Trim(fmt.Sprint(d), "[]"))
}
