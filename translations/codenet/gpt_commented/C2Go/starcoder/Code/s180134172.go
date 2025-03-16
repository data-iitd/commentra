package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var n, k int
    var p [99999]int
    var i, j, l, m, o int

    // Read the number of elements (n) and the number of smallest elements to sum (k)
    n, k = read_input()

    // Read n integers into the array p
    for i = 0; i < n; i++ {
        p[i] = read_input()
    }

    // Selection sort algorithm to sort the array p in ascending order
    for i = 0; i < n; i++ {
        l = i // Assume the minimum is the first element
        for j = i + 1; j < n; j++ {
            // Update l if a smaller element is found
            if p[j] < p[l] {
                l = j
            }
        }
        // Swap the found minimum element with the first element
        if l!= i {
            m = p[i]
            p[i] = p[l]
            p[l] = m
        }
    }

    // Calculate the sum of the first k smallest elements in the sorted array
    for i = 0; i < k; i++ {
        o += p[i]
    }

    // Print the result: the sum of the k smallest elements
    fmt.Printf("%d\n", o)
}

func read_input() (int, int) {
    var n, k int
    fmt.Scanf("%d %d", &n, &k)
    return n, k
}

func read_input_array() [99999]int {
    var p [99999]int
    for i := 0; i < 99999; i++ {
        fmt.Scanf("%d", &p[i])
    }
    return p
}

func read_input_string() string {
    var s string
    fmt.Scanf("%s", &s)
    return s
}

func read_input_int() int {
    var i int
    fmt.Scanf("%d", &i)
    return i
}

func read_input_float() float64 {
    var f float64
    fmt.Scanf("%f", &f)
    return f
}

func read_input_line() string {
    var s string
    fmt.Scanf("%s", &s)
    return s
}

func read_input_lines(n int) []string {
    var lines []string
    for i := 0; i < n; i++ {
        lines = append(lines, read_input_line())
    }
    return lines
}

func read_input_ints(n int) []int {
    var ints []int
    for i := 0; i < n; i++ {
        ints = append(ints, read_input_int())
    }
    return ints
}

func read_input_floats(n int) []float64 {
    var floats []float64
    for i := 0; i < n; i++ {
        floats = append(floats, read_input_float())
    }
    return floats
}

func read_input_strings(n int) []string {
    var strings []string
    for i := 0; i < n; i++ {
        strings = append(strings, read_input_string())
    }
    return strings
}

func read_input_int_line() []int {
    var ints []int
    for _, s := range strings.Split(read_input_line(), " ") {
        if s!= "" {
            i, _ := strconv.Atoi(s)
            ints = append(ints, i)
        }
    }
    return ints
}

func read_input_float_line() []float64 {
    var floats []float64
    for _, s := range strings.Split(read_input_line(), " ") {
        if s!= "" {
            f, _ := strconv.ParseFloat(s, 64)
            floats = append(floats, f)
        }
    }
    return floats
}

func read_input_string_line() []string {
    return strings.Split(read_input_line(), " ")
}

func read_input_int_lines(n int) [][]int {
    var lines [][]int
    for i := 0; i < n; i++ {
        lines = append(lines, read_input_int_line())
    }
    return lines
}

func read_input_float_lines(n int) [][]float64 {
    var lines [][]float64
    for i := 0; i < n; i++ {
        lines = append(lines, read_input_float_line())
    }
    return lines
}

func read_input_string_lines(n int) [][]string {
    var lines [][]string
    for i := 0; i < n; i++ {
        lines = append(lines, read_input_string_line())
    }
    return lines
}

