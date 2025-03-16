package main

import "fmt"

func main() {
	var n int // Declare an integer variable 'n' to store the number of elements
	var l [2001]int // Declare an integer array 'l' of size 2001
	var i, j, k, cnt, tmp int // Declare integer variables 'i', 'j', 'k', 'cnt', and 'tmp' for loop indices

	fmt.Scan(&n) // Read an integer value from the standard input and store it in 'n'

	for i = 0; i < n; i++ { // Iterate through all elements of the array 'l'
		fmt.Scan(&l[i]) // Read an integer value from the standard input and store it in the current index of 'l'
	}

	for i = 0; i < n-1; i++ { // Iterate through all elements except the last one in the array 'l'
		for j = i + 1; j < n; j++ { // Iterate through the remaining elements
			if l[j] < l[i] { // If the current element is smaller than the previous one
				tmp = l[i] // Swap the current and previous elements
				l[i] = l[j]
				l[j] = tmp // Update the array 'l' with the swapped elements
			}
		}
	}

	for i = 0; i < n-2; i++ { // Iterate through all elements except the last two in the array 'l'
		for j = i + 1; j < n-1; j++ { // Iterate through the remaining elements except the last one
			for k = j + 1; k < n; k++ { // Iterate through the remaining elements
				if l[i]+l[j] > l[k] { // Check if the sum of the first two elements is greater than the third one
					cnt++ // Increment the counter if the condition is true
				} else { // If the condition is false, break out of the inner loop
					break
				}
			}
		}
	}

	fmt.Println(cnt) // Print the value of the counter to the standard output
}

