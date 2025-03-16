
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
"fmt"
"os"
"strconv"
)

func main() {
// Function main starts the execution of the program
var i, n, tmp int
var min, max, sum int64

fmt.Scanf("%d", &n)
// Read the number of integers to be entered from the user
fmt.Println("Enter the number of integers: ")
for i = 0; i < n; i++ {
// Use a for loop to read and process each integer
fmt.Scanf("%d", &tmp)
// Read the next integer from the user and store it in variable tmp
if min > tmp {
min = tmp
}
// If the current integer is smaller than the current minimum, update the minimum
if max < tmp {
max = tmp
}
// If the current integer is larger than the current maximum, update the maximum
sum += tmp
// Add the current integer to the sum
}

fmt.Printf("%d %d %d\n", min, max, sum)
// Print the minimum, maximum, and sum of the entered integers
}

