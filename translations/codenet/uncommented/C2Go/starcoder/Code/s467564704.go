package main

import "fmt"

func main() {
	var input [4][4]int
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			fmt.Scanf("%d", &input[i][j])
		}
	}
	var tc int
	fmt.Scanf("%d", &tc)
	var testcase int
	for i := 0; i < tc; i++ {
		fmt.Scanf("%d", &testcase)
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

