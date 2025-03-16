// main function is the entry point of our program
func main() {
	// Initialize a new FastScanner object called fsc
	fsc := NewFastScanner()

	// Read the first three integers A, B, and C from the standard input
	A, B, C := fsc.NextInt(), fsc.NextInt(), fsc.NextInt()

	// Check if the difference between B and A is equal to the difference between C and B
	if B-A == C-B {
		// If it is, print "YES"
		fmt.Println("YES")
	} else {
		// Otherwise, print "NO"
		fmt.Println("NO")
	}
}

// FastScanner struct and methods for reading input efficiently
type FastScanner struct {
	r   *bufio.Reader
	buf []byte
	p   int
}

func NewFastScanner() *FastScanner {
	// Initialize a new bufio.Reader with a buffer size of 1024 bytes
	rdr := bufio.NewReaderSize(os.Stdin, 1024)
	// Initialize a new FastScanner object with the reader
	return &FastScanner{r: rdr}
}

func (s *FastScanner) Next() string {
	// Preprocess the input buffer if necessary
	s.pre()

	// Find the start index of the next token
	start := s.p
	// Find the end index of the next token (space or newline character)
	for s.p < len(s.buf) {
		if s.buf[s.p] == ' ' {
			break
		}
		s.p++
	}

	// Return the substring of the input buffer from the start index to the current position
	result := string(s.buf[start:s.p])
	// Move the position index to the next character
	s.p++

	// Return the result
	return result
}

func (s *FastScanner) NextLine() string {
	// Preprocess the input buffer if necessary
	s.pre()

	// Find the start index of the next line
	start := s.p
	// Read the rest of the line into the buffer
	s.p = len(s.buf)

	// Return the substring of the input buffer from the start index to the end of the line
	return string(s.buf[start:])
}

func (s *FastScanner) NextInt() int {
	// Read a string token as an integer
	token := s.Next()
	// Convert the string token to an integer and return it
	num, _ := strconv.Atoi(token)
	return num
}

func (s *FastScanner) pre() {
	// If the position index is at the end of the buffer, read a new line
	if s.p >= len(s.buf) {
		s.readLine()
		s.p = 0
	}
}

func (s *FastScanner) readLine() {
	// Read a line from the input buffer into a temporary byte slice
	line, _ := s.r.ReadLine()
	// Copy the temporary byte slice to the FastScanner's buffer
	s.buf = append(s.buf, line...)
}

// Helper functions for finding the maximum and minimum values
func IntMax(a, b int) int {
	// Return the larger of the two integers
	if a < b {
		return b
	}
	return a
}

func Int64Max(a, b int64) int64 {
	// Return the larger of the two integers
	if a < b {
		return b
	}
	return a
}

func Float64Max(a, b float64) float64 {
	// Return the larger of the two floating-point numbers
	if a < b {
		return b
	}
	return a
}

func IntMin(a, b int) int {
	// Return the smaller of the two integers
	if a > b {
		return b
	}
	return a
}

func Int64Min(a, b int64) int64 {
	// Return the smaller of the two integers
	if a > b {
		return b
	}
	return a
}

func Float64Min(a, b float64) float64 {
	// Return the smaller of the two floating-point numbers
	if a > b {
		return b
	}
	return a
}

// Helper function for finding the greatest common divisor of two integers
func IntGcd(a, b int) int {
	// If b is 0, return a as the GCD
	if b == 0 {
		return a
	}

	// Recursively call IntGcd with b and the remainder of a divided by b
	return IntGcd(b, a%b)
}

func Int64Gcd(a, b int64) int64 {
	// If b is 0, return a as the GCD
	if b == 0 {
		return a
	}

	// Recursively call Int64Gcd with b and the remainder of a divided by b
	return Int64Gcd(b, a%b)
}

// Helper function for finding the absolute value of an integer
func IntAbs(a int) int {
	// If a is negative, return the negative of a
	if a < 0 {
		return -a
	}
	// Otherwise, return a as is
	return a
}

func Int64Abs(a int64) int64 {
	// If a is negative, return the negative of a
	if a < 0 {
		return -a
	}
	// Otherwise, return a as is
	return a
}

