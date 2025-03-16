
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    S, _ := reader.ReadString('\n')
    S = S[:len(S)-1]

    T, _ := reader.ReadString('\n')
    T = T[:len(T)-1]

    A, _ := strconv.Atoi(reader.ReadString('\n')[ : len(reader.ReadString('\n'))-1 ])

    B, _ := strconv.Atoi(reader.ReadString('\n')[ : len(reader.ReadString('\n'))-1 ])

    U, _ := reader.ReadString('\n')
    U = U[:len(U)-1]

    solve(S, T, A, B, U)
}

func solve(S string, T string, A int, B int, U string) {
    if S == U {
        A -= 1
    }
    if T == U {
        B -= 1
    }
    fmt.Println(A, B)
}

