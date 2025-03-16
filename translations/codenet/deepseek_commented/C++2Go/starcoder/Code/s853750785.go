
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
<<<<<<< HEAD
	"strings"
=======
>>>>>>> 98c87cb78a (data updated)
)

// Define type aliases for convenience
type ll int64

// Define mathematical constants and macros
const (
	rad_to_deg = 180 / 3.141592653589793
	EPS        = 1e-7
	INF        = 1e9
	PI         = 3.141592653589793
	mod        = 1e9 + 7
)

// Define a pair type for convenience
<<<<<<< HEAD
type P struct{ x, y int }
=======
type P struct{
	first, second int
}
>>>>>>> 98c87cb78a (data updated)

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to calculate the least common multiple (LCM)
func lcd(a, b int) int {
	if b == 0 {
		return a
	}
	return (a / gcd(a, b)) * b
}

// Function to return the digits of a number as a vector
func divnum(num int) []int {
	var p []int
	for num > 0 {
		p = append(p, num%10)
		num /= 10
	}
	return p
}

// Function to count the number of digits in a number
func digiter(num int) int {
	var p []int
	for num > 0 {
		p = append(p, num%10)
		num /= 10
	}
	return len(p)
}

// Function to convert a string to a vector of integers
func convertstring(s string) []int {
	var d []int
<<<<<<< HEAD
	n := len(s)
	for i := 0; i < n; i++ {
		d = append(d, int(s[i])-48)
=======
	for i := 0; i < len(s); i++ {
		d = append(d, int(s[i]) - '0')
>>>>>>> 98c87cb78a (data updated)
	}
	return d
}

// Function to perform prime factorization of a number
func prime_factor(n int) map[int]int {
	var ret map[int]int
	for i := 2; i*i <= n; i++ {
		for n%i == 0 {
			ret[i]++
			n /= i
		}
	}
	if n!= 1 {
		ret[n] = 1
	}
	return ret
}

// Function to find all divisors of a number
func divisor(n int) []int {
	var res []int
	for i := 1; i*i <= n; i++ {
		if n%i!= 0 {
			continue
		}
		res = append(res, i)
		if i*i!= n {
			res = append(res, n/i)
		}
	}
	return res
}

// Function to compute x raised to the power n modulo m
func myPow(x, n, m int) int {
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		return myPow(x*x%m, n/2, m)
	}
	return x * myPow(x, n-1, m) % m
}

// Function to generate a list of prime numbers using the Sieve of Eratosthenes
func Eratosthenes(N int) []int {
	is_prime := make([]bool, N+1)
	for i := 0; i <= N; i++ {
		is_prime[i] = true
	}
	var P []int
	for i := 2; i <= N; i++ {
		if is_prime[i] {
<<<<<<< HEAD
			for j := 2 * i; j <= N; j += i {
=======
			for j := 2*i; j <= N; j += i {
>>>>>>> 98c87cb78a (data updated)
				is_prime[j] = false
			}
			P = append(P, i)
		}
	}
	return P
}

// Define a structure for modular arithmetic
type mint struct {
	x ll
}

// Define a structure for combinations (n choose k)
type combination struct {
<<<<<<< HEAD
	fact  []mint
	ifact []mint
=======
	fact, ifact []mint
>>>>>>> 98c87cb78a (data updated)
}

// Function to calculate permutations with repetition
func f(n, k int) mint {
	if n < 0 {
		return 0
	}
	// nPk = nCk * k!
	res := comb(n, k)
	res *= comb.fact[k]
	return res
}

// Function to calculate the number of combinations (n choose k)
func comb(n, k int) mint {
	if k < 0 || k > n {
		return 0
	}
	return comb.fact[n] * comb.ifact[k] * comb.ifact[n-k]
}

<<<<<<< HEAD
// Function to initialize the combination structure
func init() {
	comb.fact = make([]mint, 1000005)
	comb.ifact = make([]mint, 1000005)
	comb.fact[0] = 1
	for i := 1; i <= 1000000; i++ {
		comb.fact[i] = comb.fact[i-1] * mint(i)
	}
	comb.ifact[1000000] = comb.fact[1000000].inv()
	for i := 999999; i >= 0; i-- {
=======
// Precompute combinations up to 1,000,005
func init() {
	comb.fact = make([]mint, 1000006)
	comb.ifact = make([]mint, 1000006)
	comb.fact[0] = 1
	for i := 1; i <= 1000005; i++ {
		comb.fact[i] = comb.fact[i-1] * mint(i)
	}
	comb.ifact[1000005] = comb.fact[1000005].inv()
	for i := 1000004; i >= 0; i-- {
>>>>>>> 98c87cb78a (data updated)
		comb.ifact[i] = comb.ifact[i+1] * mint(i+1)
	}
}

// Function to read input from stdin
func read_input() (N, M int) {
	fmt.Scanf("%d %d", &N, &M)
	return
}

// Function to read input from stdin
<<<<<<< HEAD
func read_input_line() (N, M int) {
	line := bufio.NewScanner(os.Stdin)
	line.Scan()
	nums := strings.Split(line.Text(), " ")
	N, _ = strconv.Atoi(nums[0])
	M, _ = strconv.Atoi(nums[1])
	return
}

// Function to read input from stdin
func read_input_lines(N int) (H []int) {
	H = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &H[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_string(N int) (H []string) {
	H = make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%s", &H[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_int(N int) (H []int) {
	H = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &H[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_int64(N int) (H []int64) {
	H = make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &H[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_float64(N int) (H []float64) {
	H = make([]float64, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%f", &H[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_float32(N int) (H []float32) {
	H = make([]float32, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%f", &H[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_P(N int) (H []P) {
	H = make([]P, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &H[i].x, &H[i].y)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_mint(N int) (H []mint) {
	H = make([]mint, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &H[i].x)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_combination(N int) (H []combination) {
	H = make([]combination, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &H[i].x, &H[i].y)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_mint_and_int(N int) (H []mint, I []int) {
	H = make([]mint, N)
	I = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &H[i].x, &I[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_mint_and_int64(N int) (H []mint, I []int64) {
	H = make([]mint, N)
	I = make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &H[i].x, &I[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_mint_and_float64(N int) (H []mint, I []float64) {
	H = make([]mint, N)
	I = make([]float64, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %f", &H[i].x, &I[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_mint_and_float32(N int) (H []mint, I []float32) {
	H = make([]mint, N)
	I = make([]float32, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %f", &H[i].x, &I[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_mint_and_P(N int) (H []mint, I []P) {
	H = make([]mint, N)
	I = make([]P, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d %d", &H[i].x, &I[i].x, &I[i].y)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_mint_and_combination(N int) (H []mint, I []combination) {
	H = make([]mint, N)
	I = make([]combination, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d %d", &H[i].x, &I[i].x, &I[i].y)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_int_and_mint(N int) (H []int, I []mint) {
	H = make([]int, N)
	I = make([]mint, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &H[i], &I[i].x)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_int64_and_mint(N int) (H []int64, I []mint) {
	H = make([]int64, N)
	I = make([]mint, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &H[i], &I[i].x)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_float64_and_mint(N int) (H []float64, I []mint) {
	H = make([]float64, N)
	I = make([]mint, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%f %d", &H[i], &I[i].x)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_float32_and_mint(N int) (H []float32, I []mint) {
	H = make([]float32, N)
	I = make([]mint, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%f %d", &H[i], &I[i].x)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_P_and_mint(N int) (H []P, I []mint) {
	H = make([]P, N)
	I = make([]mint, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d %d", &H[i].x, &H[i].y, &I[i].x)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_combination_and_mint(N int) (H []combination, I []mint) {
	H = make([]combination, N)
	I = make([]mint, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d %d", &H[i].x, &H[i].y, &I[i].x)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_int_and_int(N int) (H []int, I []int) {
	H = make([]int, N)
	I = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &H[i], &I[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_int64_and_int64(N int) (H []int64, I []int64) {
	H = make([]int64, N)
	I = make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &H[i], &I[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_float64_and_float64(N int) (H []float64, I []float64) {
	H = make([]float64, N)
	I = make([]float64, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%f %f", &H[i], &I[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_float32_and_float32(N int) (H []float32, I []float32) {
	H = make([]float32, N)
	I = make([]float32, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%f %f", &H[i], &I[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_P_and_P(N int) (H []P, I []P) {
	H = make([]P, N)
	I = make([]P, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d %d %d", &H[i].x, &H[i].y, &I[i].x, &I[i].y)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_combination_and_combination(N int) (H []combination, I []combination) {
	H = make([]combination, N)
	I = make([]combination, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d %d %d", &H[i].x, &H[i].y, &I[i].x, &I[i].y)
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_int_and_int_and_int(N int) (H []int, I []int, J []int) {
	H = make([]int, N)
	I = make([]int, N)
	J = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d %d", &H[i], &I[i], &J[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_int64_and_int64_and_int64(N int) (H []int64, I []int64, J []int64) {
	H = make([]int64, N)
	I = make([]int64, N)
	J = make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d %d", &H[i], &I[i], &J[i])
	}
	return
}

// Function to read input from stdin
func read_input_lines_as_float64_and_float64_and_float64(N int) (H []float64, I []float6
=======
func read_input_line(N int) []int {
	var H []int
	for i := 0; i < N; i++ {
		var h int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_string(N int) []string {
	var H []string
	for i := 0; i < N; i++ {
		var h string
		fmt.Scanf("%s", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_slice(N int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash_and_percent(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash_and_percent_and_caret(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash_and_percent_and_caret_and_ampersand(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash_and_percent_and_caret_and_ampersand_and_pipe(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash_and_percent_and_caret_and_ampersand_and_pipe_and_equal(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash_and_percent_and_caret_and_ampersand_and_pipe_and_equal_and_open_parenthesis(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash_and_percent_and_caret_and_ampersand_and_pipe_and_equal_and_open_parenthesis_and_open_bracket(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash_and_percent_and_caret_and_ampersand_and_pipe_and_equal_and_open_parenthesis_and_open_bracket_and_open_brace(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash_and_percent_and_caret_and_ampersand_and_pipe_and_equal_and_open_parenthesis_and_open_bracket_and_open_brace_and_question(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_comma_and_semicolon_and_colon_and_dot_and_dash_and_plus_and_star_and_slash_and_percent_and_caret_and_ampersand_and_pipe_and_equal_and_open_parenthesis_and_open_bracket_and_open_brace_and_question_and_at(N, M int) [][]int {
	var H [][]int
	for i := 0; i < N; i++ {
		var h []int
		fmt.Scanf("%d", &h)
		H = append(H, h)
	}
	return H
}

// Function to read input from stdin
func read_input_line_as_int_matrix_with_space_and_
>>>>>>> 98c87cb78a (data updated)
