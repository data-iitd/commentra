

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

    s1Temp := strings.Split(readLine(reader), " ")

    s1 := s1Temp[0]

    s2 := readLine(reader)

    if isValid(s1, s2) == false {
        fmt.Println(-1)
        return
    }

    m1 := make(map[string]int)

    for _, c := range s1 {
        m1[string(c)]++
    }

    m2 := make(map[string]int)

    for _, c := range s2 {
        m2[string(c)]++
    }

    ans := 0

    hs := make(map[string]bool)

    for _, c := range s2 {
        if _, ok := hs[string(c)];!ok {
            hs[string(c)] = true
            x1 := m1[string(c)]
            x2 := m2[string(c)]
            x1 = int(math.Min(float64(x1), float64(x2)))
            ans += x1
        }
    }

    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    panic(err)
}

func isValid(s1 string, s2 string) bool {
    n1 := len(s1)
    n2 := len(s2)

    map := make(map[string]bool)

    for _, c := range s1 {
        map[string(c)] = true
    }

    for _, c := range s2 {
        if _, ok := map[string(c)];!ok {
            return false
        }
    }

    return true
}

Translate the above Go code to C++ and end with comment "