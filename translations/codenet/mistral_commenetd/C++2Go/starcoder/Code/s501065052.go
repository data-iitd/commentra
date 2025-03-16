
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements in the memory array:")
    N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

    mem := make([]int, N+1)
    fmt.Println("Enter the memory locations of each process:")
    for i := 1; i <= N; i++ {
        P, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
        mem[P] = i
    }

    maxcnt := 1
    cnt := 1
    for i := 1; i < N; i++ {
        if mem[i] < mem[i+1] {
            cnt++
        } else {
            maxcnt = max(maxcnt, cnt)
            cnt = 1
        }
    }
    maxcnt = max(maxcnt, cnt)

    fmt.Println(N - maxcnt)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

<<<<<<< HEAD
Translate the above Go code to Python and end with comment "
=======
>>>>>>> 98c87cb78a (data updated)
