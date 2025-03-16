package main

import "fmt"

func main() {
	var h1, h2, m1, m2, k int
	fmt.Print("Enter hours and minutes for the first time: ")
	fmt.Scan(&h1, &m1)
	fmt.Print("Enter hours and minutes for the second time: ")
	fmt.Scan(&h2, &m2)
	ans := h2*60 + m2
	fmt.Println("The total minutes of the second time are: ", ans)
	ans -= (h1*60 + m1)
	fmt.Println("The difference in minutes is: ", ans)
	ans -= k
	fmt.Println("The difference in minutes after subtracting ", k, " is: ", ans)
	hours := ans / 60
	minutes := ans % 60
	fmt.Println(hours, " hours and ", minutes, " minutes")
}

