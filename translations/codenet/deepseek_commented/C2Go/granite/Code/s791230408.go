
package main

import "fmt"

func main() {
	var j, a, b, c, max, k int

	// Step 1: Read the number of test cases (j) from the user input.
	fmt.Scan(&j)

	for i := 0; i < j; i++ {
		// Step 3: For each test case, read three integers (a, b, c).
		fmt.Scan(&a)
		fmt.Scan(&b)
		fmt.Scan(&c)

		// Step 4: Determine the maximum of the three integers.
		max = a
		k = 0
		if max <= b {
			max = b
			k = 1
		}
		if max <= c {
			max = c
			k = 2
		}

		// Step 5: Calculate the square of the maximum and the squares of a, b, and c.
		max = max * max
		a = a * a
		b = b * b
		c = c * c

		// Step 6: Check if the square of the maximum is equal to the sum of the squares of the other two integers.
		if k == 0 && max == b+c {
			fmt.Println("YES")
		} else if k == 1 && max == a+c {
			fmt.Println("YES")
		} else if k == 2 && max == a+b {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

