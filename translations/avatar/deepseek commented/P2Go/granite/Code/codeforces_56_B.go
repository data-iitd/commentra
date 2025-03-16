

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

    N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    A := readLine(reader)

    mn, mx := N+1, -1
    for i := 0; i < N; i++ {
        a, _ := strconv.Atoi(A[i])
        if a!= i+1 {
            if i < mn {
                mn = i
            }
            if i > mx {
                mx = i
            }
        }
    }

    if mx == -1 {
        fmt.Println("0 0")
    } else {
        A = append(A[:mn], reverse(A[mn:mx+1])...)
        A = append(A[:mx+1], A[mx+1:]...)
        if isSorted(A) {
            fmt.Printf("%d %d\n", mn+1, mx+1)
        } else {
            fmt.Println("0 0")
        }
    }
}

func readLine(reader *bufio.Reader) []string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Split(string(str), " ")
    } else {
        panic(err)
    }
}

func reverse(s []string) []string {
    for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
        s[i], s[j] = s[j], s[i]
    }
    return s
}

func isSorted(s []string) bool {
    for i := 1; i < len(s); i++ {
        if s[i-1] > s[i] {
            return false
        }
    }
    return true
}

