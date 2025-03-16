

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize Scanner to read input from standard input
    scanner := bufio.NewScanner(os.Stdin)
    // Initialize variables to store the number of elements and the elements
    var n int
    var vec [][]int
    // Read the number of elements
    fmt.Fscanf(scanner, "%d\n", &n)
    // Initialize a 2D array to store the elements
    vec = make([][]int, n)
    // Read the elements into the 2D array
    for i := 0; i < n; i++ {
        var a, b, c, price int
        fmt.Fscanf(scanner, "%d %d %d %d\n", &a, &b, &c, &price)
        vec[i] = []int{a, b, c, price}
    }
    // Initialize variables to store the best index and its price
    var ans int
    var ansprice int = 200000
    // Loop through each element to find the best one
    for i := 0; i < n; i++ {
        var fl int = 1 // Flag to check if the element is dominated
        // Compare the current element with every other element
        for j := 0; j < n; j++ {
            if vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2] {
                fl = 0 // The element is dominated
            }
        }
        // If the element is not dominated, check its price
        if fl == 1 {
            if vec[i][3] < ansprice {
                ansprice = vec[i][3] // Update the minimum price
                ans = i + 1 // Update the best index
            }
        }
    }
    // Output the index of the best element
    fmt.Println(ans)
}

