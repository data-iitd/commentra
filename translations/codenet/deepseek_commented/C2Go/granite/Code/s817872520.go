
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	INF = 0x5fffffff // Define the maximum possible integer value
)

func main() {
	var w, i, k, f, close, ans int // Declare variables to store input, indices, and results
	var a, b []int // Declare arrays 'a' and 'b' to store integers

	reader := bufio.NewReader(os.Stdin) // Create a buffer reader for input
	fmt.Fscanf(reader, "%d\n", &w) // Read the width of the array and store it in 'w'
	a = make([]int, w+1) // Initialize array 'a' with size 'w+1'
	b = make([]int, w+1) // Initialize array 'b' with size 'w+1'
	for ans = 0, f = 0, i = 1; i <= w; i++ { // Initialize variables and start parsing the input
		fmt.Fscanf(reader, "%d", &a[i]) // Read the next integer and store it in 'a[i]'
		if a[i] == 0 {
			f |= 1 // Set flag if zero is found
		} else if a[i] < 0 {
			f |= 2 // Set flag if negative number is found
		} else {
			ans += a[i] // Add to the sum if positive number
		}
	}
	if ans == 0 || (f&1) == 0 { // If no positive numbers or zero found, output 0
		fmt.Println(0)
		return
	}
	if (f & 2) == 0 { // If no negative numbers, output the sum of positive numbers
		fmt.Println(ans)
		return
	}

	// Calculate the minimum evacuation routes
	for close = 0, f = 0, i = 1; i <= w; i++ { // First pass from left to right
		if a[i] == 0 {
			close = INF
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close-i+f > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			if f < 0 {
				b[i] = INF // If no negative number found yet, set to INF
			} else {
				k = close - i + f
				if k < 0 {
					k = 0
				}
				b[i] = k
			}
		}
	}

	for close = 0, f = w, i = w; i >= 1; i-- { // Second pass from right to left
		if a[i] == 0 {
			close = INF
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close+i-f > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			if f < 0 {
				b[i] = INF // If no negative number found yet, set to INF
			} else {
				k = close + i - f
				if k < 0 {
					k = 0
				}
				if k > b[i] {
					b[i] = k
				}
			}
		}
	}

	for ans = 0, i = 1; i <= w; i++ { // Calculate the total evacuation route
		if a[i] > 0 {
			if b[i] > a[i] {
				ans += a[i] // Add the minimum of b[i] and a[i]
			} else {
				ans += b[i]
			}
		}
	}
	fmt.Println(ans) // Output the final result
}

