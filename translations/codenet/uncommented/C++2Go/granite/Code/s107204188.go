
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
    var n, t int
    var err error
    var A []int
    var minA int = 100000001
    var num int = 0
    var f int = 0
    input_array := strings.Split(strings.TrimSpace(readLine(reader)), " ")
    n, err = strconv.Atoi(input_array[0])
    checkError(err)
    t, err = strconv.Atoi(input_array[1])
    checkError(err)
    for i := 0; i < n; i++ {
        A_item, err := strconv.Atoi(readLine(reader))
        checkError(err)
        A = append(A, A_item)
    }
    for i := 0; i < n; i++ {
        if minA > A[i] {
            minA = A[i]
        } else {
            if f == A[i]-minA {
                num++
            } else if f < A[i]-minA {
                num = 1
                f = A[i] - minA
            }
        }
    }
    fmt.Println(num)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    panic(err)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

