
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
    var n, L, R, QL, QR int
    var W []int
    var sum_el []int
    var answer int
    var energy int
    var i int
    var tmp string
    tmp = readLine(reader)
    strs := strings.Split(tmp, " ")
    n, _ = strconv.Atoi(strs[0])
    L, _ = strconv.Atoi(strs[1])
    R, _ = strconv.Atoi(strs[2])
    QL, _ = strconv.Atoi(strs[3])
    QR, _ = strconv.Atoi(strs[4])
    W = make([]int, n)
    sum_el = make([]int, n+1)
    for i = 1; i <= n; i++ {
        tmp = readLine(reader)
        W[i-1], _ = strconv.Atoi(tmp)
    }
    sum_el[1] = W[0]
    for i = 2; i <= n; i++ {
        sum_el[i] = W[i-1] + sum_el[i-1]
    }
    answer = QR * (n - 1) + sum_el[n] * R
    for i = 1; i <= n; i++ {
        energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i])
        if i > (n - i) {
            energy = energy + (i - (n - i) - 1) * QL
        } else if (n - i) > i {
            energy = energy + ((n - i) - i - 1) * QR
        }
        if energy < answer {
            answer = energy
        }
    }
    fmt.Println(answer)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }
    return ""
}

