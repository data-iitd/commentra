<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
    // Step 3: Declare variables to store input values
    var a, b, c, d, e, k int

    // Step 4: Read input values from the user
    fmt.Scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &k)

    // Step 5: Calculate the difference between e and a and check if it is less than or equal to k
<<<<<<< HEAD
    fmt.Println("Yay!" if e-a <= k else ":(")
=======
    if e-a <= k {
        fmt.Println("Yay!")
    } else {
        fmt.Println(":(")
    }
>>>>>>> 98c87cb78a (data updated)
}

