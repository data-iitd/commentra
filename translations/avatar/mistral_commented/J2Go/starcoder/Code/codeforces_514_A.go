
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	number, _ := strconv.ParseInt(input, 10, 64)
	var digits []int64
	for number > 0 {
		digit := number % 10
		if 9-digit < digit {
			if number/10 == 0 && 9-digit == 0 {
				digits = append(digits, digit)
			} else {
				digits = append(digits, 9-digit)
			}
		} else {
			digits = append(digits, digit)
		}
		number = number / 10
	}
	var newNumber int64
	for i := 0; i < len(digits); i++ {
		newNumber += digits[i] * int64(math.Pow(10, float64(i)))
	}
	fmt.Println(newNumber)
}

