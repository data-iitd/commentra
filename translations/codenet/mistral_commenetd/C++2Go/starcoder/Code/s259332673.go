<<<<<<< HEAD

import "fmt"

func main() {
	var h1, h2, m1, m2, k int
	fmt.Scanf("%d %d", &h1, &m1)
	fmt.Println("Enter hours and minutes for the first time: ")
	fmt.Scanf("%d %d", &h1, &m1)

	fmt.Scanf("%d %d", &h2, &m2)
	fmt.Println("Enter hours and minutes for the second time: ")
	fmt.Scanf("%d %d", &h2, &m2)

	ans := h2*60 + m2
	fmt.Println("The total minutes of the second time are: ", ans)

	ans -= h1*60 + m1
	fmt.Println("The difference in minutes is: ", ans)

	ans -= k
	fmt.Println("The difference in minutes after subtracting ", k, " is: ", ans)

	hours := ans / 60
	minutes := ans % 60
	fmt.Println(hours, " hours and ", minutes, " minutes")
=======
package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var h1, h2, m1, m2, k int
    fmt.Println("Enter hours and minutes for the first time: ")
    fmt.Scanf("%d %d", &h1, &m1)
    fmt.Println("Enter hours and minutes for the second time: ")
    fmt.Scanf("%d %d", &h2, &m2)
    ans := h2*60 + m2
    fmt.Println("The total minutes of the second time are: ", ans)
    ans -= h1*60 + m1
    fmt.Println("The difference in minutes is: ", ans)
    fmt.Println("Enter the difference in minutes: ")
    fmt.Scanf("%d", &k)
    ans -= k
    fmt.Println("The difference in minutes after subtracting ", k, " is: ", ans)
    hours := ans / 60
    minutes := ans % 60
    fmt.Println(hours, " hours and ", minutes, " minutes")
>>>>>>> 98c87cb78a (data updated)
}

