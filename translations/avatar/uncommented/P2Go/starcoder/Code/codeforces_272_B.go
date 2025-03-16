package main
import "fmt"
func main() {
    var input string
    fmt.Scanf("%s", &input)
    fmt.Println(nPairsWithCommonFX(strings.Split(input, " ")))
}
func nPairsWithCommonFX(sequence []string) int {
    storage := make(map[int][]int)
    FXs := make([]int, 0)
    for _, value := range sequence {
        y := f(value)
        if _, ok := storage[y];!ok {
            storage[y] = []int{value}
            FXs = append(FXs, y)
        } else {
            storage[y] = append(storage[y], value)
        }
    }
    return (sum(len(storage[y]) * len(storage[y]) for _, y := range FXs) - sum(len(storage[y]) for _, y := range FXs)) / 2
}
func f(n string) int {
    y := 1
    for n!= "1" {
        if n[0] == '1' {
            y += 1
        }
        n = n[1:]
    }
    return y
}
