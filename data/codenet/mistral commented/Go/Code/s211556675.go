// I/O
type Scanner struct {
	sc *bufio.Scanner
}

// NewScanner initializes a new Scanner struct with a bufio.Scanner and sets its properties
func NewScanner() *Scanner {
	sc := bufio.NewScanner(os.Stdin) // Create a new bufio.Scanner from os.Stdin
	sc.Split(bufio.ScanWords)        // Set the scanner to split input into words
	sc.Buffer(make([]byte, 1024), int(1e+9)) // Set the buffer size for efficient reading
	return &Scanner{sc}               // Return a pointer to the newly created Scanner struct
}

// (s *Scanner) nextStr reads a single word as a string from the input
func (s *Scanner) nextStr() string {
	s.sc.Scan() // Read the next token from the input
	return s.sc.Text() // Return the token as a string
}

// (s *Scanner) nextInt reads a single integer from the input
func (s *Scanner) nextInt() int {
	i, _ := strconv.Atoi(s.nextStr()) // Convert the next string to an integer
	return i                          // Return the integer value
}

// (s *Scanner) nextFloat reads a single floating-point number from the input
func (s *Scanner) nextFloat() float64 {
	f, _ := strconv.ParseFloat(s.nextStr(), 64) // Convert the next string to a floating-point number
	return f                                    // Return the floating-point value
}

// (s *Scanner) nextRuneSlice reads a slice of runes from the input
func (s *Scanner) nextRuneSlice() []rune {
	return []rune(s.nextStr()) // Convert the next string to a slice of runes and return it
}

// (s *Scanner) nextIntSlice reads a slice of integers from the input with a given length
func (s *Scanner) nextIntSlice(n int) []int {
	res := make([]int, n) // Create a slice of integers with the given length
	for i := 0; i < n; i++ {
		res[i] = s.nextInt() // Read and assign the next integer to the current index in the slice
	}
	return res // Return the slice of integers
}

// (s *Scanner) nextFloatSlice reads a slice of floating-point numbers from the input with a given length
func (s *Scanner) nextFloatSlice(n int) []float64 {
	res := make([]float64, n) // Create a slice of floating-point numbers with the given length
	for i := 0; i < n; i++ {
		res[i] = s.nextFloat() // Read and assign the next floating-point number to the current index in the slice
	}
	return res // Return the slice of floating-point numbers
}

// Arithmetic
func max(nums ...int) int {
	m := nums[0] // Initialize the maximum value with the first number
	for _, i := range nums { // Iterate through the rest of the numbers
		if m < i { // If the current number is greater than the maximum value
			m = i // Update the maximum value
		}
	}
	return m // Return the maximum value
}

func min(nums ...int) int {
	m := nums[0] // Initialize the minimum value with the first number
	for _, i := range nums { // Iterate through the rest of the numbers
		if m > i { // If the current number is smaller than the minimum value
			m = i // Update the minimum value
		}
	}
	return m // Return the minimum value
}

func abs(x int) int {
	if x > 0 { // If the number is positive
		return x // Return the number as is
	}
	return -x // If the number is negative, return its negation
}

func pow(x, y int) int {
	res := 1 // Initialize the result to 1
	for i := 0; i < y; i++ { // Iterate y times
		res *= x // Multiply the result by x
	}
	return res // Return the result
}

// Sort
type Val struct {
	id, num int
}
type ByNum []Val

// ByNum is a type alias for a slice of Val structs, used for sorting

func (a ByNum) Len() int { return len(a) } // Len method for interface slice
func (a ByNum) Less(i, j int) bool { // Less method for sorting based on the num field
	return a[i].num < a[j].num
}
func (a ByNum) Swap(i, j int) { // Swap method for swapping elements in the slice
	a[i], a[j] = a[j], a[i]
}

// Main function
func main() {
	sc := NewScanner() // Initialize a new Scanner
	wtr := bufio.NewWriter(os.Stdout) // Initialize a new bufio.Writer for output

	// Read input values
	A, B, C, K := sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt()

	// Find the maximum value among A, B, and C
	ma := max(A, B, C)

	// Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
	rest := 0
	if ma == A {
		rest += B + C
	} else if ma == B {
		rest += A + C
	} else {
		rest += A + B
	}

	// Calculate the final answer
	answer := pow(ma, K) + rest

	// Write the answer to the output
	fmt.Fprintln(wtr, answer)
	wtr.Flush() // Flush the buffer to write the output
}

// 