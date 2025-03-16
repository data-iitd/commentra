
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
    fmt.Println("Enter the values for n, L, R, QL, QR:")
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    L, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    R, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    QL, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    QR, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    fmt.Println("Enter the list of weights W:")
    W := readLine(reader)
    W_temp := strings.Split(W, " ")
    var W_slice []int
    for _, W_item := range W_temp {
        W_item_temp, _ := strconv.Atoi(W_item)
        W_slice = append(W_slice, W_item_temp)
    }
    sumEl := make([]int, n+1)
    sumEl[0] = 0
    for i := 1; i < n+1; i++ {
        sumEl[i] = W_slice[i-1] + sumEl[i-1]
    }
    answer := QR * (n - 1) + sumEl[n] * R
    for i := 1; i < n+1; i++ {
        energy := L*sumEl[i] + R*(sumEl[n]-sumEl[i])
        if i > (n-i) {
            energy = energy + (i-(n-i)-1)*QL
        } else if (n-i) > i {
            energy = energy + ((n-i)-i-1)*QR
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
        return strings.Trim(string(str), "\r\n")
    }
    return ""
}

