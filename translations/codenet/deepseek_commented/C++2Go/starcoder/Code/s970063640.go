<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

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
    fmt.Println("Enter the number of elements")
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    fmt.Println("Enter the value of a")
    a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    sum := 0
    s := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Println("Enter the element")
        s[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    }
    sort.Ints(s)
    for i := n - 1; i > n - a - 1; i-- {
        sum += s[i]
    }
    fmt.Println(sum)
}

