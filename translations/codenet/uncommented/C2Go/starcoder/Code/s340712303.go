package main

import "fmt"

func main() {
	var num1, num2, a, ans, sum int
	var math [2000]int
	math[0] = 1
	fmt.Scanf("%d", &num1)
	for i := 0; i < num1; i++ {
		fmt.Scanf("%d", &a)
		sum += a
		for j := sum - a; j >= 0; j-- {
			if math[j] == 1 {
				math[j+a] = 1
			}
		}
	}
	fmt.Scanf("%d", &num2)
	for i := 0; i < num2; i++ {
		fmt.Scanf("%d", &ans)
		if math[ans] == 1 {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

