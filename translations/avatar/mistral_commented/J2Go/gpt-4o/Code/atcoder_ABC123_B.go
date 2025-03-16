package main

import (
	"fmt"
	"sort"
)

func main() {
	var a [5]int // Creating an integer array 'a' of size 5
	var r [5]int // Creating an integer array 'r' of size 5
	mapData := make(map[int]int) // Creating an empty map to store integer keys and their corresponding integer values

	// Reading input elements of array 'a' and storing their remainders in array 'r'
	for i := 0; i < len(a); i++ {
		fmt.Scan(&a[i]) // Reading an integer value from the console and storing it in the 'i'th index of array 'a'
		r[i] = a[i] % 10 // Calculating the remainder of the 'i'th element of array 'a' and storing it in the 'i'th index of array 'r'

		b := 10 // Initializing 'b' to 10
		if r[i] != 0 { // Checking if the remainder of the 'i'th element of array 'a' is not zero
			b = 10 - r[i] // Calculating the complement of the remainder and assigning it to 'b'
			mapData[b] = a[i] // Storing the complement as a key and the corresponding integer value (the 'i'th element of array 'a') in the map
		}
	}

	ans := 0 // Initializing 'ans' to zero

	// Checking if the map is empty
	if len(mapData) == 0 {
		for i := 0; i < len(a); i++ { // Iterating through the array 'a'
			ans += a[i] // Adding the 'i'th element of array 'a' to the sum 'ans'
		}
		fmt.Println(ans) // Printing the sum of all elements in array 'a'
		return // Exiting the method if the map is empty
	}

	// Getting the last key (complement) from the map
	var last int
	keys := make([]int, 0, len(mapData))
	for k := range mapData {
		keys = append(keys, k)
	}
	sort.Ints(keys) // Sorting the keys
	last = mapData[keys[len(keys)-1]] // Finding its corresponding value (the last element of array 'a')

	idx := 0 // Initializing 'idx' to zero

	// Finding the index of the last element in array 'a'
	for i := 0; i < len(a); i++ {
		if a[i] == last { // Checking if the 'i'th element of array 'a' is equal to the last element
			idx = i // If true, assigning the index to 'idx'
			break // Exiting the loop
		}
	}

	// Calculating the sum of all elements in array 'a' except the last one
	for i := 0; i < len(a); i++ {
		if i != idx { // Checking if the current index is not equal to 'idx'
			if a[i]%10 == 0 { // Checking if the 'i'th element of array 'a' is a multiple of 10
				ans += a[i] // If true, adding it to the sum 'ans'
			} else { // If the 'i'th element of array 'a' is not a multiple of 10
				ans += a[i] + (10 - r[i]) // Adding the 'i'th element of array 'a' and its complement to the sum 'ans'
			}
		}
	}

	// Adding the last element of array 'a' to the sum 'ans'
	ans += last

	fmt.Println(ans) // Printing the final sum
}

// <END-OF-CODE>
