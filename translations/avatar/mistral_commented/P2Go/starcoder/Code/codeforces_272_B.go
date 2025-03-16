package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// f returns the FX value of the given number
func f(n int) int {
    fx := 1
    for n!= 1 {
        if n%2!= 0 {
            fx += 1
        }
        n /= 2
    }
    return fx
}

// nPairsWithCommonFX returns the number of pairs with common FX
func nPairsWithCommonFX(sequence []int) int {
    storage := make(map[int][]int)
    FXs := make([]int, 0)
    for _, value := range sequence {
        fx := f(value)
        if fx not in storage {
            storage[fx] = []int{value}
            FXs = append(FXs, fx)
        } else {
            storage[fx] = append(storage[fx], value)
        }
    }
    result := (sum(len(storage[fx]) * len(storage[fx]) for _, fx := range FXs) - sum(len(storage[fx]) for _, fx := range FXs)) / 2
    return int(result)
}

// sum returns the sum of the given values
func sum(values...int) int {
    result := 0
    for _, value := range values {
        result += value
    }
    return result
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    reader.ReadString('\n')
    sequence := strings.Split(strings.TrimSpace(reader.ReadString('\n')), " ")
    sequence = sequence[:len(sequence)-1]
    sequence = make([]int, len(sequence))
    for i, value := range sequence {
        sequence[i], _ = strconv.Atoi(value)
    }
    result := nPairsWithCommonFX(sequence)
    fmt.Println(result)
}

// 