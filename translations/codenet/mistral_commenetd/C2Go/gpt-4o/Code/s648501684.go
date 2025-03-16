package main

import (
	"fmt"
)

func main() {
	var n, k, q int64 // Declare and initialize three long integers n, k, and q to read input values from the user

	fmt.Scanf("%d %d %d", &n, &k, &q) // Read the input values n, k, and q from the user using Scanf

	arr := make([]int64, n+1) // Declare an integer slice arr of size n+1

	for i := int64(0); i <= n; i++ { // Initialize the array arr with zeros using a for loop
		arr[i] = 0
	}

	for i := int64(0); i < q; i++ { // Read q query values from the user and increment the corresponding index in the array arr
		var temp int64
		fmt.Scanf("%d", &temp)
		arr[temp] += 1
	}

	for i := int64(1); i <= n; i++ { // Check each index i in the array arr and print "Yes" if the count is greater than q-k, otherwise print "No"
		if arr[i] > (q - k) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

// <END-OF-CODE>
