<<<<<<< HEAD

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare integer variables to store input values and intermediate results
    var a, b, c, d, i, j int

    // Read four integers from the user
    fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)

    // Perform multiplication operations and store the results in i and j
    i = a * b
    j = c * d

    // Use an if-else statement to compare the results and print the larger one
    if i > j {
        fmt.Println(i)
    } else {
        fmt.Println(j)
    }
}

=======
package main

import "fmt"

func main() {
	var a, b, c, d, i, j int
	fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)
	i = a * b
	j = c * d
	if i > j {
		fmt.Println(i)
	} else {
		fmt.Println(j)
	}
}
>>>>>>> 98c87cb78a (data updated)
