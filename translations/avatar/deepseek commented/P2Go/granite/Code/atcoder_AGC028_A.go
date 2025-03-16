

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
    M, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    S := readLine(reader)
    T := readLine(reader)
    list_S := strings.Split(S, "")
    list_T := strings.Split(T, "")
    Number_i := make([]int, N)
    for i := 0; i < N; i++ {
        Number_i[i] = i
    }
    Number_iMN := make([]float64, N)
    for i := 0; i < N; i++ {
        Number_iMN[i] = float64(i * M / N)
    }
    Number_j := make([]int, M)
    for j := 0; j < M; j++ {
        Number_j[j] = j
    }
    Kaburi_j := make([]int, 0)
    for _, j := range Number_j {
        if contains(Number_iMN, float64(j)) {
            Kaburi_j = append(Kaburi_j, j)
        }
    }
    Kaburi_i := make([]int, 0)
    for _, j := range Kaburi_j {
        Kaburi_i = append(Kaburi_i, int(float64(j)*float64(N)/float64(M)))
    }
    counter := 0
    Flag := 0
    Kaburi_Size := len(Kaburi_i)
    for counter <= Kaburi_Size-1 {
        if list_S[Kaburi_i[counter]]!= list_T[Kaburi_j[counter]] {
            Flag = 1
            break
        }
        counter++
    }
    if Flag == 1 {
        fmt.Println(-1)
    } else {
        fmt.Println(N * M / gcd(N, M))
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

func contains(s []float64, e float64) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}

func gcd(a, b int) int {
    for b!= 0 {
        a, b = b, a%b
    }
    return a
}

