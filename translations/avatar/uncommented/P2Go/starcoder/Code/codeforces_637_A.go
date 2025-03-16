package main
import (
"bufio"
"fmt"
"os"
"sort"
"strconv"
"strings"
)
func main() {
reader := bufio.NewReader(os.Stdin)
fmt.Println("Enter the number of elements in the array")
n, _ := strconv.Atoi(reader.ReadString('\n'))
fmt.Println("Enter the elements of the array")
s := make([]string, n)
for i := 0; i < n; i++ {
s[i], _ = reader.ReadString('\n')
}
w := make(map[string]int)
for i := 0; i < n; i++ {
w[s[i]]++
}
sort.Slice(s, func(i, j int) bool {
return w[s[i]] > w[s[j]]
})
c, a := -1, 0
for i := 0; i < n; i++ {
if w[s[i]] == w[s[0]] {
if i > c {
a = i
c = i
}
}
}
fmt.Println(s[a])
}
