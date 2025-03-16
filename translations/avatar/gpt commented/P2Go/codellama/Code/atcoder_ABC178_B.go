
// Import necessary libraries for mathematical operations, data structures, and system functions
import (
	"fmt"
	"math"
	"sort"
)

// Set the maximum recursion limit to handle deep recursion cases
const maxRecursionLimit = 10000000

// Define a large constant for infinity
const inf = 1000000000000000000

// Define a modulus value commonly used in competitive programming
const mod = 1000000007

// Define directional movements for 4 directions (up, right, down, left)
var dd = [4][2]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}

// Define diagonal movements for 8 directions (including diagonals)
var ddn = [8][2]int{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}

// Function to read a line of input and return it as a list of integers
func LI() []int {
	var a []int
	fmt.Scan(&a)
	return a
}

// Function to read a single integer from input
func I() int {
	var a int
	fmt.Scan(&a)
	return a
}

// Function to read a single float from input
func F() float64 {
	var a float64
	fmt.Scan(&a)
	return a
}

// Function to read a line of input and return it as a list of strings
func LS() []string {
	var a []string
	fmt.Scan(&a)
	return a
}

// Function to read a single string from input
func S() string {
	var a string
	fmt.Scan(&a)
	return a
}

// Main function to execute the core logic of the program
func main() {
	// Read four integers from input
	a, b, c, d := LI()

	// Calculate the maximum value from the products of the pairs and return it
	fmt.Println(max(a * c, b * d, a * d, b * c))
}

// Function to find the maximum value from a list of integers
func max(a ...int) int {
	m := a[0]
	for _, e := range a {
		if e > m {
			m = e
		}
	}
	return m
}

// Function to find the minimum value from a list of integers
func min(a ...int) int {
	m := a[0]
	for _, e := range a {
		if e < m {
			m = e
		}
	}
	return m
}

// Function to find the absolute value of an integer
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Function to find the absolute value of a float
func absF(a float64) float64 {
	if a < 0 {
		return -a
	}
	return a
}

// Function to find the square of an integer
func sq(a int) int {
	return a * a
}

// Function to find the square of a float
func sqF(a float64) float64 {
	return a * a
}

// Function to find the sum of a list of integers
func sum(a []int) int {
	s := 0
	for _, e := range a {
		s += e
	}
	return s
}

// Function to find the sum of a list of floats
func sumF(a []float64) float64 {
	s := 0.0
	for _, e := range a {
		s += e
	}
	return s
}

// Function to find the product of a list of integers
func prod(a []int) int {
	p := 1
	for _, e := range a {
		p *= e
	}
	return p
}

// Function to find the product of a list of floats
func prodF(a []float64) float64 {
	p := 1.0
	for _, e := range a {
		p *= e
	}
	return p
}

// Function to find the mean of a list of integers
func mean(a []int) float64 {
	return float64(sum(a)) / float64(len(a))
}

// Function to find the mean of a list of floats
func meanF(a []float64) float64 {
	return sumF(a) / float64(len(a))
}

// Function to find the median of a list of integers
func median(a []int) int {
	sort.Ints(a)
	return a[len(a)/2]
}

// Function to find the median of a list of floats
func medianF(a []float64) float64 {
	sort.Float64s(a)
	return a[len(a)/2]
}

// Function to find the mode of a list of integers
func mode(a []int) int {
	sort.Ints(a)
	m := a[0]
	c := 1
	for i := 1; i < len(a); i++ {
		if a[i] == m {
			c++
		} else {
			c--
		}
		if c == 0 {
			m = a[i]
			c = 1
		}
	}
	return m
}

// Function to find the mode of a list of floats
func modeF(a []float64) float64 {
	sort.Float64s(a)
	m := a[0]
	c := 1
	for i := 1; i < len(a); i++ {
		if a[i] == m {
			c++
		} else {
			c--
		}
		if c == 0 {
			m = a[i]
			c = 1
		}
	}
	return m
}

// Function to find the variance of a list of integers
func variance(a []int) float64 {
	m := mean(a)
	s := 0.0
	for _, e := range a {
		s += (float64(e) - m) * (float64(e) - m)
	}
	return s / float64(len(a)-1)
}

// Function to find the variance of a list of floats
func varianceF(a []float64) float64 {
	m := meanF(a)
	s := 0.0
	for _, e := range a {
		s += (e - m) * (e - m)
	}
	return s / float64(len(a)-1)
}

// Function to find the standard deviation of a list of integers
func stddev(a []int) float64 {
	return math.Sqrt(variance(a))
}

// Function to find the standard deviation of a list of floats
func stddevF(a []float64) float64 {
	return math.Sqrt(varianceF(a))
}

// Function to find the dot product of two lists of integers
func dot(a, b []int) int {
	s := 0
	for i := 0; i < len(a) && i < len(b); i++ {
		s += a[i] * b[i]
	}
	return s
}

// Function to find the dot product of two lists of floats
func dotF(a, b []float64) float64 {
	s := 0.0
	for i := 0; i < len(a) && i < len(b); i++ {
		s += a[i] * b[i]
	}
	return s
}

// Function to find the cross product of two lists of integers
func cross(a, b []int) int {
	s := 0
	for i := 0; i < len(a) && i < len(b); i++ {
		s += a[i] * b[i]
	}
	return s
}

// Function to find the cross product of two lists of floats
func crossF(a, b []float64) float64 {
	s := 0.0
	for i := 0; i < len(a) && i < len(b); i++ {
		s += a[i] * b[i]
	}
	return s
}

// Function to find the convolution of two lists of integers
func conv(a, b []int) []int {
	c := make([]int, len(a)+len(b)-1)
	for i := range c {
		s := 0
		for j := 0; j < i+1 && j < len(a) && j < len(b); j++ {
			s += a[j] * b[i-j]
		}
		c[i] = s
	}
	return c
}

// Function to find the convolution of two lists of floats
func convF(a, b []float64) []float64 {
	c := make([]float64, len(a)+len(b)-1)
	for i := range c {
		s := 0.0
		for j := 0; j < i+1 && j < len(a) && j < len(b); j++ {
			s += a[j] * b[i-j]
		}
		c[i] = s
	}
	return c
}

// Function to find the power set of a list of integers
func powerset(a []int) [][]int {
	ps := [][]int{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []int{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of strings
func powersetS(a []string) [][]string {
	ps := [][]string{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []string{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of integers
func powersetI(a []int) [][]int {
	ps := [][]int{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []int{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of floats
func powersetF(a []float64) [][]float64 {
	ps := [][]float64{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []float64{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of booleans
func powersetB(a []bool) [][]bool {
	ps := [][]bool{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []bool{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of runes
func powersetR(a []rune) [][]rune {
	ps := [][]rune{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []rune{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of bytes
func powersetB(a []byte) [][]byte {
	ps := [][]byte{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []byte{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of complex numbers
func powersetC(a []complex128) [][]complex128 {
	ps := [][]complex128{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []complex128{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of complex numbers
func powersetC(a []complex64) [][]complex64 {
	ps := [][]complex64{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []complex64{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of integers
func powersetI(a []int) [][]int {
	ps := [][]int{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []int{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of runes
func powersetR(a []rune) [][]rune {
	ps := [][]rune{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []rune{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of strings
func powersetS(a []string) [][]string {
	ps := [][]string{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []string{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of bytes
func powersetB(a []byte) [][]byte {
	ps := [][]byte{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []byte{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set of a list of complex numbers
func powersetC(a []complex128) [][]complex128 {
	ps := [][]complex128{}
	for i := 0; i < 1<<uint(len(a)); i++ {
		s := []complex128{}
		for j := 0; j < len(a); j++ {
			if i&(1<<uint(j)) > 0 {
				s = append(s, a[j])
			}
		}
		ps = append(ps, s)
	}
	return ps
}

// Function to find the power set o