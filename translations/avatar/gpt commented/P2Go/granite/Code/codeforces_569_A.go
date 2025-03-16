
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read three integers from input: t (target), s (initial value), and q (growth factor)
	t, s, q := readThreeIntegers()

	// Initialize a counter for the number of iterations
	ans := 0

	// Loop until the initial value s is less than the target t
	for s < t {
		// Multiply the current value of s by the growth factor q
		s *= q
		// Increment the counter for each multiplication
		ans++
	}

	// Print the total number of multiplications needed for s to reach or exceed t
	fmt.Println(ans)
}

func readThreeIntegers() (int, int, int) {
	scanner := bufio.NewScanner(os.Stdin)
	var t, s, q int
	fmt.Scan(&t, &s, &q)
	return t, s, q
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	var num int
	fmt.Scan(&num)
	return num
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readStringSlice() []string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	text := scanner.Text()
	return strings.Split(text, " ")
}

func readIntSlice() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	text := scanner.Text()
	stringSlice := strings.Split(text, " ")
	intSlice := make([]int, 0)
	for _, str := range stringSlice {
		num, _ := strconv.Atoi(str)
		intSlice = append(intSlice, num)
	}
	return intSlice
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func max(x, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}

func pow(x, n int) int {
	result := 1
	for i := 0; i < n; i++ {
		result *= x
	}
	return result
}

func abs(x int) int {
	if x < 0 {
		return -x
	} else {
		return x
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

func sortIntSlice(intSlice []int) []int {
	sort.Ints(intSlice)
	return intSlice
}

func sortStringSlice(stringSlice []string) []string {
	sort.Strings(stringSlice)
	return stringSlice
}

func reverseIntSlice(intSlice []int) []int {
	for i, j := 0, len(intSlice)-1; i < j; i, j = i+1, j-1 {
		intSlice[i], intSlice[j] = intSlice[j], intSlice[i]
	}
	return intSlice
}

func reverseStringSlice(stringSlice []string) []string {
	for i, j := 0, len(stringSlice)-1; i < j; i, j = i+1, j-1 {
		stringSlice[i], stringSlice[j] = stringSlice[j], stringSlice[i]
	}
	return stringSlice
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(n int) int {
	if n <= 1 {
		return 2
	}
	num := n
	for {
		num++
		if isPrime(num) {
			return num
		}
	}
}

func prevPrime(n int) int {
	if n <= 1 {
		return 2
	}
	num := n
	for {
		num--
		if isPrime(num) {
			return num
		}
	}
}

func factorial(n int) int {
	result := 1
	for i := 1; i <= n; i++ {
		result *= i
	}
	return result
}

func permutation(n, r int) int {
	return factorial(n) / factorial(n-r)
}

func combination(n, r int) int {
	return permutation(n, r) / factorial(r)
}

func isPermutation(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	charCount := make(map[rune]int)
	for _, char := range s1 {
		charCount[char]++
	}
	for _, char := range s2 {
		if charCount[char] == 0 {
			return false
		}
		charCount[char]--
	}
	return true
}

func isAnagram(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	charCount := make(map[rune]int)
	for _, char := range s1 {
		charCount[char]++
	}
	for _, char := range s2 {
		if charCount[char] == 0 {
			return false
		}
		charCount[char]--
	}
	return true
}

func isPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i]!= s[len(s)-1-i] {
			return false
		}
	}
	return true
}

func isPalindromeNum(num int) bool {
	return isPalindrome(strconv.Itoa(num))
}

func isPalindromeRunes(runes []rune) bool {
	return isPalindrome(string(runes))
}

func isPalindromeString(s string) bool {
	return isPalindrome(s)
}

func isPalindromeIntSlice(intSlice []int) bool {
	return isPalindrome(fmt.Sprintf("%v", intSlice))
}

func isPalindromeStringSlice(stringSlice []string) bool {
	return isPalindrome(fmt.Sprintf("%v", stringSlice))
}

func isPalindromeRunesSlice(runesSlice [][]rune) bool {
	return isPalindrome(fmt.Sprintf("%v", runesSlice))
}

func isPalindromeIntSliceSlice(intSliceSlice [][]int) bool {
	return isPalindrome(fmt.Sprintf("%v", intSliceSlice))
}

func isPalindromeStringSliceSlice(stringSliceSlice [][]string) bool {
	return isPalindrome(fmt.Sprintf("%v", stringSliceSlice))
}

func isPalindromeRunesSliceSlice(runesSliceSlice [][][]rune) bool {
	return isPalindrome(fmt.Sprintf("%v", runesSliceSlice))
}

func isPalindromeIntSliceSliceSlice(intSliceSliceSlice [][][][]int) bool {
	return isPalindrome(fmt.Sprintf("%v", intSliceSliceSlice))
}

func isPalindromeStringSliceSliceSlice(stringSliceSliceSlice [][][][][]string) bool {
	return isPalindrome(fmt.Sprintf("%v", stringSliceSliceSlice))
}

func isPalindromeRunesSliceSliceSlice(runesSliceSliceSlice [][][][][][]rune) bool {
	return isPalindrome(fmt.Sprintf("%v", runesSliceSliceSlice))
}

func isPalindromeIntSliceSliceSliceSlice(intSliceSliceSliceSlice [][][][][][][]int) bool {
	return isPalindrome(fmt.Sprintf("%v", intSliceSliceSliceSlice))
}

func isPalindromeStringSliceSliceSliceSlice(stringSliceSliceSliceSlice [][][][][][][]string) bool {
	return isPalindrome(fmt.Sprintf("%v", stringSliceSliceSliceSlice))
}

func isPalindromeRunesSliceSliceSliceSlice(runesSliceSliceSliceSlice [][][][][][][][]rune) bool {
	return isPalindrome(fmt.Sprintf("%v", runesSliceSliceSliceSlice))
}

func isPalindromeIntSliceSliceSliceSliceSlice(intSliceSliceSliceSliceSlice [][][][][][][][][]int) bool {
	return isPalindrome(fmt.Sprintf("%v", intSliceSliceSliceSliceSlice))
}

func isPalindromeStringSliceSliceSliceSliceSlice(stringSliceSliceSliceSliceSlice [][][][][][][][][]string) bool {
	return isPalindrome(fmt.Sprintf("%v", stringSliceSliceSliceSliceSlice))
}

func isPalindromeRunesSliceSliceSliceSliceSlice(runesSliceSliceSliceSliceSliceSlice [][][][][][][][][][]rune) bool {
	return isPalindrome(fmt.Sprintf("%v", runesSliceSliceSliceSliceSliceSlice))
}

func isPalindromeIntSliceSliceSliceSliceSliceSlice(intSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][]int) bool {
	return isPalindrome(fmt.Sprintf("%v", intSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeStringSliceSliceSliceSliceSliceSlice(stringSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][]string) bool {
	return isPalindrome(fmt.Sprintf("%v", stringSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeRunesSliceSliceSliceSliceSliceSliceSlice(runesSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][]rune) bool {
	return isPalindrome(fmt.Sprintf("%v", runesSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeIntSliceSliceSliceSliceSliceSliceSliceSlice(intSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][][]int) bool {
	return isPalindrome(fmt.Sprintf("%v", intSliceSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeStringSliceSliceSliceSliceSliceSliceSliceSliceSlice(stringSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][][]string) bool {
	return isPalindrome(fmt.Sprintf("%v", stringSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeRunesSliceSliceSliceSliceSliceSliceSliceSliceSlice(runesSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][][][]rune) bool {
	return isPalindrome(fmt.Sprintf("%v", runesSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeIntSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice(intSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][][][][]int) bool {
	return isPalindrome(fmt.Sprintf("%v", intSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeStringSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice(stringSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][][][][]string) bool {
	return isPalindrome(fmt.Sprintf("%v", stringSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeRunesSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice(runesSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][][][][][]rune) bool {
	return isPalindrome(fmt.Sprintf("%v", runesSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeIntSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice(intSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][][][][][][]int) bool {
	return isPalindrome(fmt.Sprintf("%v", intSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeStringSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice(stringSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][][][][][][]string) bool {
	return isPalindrome(fmt.Sprintf("%v", stringSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeRunesSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice(runesSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][][][][][][][][][]rune) bool {
	return isPalindrome(fmt.Sprintf("%v", runesSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeIntSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice(intSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][][][][][][][][][][][][][][][][][]int) bool {
	return isPalindrome(fmt.Sprintf("%v", intSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice))
}

func isPalindromeStringSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice(stringSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSliceSlice [][][][][]