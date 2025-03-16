
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var num int
	var vecIntValue []int
	var i, j, k int
	var iIntValue int

	fmt.Scan(&num)
	for i = 0; i < num; i++ {
		fmt.Scan(&iIntValue)
		vecIntValue = append(vecIntValue, iIntValue)
	}

	for i = 1; i < len(vecIntValue); i++ {
		if i != 0 {
			iIntValue = vecIntValue[i]
			j = i - 1
			for j >= 0 && vecIntValue[j] > iIntValue {
				vecIntValue[j+1] = vecIntValue[j]
				j--
			}
			vecIntValue[j+1] = iIntValue
		}

		for k = 0; k < len(vecIntValue); k++ {
			fmt.Print(vecIntValue[k])
			if k != len(vecIntValue)-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}

