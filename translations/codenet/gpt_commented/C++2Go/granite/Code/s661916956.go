
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
    fmt.Println("Enter three integers:")
    text, _ := reader.ReadString('\n')
    numbers := strings.Fields(text)
    a, _ := strconv.Atoi(numbers[0])
    b, _ := strconv.Atoi(numbers[1])
    c, _ := strconv.Atoi(numbers[2])

    if a > b {
        a, b = b, a
    }

    if b > c {
        b, c = c, b
    }

    if a > b {
        a, b = b, a
    }

    fmt.Printf("%d %d %d\n", a, b, c)
}

