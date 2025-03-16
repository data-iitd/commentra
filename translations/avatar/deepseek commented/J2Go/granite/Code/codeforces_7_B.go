
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
    var t, m int
    fmt.Fscanf(reader, "%d %d\n", &t, &m)
    memory := make([]int, m)
    allocIdx := 0
    for j := 0; j < t; j++ {
        command, _ := reader.ReadString('\n')
        command = strings.TrimSpace(command)
        commandArgs := strings.Split(command, " ")
        switch commandArgs[0] {
        case "alloc":
            n, _ := strconv.Atoi(commandArgs[1])
            len := 0
            canAlloc := false
            for i := 0; i < m; i++ {
                if memory[i] == 0 {
                    len++
                } else {
                    len = 0
                }
                if len == n {
                    canAlloc = true
                    len = i - n + 1
                    break
                }
            }
            if canAlloc {
                allocIdx++
                for i := len; i < len+n; i++ {
                    memory[i] = allocIdx
                }
                fmt.Println(allocIdx)
            } else {
                fmt.Println("NULL")
            }
        case "erase":
            x, _ := strconv.Atoi(commandArgs[1])
            if x <= 0 {
                fmt.Println("ILLEGAL_ERASE_ARGUMENT")
                break
            }
            hasErased := false
            for i := 0; i < m; i++ {
                if memory[i] == x {
                    memory[i] = 0
                    hasErased = true
                }
            }
            if!hasErased {
                fmt.Println("ILLEGAL_ERASE_ARGUMENT")
            }
        case "defragment":
            d := 0
            for i := 0; i < m; i++ {
                if memory[i] == 0 {
                    d++
                } else {
                    memory[i-d] = memory[i]
                }
            }
            for i := m - d; i < m; i++ {
                memory[i] = 0
            }
        default:
            fmt.Println("h")
        }
    }
}
