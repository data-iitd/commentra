

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter two integers separated by a space:")
    text, _ := reader.ReadString('\n')
    numbers := strings.Split(text, " ")
    n, _ := strconv.Atoi(numbers[0])
    m, _ := strconv.Atoi(numbers[1])
    i := 1
    for m >= i {
        m -= i
        i = (i % n) + 1
    }
    fmt.Println(m)
}

