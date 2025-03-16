
package main

import "fmt"

func main() {
    var x, t, a, b, da, db int
    fmt.Scan(&x, &t, &a, &b, &da, &db)

    // Define the main function to perform the logic
    func main() {
        // Check if the value of x is 0
        if x == 0 {
            fmt.Println("YES")
            return "Result Found"
        }

        // Calculate the maximum number of times a and b can be decremented within the time limit t
        a_time := min(a/da, t-1)
        b_time := min(b/db, t-1)

        // Iterate over all possible combinations of decrements for a and b within their respective limits
        for i := 0; i <= a_time; i++ {
            for j := 0; j <= b_time; j++ {
                // Check if either a or b (or their sum) equals x
                if a-da*i == x || b-db*j == x {
                    fmt.Println("YES")
                    return "Result Found"
                }
                if (a-da*i)+(b-db*j) == x {
                    fmt.Println("YES")
                    return "Result Found"
                }
            }
        }

        // Return "Result Not Found" if no combination results in x
        return "Result Not Found"
    }

    // Call the main function and store the result
    ff := main()

    // Check the result and print "NO" if the result is "Result Not Found"
    if ff == "Result Not Found" {
        fmt.Println("NO")
    }
}

// Define the min function to return the minimum of two integers
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

// End of code
