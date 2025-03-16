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
n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
a := make([]int, n)
fmt.Println("Enter the elements of the array")
for i := 0; i < n; i++ {
a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
}
pre := int(math.MaxInt64)
ans := 0
sort.Sort(sort.Reverse(sort.IntSlice(a)))
for j := 0; j < n; j++ {
ans += max(0, min(pre-1, a[j]))
pre = max(0, min(pre-1, a[j]))
}
fmt.Println(ans)
}
