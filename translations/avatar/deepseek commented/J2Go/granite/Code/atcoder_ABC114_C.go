
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	N int
	i int64
	c int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialNumber = 357
	c = 0
	i = initialNumber

	for i <= N {
		s := strconv.FormatInt(i, 10)
		if contains(s, "3") && contains(s, "5") && contains(s, "7") {
			c++
		}

		sb := &strings.Builder{}
		f := false
		for j := len(s) - 1; j >= 0; j-- {
			a := string(s[j])
			if f {
				sb.WriteString(a)
			} else {
				switch a {
				case "3":
					sb.WriteString("5")
					f = true
				case "5":
					sb.WriteString("7")
					f = true
				default:
					sb.WriteString("3")
				}
			}
		}
		if!f {
			sb.WriteString("3")
		}

		s2 := sb.String()
		s3 := reverse(s2)
		i2, _ := strconv.ParseInt(s3, 10, 64)
		i = i2
	}

	fmt.Println(c)
}

func contains(s string, substr string) bool {
	return strings.Contains(s, substr)
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < len(runes)/2; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// Read input from the user
func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt64() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func readFloat64() float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

// Output the result
func printInt(num int) {
	fmt.Println(num)
}

func printString(s string) {
	fmt.Println(s)
}

func printInt64(num int64) {
	fmt.Println(num)
}

func printFloat64(num float64) {
	fmt.Println(num)
}

// Helper methods to read different types of input
func gs() string {
	return scanner.Text()
}

func gi() int {
	return readInt()
}

func gl() int64 {
	return readInt64()
}

func gd() float64 {
	return readFloat64()
}

// End of code