
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
    fmt.Fprintln(os.Stderr, "Enter the number of elements:")
    n, _ := strconv.Atoi(reader.ReadLine())
    fmt.Fprintln(os.Stderr, "Enter the elements:")
    line, _ := reader.ReadString('\n')
    elements := strings.Split(strings.TrimSpace(line), " ")
    elementsInt := make([]int, n)
    for i := 0; i < n; i++ {
        elementsInt[i], _ = strconv.Atoi(elements[i])
    }
    for i := 1; i < n; i++ {
        if elementsInt[i]!= elementsInt[i-1] && elementsInt[i] < elementsInt[i-1]*2 {
            fmt.Println("YES")
            return
        }
    }
    fmt.Println("NO")
}
