package main

import (
	"fmt"
	"math"
)

func main() {
	menu := [][]int{}
	for i := 0; i < 5; i++ {
		var m string
		fmt.Scan(&m) // Taking input from the user
		e := int(m[len(m)-1] - '0') // Extracting the last digit and converting it to an integer
		if e == 0 {
			e = 10 // If the last digit is 0, change it to 10
		}
		menu = append(menu, []int{toInt(m), e}) // Appending the input value and the processed last digit as a list to the menu list
	}
	sortMenu(menu) // Sorting the menu list based on the last digit
	ans := 0
	for _, m := range menu[1:] {
		ans += int(math.Ceil(float64(m[0]) / 10)) * 10 // Calculating the sum of the ceiling of each element divided by 10, multiplied by 10
	}
	fmt.Println(ans + menu[0][0]) // Printing the sum of the first element and the calculated ans
}

func toInt(s string) int {
	var result int
	for _, char := range s {
		result = result*10 + int(char-'0')
	}
	return result
}

func sortMenu(menu [][]int) {
	for i := 0; i < len(menu); i++ {
		for j := i + 1; j < len(menu); j++ {
			if menu[i][1] > menu[j][1] {
				menu[i], menu[j] = menu[j], menu[i]
			}
		}
	}
}

