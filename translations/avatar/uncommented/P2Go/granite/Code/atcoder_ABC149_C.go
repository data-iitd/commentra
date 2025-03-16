
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a number: ")
    text, _ := reader.ReadString('\n')
    number, _ := strconv.Atoi(text)
    prime := make([]bool, 100010)
    for i := 0; i < 100010; i++ {
        prime[i] = true
    }
    prime[0] = false
    prime[1] = false
    for i := 4; i < 100010; i += 2 {
        prime[i] = false
    }
    i := 3
    for i*i <= 100008 {
        if prime[i] {
            for j := i + i; j < 100008; j += i {
                prime[j] = false
            }
        }
        i += 2
    }
    for i = number; i < 100008; i++ {
        if prime[i] {
            fmt.Println(i)
            break
        }
    }
}
