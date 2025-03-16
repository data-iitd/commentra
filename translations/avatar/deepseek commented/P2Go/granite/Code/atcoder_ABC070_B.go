

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
    fmt.Println("Enter the elements of the list (separated by spaces):")
    text, _ := reader.ReadString('\n')
    A := strings.Split(text, " ")
    var B []int
    for _, v := range A {
        x, _ := strconv.Atoi(v)
        B = append(B, x)
    }
    if B[1] <= B[2] || B[3] <= B[0] {
        fmt.Println(0)
    } else {
        for i := 0; i < len(B)-1; i++ {
            for j := 0; j < len(B)-i-1; j++ {
                if B[j] > B[j+1] {
                    B[j], B[j+1] = B[j+1], B[j]
                }
            }
        }
        fmt.Println(B[2] - B[1])
    }
}

