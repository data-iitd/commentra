

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
    fmt.Print("Enter a number: ")
    text, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(text))

    square := n * n
    odd := make([]int, 0)
    even := make([]int, 0)

    for i := 1; i <= square; i++ {
        if i%2 == 0 {
            even = append(even, i)
        } else {
            odd = append(odd, i)
        }
    }

    loop := square / n
    div := loop / 2

    for i := 1; i <= loop; i++ {
        for j := 0; j < div; j++ {
            if i%2 == 1 {
                fmt.Printf("%d %d ", odd[0], even[len(even)-1])
                odd = odd[1:]
                even = even[:len(even)-1]
            } else {
                fmt.Printf("%d %d ", even[0], odd[len(odd)-1])
                odd = odd[:len(odd)-1]
                even = even[1:]
            }
        }
        fmt.Println()
    }
}

