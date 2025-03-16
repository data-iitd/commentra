

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of slimes N:")
    text, _ := reader.ReadString('\n')
    N, _ := strconv.Atoi(strings.TrimSpace(text))
    size := 1 << uint(N)
    S := make([]int, size)
    spawned := make([]bool, size)
    spawned[size-1] = true
    fmt.Println("Enter the initial positions of slimes separated by spaces:")
    text, _ = reader.ReadString('\n')
    parts := strings.Fields(strings.TrimSpace(text))
    for i, part := range parts {
        S[i], _ = strconv.Atoi(part)
    }
    sort.Ints(S)
    active := []int{size - 1}
    spawned[size-1] = true
    for i := 0; i < N; i++ {
        sort.Sort(sort.Reverse(sort.IntSlice(active)))
        activated := []int{}
        next := size - 1
        for _, slime := range active {
            for next >= 0 && (S[next] >= slime || spawned[next]) {
                next--
            }
            if next < 0 {
                fmt.Println("No")
                return
            }
            spawned[next] = true
            activated = append(activated, S[next])
        }
        active = append(active, activated...)
    }
    fmt.Println("Yes")
}

