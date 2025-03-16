
###
# Import necessary libraries
###

import (
    "bufio"
    "bytes"
    "container/heap"
    "fmt"
    "os"
    "sort"
)

# Define helper functions
func hpop(heap *IntHeap) int {
    res := heap.val[0]
    heap.val = heap.val[1:]
    *heap = IntHeap{val: heap.val}
    heap.Fix(0)
    return res
}

func hpush(heap *IntHeap, item int) {
    heap.val = append(heap.val, item)
    heap.Fix(len(heap.val) - 1)
}

###
# Function to find the solution
###

func solution() {
    // Initialize the scanner to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read the first line and count the number of occurrences of each color
    scanner.Scan()
    bought_count := make(map[byte]int)
    for _, char := range scanner.Text() {
        bought_count[char]++
    }

    // Read the second line and count the number of occurrences of each color
    scanner.Scan()
    made_cout := make(map[byte]int)
    for _, char := range scanner.Text() {
        made_cout[char]++
    }

    // Initialize result to 0
    res := 0

    // Iterate through each color in made_cout
    for color, count := range made_cout {
        // Check if the color is present in bought_count
        if _, ok := bought_count[color];!ok {
            // If not, print -1 and exit the function
            fmt.Println(-1)
            return
        }

        // Update the result by adding the minimum of bought and made counts
        res += min(bought_count[color], count)
    }

    // Print the result
    fmt.Println(res)
}

###
# Main function to run the solution function for multiple test cases
###

func main() {
    // Initialize the scanner to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read the number of test cases
    scanner.Scan()
    t := readNum(scanner.Bytes())

    // Run the solution function for each test case
    for t > 0 {
        solution()
        t--
    }
}

func readInt(bytes []byte, from int, val *int) int {
    i := from
    sign := 1
    if bytes[i] == '-' {
        sign = -1
        i++
    }
    tmp := 0
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp = tmp*10 + int(bytes[i]-'0')
        i++
    }
    *val = tmp * sign
    return i
}

func readNum(scanner *bufio.Scanner) (a int) {
    scanner.Scan()
    readInt(scanner.Bytes(), 0, &a)
    return
}

func readTwoNums(scanner *bufio.Scanner) (a int, b int) {
    res := readNNums(scanner, 2)
    a, b = res[0], res[1]
    return
}

func readNNums(scanner *bufio.Scanner, n int) []int {
    res := make([]int, n)
    x := 0
    scanner.Scan()
    for i := 0; i < n; i++ {
        for x < len(scanner.Bytes()) && scanner.Bytes()[x] =='' {
            x++
        }
        x = readInt(scanner.Bytes(), x, &res[i])
    }
    return res
}

func fillNNums(scanner *bufio.Scanner, n int, res []int) {
    x := 0
    scanner.Scan()
    for i := 0; i < n; i++ {
        for x < len(scanner.Bytes()) && scanner.Bytes()[x] =='' {
            x++
        }
        x = readInt(scanner.Bytes(), x, &res[i])
    }
}

func readUint64(bytes []byte, from int, val *uint64) int {
    i := from

    var tmp uint64
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp = tmp*10 + uint64(bytes[i]-'0')
        i++
    }
    *val = tmp

    return i
}

func readInt64(bytes []byte, from int, val *int64) int {
    i := from
    var tmp int64
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp = tmp*10 + int64(bytes[i]-'0')
        i++
    }
    *val = tmp
    return i
}

func readNInt64s(scanner *bufio.Scanner, n int) []int64 {
    res := make([]int64, n)
    x := -1
    scanner.Scan()
    for i := 0; i < n; i++ {
        x = readInt64(scanner.Bytes(), x+1, &res[i])
    }
    return res
}

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    t := readNum(scanner)

    for t > 0 {
        t--
        solution()
    }
}

func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}