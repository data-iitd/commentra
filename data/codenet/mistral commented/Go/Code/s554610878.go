
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const (
	initialBufSize = 10000
	maxBufSize     = 1000000
)

// Initialize scanner
var (
	sc *bufio.Scanner = func() *bufio.Scanner {
		sc := bufio.NewScanner(os.Stdin)
		buf := make([]byte, initialBufSize)
		sc.Buffer(buf, maxBufSize)
		sc.Split(bufio.ScanWords)
		return sc
	}()
	mod int = 1e9 + 7
)

// Main function
func main() {
	// Initialize week array
	week := []string{ "SUN","MON","TUE","WED","THU","FRI","SAT" }

	// Read input string from scanner
	s := getString()

	// Find index of the given day in week array
	index := -1
	for i, day := range week {
		if s == day {
			index = i
			break
		}
	}

	// Print the result
	fmt.Println(7 - index)
}

// Function to read integer input from scanner
func getInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// Function to read string input from scanner
func getString() string {
	sc.Scan()
	return sc.Text()
}

// Function to calculate absolute value of a number
func abs(a int) int {
	return int(math.Abs(float64(a)))
}

// Function to calculate power of a number
func pow(p, q int) int {
	return int(math.Pow(float64(p), float64(q)))
}

// Function to find minimum of given numbers
func min(nums ...int) int {
	if len(nums) == 0 {
		panic("funciton min() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i])))
	}
	return res
}

// Function to find maximum of given numbers
func max(nums ...int) int {
	if len(nums) == 0 {
		panic("funciton max() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i])))
	}
	return res
}

// Function to check if a string is present in a slice of strings
func strSearch(a []string, b string) bool {
	for i := 0; i < len(a); i++ {
		if a[i] == b {
			return true
		}
	}
	return false
}

// Function to print an integer array
func printIntArray(array []int) {
	strArray := fmt.Sprint(array)
	fmt.Println(strArray[1 : len(strArray) - 1])
}

// Function to calculate modulo of a number
func calcMod(x int) int {
	return x % mod
}

// Function to read a single line of input as string
func getString() string {
	sc.Scan() // Read input string
	return sc.Text() // Return the input string
}

// Function to read a single line of input as integer
func getInt() int {
	str := getString() // Read input string
	i, err := strconv.Atoi(str) // Convert string to integer
	if err != nil { // If conversion fails, panic with error message
		panic(err)
	}
	return i // Return the integer value
}

// Main function
func main() {
	// Initialize week array with 7 days of the week
	week := []string{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}

	// Read input string from scanner
	s := getString()

	// Find index of the given day in week array
	index := -1
	for i, day := range week {
		if s == day {
			index = i
			break
		}
	}

	// If the given day is not present in the week array, panic with error message
	if index == -1 {
		panic("Invalid day of the week")
	}

	// Calculate the difference between the index of the given day and the index of Sunday
	// and print the result
	fmt.Println(7 - index)
}

// Function to calculate the absolute value of a number
func abs(num int) int {
	return math.Abs(float64(num))
}

// Function to calculate the power of a number
func pow(base, exp int) int {
	return int(math.Pow(float64(base), float64(exp)))
}

// Function to find the minimum of given numbers
func min(nums ...int) int {
	if len(nums) == 0 {
		panic("min() requires at least one argument")
	}
	min := nums[0]
	for _, num := range nums {
		if num < min {
			min = num
		}
	}
	return min
}

// Function to find the maximum of given numbers
func max(nums ...int) int {
	if len(nums) == 0 {
		panic("max() requires at least one argument")
	}
	max := nums[0]
	for _, num := range nums {
		if num > max {
			max = num
		}
	}
	return max
}

// Function to check if a string is present in a slice of strings
func strSearch(slice []string, str string) bool {
	for _, s := range slice {
		if s == str {
			return true
		}
	}
	return false
}

// Function to print an integer array
func printIntArray(array []int) {
	fmt.Println(array)
}

// Function to calculate the modulo of a number
func calcMod(num int) int {
	return num % mod
}

// Function to read a single line of input as string
func getString() string {
	sc.Scan()
	return sc.Text()
}

// Function to read a single line of input as integer
func getInt() int {
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return i
}

// Main function
func main() {
	// Initialize week array with 7 days of the week
	week := []string{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}

	// Read input string from scanner
	s := getString()

	// Find index of the given day in week array
	index := -1
	for i, day := range week {
		if day == s {
			index = i
			break
		}
	}

	// If the given day is not present in the week array, panic with error message
	if index == -1 {
		panic("Invalid day of the week")
	}

	// Calculate the number of days between the given day and Sunday
	// and print the result
	fmt.Println(7 - index)
}

// Function to calculate the absolute value of a number
func abs(num int) int {
	return math.Abs(float64(num))
}

// Function to calculate the power of a number
func pow(base, exp int) int {
	return int(math.Pow(float64(base), float64(exp)))
}

// Function to find the minimum of given numbers
func min(nums ...int) int {
	if len(nums) == 0 {
		panic("min() requires at least one argument")
	}
	min := nums[0]
	for _, num := range nums {
		if num < min {
			min = num
		}
	}
	return min
}

// Function to find the maximum of given numbers
func max(nums ...int) int {
	if len(nums) == 0 {
		panic("max() requires at least one argument")
	}
	max := nums[0]
	for _, num := range nums {
		if num > max {
			max = num
		}
	}
	return max
}

// Function to check if a string is present in a slice of strings
func strSearch(slice []string, str string) bool {
	for _, s := range slice {
		if s == str {
			return true
		}
	}
	return false
}

// Function to print an integer array
func printIntArray(array []int) {
	fmt.Println(array)
}

// Function to calculate the modulo of a number
func calcMod(num int) int {
	return num % mod
}

// Function to read a single line of input as string
func getString() string {
	sc.Scan()
	return sc.Text()
}

// Function to read a single line of input as integer
func getInt() int {
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return i
}

// Main function
func main() {
	// Initialize week array with 7 days of the week
	week := []string{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}

	// Read input string from scanner
	s := getString()

	// Find index of the given day in week array
	index := -1
	for i, day := range week {
		if day == s {
			index = i
			break
		}
	}

	// If the given day is not present in the week array, panic with error message
	if index == -1 {
		panic("Invalid day of the week")
	}

	// Calculate the number of days between the given day and Sunday
	// and print the result
	daysUntilSunday := 7 - index
	fmt.Println("The number of days until Sunday is:", daysUntilSunday)
}

// Function to calculate the absolute value of a number
func abs(num int) int {
	return math.Abs(float64(num))
}

// Function to calculate the power of a number
func pow(base, exp int) int {
	return int(math.Pow(float64(base), float64(exp)))
}

// Function to find the minimum of given numbers
func min(nums ...int) int {
	if len(nums) == 0 {
		panic("min() requires at least one argument")
	}
	min := nums[0]
	for _, num := range nums {
		if num < min {
			min = num
		}
	}
	return min
}

// Function to find the maximum of given numbers
func max(nums ...int) int {
	if len(nums) == 0 {
		panic("max() requires at least one argument")
	}
	max := nums[0]
	for _, num := range nums {
		if num > max {
			max = num
		}
	}
	return max
}

// Function to check if a string is present in a slice of strings
func strSearch(slice []string, str string) bool {
	for _, s := range slice {
		if s == str {
			return true
		}
	}
	return false
}

// Function to print an integer array
func printIntArray(array []int) {
	fmt.Println(array)
}

// Function to calculate the modulo of a number
func calcMod(num int) int {
	return num % mod
}

// Function to read a single line of input as string
func getString() string {
	sc.Scan()
	return sc.Text()
}

// Function to read a single line of input as integer
func getInt() int {
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return i
}

// Main function
func main() {
	// Initialize week array with 7 days of the week
	week := []string{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}

	// Read input string from scanner
	s := getString()

	// Find index of the given day in week array
	index := -1
	for i, day := range week {
		if day == s {
			index = i
			break
		}
	}

	// If the given day is not present in the week array, panic with error message
	if index == -1 {
		panic("Invalid day of the week")
	}

	// Calculate the number of days between the given day and Sunday
	// and print the result
	daysUntilSunday := 7 - index
	fmt.Println("The number of days until Sunday is:", daysUntilSunday)
}

// Function to calculate the absolute value of a number
func abs(num int) int {
	return math.Abs(float64(num))
}

// Function to calculate the power of a number
func pow(base, exp int) int {
	return int(math.Pow(float64(base), float64(exp)))
}

// Function to find the minimum of given numbers
func min(nums ...int) int {
	if len(nums) == 0 {
		panic("min() requires at least one argument")
	}
	min := num