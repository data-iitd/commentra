
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to calculate x^y mod mod using efficient exponentiation by squaring
func modPower(x, y, mod int) int {
	res := 1
	x %= mod
	if x == 0 {
		return 0
	}
	for y > 0 {
		if y%2 == 1 {
			res = (res * x) % mod
		}
		y = y >> 1
		x = (x * x) % mod
	}
	return res
}

// Main function to read input, calculate the maximum product, and print the result
func main() {
	reader := bufio.NewReader(os.Stdin)
	var a [4]int64
	for i := 0; i < 4; i++ {
		input, _ := reader.ReadString('\n')
		a[i], _ = strconv.ParseInt(strings.TrimSpace(input), 10, 64)
	}
	result := int(math.Max(float64(a[0]*a[2]), math.Max(float64(a[1]*a[3]), math.Max(float64(a[0]*a[3]), float64(a[1]*a[2])))))
	fmt.Println(result)
}

// END-OF-CODE