// Package main
// Imports
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to find the solution
func solve(N int, x []int, y []int) {
	// Initialize an empty list to store distances
	distances := []float64{}

	// Generate all possible permutations of indices from 0 to N-1
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}
	permutations := generatePermutations(indices)

	// For each permutation, calculate the total distance between adjacent points
	for permutation := range permutations {
		totalDistance := 0.0
		for i := 0; i < N-1; i++ {
			// Get the first and second indices of the current pair
			f, t := permutation[i], permutation[i+1]
			// Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
			distance := math.Sqrt(math.Pow(float64(x[t]-x[f]), 2) + math.Pow(float64(y[t]-y[f]), 2))
			// Add the distance to the total distance
			totalDistance += distance
		}
		// Append the total distance to the distances list
		distances = append(distances, totalDistance)
	}

	// Calculate the average distance from all permutations
	result := sum(distances) / float64(len(distances))

	// Print the result
	fmt.Printf("%.2f\n", result)
}

// Function to generate all permutations of a given array
func generatePermutations(arr []int) chan []int {
	// Initialize a channel to store permutations
	permutations := make(chan []int)

	// Function to generate permutations
	var generate func(arr []int, n int)
	generate = func(arr []int, n int) {
		// If the permutation is done, send it to the channel
		if n == len(arr) {
			permutations <- arr
			return
		}

		// Iterate over all indices
		for i := 0; i < n; i++ {
			// Swap the elements at indices i and n
			arr[i], arr[n] = arr[n], arr[i]
			// Generate the next permutation
			generate(arr, n+1)
			// Backtrack
			arr[i], arr[n] = arr[n], arr[i]
		}
	}

	// Start generating permutations
	go generate(arr, 0)

	// Return the channel
	return permutations
}

// Function to calculate the sum of all elements in an array
func sum(arr []float64) float64 {
	// Initialize a variable to store the sum
	sum := 0.0
	// Iterate over all elements
	for _, element := range arr {
		// Add the element to the sum
		sum += element
	}
	// Return the sum
	return sum
}

// Main function to read input and call the solve function
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if the script is executed directly
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if the script is executed directly
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if the script is executed directly
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if the script is executed directly
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if the script is executed directly
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if the script is executed directly
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if the script is executed directly
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if the script is executed directly
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if the script is executed directly
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if the script is executed directly
func main() {
	// Read the number of points and their coordinates from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// Function to read a line from the given reader
func readLine(reader *bufio.Reader) string {
	// Read a line
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

// Run the main function if 