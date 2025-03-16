package main

import (
	"fmt"
)

func main() {
	var input [4][4]int
	var tc int

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			fmt.Scan(&input[i][j])
		}
	}
	fmt.Scan(&tc)

	for i := 0; i < tc; i++ {
		var testcase int
		fmt.Scan(&testcase)
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				if input[i][j] == testcase {
					input[i][j] = 0
				}
			}
		}
	}

	if input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
	} else if input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0 {
		fmt.Println("Yes")
	} else if input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0 {
		fmt.Println("Yes")
	} else if input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0 {
		fmt.Println("Yes")
	} else if input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
	} else if input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0 {
		fmt.Println("Yes")
	} else if input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0 {
		fmt.Println("Yes")
	} else if input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

