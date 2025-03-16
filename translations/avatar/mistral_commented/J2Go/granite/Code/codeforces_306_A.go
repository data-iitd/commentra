

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

    fmt.Print("Enter the first integer: ")
    n, _ := reader.ReadString('\n')
    n = strings.TrimSpace(n)
    nInt, _ := strconv.Atoi(n)

    fmt.Print("Enter the second integer: ")
    m, _ := reader.ReadString('\n')
    m = strings.TrimSpace(m)
    mInt, _ := strconv.Atoi(m)

    a := make([]int, mInt)

    if nInt%mInt == 0 {
        for i := 0; i < mInt; i++ {
            a[i] = nInt / mInt
        }
    } else {
        sub := nInt / mInt
        test := nInt - (sub * mInt)

        count := 0
        for i := 0; i < test; i++ {
            a[count] = a[count] + 1
            count++

            if count > mInt {
                count = 0
            }
        }
    }

    for i := len(a) - 1; i >= 0; i-- {
        fmt.Print(a[i], " ")
    }

    fmt.Println()
}

This Go code is almost identical to the Java code, with some minor differences in syntax. The main difference is that Go uses the "bufio" package for reading input from the console, while Java uses the "Scanner" class. Additionally, Go uses the "strconv" package for converting strings to integers, while Java uses the "Integer.parseInt()" method.

I hope this helps! Let me know if you have any further questions.