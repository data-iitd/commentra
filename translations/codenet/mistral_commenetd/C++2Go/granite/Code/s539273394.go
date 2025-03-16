
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    primeList []int
    primeCounter int
)

func sosuubunnpu() {
    primeOrNot := make([]int, 1001)
    for i := 1; i <= 1000; i++ {
        primeOrNot[i] = 0
    }
    for i := 2; i <= 1000; i++ {
        for j := 2; j <= 1000/i; j++ {
            if primeOrNot[i] == 0 {
                primeOrNot[i*j] = 1
            }
        }
    }
    for i := 2; i <= 1000; i++ {
        if primeOrNot[i] == 0 {
            primeList = append(primeList, i)
            primeCounter++
        }
    }
}

func innsuubunnkai(N, n int) []int {
    time := 0
    for {
        if N%n == 0 {
            N = N / n
            time++
        } else {
            break
        }
    }
    return []int{time, N}
}

func main() {
    sosuubunnpu()
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    N, _ := strconv.Atoi(scanner.Text())
    innsuu := make([]int, 11)
    A := make([][]int, N+1)
    for i := 0; i <= N; i++ {
        A[i] = make([]int, 11)
    }
    primeNum := make([]int, 1001)
    for currentNum := 2; currentNum <= N; currentNum++ {
        kekka := innsuubunnkai(currentNum, primeList[0])
        for i := 0; i < primeCounter; i++ {
            kekka = innsuubunnkai(kekka[1], primeList[i])
            primeNum[i] += kekka[0]
        }
    }
    result := 1
    for currentNum := 2; currentNum <= N; currentNum++ {
        for i := 0; i < 11; i++ {
            innsuu[i] += A[currentNum][i]
        }
    }
    for i := 0; i < primeCounter; i++ {
        result = (result * (primeNum[i] + 1)) % 1000000007
    }
    fmt.Println(result)
}

