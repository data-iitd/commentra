
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
    fmt.Println(nPairsWithCommonFX(stringToIntArray(readLine(reader))))
}

func nPairsWithCommonFX(sequence []int) int {
    storage := make(map[int][]int)
    FXs := make([]int, 0)
    for _, value := range sequence {
        y := f(value)
        if _, ok := storage[y];!ok {
            storage[y] = make([]int, 0)
            FXs = append(FXs, y)
        }
        storage[y] = append(storage[y], value)
    }
    result := 0
    for _, y := range FXs {
        result += len(storage[y]) * len(storage[y])
    }
    result -= sum(len(storage[y]) for _, y := range FXs)
    return result / 2
}

func f(n int) int {
    y := 1
    for n!= 1 {
        if n%2 == 1 {
            y++
        }
        n /= 2
    }
    return y
}

func stringToIntArray(s string) []int {
    split := strings.Split(s, " ")
    result := make([]int, len(split))
    for i, str := range split {
        val, _ := strconv.Atoi(str)
        result[i] = val
    }
    return result
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }
    panic(err)
}

func sum(numbers...int) int {
    result := 0
    for _, n := range numbers {
        result += n
    }
    return result
}

