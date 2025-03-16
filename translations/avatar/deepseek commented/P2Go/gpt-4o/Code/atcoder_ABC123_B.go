package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
)

func main() {
	menu := [][]int{}
	for i := 0; i < 5; i++ {
		var m string
		fmt.Scan(&m) // Taking input from the user
		e, _ := strconv.Atoi(string(m[len(m)-1])) // Extracting the last digit and converting it to an integer
		if e == 0 {
			e = 10 // If the last digit is 0, change it to 10
		}
		value, _ := strconv.Atoi(m)
		menu = append(menu, []int{value, e}) // Appending the input value and the processed last digit as a slice to the menu slice
	}

	sort.Slice(menu, func(i, j int) bool {
		return menu[i][1] < menu[j][1] // Sorting the menu slice based on the last digit
	})

	ans := 0
	for _, m := range menu[1:] {
		ans += int(math.Ceil(float64(m[0]) / 10)) * 10 // Calculating the sum of the ceiling of each element divided by 10, multiplied by 10
	}
	fmt.Println(ans + menu[0][0]) // Printing the sum of the first element and the calculated ans
}

// <END-OF-CODE>
