

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func isSolution(columnsCount int, x string) bool {
    allXs := make([]bool, columnsCount)
    for i := 0; i < 12; i++ {
        if x[i]!= 'X' {
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

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    t, _ := strconv.Atoi(reader.ReadLine())
    for i := 0; i < t; i++ {
        possibleSolutions := 0
        solutions := ""
        s := reader.ReadLine()
        if isSolution(12, s) {
            solutions += " 1x12"
            possibleSolutions++
        }
        if isSolution(6, s) {
            solutions += " 2x6"
            possibleSolutions++
        }
        if isSolution(4, s) {
            solutions += " 3x4"
            possibleSolutions++
        }
        if isSolution(3, s) {
            solutions += " 4x3"
            possibleSolutions++
        }
        if isSolution(2, s) {
            solutions += " 6x2"
            possibleSolutions++
        }
        if isSolution(1, s) {
            solutions += " 12x1"
            possibleSolutions++
        }
        fmt.Fprintf(writer, "%d%s\n", possibleSolutions, solutions)
    }
    writer.Flush()
}

