// Importing required libraries
import (
	"fmt"
	"math"
)

// Taking input of n and number of distinct numbers
var n, num int
fmt.Scan(&n, &num)

// Creating a set of distinct numbers
num_set := make(map[int]bool)
for i := 0; i < num; i++ {
	var temp int
	fmt.Scan(&temp)
	num_set[temp] = true
}

// Finding the powers of 2 that appear exactly twice in the binary representation of each number in num_set
two_times_set := make(map[int]bool)
for i := range num_set {
	// Initializing a counter to keep track of the number of times 2 is divided
	power_of_two := 0

	// Dividing i by 2 repeatedly until it is no longer odd
	for i%2 == 0 {
		power_of_two++
		i /= 2
	}

	// If the number of times 2 is divided is not exactly 1, then the answer is 0
	if power_of_two > 1 {
		fmt.Println(0)
		break
	}

	// Add the power of 2 to two_times_set
	two_times_set[power_of_two] = true
}

// If the size of two_times_set is not exactly 1, then the answer is 0
if len(two_times_set) != 1 {
	fmt.Println(0)
	return
}

// Finding the least common multiple of all numbers in num_set
num_list := make([]int, 0, len(num_set))
for i := range num_set {
	num_list = append(num_list, i)
}
lcm := num_list[0]

// Finding the least common multiple of the first number and the next number
for i := 1; i < len(num_list); i++ {
	lcm = lcm * num_list[i] / gcd(lcm, num_list[i])
}

// Printing the answer
fmt.Println((num - lcm/2) / lcm + 1)

// 