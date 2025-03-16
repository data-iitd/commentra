
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    var t int
    fmt.Scan(&t)
    for i := 0; i < t; i++ {
        var possibleSolutions int
        var solutions strings.Builder
        var s string
        fmt.Scan(&s)
        if isSolution(12, s) {
            solutions.WriteString(" 1x12")
            possibleSolutions++
        }
        if isSolution(6, s) {
            solutions.WriteString(" 2x6")
            possibleSolutions++
        }
        if isSolution(4, s) {
            solutions.WriteString(" 3x4")
            possibleSolutions++
        }
        if isSolution(3, s) {
            solutions.WriteString(" 4x3")
            possibleSolutions++
        }
        if isSolution(2, s) {
            solutions.WriteString(" 6x2")
            possibleSolutions++
        }
        if isSolution(1, s) {
            solutions.WriteString(" 12x1")
            possibleSolutions++
        }
        fmt.Println(possibleSolutions, solutions)
    }
}

func isSolution(columnsCount int, x string) bool {
    allXs := make([]bool, columnsCount)
    for i := 0; i < columnsCount; i++ {
        allXs[i] = true
    }
    for i := 0; i < 12; i++ {
        if x[i] != 'X' {
            allXs[i%columnsCount] = false
        }
    }
    for i := 0; i < columnsCount; i++ {
        if allXs[i] {
            return true
        }
    }
    return false
}

