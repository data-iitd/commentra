package main

import "fmt"

func main() {
	var i, sum int = 0, 0
	var flag int = 0
	var x [1002]byte
	fmt.Scanf("%s", &x)
	for {
		for i = 0; i < 1002; i++ {
			if x[i] == 0 {
				fmt.Printf("%d\n", sum)
				break
			} else {
				sum += int(x[i]) - 0x30
			}
		}
		sum = 0
		fmt.Scanf("%s", &x)
		if x[0] == 0x30 {
			break
		}
	}
}

