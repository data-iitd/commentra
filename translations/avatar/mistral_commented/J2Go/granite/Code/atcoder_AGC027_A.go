

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    NTemp, err := reader.ReadString('\n')
    checkError(err)
    N, err := strconv.ParseInt(strings.TrimSpace(NTemp), 10, 64)
    checkError(err)

    xTemp, err := reader.ReadString('\n')
    checkError(err)
    x, err := strconv.ParseInt(strings.TrimSpace(xTemp), 10, 64)
    checkError(err)

    sweet := make([]int64, N)

    for i := int64(0); i < N; i++ {
        aTemp, err := reader.ReadString('\n')
        checkError(err)
        a, err := strconv.ParseInt(strings.TrimSpace(aTemp), 10, 64)
        checkError(err)
        sweet[i] = a
    }

    sort.Slice(sweet, func(i, j int) bool {
        return sweet[i] < sweet[j]
    })

    num := int64(0)

    for i := int64(0); i < N; i++ {
        if x-sweet[i] >= 0 {
            x = x - sweet[i]
            num++
        } else {
            break
        }
    }

    if num == N && x > 0 {
        num--
    }

    fmt.Println(num)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

This code is almost identical to the Java code, with the only difference being the syntax for reading input from the standard input. The Go code uses the bufio package to read input line by line, and the strconv package to convert the input strings to integers. The sort.Slice() function is used to sort the sweet list in ascending order. The rest of the code is the same as the Java code.

Please note that the Go code assumes that the input values for N and x are valid integers. You may need to add additional error handling code to handle invalid input.

Let me know if you have any further questions.