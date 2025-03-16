
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
    fmt.Println("Enter the number of elements in the list:")
    inp, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(inp))
    fmt.Println("Enter the elements of the list:")
    inp, _ = reader.ReadString('\n')
    list := strings.Split(strings.TrimSpace(inp), " ")
    for i := 0; i < len(list); i++ {
        if i == 0 {
            a, _ := strconv.Atoi(list[i+1])
            b, _ := strconv.Atoi(list[i])
            fmt.Printf("%d %d\n", a-b, b-list[0])
            continue
        } else if i == len(list)-1 {
            a, _ := strconv.Atoi(list[len(list)-1])
            b, _ := strconv.Atoi(list[len(list)-2])
            fmt.Printf("%d %d\n", a-b, a-list[0])
            continue
        }
        a, _ := strconv.Atoi(list[i])
        b, _ := strconv.Atoi(list[i-1])
        c, _ := strconv.Atoi(list[i+1])
        if a-b > c-a {
            fmt.Printf("%d ", c-a)
        } else {
            fmt.Printf("%d ", a-b)
        }
        if a-list[0] > list[len(list)-1]-a {
            fmt.Printf("%d\n", a-list[0])
        } else {
            fmt.Printf("%d\n", list[len(list)-1]-a)
        }
    }
}
