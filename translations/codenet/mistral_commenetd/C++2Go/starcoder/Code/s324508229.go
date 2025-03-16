
<<<<<<< HEAD

import (
	"fmt"
	"math"
)

// Function to calculate the count of numbers with 'a' as the last digit and 'b' as the digit before last
func count(a, b int) int {
	return int(math.Ceil(float64(a) / float64(10))) * int(math.Ceil(float64(b) / float64(10)))
}

// Function to calculate the answer
func answer(n int) int {
	// Initialize answer variable with zero
	ans := 0

	// Iterate through each row and column from 1 to 9
	for i := 1; i <= 9; i++ {
		for j := 1; j <= 9; j++ {
			// Multiply the count of 'i'th row and 'j'th column with the count of 'j'th row and 'i'th column
			// and add it to the answer
			ans += count(i, j) * count(j, i)
		}
	}

	// Return the final answer
	return ans
}

// Main function
func main() {
	var n int
	fmt.Scanf("%d", &n)
	fmt.Printf("%d\n", answer(n))
=======
package main

import (
    "fmt"
    "math"
)

// Function to count the number of times a number 'i' has the same digit before last and last digit
func count(i int) (int, int) {
    // Extract the last digit 'b' and the digit before last 'a' from the number 'i'
    b := i % 10
    a := i

    // While 'a' has more digits than one, extract the digit before last one
    for a >= 10 {
        a /= 10
    }

    // Return the count of 'a'th row and 'b'th column
    return a, b
}

// Function to count the number of times a number 'i' has the same digit before last and last digit
func main() {
    var n, i, a, b int
    var cnt [10][10]int

    // Read the number of test cases
    fmt.Scanf("%d", &n)

    // Iterate through each number from 1 to n
    for i = 1; i <= n; i++ {
        // Extract the last digit 'b' and the digit before last 'a' from the number 'i'
        a, b = count(i)

        // Increment the count of 'a'th row and 'b'th column in the 'cnt' array
        cnt[a][b]++
    }

    // Initialize answer variable 'ans' with zero
    ans := 0

    // Iterate through each row and column from 1 to 9
    for i = 1; i <= 9; i++ {
        for j := 1; j <= 9; j++ {
            // Multiply the count of 'i'th row and 'j'th column with the count of 'j'th row and 'i'th column
            // and add it to the answer
            ans += cnt[i][j] * cnt[j][i]
        }
    }

    // Print the final answer
    fmt.Printf("%d\n", ans)
>>>>>>> 98c87cb78a (data updated)
}

