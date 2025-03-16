package main

import "fmt"

func main() {
	var a int
	var z string
	fmt.Scanf("%d\n", &a)
	fmt.Scanf("%s\n", &z)
	for i := 0; i < a-1; i++ {
		if z[i] == z[i+1] {
			fmt.Println("Bad")
			return
		}
	}
	fmt.Println("Good")
}

