

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    fmt.Print("Enter the value of A: ")
    A, _ := reader.ReadString('\n')
    A = strings.TrimSpace(A)
    A_int, _ := strconv.Atoi(A)

    fmt.Print("Enter the value of B: ")
    B, _ := reader.ReadString('\n')
    B = strings.TrimSpace(B)
    B_int, _ := strconv.Atoi(B)

    ans := A_int - 2*B_int
    if ans < 0 {
        ans = 0
    }

    fmt.Println(ans)
}

