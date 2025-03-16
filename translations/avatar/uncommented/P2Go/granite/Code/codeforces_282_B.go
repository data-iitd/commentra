
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
    firstline, _ := strconv.Atoi(reader.ReadLine())
    total := 0
    memory := make([]string, 0)
    for x := 0; x < firstline; x++ {
        line := reader.ReadLine()
        parts := strings.Split(string(line), " ")
        A, _ := strconv.Atoi(parts[0])
        G, _ := strconv.Atoi(parts[1])
        if total+A <= 500 {
            total += A
            memory = append(memory, "A")
        } else {
            total -= G
            memory = append(memory, "G")
        }
    }
    fmt.Println(strings.Join(memory, ""))
}
