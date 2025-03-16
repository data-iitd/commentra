// Read N and X from input
var N, X int
fmt.Scanf("%d %d", &N, &X)

// Import the permutations function from itertools
import "itertools"

// Define the calc function which processes a list x
func calc(x []int) int {
	// Define a nested sub function within calc for further processing
	func sub(y []int, debug int) int {
		// Print the current state of y if debug mode is on
		if debug > 0 {
			fmt.Println("D", y)
		}
		// Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
		for len(y) > 1 {
			y = []int{sorted(y[i:i+3])[1] for i := range len(y)-2}
			// Print the current state of y if debug mode is on
			if debug > 0 {
				fmt.Println("D", y)
			}
		}
		// Return the final single element of y
		return y[0]
	}
	// Process the input list x using sub function
	y := sub(x)
	// Check if the final element of y is 2
	if y[0] == 2 {
		// Call sub again with debug mode on and print the result
		sub(x, 1)
		fmt.Println("=", x)
	}
	// Return the first element of the final y
	return y[0]
}

// Check if X is 1 or N * 2 - 1, print "No" if true
if X == 1 || X == N*2-1 {
	fmt.Println("No")
} else {
	// Print "Yes" if X is not 1 or N * 2 - 1
	fmt.Println("Yes")
	// Construct the list xs based on the value of X
	if X == N*2-2 {
		xs := []int{i for i := range N-1 : X+2}
		xs = append(xs, []int{i for i := range 1 : N-1}...)
	} else {
		ys := []int{i for i := range 1 : X-1}
		ys = append(ys, []int{X+3, X-1, X, X+1}...)
		xs := ys[:N-3]
		xs = append(xs, []int{X+2, X-1, X, X+1}...)
		xs = append(xs, ys[N-3:]...)
	}
	// Print each element of xs
	for _, x := range xs {
		fmt.Println(x)
	}
}

