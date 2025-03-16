package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a new Scanner to read input from the standard input
	scn := bufio.NewScanner(os.Stdin)

	// Read the first integer n representing the size of the array
	scn.Scan()
	n, _ := strconv.Atoi(scn.Text())

	// Create an integer array arr of size n
	arr := make([]int, n)

	// Use a for loop to read n integers from the standard input and store them in the array arr
	for i := 0; i < n; i++ {
		scn.Scan()
		arr[i], _ = strconv.Atoi(scn.Text()) // Read the next integer and store it in the current index of the array
	}

	// Initialize a variable ans with the first element of the array and add 1 to it
	ans := arr[0] + 1

	// Use another for loop to iterate through the remaining elements of the array arr
	for i := 1; i < n; i++ {
		// Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
		ans += int(math.Abs(float64(arr[i] - arr[i-1]))) + 2
	}

	// Finally, print the value of ans to the standard output
	fmt.Println(ans)
}
