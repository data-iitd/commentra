package main

import "fmt"

func main() {
	var a, b int // Declare two integer variables a and b

	fmt.Scan(&a) // Take an integer input from the user and store it in variable a

	fmt.Println(a/(60*60), a%(60*60)/60, a%(60*60)%60) // Calculate and output the hours, minutes, and seconds
}

