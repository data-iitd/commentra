

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

    A := make([]int, N)

    for i := 0; i < N; i++ {
        A[i] = 0
    }

    for i := 0; i < M; i++ {
        k, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

        for j := 0; j < k; j++ {
            s, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
            s--

            A[s] |= 1 << i
        }
    }

    p := 0

    for i := 0; i < M; i++ {
        x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
        p |= x << i
    }

    ans := 0

    for s := 0; s < 1<<N; s++ {
        t := 0

        for i := 0; i < N; i++ {
            if (s>>i)&1 == 1 {
                t ^= A[i]
            }
        }

        if p == t {
            ans++
        }
    }

    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
}

