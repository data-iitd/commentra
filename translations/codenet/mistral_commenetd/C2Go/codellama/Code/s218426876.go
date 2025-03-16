
package main

import "fmt"

func main() {
	var i int
	var sum int = 0
	var flag int = 0
	var x [1002]byte

	fmt.Print("Enter a string of digits separated by spaces or newline: ")
	fmt.Scan(&x)

	for {
		sum = 0

		for i = 0; i < 1002; i++ {
			if x[i] == 0 {
				fmt.Printf("Sum of digits in previous string: %d\n", sum)
				break
			} else {
				sum += int(x[i]) - 0x30
			}
		}

		sum = 0

		fmt.Print("Enter a string of digits separated by spaces or newline: ")
		fmt.Scan(&x)

		if x[0] == 0x30 {
			break
		}
	}
}

