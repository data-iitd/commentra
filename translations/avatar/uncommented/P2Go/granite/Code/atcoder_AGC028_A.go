
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
    N, M := 0, 0
    fmt.Fscanf(reader, "%d %d\n", &N, &M)
    S := make([]byte, N)
    T := make([]byte, M)
    fmt.Fscanf(reader, "%s\n", S)
    fmt.Fscanf(reader, "%s\n", T)
    list_S := make([]byte, N)
    list_T := make([]byte, M)
    for i := 0; i < N; i++ {
        list_S[i] = S[i]
    }
    for i := 0; i < M; i++ {
        list_T[i] = T[i]
    }
    Number_i := make([]int, N)
    for i := 0; i < N; i++ {
        Number_i[i] = i
    }
    Number_iMN := make([]int, 0)
    for i := 0; i < N; i++ {
        Number_iMN = append(Number_iMN, i*M/N)
    }
    Number_j := make([]int, M)
    for i := 0; i < M; i++ {
        Number_j[i] = i
    }
    Kaburi_j := make([]int, 0)
    for i := 0; i < M; i++ {
        if contains(Number_iMN, Number_j[i]) {
            Kaburi_j = append(Kaburi_j, Number_j[i])
        }
    }
    Kaburi_i := make([]int, 0)
    for i := 0; i < len(Kaburi_j); i++ {
        Kaburi_i = append(Kaburi_i, int(Kaburi_j[i]*N/M))
    }
    counter := 0
    Flag := 0
    Kaburi_Size := len(Kaburi_i)
    for counter <= Kaburi_Size-1 {
        if list_S[Kaburi_i[counter]] == list_T[Kaburi_j[counter]] {
            pass
        } else {
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

func gcd(a, b int) int {
    for b!= 0 {
        a, b = b, a%b
    }
    return a
}

func contains(s []int, e int) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}
