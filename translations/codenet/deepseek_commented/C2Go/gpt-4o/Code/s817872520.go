package main

import (
	"fmt"
	"math"
	"strings"
)

const INF = 0x5fffffff // Define the maximum possible integer value

func getInt(p *string) (int, *string) {
	n := 0
	if (*p)[0] == '-' { // Check if the number is negative
		*p = (*p)[1:] // Move the pointer forward
		for (*p)[0] >= '0' && (*p)[0] <= '9' {
			n = (n << 3) + (n << 1) + int((*p)[0]-'0')
			*p = (*p)[1:] // Move the pointer forward
		}
		return -n, p
	}
	for (*p)[0] >= '0' && (*p)[0] <= '9' {
		n = (n << 3) + (n << 1) + int((*p)[0]-'0')
		*p = (*p)[1:] // Move the pointer forward
	}
	return n, p
}

func main() {
	var w, i, k, f, close, ans int
	var a [100002]int
	var b [100002]int

	var buf string
	fmt.Scanln(&buf) // Read the width of the array
	p := strings.TrimSpace(buf)
	w, p = getInt(&p)

	fmt.Scanln(&buf) // Read the input line into the buffer
	p = strings.TrimSpace(buf)

	f = 0
	ans = 0
	for i = 1; i <= w; i++ {
		k, p = getInt(&p)
		a[i] = k
		if k == 0 {
			f |= 1 // Set flag if zero is found
		} else if k < 0 {
			f |= 2 // Set flag if negative number is found
		} else {
			ans += k // Add to the sum if positive number
		}
	}

	if ans == 0 || (f&1) == 0 {
		fmt.Println("0")
		return
	}
	if (f & 2) == 0 {
		fmt.Println(ans)
		return
	}

	// Calculate the minimum evacuation routes
	for close = 0; i <= w; i++ { // First pass from left to right
		if a[i] == 0 {
			close = INF
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close-(i-f) > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			if f < 0 {
				b[i] = INF
			} else {
				k = close - (i - f)
				if k < 0 {
					k = 0
				}
				b[i] = k
			}
		}
	}

	for close = 0; i >= 1; i-- { // Second pass from right to left
		if a[i] == 0 {
			close = INF
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close-(f-i) > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			if f < 0 {
				b[i] = INF
			} else {
				k = close - (f - i)
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

// <END-OF-CODE>
