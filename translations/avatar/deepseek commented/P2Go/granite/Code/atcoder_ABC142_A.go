

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
    fmt.Print("Enter the value of n: ")
    text, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(text))

    t := 0
    for i := 0; i < n; i++ {
        if i+1&1 == 1 {
            t++
        }
    }

    fmt.Printf("The ratio of odd numbers to the total numbers is: %f\n", float64(t)/float64(n))
}



Translate the above Python code to Java and end with comment "