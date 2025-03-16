

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter k, n, and w: ")
    text, _ := reader.ReadString('\n')
    k, n, w := textToIntegerArray(text)
    total := 0
    for i := 1; i <= w; i++ {
        total += i * k
    }
    if total > n {
        fmt.Println(total - n)
    } else {
        fmt.Println(0)
    }
}

func textToIntegerArray(text string) (int, int, int) {
    parts := strings.Split(text, " ")
    k, _ := strconv.Atoi(parts[0])
    n, _ := strconv.Atoi(parts[1])
    w, _ := strconv.Atoi(parts[2])
    return k, n, w
}

