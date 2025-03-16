
package main

import (
    "bufio"
    "bytes"
    "container/heap"
    "fmt"
    "os"
    "sort"
)

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
func valid(i, j, n, m int) bool {
    if i < n && i >= 0 && j >= 0 && j < m {
        return true
    }
    return false
}

// Function to calculate the sum of an arithmetic series from i to n
func sumn(i, n int) int {
    return (n - i) * (i + n) / 2
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
func sqfun(a, b, c int) int {
    return (-b + int(math.Sqrt(float64(b*b-4*a*c)))) / 2 * a
}

// Function to read a single or multiple integer values from input
func value() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a single or multiple integer values from standard input
func values() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a list of integers from input
func inlst() (val []int) {
    res := []int{}
    for {
        tmp := value()
        if tmp == 0 {
            break
        }
        res = append(res, tmp)
    }
    return res
}

// Function to read a list of integers from standard input
func inlsts() (val []int) {
    res := []int{}
    for {
        tmp := values()
        if tmp == 0 {
            break
        }
        res = append(res, tmp)
    }
    return res
}

// Function to read a single integer from input
func inp() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a single integer from standard input
func inps() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a string from input
func instr() (val string) {
    _, _ = fmt.Fscanln(bufio.NewReader(os.Stdin), &val)
    return
}

// Function to split a string into a list of words
func stlst() (val []string) {
    res := []string{}
    for {
        tmp := instr()
        if tmp == "" {
            break
        }
        res = append(res, tmp)
    }
    return res
}

// Main logic of the program
func solve() {
    l := []string{}
    for i := 0; i < 3; i++ {
        l = append(l, f(instr()))
    }
    t := permutations(l, len(l))
    l = []string{}
    for i := 0; i < inp(); i++ {
        if f(instr()) == t[i] {
            fmt.Println("ACC")
        } else {
            fmt.Println("WA")
        }
    }
}

func main() {
    solve()
}

// Function to sanitize a string by converting it to lowercase and removing certain characters
func f(s string) string {
    var r bytes.Buffer
    for _, i := range s {
        if i!= '-' && i!= ';' && i!= '_' {
            r.WriteRune(unicode.ToLower(i))
        }
    }
    return r.String()
}

// Function to generate all permutations of a given list
func permutations(arr []string, n int) []string {
    var res []string
    var p []string
    for i := 0; i < n; i++ {
        p = append(p, arr[i])
    }
    heap.Init(&p)
    for p!= nil {
        res = append(res, strings.Join(p, ""))
        p = heap.Next(&p)
    }
    return res
}

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
func valid(i, j, n, m int) bool {
    if i < n && i >= 0 && j >= 0 && j < m {
        return true
    }
    return false
}

// Function to calculate the sum of an arithmetic series from i to n
func sumn(i, n int) int {
    return (n - i) * (i + n) / 2
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
func sqfun(a, b, c int) int {
    return (-b + int(math.Sqrt(float64(b*b-4*a*c)))) / 2 * a
}

// Function to read a single or multiple integer values from input
func value() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a single or multiple integer values from standard input
func values() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a list of integers from input
func inlst() (val []int) {
    res := []int{}
    for {
        tmp := value()
        if tmp == 0 {
            break
        }
        res = append(res, tmp)
    }
    return res
}

// Function to read a list of integers from standard input
func inlsts() (val []int) {
    res := []int{}
    for {
        tmp := values()
        if tmp == 0 {
            break
        }
        res = append(res, tmp)
    }
    return res
}

// Function to read a single integer from input
func inp() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a single integer from standard input
func inps() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a string from input
func instr() (val string) {
    _, _ = fmt.Fscanln(bufio.NewReader(os.Stdin), &val)
    return
}

// Function to split a string into a list of words
func stlst() (val []string) {
    res := []string{}
    for {
        tmp := instr()
        if tmp == "" {
            break
        }
        res = append(res, tmp)
    }
    return res
}

// Main logic of the program
func solve() {
    l := []string{}
    for i := 0; i < 3; i++ {
        l = append(l, f(instr()))
    }
    t := permutations(l, len(l))
    l = []string{}
    for i := 0; i < inp(); i++ {
        if f(instr()) == t[i] {
            fmt.Println("ACC")
        } else {
            fmt.Println("WA")
        }
    }
}

func main() {
    solve()
}

// Function to sanitize a string by converting it to lowercase and removing certain characters
func f(s string) string {
    var r bytes.Buffer
    for _, i := range s {
        if i!= '-' && i!= ';' && i!= '_' {
            r.WriteRune(unicode.ToLower(i))
        }
    }
    return r.String()
}

// Function to generate all permutations of a given list
func permutations(arr []string, n int) []string {
    var res []string
    var p []string
    for i := 0; i < n; i++ {
        p = append(p, arr[i])
    }
    heap.Init(&p)
    for p!= nil {
        res = append(res, strings.Join(p, ""))
        p = heap.Next(&p)
    }
    return res
}

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
func valid(i, j, n, m int) bool {
    if i < n && i >= 0 && j >= 0 && j < m {
        return true
    }
    return false
}

// Function to calculate the sum of an arithmetic series from i to n
func sumn(i, n int) int {
    return (n - i) * (i + n) / 2
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
func sqfun(a, b, c int) int {
    return (-b + int(math.Sqrt(float64(b*b-4*a*c)))) / 2 * a
}

// Function to read a single or multiple integer values from input
func value() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a single or multiple integer values from standard input
func values() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a list of integers from input
func inlst() (val []int) {
    res := []int{}
    for {
        tmp := value()
        if tmp == 0 {
            break
        }
        res = append(res, tmp)
    }
    return res
}

// Function to read a list of integers from standard input
func inlsts() (val []int) {
    res := []int{}
    for {
        tmp := values()
        if tmp == 0 {
            break
        }
        res = append(res, tmp)
    }
    return res
}

// Function to read a single integer from input
func inp() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a single integer from standard input
func inps() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a string from input
func instr() (val string) {
    _, _ = fmt.Fscanln(bufio.NewReader(os.Stdin), &val)
    return
}

// Function to split a string into a list of words
func stlst() (val []string) {
    res := []string{}
    for {
        tmp := instr()
        if tmp == "" {
            break
        }
        res = append(res, tmp)
    }
    return res
}

// Main logic of the program
func solve() {
    l := []string{}
    for i := 0; i < 3; i++ {
        l = append(l, f(instr()))
    }
    t := permutations(l, len(l))
    l = []string{}
    for i := 0; i < inp(); i++ {
        if f(instr()) == t[i] {
            fmt.Println("ACC")
        } else {
            fmt.Println("WA")
        }
    }
}

func main() {
    solve()
}

// Function to sanitize a string by converting it to lowercase and removing certain characters
func f(s string) string {
    var r bytes.Buffer
    for _, i := range s {
        if i!= '-' && i!= ';' && i!= '_' {
            r.WriteRune(unicode.ToLower(i))
        }
    }
    return r.String()
}

// Function to generate all permutations of a given list
func permutations(arr []string, n int) []string {
    var res []string
    var p []string
    for i := 0; i < n; i++ {
        p = append(p, arr[i])
    }
    heap.Init(&p)
    for p!= nil {
        res = append(res, strings.Join(p, ""))
        p = heap.Next(&p)
    }
    return res
}

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
func valid(i, j, n, m int) bool {
    if i < n && i >= 0 && j >= 0 && j < m {
        return true
    }
    return false
}

// Function to calculate the sum of an arithmetic series from i to n
func sumn(i, n int) int {
    return (n - i) * (i + n) / 2
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
func sqfun(a, b, c int) int {
    return (-b + int(math.Sqrt(float64(b*b-4*a*c)))) / 2 * a
}

// Function to read a single or multiple integer values from input
func value() (val int) {
    _, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &val)
    return
}

// Function to read a single or multiple