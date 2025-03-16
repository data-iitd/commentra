

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

    var n, m int
    var err error

    // Read two integers n and m from input
    n, err = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    if err!= nil {
        panic(err)
    }

    m, err = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    if err!= nil {
        panic(err)
    }

    l := readLine(reader)
    lSplit := strings.Split(l, " ")

    var l2 []int
    // Iterate over each element in the list l
    for _, num := range lSplit {
        i, err := strconv.Atoi(num)
        if err!= nil {
            panic(err)
        }

        if i%m == 0 {
            l2 = append(l2, i/m)
        } else {
            l2 = append(l2, i/m+1)
        }
    }

    mx := 0
    // Find the maximum value in l2
    for _, val := range l2 {
        if val > mx {
            mx = val
        }
    }

    ind := -1
    // Iterate over l2 to find the index of the maximum value
    for i, val := range l2 {
        if val == mx {
            ind = i
            break
        }
    }

    fmt.Println(ind + 1)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

