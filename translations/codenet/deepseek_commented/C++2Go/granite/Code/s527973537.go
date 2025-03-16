
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Step 3: Input a string
    reader := bufio.NewReader(os.Stdin)
    N, _ := reader.ReadString('\n')
    N = strings.TrimSpace(N)

    // Step 4: Calculate the sum of digits
    S := 0
    for _, c := range N {
        S += int(c - '0')
    }

    // Step 5: Check if the number is divisible by the sum of its digits
    if i, _ := strconv.Atoi(N); i%S == 0 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }

    // Step 6: Return 0
    os.Exit(0)
}
