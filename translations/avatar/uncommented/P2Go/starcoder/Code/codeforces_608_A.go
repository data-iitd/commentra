package main
import (
"fmt"
"bufio"
"os"
)
func main() {
reader := bufio.NewReader(os.Stdin)
fmt.Println("Enter the number of elements in the array")
n, _ := reader.ReadString('\n')
n, _ = strconv.Atoi(n)
fmt.Println("Enter the sum of the elements in the array")
s, _ := reader.ReadString('\n')
s, _ = strconv.Atoi(s)
c := 0
for i := 0; i < n; i++ {
fmt.Println("Enter the starting and ending index of the array")
f, t, _ := reader.ReadString('\n')
f, t, _ = strconv.Atoi(f), strconv.Atoi(t), _
x := t - (s - f)
if x > c {
c = x
}
}
fmt.Println(s + c)
}
