
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
reader := bufio.NewReader(os.Stdin)
fmt.Print("Enter the number of elements: ")
n, _ := strconv.Atoi(reader.ReadLine())

p := make([]int, n)
fmt.Println("Enter the elements of the array:")
for i := 0; i < n; i++ {
p[i], _ = strconv.Atoi(reader.ReadLine())
}

ans := 0
for i := 0; i < n-1; i++ {
if p[i] == i+1 {
p[i+1] = p[i]
ans++
}
}
if p[n-1] == n {
ans++
}
fmt.Println("Number of swaps:", ans)
}

