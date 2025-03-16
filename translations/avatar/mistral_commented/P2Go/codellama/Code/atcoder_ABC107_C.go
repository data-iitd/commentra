// Importing the fmt module for formatting the output
import "fmt"

// Taking the number of elements N and the number of queries K as input
var N, K int
fmt.Scan(&N, &K)

// Creating an empty list to store positive numbers and another empty list to store negative numbers
var lst []int
var lst_p []int
var lst_m []int

// Iterating through the list to find positive and negative numbers
for i := 0; i < N; i++ {
	// If the number is zero, decrement the number of queries K
	if lst[i] == 0 {
		K--
	}
	// If the number is positive, add it to the list of positive numbers
	if lst[i] > 0 {
		lst_p = append(lst_p, lst[i])
	}
	// If the number is negative, add it to the list of negative numbers
	if lst[i] < 0 {
		lst_m = append(lst_m, lst[i])
	}
}

// Initializing variables p and m to 0 and setting the initial values of x and y
var p, m, x, y int
lastx := len(lst_p)
lasty := len(lst_m)

// Function to check the minimum number of moves required to make the sum of the first k elements equal to or less than 0
func check(k int) int {
	// Initializing the answer as a large number
	ans := 1000000000

	// Iterating through all possible combinations of taking elements from positive and negative lists
	for j := 0; j <= k; j++ {
		// If the index j is greater than the length of the list of positive numbers or if the number of elements to be taken from negative list is greater than the number of negative elements, then skip this iteration
		if j > lastx || k-j > lasty {
			continue
		}

		// If j is 0, then p is initialized to 0
		if j == 0 {
			p = 0
		}
		// If j is not 0, then p is the last element of the list of positive numbers
		else {
			p = lst_p[j-1]
		}

		// If k - j is 0, then m is initialized to 0
		if k-j == 0 {
			m = 0
		}
		// If k - j is not 0, then m is the last element of the list of negative numbers
		else {
			m = lst_m[lasty-(k-j)]
		}

		// Updating the answer with the minimum of the current answer and the sum of the absolute difference of p and m and the sum of p and m
		ans = min(ans, 2*p+abs(m), p+2*abs(m))
	}

	// Returning the answer
	return ans
}

// Printing the minimum number of moves required to make the sum of the first K elements equal to or less than 0
fmt.Println(check(K))

// END-OF-CODE
