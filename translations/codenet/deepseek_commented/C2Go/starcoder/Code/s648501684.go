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
	// Declare variables to store the input values
<<<<<<< HEAD
	var n, k, q int64
=======
	var n, k, q int
>>>>>>> 98c87cb78a (data updated)

	// Read three long integers from the standard input
	fmt.Scanf("%d %d %d", &n, &k, &q)

	// Declare an array of size n initialized to 0
<<<<<<< HEAD
	arr := make([]int64, n)
	for i := int64(0); i <= n; i++ {
=======
	arr := make([]int, n)
	for i := 0; i <= n; i++ {
>>>>>>> 98c87cb78a (data updated)
		arr[i] = 0 // Initialize each element to 0
	}

	// Read q integers and increment the corresponding index in the array arr
<<<<<<< HEAD
	for i := int64(0); i < q; i++ {
		var temp int64
=======
	for i := 0; i < q; i++ {
		var temp int
>>>>>>> 98c87cb78a (data updated)
		fmt.Scanf("%d", &temp)
		arr[temp] += 1
	}

	// Check if the value at each index in arr is greater than q-k
<<<<<<< HEAD
	for i := int64(1); i <= n; i++ {
=======
	for i := 1; i <= n; i++ {
>>>>>>> 98c87cb78a (data updated)
		if arr[i] > (q - k) {
			fmt.Println("Yes") // Print "Yes" if the condition is met
		} else {
			fmt.Println("No") // Print "No" otherwise
		}
	}
}

