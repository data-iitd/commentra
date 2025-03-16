package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func input() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func ceil(a, b int) int {
	return int(math.Ceil(float64(a) / float64(b)))
}

func round(x float64) int {
	return int(math.Round(x*2+1) / 2)
}

func fermat(x, y, MOD int) int {
	return x * pow(y, MOD-2, MOD) % MOD
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func lcmList(nums []int) int {
	lcm := nums[0]
	for _, num := range nums[1:] {
		lcm = lcm * num / gcd(lcm, num)
	}
	return lcm
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	scanner.Scan()
	values := splitToInts(scanner.Text())
	q, h, s, d := values[0], values[1], values[2], values[3]
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Calculating the best price for single liters
	best1L := min(q*4, h*2, s)

	// Calculating the best price for double liters
	best2L := min(d, best1L*2)

	// Checking if the quantity n is even or odd and printing the total cost accordingly
	if n%2 == 0 {
		fmt.Fprintln(writer, best2L*(n/2))
	} else {
		fmt.Fprintln(writer, best2L*(n/2)+best1L)
	}
}

func splitToInts(s string) []int {
	fields := strings.Split(s, " ")
	ints := make([]int, len(fields))
	for i, v := range fields {
		ints[i], _ = strconv.Atoi(v)
	}
	return ints
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func pow(x, y, mod int) int {
	result := 1
	for y > 0 {
		if y%2 == 1 {
			result = result * x % mod
		}
		y = y / 2
		x = x * x % mod
	}
	return result
}
