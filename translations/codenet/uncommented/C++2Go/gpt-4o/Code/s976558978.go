package main

import (
	"fmt"
	"os"
)

func main() {
	// Uncomment the following line to read from a file
	// file, err := os.Open("dataabc155A.txt")
	// if err != nil {
	//     fmt.Println(err)
	//     return
	// }
	// defer file.Close()

	var a, b int
	fmt.Scan(&a)
	fmt.Scan(&b)

	if a < b {
		for i := 0; i < b; i++ {
			fmt.Print(a)
			if i < b-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	} else {
		for i := 0; i < a; i++ {
			fmt.Print(b)
			if i < a-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}

// <END-OF-CODE>
