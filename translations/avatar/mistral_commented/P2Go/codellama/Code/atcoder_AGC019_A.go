# Import necessary libraries and modules
import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Define helper functions
func input() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func ceil(a, b int) int {
	return int(-(-a / b))
}

func round(x float64) int {
	return int((x*2 + 1) / 2)
}

func fermat(x, y, MOD int) int {
	return int(math.Pow(float64(x), float64(y)) % float64(MOD))
}

func lcm(x, y int) int {
	return (x * y) / gcd(x, y)
}

func lcm_list(nums []int) int {
	result := 1
	for _, num := range nums {
		result = lcm(result, num)
	}
	return result
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	// Read input
	q, _ := strconv.Atoi(input())
	h, _ := strconv.Atoi(input())
	s, _ := strconv.Atoi(input())
	d, _ := strconv.Atoi(input())
	n, _ := strconv.Atoi(input())

	// Calculate the length of the longest segment that can be formed
	// using the given resources
	best1L := int(math.Min(float64(q*4), float64(h*2), float64(s)))
	best2L := int(math.Min(float64(d), float64(best1L*2)))

	// Check if n is even
	if n%2 == 0 {
		// If it is, print the length of the longest segment that can be formed
		// by dividing n into pairs and using the best2L length for each pair
		fmt.Println(best2L * (n / 2))
	} else {
		// If n is odd, print the length of the longest segment that can be formed
		// by dividing n-1 into pairs and using the best2L length for each pair,
		// and adding the best1L length at the end
		fmt.Println(best2L*(n/2) + best1L)
	}
}

