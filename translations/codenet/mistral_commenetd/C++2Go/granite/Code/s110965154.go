

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to sort the vector in ascending order using insertion sort algorithm
func sort(a_rvecIntValue []int) {
	for i := 0; i < len(a_rvecIntValue); i++ {
		if i!= 0 {
			j := i - 1
			for j >= 0 && a_rvecIntValue[j] > a_rvecIntValue[i] {
				a_rvecIntValue[j+1] = a_rvecIntValue[j]
				j--
			}
			a_rvecIntValue[j+1] = a_rvecIntValue[i]
		}
		for k := 0; k < len(a_rvecIntValue); k++ {
			fmt.Printf("%d", a_rvecIntValue[k])
			if k!= len(a_rvecIntValue)-1 {
				fmt.Printf(" ")
			}
		}
		fmt.Println()
	}
}

func main() {
	var iNum int
	var iIntValue int
	var vecIntValue []int
	var err error
	var line string
	var scanner *bufio.Scanner

	scanner = bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		line = scanner.Text()
		iNum, err = strconv.Atoi(line)
		if err!= nil {
			fmt.Println("Error:", err)
			return
		}
	}

	for i := 0; i < iNum; i++ {
		if scanner.Scan() {
			line = scanner.Text()
			iIntValue, err = strconv.Atoi(line)
			if err!= nil {
				fmt.Println("Error:", err)
				return
			}
			vecIntValue = append(vecIntValue, iIntValue)
		}
	}

	sort(vecIntValue)
}

