// Importing the fmt and strconv packages
import (
	"fmt"
	"strconv"
)

// Assigning the stdin readline function to a variable named input
input := func() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Reading the first line of input and storing the number of test cases and the target sum in variables n and s
n, _ := strconv.Atoi(input())
s, _ := strconv.Atoi(input())

// Initializing a variable c to 0
c := 0

// Iterating through the test cases using a for loop
for i := 0; i < n; i++ {
	// Reading the start and end time of each activity from the input
	f, _ := strconv.Atoi(input())
	t, _ := strconv.Atoi(input())

	// Calculating the difference between the end time and the difference between the target sum and start time
	x := t - (s - f)

	// Updating the variable c with the maximum value of x calculated in the current iteration
	if x > c {
		c = x
	}
}

// Printing the final answer which is the sum of the target sum and the maximum overlap calculated
fmt.Println(s + c)

