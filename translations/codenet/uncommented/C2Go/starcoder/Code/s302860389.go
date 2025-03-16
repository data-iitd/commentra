package main

import "fmt"

func main() {
	var inputNumbers [5]byte
	var temp [2]byte
	var a, b, c, d int
	var sum int
	var symbols [3]byte

	fmt.Scanf("%s", &inputNumbers)

	temp[1] = 0
	temp[0] = inputNumbers[0]
	a = int(temp[0] - '0')
	temp[0] = inputNumbers[1]
	b = int(temp[0] - '0')
	temp[0] = inputNumbers[2]
	c = int(temp[0] - '0')
	temp[0] = inputNumbers[3]
	d = int(temp[0] - '0')

	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				if i == 0 {
					sum = a + b
					symbols[0] = '+'
				} else {
					sum = a - b
					symbols[0] = '-'
				}

				if j == 0 {
					sum = sum + c
					symbols[1] = '+'
				} else {
					sum = sum - c
					symbols[1] = '-'
				}

				if k == 0 {
					sum = sum + d
					symbols[2] = '+'
				} else {
					sum = sum - d
					symbols[2] = '-'
				}

				if sum == 7 {
					fmt.Printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)
					return
				}
			}
		}
	}
}

