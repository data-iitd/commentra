
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
    fmt.Print("Enter the number of elements: ")
    n, _ := strconv.Atoi(reader.ReadLine()[0 : len(reader.ReadLine())-1])
    fmt.Print("Enter the elements: ")
    input := reader.ReadLine()[0 : len(reader.ReadLine())-1]
    a := strings.Split(input, " ")
    var currentLevel, counter, counterTurns int
    for counter < n {
        counterTurns++
        for i := 0; i < n; i++ {
            if a[i]!= "-1" && a[i] <= counter {
                counter++
                a[i] = "-1"
            }
        }
        a = reverse(a)
    }
    fmt.Println(counterTurns)
}

func reverse(a []string) []string {
    for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
        a[i], a[j] = a[j], a[i]
    }
    return a
}

