
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    sosuubunnpu [1001]bool
    prime_list [1001]int
    prime_num [1001]int
    prime_counter int
)

func sosuubunnpu() {
    for i := 1; i <= 1000; i++ {
        sosuubunnpu[i] = false
    }
    for i := 2; i <= 1000; i++ {
        for j := 2; j <= 1000/i; j++ {
            if sosuubunnpu[i] == false {
                sosuubunnpu[i*j] = true
            }
        }
    }
    for i := 2; i <= 1000; i++ {
        if sosuubunnpu[i] == false {
            prime_list[prime_counter] = i
            prime_counter++
        }
    }
}

func innsuubunnkai(N int, n int) (int, int) {
    time := 0
    for {
        if N%n == 0 {
            N = N / n
            time++
        } else {
            break
        }
    }
    return time, N
}

func main() {
    sosuubunnpu()
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(reader.ReadLine())
    innsuu := make([]int, 11)
    A := make([][]int, N+1)
    for i := 0; i <= N; i++ {
        A[i] = make([]int, 11)
    }
    for current_num := 2; current_num <= N; current_num++ {
        kekka := innsuubunnkai(current_num, prime_list[0])
        prime_num[0] += kekka[0]
        for i := 1; i < prime_counter; i++ {
            kekka = innsuubunnkai(kekka[1], prime_list[i])
            prime_num[i] += kekka[0]
        }
    }
    for current_num := 2; current_num <= N; current_num++ {
        for i := 0; i < 11; i++ {
            innsuu[i] += A[current_num][i]
        }
    }
    result := int64(1)
    for i := 0; i < prime_counter; i++ {
        result = (result * (int64(prime_num[i]) + 1)) % 1000000007
    }
    fmt.Println(result)
}

