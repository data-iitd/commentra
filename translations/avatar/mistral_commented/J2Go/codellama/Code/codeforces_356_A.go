
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initializing FastReader for reading input
    in := FastReader{}

    n := in.nextInt() // Reading the number of elements in the array

    left := make([]int, n) // Creating a slice to store the indices of elements in the sorted order
    answer := make([]int, n) // Creating a slice to store the answer for each index

    // Adding all the indices to the slice and initializing the answer slice with -1
    for i := 0; i < n; i++ {
        left[i] = i
        answer[i] = -1
    }

    q := in.nextInt() // Reading the number of queries

    // Processing each query
    for q > 0 {
        l := in.nextInt() - 1 // Reading the left index of the query range
        r := in.nextInt() - 1 // Reading the right index of the query range
        win := in.nextInt() // Reading the winning index

        // Updating the answer for the winning index and all the indices between the left and right indices
        for i := l; i <= r; i++ {
            if left[i] != -1 {
                answer[left[i]] = win
                left[i] = -1
            }
        }

        // Updating the answer for the winning index in the answer slice
        answer[win-1] = 0

        // Adding the winning index back to the slice
        left[win-1] = win - 1

        q--
    }

    ans := "" // Creating a string to store the answer as a string

    // Printing the answer for each index in the answer slice
    for i := 0; i < n; i++ {
        ans += strconv.Itoa(answer[i])
        if i != n-1 {
            ans += " "
        }
    }

    fmt.Println(ans) // Printing the answer as a single line
}

type FastReader struct {
    br *bufio.Reader
    st *strings.Reader
}

func (f *FastReader) next() string {
    if f.st == nil || !f.st.Scan() {
        line, _, err := f.br.ReadLine()
        if err != nil {
            panic(err)
        }
        f.st = strings.NewReader(string(line))
    }
    return f.st.Text()
}

func (f *FastReader) nextInt() int {
    return int(f.nextInt64())
}

func (f *FastReader) nextInt64() int64 {
    return int64(f.nextInt64())
}

func (f *FastReader) nextFloat() float64 {
    return float64(f.nextFloat64())
}

func (f *FastReader) nextFloat64() float64 {
    return float64(f.nextFloat64())
}

func (f *FastReader) nextLine() string {
    line, _, err := f.br.ReadLine()
    if err != nil {
        panic(err)
    }
    return string(line)
}

func (f *FastReader) init() {
    f.br = bufio.NewReader(os.Stdin)
}

func (f *FastReader) init(file string) {
    f.br = bufio.NewReader(os.Stdin)
}

