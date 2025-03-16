
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers n and k from input, where n is the total number of elements and k is the position of interest
	var n, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &k)

	// Read the string of values (v) from input
	v := strings.TrimSpace(readLine())

	// Define the directions for movement: LEFT and RIGHT
	d := []string{"LEFT", "RIGHT"}

	// Determine if we should move LEFT or RIGHT based on the position k
	// If k is closer to the start (LEFT), f will be true; otherwise, it will be false
	f := k-1 < n-k

	// Calculate the minimum number of moves needed to reach the desired position
	m := int(Min(float64(k-1), float64(n-k)))

	// Initialize an empty list to store the sequence of moves and prints
	a := []string{}

	// Append the necessary number of LEFT or RIGHT moves to the list based on the calculated minimum moves
	for i := 0; i < m; i++ {
		a = append(a, d[!f]) // Append the opposite direction of f
	}

	// Append the print commands for each character in the string v
	// The slicing reverses the order of characters if moving RIGHT (f is true)
	for _, i := range v[::-1+2*f] {
		a = append(a, "PRINT "+string(i)) // Append the print command for the current character
		a = append(a, d[f])               // Append the direction for the next move
	}

	// Print the final sequence of moves and print commands, excluding the last move
	for _, i := range a[:len(a)-1] {
		fmt.Println(i)
	}
}

func readLine() string {
	buf := new(strings.Builder)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	buf.ReadBytes('\n')
	return buf.String()
}

func Min(x, y float64) float64 {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	tmp := pow(x, n/2)
	if n%2 == 0 {
		return tmp * tmp
	} else {
		return tmp * tmp * x
	}
}

func powMod(x, n, mod int) int {
	if n == 0 {
		return 1
	}
	tmp := powMod(x, n/2, mod)
	tmp = (tmp * tmp) % mod
	if n%2 == 1 {
		tmp = (tmp * x) % mod
	}
	return tmp
}

func formatInt(num int) string {
	return strconv.Itoa(num)
}

func formatInt64(num int64) string {
	return strconv.FormatInt(num, 10)
}

func formatFloat(num float64, prec int) string {
	return strconv.FormatFloat(num, 'f', prec, 64)
}

func cdiv(num, den int) int {
	return num / den
}

func cmod(num, den int) int {
	return num - cdiv(num, den)*den
}

func isPrime(num int) bool {
	if num < 2 {
		return false
	}
	for i := 2; i*i <= num; i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(num int) int {
	if num < 2 {
		return 2
	}
	num++
	for!isPrime(num) {
		num++
	}
	return num
}

func prevPrime(num int) int {
	if num < 2 {
		return 2
	}
	num--
	for!isPrime(num) {
		num--
	}
	return num
}

func isPerfectSquare(num int) bool {
	return int(sqrt(float64(num)))*int(sqrt(float64(num))) == num
}

func sqrt(num float64) float64 {
	return nthRoot(num, 2)
}

func nthRoot(num, n int) float64 {
	return nthRootR(num, n, 0.0, 1.0e9)
}

func nthRootR(num, n, low, high float64) float64 {
	if abs(num-pow(int(high+0.5), n)) < 0.00000000000000001 {
		return high
	} else if abs(num-pow(int(low+0.5), n)) < 0.00000000000000001 {
		return low
	}
	if high-low < 0.00000000000000001 {
		return low
	}
	mid := (low + high) / 2
	if nthRootR(num, n, low, mid) > nthRootR(num, n, mid, high) {
		return nthRootR(num, n, low, mid)
	} else {
		return nthRootR(num, n, mid, high)
	}
}

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func isPalindrome(str string) bool {
	for i := 0; i < len(str)/2; i++ {
		if str[i]!= str[len(str)-1-i] {
			return false
		}
	}
	return true
}

func isAnagram(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	m := make(map[rune]int)
	for _, v := range s1 {
		m[v]++
	}
	for _, v := range s2 {
		if m[v] <= 0 {
			return false
		}
		m[v]--
	}
	return true
}

func isPermutation(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	m := make(map[rune]int)
	for _, v := range s1 {
		m[v]++
	}
	for _, v := range s2 {
		if m[v] <= 0 {
			return false
		}
		m[v]--
	}
	return true
}

func isSubsequence(s1, s2 string) bool {
	m := 0
	for _, v := range s2 {
		if m < len(s1) && s1[m] == v {
			m++
		}
	}
	return m == len(s1)
}

func isRotation(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	return s1+s1 == s2
}

func isAnagram2(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	m := make(map[rune]int)
	for _, v := range s1 {
		m[v]++
	}
	for _, v := range s2 {
		if m[v] <= 0 {
			return false
		}
		m[v]--
	}
	return true
}

func isPermutation2(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	m := make(map[rune]int)
	for _, v := range s1 {
		m[v]++
	}
	for _, v := range s2 {
		if m[v] <= 0 {
			return false
		}
		m[v]--
	}
	return true
}

func isSubsequence2(s1, s2 string) bool {
	m := 0
	for _, v := range s2 {
		if m < len(s1) && s1[m] == v {
			m++
		}
	}
	return m == len(s1)
}

func isRotation2(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	return s1+s1 == s2
}

func main() {
	// Read two integers n and k from input, where n is the total number of elements and k is the position of interest
	var n, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &k)

	// Read the string of values (v) from input
	v := strings.TrimSpace(readLine())

	// Define the directions for movement: LEFT and RIGHT
	d := []string{"LEFT", "RIGHT"}

	// Determine if we should move LEFT or RIGHT based on the position k
	// If k is closer to the start (LEFT), f will be true; otherwise, it will be false
	f := k-1 < n-k

	// Calculate the minimum number of moves needed to reach the desired position
	m := int(Min(float64(k-1), float64(n-k)))

	// Initialize an empty list to store the sequence of moves and prints
	a := []string{}

	// Append the necessary number of LEFT or RIGHT moves to the list based on the calculated minimum moves
	for i := 0; i < m; i++ {
		a = append(a, d[!f]) // Append the opposite direction of f
	}

	// Append the print commands for each character in the string v
	// The slicing reverses the order of characters if moving RIGHT (f is true)
	for _, i := range v[::-1+2*f] {
		a = append(a, "PRINT "+string(i)) // Append the print command for the current character
		a = append(a, d[f])               // Append the direction for the next move
	}

	// Print the final sequence of moves and print commands, excluding the last move
	for _, i := range a[:len(a)-1] {
		fmt.Println(i)
	}
}

func readLine() string {
	buf := new(strings.Builder)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	buf.ReadBytes('\n')
	return buf.String()
}

func Min(x, y float64) float64 {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	tmp := pow(x, n/2)
	if n%2 == 0 {
		return tmp * tmp
	} else {
		return tmp * tmp * x
	}
}

func powMod(x, n, mod int) int {
	if n == 0 {
		return 1
	}
	tmp := powMod(x, n/2, mod)
	tmp = (tmp * tmp) % mod
	if n%2 == 1 {
		tmp = (tmp * x) % mod
	}
	return tmp
}

func formatInt(num int) string {
	return strconv.Itoa(num)
}

func formatInt64(num int64) string {
	return strconv.FormatInt(num, 10)
}

func formatFloat(num float64, prec int) string {
	return strconv.FormatFloat(num, 'f', prec, 64)
}

func cdiv(num, den int) int {
	return num / den
}

func cmod(num, den int) int {
	return num - cdiv(num, den)*den
}

func isPrime(num int) bool {
	if num < 2 {
		return false
	}
	for i := 2; i*i <= num; i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(num int) int {
	if num < 2 {
		return 2
	}
	num++
	for!isPrime(num) {
		num++
	}
	return num
}

func prevPrime(num int) int {
	if num < 2 {
		return 2
	}
	num--
	for!isPrime(num) {
		num--
	}
	return num
}

func isPerfectSquare(num int) bool {
	return int(sqrt(float64(num)))*int(sqrt(float64(num))) == num
}

func sqrt(num float64) float64 {
	return nthRoot(num, 2)
}

func nthRoot(num, n int) float64 {
	return nthRootR(num, n, 0.0, 1.0e9)
}

func nthRootR(num, n, low, high float64) float64 {
	if abs(num-pow(int(high+0.5), n)) < 0.00000000000000001 {
		return high
	} else if abs(num-pow(int(low+0.5), n)) < 0.00000000000000001 {
		return low
	}
	if high-low < 0.00000000000000001 {
		return low
	}
	mid := (low + high) / 2
	if nthRootR(num, n, low, mid) > nthRootR(num, n, mid, high) {
		return nthRootR(num, n, low, mid)
	} else {
		return nthRootR(num, n, mid, high)
	}
}

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func isPalindrome(str string) bool {
	for i := 0; i < len(str)/2; i++ {
		if str[i]!= str[len(str)-1-i] {
			return false
		}
	}
	return true
}

func isAnagram(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	m := make(map[rune]int)
	for _, v := range s1 {
		m[v]++
	}
	for _, v := range s2 {
		if m[v] <= 0 {
			return false
		}
		m[v]--
	}
	return true
}

func isPermutation(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	m := make(map[rune]int)
	for _, v := range s1 {
		m[v]++
	}
	for _, v := range s2 {
		if m[v] <= 0 {
			return false
		}
		m[v]--
	}
	return true
}

func isSubsequence(s1, s2 string) bool {
	m := 0
	for _, v := range s2 {
		if m < len(s1) && s1[m] == v {
			m++
		}
	}
	return m == len(s1)
}

func isRotation(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	return s1+s1 == s2
}

func isAnagram2(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	m := make(map[rune]int)
	for _, v := range s1 