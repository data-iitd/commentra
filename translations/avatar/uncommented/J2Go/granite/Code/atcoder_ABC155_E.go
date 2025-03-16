
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const (
		INF = 1e15
	)
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter a number:")
	text, _ := reader.ReadString('\n')
	number, _ := strconv.ParseInt(text, 10, 64)
	digits := make([]int, len(strconv.FormatInt(number, 10))+1)
	for i := 0; i < len(strconv.FormatInt(number, 10)); i++ {
		digits[i] = int(number%10)
		number /= 10
	}
	digits[len(strconv.FormatInt(number, 10))] = int(number)
	bills := 0
	for i := 0; i <= len(strconv.FormatInt(number, 10)); i++ {
		if digits[i] == 10 {
			digits[i+1]++
			digits[i] = 0
		}
		if digits[i] < 5 {
			bills += digits[i]
		} else if digits[i] == 5 {
			if digits[i+1] >= 5 {
				digits[i+1]++
			}
			bills += 5
		} else {
			digits[i+1]++
			bills += 10 - digits[i]
		}
	}
	fmt.Println(bills)
}

