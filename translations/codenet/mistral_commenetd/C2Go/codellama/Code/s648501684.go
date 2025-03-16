
package main

import "fmt"

func main() {
    var n, k, q int // Declare and initialize three integers n, k, and q to read input values from the user

    fmt.Scanf("%d%d%d", &n, &k, &q) // Read the input values n, k, and q from the user using fmt.Scanf function

    arr := make([]int, n+1) // Declare an integer array arr of size n+1

    for i := 0; i <= n; i++ { // Initialize the array arr with zeros using a for loop
        arr[i] = 0
    }

    for i := 0; i < q; i++ { // Read q query values from the user and increment the corresponding index in the array arr
        var temp int
        fmt.Scanf("%d", &temp)
        arr[temp] += 1
    }

    for i := 1; i <= n; i++ { // Check each index i in the array arr and print "Yes" if the count is greater than q-k, otherwise print "No"
        if arr[i] > (q - k) {
            fmt.Println("Yes")
        } else {
            fmt.Println("No")
        }
    }
}

