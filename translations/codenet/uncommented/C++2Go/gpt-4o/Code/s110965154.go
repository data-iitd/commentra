package main

import (
	"fmt"
)

func sort(a_rvecIntValue []int) {
	for i := 0; i < len(a_rvecIntValue); i++ {
		if i != 0 {
			iIntValue := a_rvecIntValue[i]
			j := i - 1
			for j >= 0 && a_rvecIntValue[j] > iIntValue {
				a_rvecIntValue[j+1] = a_rvecIntValue[j]
				j--
			}
			a_rvecIntValue[j+1] = iIntValue
		}

		for k := 0; k < len(a_rvecIntValue); k++ {
			fmt.Print(a_rvecIntValue[k])
			if k != len(a_rvecIntValue)-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}

func main() {
	var iNum int
	fmt.Scan(&iNum)
	vecIntValue := make([]int, 0, iNum)

	for iNum > 0 {
		var iIntValue int
		fmt.Scan(&iIntValue)
		vecIntValue = append(vecIntValue, iIntValue)
		iNum--
	}

	sort(vecIntValue)
}

// <END-OF-CODE>
