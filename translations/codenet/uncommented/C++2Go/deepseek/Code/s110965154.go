package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func sort(vecIntValue []int) {
	for i := 0; i < len(vecIntValue); i++ {
		if i != 0 {
			iIntValue := vecIntValue[i]
			j := i - 1
			for j >= 0 && vecIntValue[j] > iIntValue {
				vecIntValue[j+1] = vecIntValue[j]
				j--
			}
			vecIntValue[j+1] = iIntValue
		}
		for k := 0; k < len(vecIntValue); k++ {
			fmt.Print(vecIntValue[k])
			if k != len(vecIntValue)-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	iNum, _ := strconv.Atoi(strings.TrimSpace(input))
	vecIntValue := []int{}
	for i := 0; i < iNum; i++ {
		input, _ := reader.ReadString('\n')
		iIntValue, _ := strconv.Atoi(strings.TrimSpace(input))
		vecIntValue = append(vecIntValue, iIntValue)
	}
	sort(vecIntValue)
}

