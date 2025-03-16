
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
    P, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    lis := strings.Split(strings.TrimSpace(readLine(reader)), " ")
    ls := make([]int, N)
    for i := 0; i < N; i++ {
        ls[i], _ = strconv.Atoi(lis[i])
    }
    one := 0
    zero := 0
    for i := 0; i < N; i++ {
        if ls[i] == 1 {
            one++
        } else {
            zero++
        }
    }
    pattern_a := 0
    pattern_b := 0
    for j := 0; j <= zero; j++ {
        pattern_b += combi(zero, j)
    }
    time := 0
    for time <= one {
        if time%2 == P {
            pattern_a += combi(one, time)
        }
        time++
    }
    fmt.Println(pattern_a * pattern_b)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), " \r\n")
    }
    return ""
}

func combi(N, K int) int {
    a := 1
    for i := 0; i < K; i++ {
        a *= N - i
    }
    for j := 0; j < K; j++ {
        a /= j + 1
    }
    return a
}

