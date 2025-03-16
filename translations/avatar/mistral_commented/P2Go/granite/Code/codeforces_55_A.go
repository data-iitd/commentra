

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)  // Read an integer from the user

    for n%2 == 0 {  // While n is even
        n /= 2  // Divide n by 2 to remove the last even factor
    }

    if n == 1 {  // If n is now 1
        fmt.Println("YES")  // Print 'YES'
    } else {  // Otherwise
        fmt.Println("NO")  // Print 'NO'
    }
}

