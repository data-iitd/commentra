
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var num int = 998244353
    var n int
    var ai []int
    var bi []int

    // Reading the number of test cases from the input
    fmt.Scan(&n)

    // Creating an empty ArrayList to store the first array elements
    ai = make([]int, 0)

    // Creating an empty ArrayList to store the second array elements
    bi = make([]int, 0)

    for i := 0; i < n; i++ {
        // Reading the input line
        reader := bufio.NewReader(os.Stdin)
        text, _ := reader.ReadString('\n')

        // Parsing the input line
        st := strings.Fields(text)

        // Adding the first array element to the ArrayList
        ai = append(ai, strconv.Atoi(st[0]))

        // Adding the second array element to the ArrayList
        bi = append(bi, strconv.Atoi(st[1]))
    }

    // Sorting the ArrayLists in ascending order
    sort.Ints(ai)
    sort.Ints(bi)

    if n%2 == 1 {
        // Checking if the number of test cases is odd
        fmt.Println(bi[len(bi)/2] - ai[len(ai)/2] + 1)
    } else {
        // Calculating the average of the middle two elements of the first ArrayList
        b := (float64(ai[len(ai)/2]) + float64(ai[len(ai)/2-1]) + 0.0) / 2

        // Calculating the average of the middle two elements of the second ArrayList
        c := (float64(bi[len(bi)/2]) + float64(bi[len(bi)/2-1]) + 0.0) / 2

        // Calculating and printing the answer for even number of test cases
        fmt.Println(int(2 * (c - b) + 1))
    }
}

