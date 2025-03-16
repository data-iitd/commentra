package main

import (
	"fmt"
	"math"
	"strings"
)

const INF = 0x5fffffff // Define a constant for infinity

func getInt(p *string) (int, *string) {
	n := 0 // Initialize the integer to store the result
	if (*p)[0] == '-' {
		*p = (*p)[1:] // Move to the next character
		for len(*p) > 0 && (*p)[0] >= '0' && (*p)[0] <= '9' {
			n = (n << 3) + (n << 1) + int((*p)[0]-'0') // Convert characters to integer
			*p = (*p)[1:] // Move to the next character
		}
		return -n, p // Return the negative integer
	}
	for len(*p) > 0 && (*p)[0] >= '0' && (*p)[0] <= '9' {
		n = (n << 3) + (n << 1) + int((*p)[0]-'0') // Convert characters to integer
		*p = (*p)[1:] // Move to the next character
	}
	return n, p // Return the positive integer
}

func main() {
	var w, k, f, close, ans int
	a := make([]int, 100002) // Array to hold the values of the evacuation route
	b := make([]int, 100002) // Array to hold the computed values for the evacuation route

	var buf string
	fmt.Scanln(&buf) // Read the width of the evacuation route
	p := strings.TrimSpace(buf)
	w, p = getInt(&p)

	fmt.Scanln(&buf) // Read the evacuation route values
	p = strings.TrimSpace(buf)

	ans = 0
	f = 0
	for i := 1; i <= w; i++ {
		k, p = getInt(&p) // Read the next integer into array a
		a[i] = k
		if k == 0 {
			f |= 1 // Set flag if value is zero
		} else if k < 0 {
			f |= 2 // Set flag if value is negative
		} else {
			ans += k // Accumulate positive values into ans
		}
	}

	// Check for special cases: no positive values or only zeros
	if ans == 0 || (f&1) == 0 {
		fmt.Println("0")
		return
	}
	// If there are no negative values, print the total sum
	if (f&2) == 0 {
		fmt.Println(ans)
		return
	}

	// Calculate the minimum distance to the closest zero from the left
	close = 0
	f = 0
	for i := 1; i <= w; i++ {
		if a[i] == 0 {
			close = INF
			f = -1 // Reset close distance if zero is found
		} else if a[i] < 0 {
			if f < 0 || close-(i-f) > -a[i] {
				close = -a[i]
				f = i // Update close distance if a negative value is found
			}
		} else {
			if f < 0 {
				b[i] = INF // If no zero found, set to infinity
			} else {
				k = close - (i - f)
				if k < 0 {
					k = 0 // Calculate distance
				}
				b[i] = k // Store the distance in array b
			}
		}
	}

	// Calculate the minimum distance to the closest zero from the right
	close = 0
	f = w
	for i := w; i >= 1; i-- {
		if a[i] == 0 {
			close = INF
			f = -1 // Reset close distance if zero is found
		} else if a[i] < 0 {
			if f < 0 || close-(f-i) > -a[i] {
				close = -a[i]
				f = i // Update close distance if a negative value is found
			}
		} else {
			if f < 0 {
				b[i] = INF // If no zero found, set to infinity
			} else {
				k = close - (f - i)
				if k < 0 {
					k = 0 // Calculate distance
				}
				if k > b[i] {
					b[i] = k // Update if the new distance is smaller
				}
			}
		}
	}

	// Calculate the final answer based on the minimum distances
	ans = 0
	for i := 1; i <= w; i++ {
		if a[i] > 0 {
			if b[i] > a[i] {
				ans += a[i]
			} else {
				ans += b[i]
			}
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
