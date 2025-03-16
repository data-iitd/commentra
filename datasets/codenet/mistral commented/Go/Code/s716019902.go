// Constants
const mod = 998244353
const facNum = 300001

// Main function
func main() {
	// Initialize a new scanner
	sc := newScanner(os.Stdin)

	// Read an integer N from the standard input
	N := sc.i()

	// Initialize a variable sum to 0
	sum := 0

	// Loop through numbers from 1 to N
	for i := 1; i <= N; i++ {
		// If the number is not divisible by 3 or 5, add it to the sum
		if i%3 != 0 && i%5 != 0 {
			sum += i
		}
	}

	// Print the result to the standard output
	fmt.Println(sum)
}

// I/O
type scanner struct {
	sc *bufio.Scanner
}

// New scanner constructor
func newScanner(input io.Reader) *scanner {
	// Initialize a new bufio.Scanner with the given input
	sc := bufio.NewScanner(input)

	// Set the scanner to split input on words
	sc.Split(bufio.ScanWords)

	// Set the scanner buffer size
	sc.Buffer(make([]byte, 1024), int(1e+9))

	// Return a new scanner instance
	return &scanner{sc}
}

// Helper methods for scanner
func (s *scanner) s() string {
	// Scan the next token and return it as a string
	s.sc.Scan()
	return s.sc.Text()
}

func (s *scanner) i() int {
	// Convert the next token to an integer and return it
	i, _ := strconv.Atoi(s.s())
	return i
}

func (s *scanner) f() float64 {
	// Convert the next token to a float64 and return it
	f, _ := strconv.ParseFloat(s.s(), 64)
	return f
}

func (s *scanner) bs() []byte {
	// Return the next token as a byte slice
	return []byte(s.s())
}

func (s *scanner) is(n int) []int {
	// Read n integers from the standard input and return them as a slice
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = s.i()
	}
	return res
}

func (s *scanner) fs(n int) []float64 {
	// Read n floating-point numbers from the standard input and return them as a slice
	res := make([]float64, n)
	for i := 0; i < n; i++ {
		res[i] = s.f()
	}
	return res
}

// Math functions
func Pow(a, n int) int {
	// Calculate a^n modulo mod
	ans := 1
	for n > 0 {
		if (n & 1) == 1 {
			ans = ans * a % mod
		}
		a = a * a % mod
		n = n >> 1
	}
	return ans
}

func Gcd(a, b int) int {
	// Calculate the greatest common divisor of a and b
	if a < b {
		return Gcd(b, a)
	}
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func min(a, b int) int {
	// Return the minimum of a and b
	if a < b {
		return a
	}
	return b
}

// Combination function
func combination(n, k int, fac, ifac []int) int {
	// Calculate the binomial coefficient (n choose k) modulo mod
	if n < k || n < 0 {
		return 0
	}
	if k == 0 {
		return 1
	}
	// While n is not 0
	ans := ifac[k] * ifac[n-k] % mod
	return ans * fac[n] % mod
}

// Factorial function
func factorial() (fac []int, ifac []int) {
	// Calculate and return the factorial of all numbers from 0 to facNum-1
	fac = make([]int, facNum)
	fac[0] = 1
	ifac = make([]int, facNum)
	ifac[0] = 1
	for i := 1; i < facNum; i++ {
		fac[i] = fac[i-1] * i % mod
		ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod
	}
	return
}

// Lower bound function
func lowerBound(vs []int, v int) (index int) {
	// Calculate the index of the first element in vs that is greater than or equal to v
	n := len(vs) / 2
	m := len(vs)
	for m != n {
		if vs[n] < v {
			n = (m-n+1)/2 + n
			//m = m
		} else {
			m = n
			n = n / 2
		}
	}
	return n
}

// IntSlice function
func IntSlice(n, init int) []int {
	// Create and initialize a slice of length n with the given initial value
	r := make([]int, n)
	for i := range r {
		r[i] = init
	}
	return r
}

// 