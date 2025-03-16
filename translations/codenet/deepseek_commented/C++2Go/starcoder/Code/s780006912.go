<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Declare the necessary variables.
	// We need to declare a variable to store the number of elements in the array and an array to store the elements.
	var n int
	var array [100]int

	// Step 2: Read the number of elements and the elements of the array.
	// We need to read the number of elements from the user and then read the elements of the array from the user.
<<<<<<< HEAD
	fmt.Scanf("%d\n", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d\n", &array[i])
=======
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &array[i])
>>>>>>> 98c87cb78a (data updated)
	}

	// Step 3: Calculate the sum of the products of all pairs of elements in the array.
	// We need to use nested loops to iterate through all pairs of elements in the array and calculate their products.
	var sum int
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			sum += array[i] * array[j]
		}
	}

	// Step 4: Print the result.
	// Finally, we need to print the calculated sum.
<<<<<<< HEAD
	fmt.Printf("%d\n", sum)
=======
	fmt.Println(sum)
>>>>>>> 98c87cb78a (data updated)
}

