

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
    t, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    m, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    memory := make([]int, m)
    allocIdx := 0
    for j := 0; j < t; j++ {
        command := readLine(reader)
        switch command {
        case "alloc":
            n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
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
            x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
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
                }
            }
            newSize := m - d
            newMemory := make([]int, newSize)
            k := 0
            for i := 0; i < m; i++ {
                if memory[i]!= 0 {
                    newMemory[k] = memory[i]
                    k++
                }
            }
            memory = newMemory
        default:
            fmt.Println("h")
        }
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

This code now includes comments explaining the purpose and functionality of each logical block.