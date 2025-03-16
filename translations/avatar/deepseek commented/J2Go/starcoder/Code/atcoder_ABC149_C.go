package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"math"
)

func main() {
	var x int
	fmt.Print("Enter an integer: ")
	input, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	x, _ = strconv.Atoi(input[:len(input)-1])

	if x!= 2 && x % 2 == 0 {
		x++
	}

	for {
		var i int
		sqrtNum := math.Sqrt(float64(x))

		for i = 3; i <= int(sqrtNum); i += 2 {
			if x % i == 0 {
				break
			}
		}

		if i > int(sqrtNum) {
			break
		}

		x += 2
	}

	fmt.Println(x)
}

