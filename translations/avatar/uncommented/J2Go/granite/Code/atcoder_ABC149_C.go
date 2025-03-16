
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"math"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	number, _ := strconv.Atoi(text)
	if number!= 2 && number%2 == 0 {
		number++
	}
	for {
		i := 3
		sqrtNum := math.Sqrt(float64(number))
		for i <= int(sqrtNum) {
			if number%i == 0 {
				break
			}
			i += 2
		}
		if i > int(sqrtNum) {
			break
		}
		number += 2
	}
	fmt.Println(number)
}

