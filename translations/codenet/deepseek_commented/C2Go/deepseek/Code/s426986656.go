package main

import (
	"fmt"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	flag := 0

	for i := 1; i <= 3; i++ {
		if (A*B*i)%2 == 1 {
			flag = 1
			break
		}
	}

	if flag == 1 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

