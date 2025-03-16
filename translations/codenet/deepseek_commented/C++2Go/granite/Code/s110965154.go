
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter the number of integers to be sorted: ")
	num, _ := reader.ReadString('\n')
	num = strings.TrimSpace(num)
	numInt, _ := strconv.Atoi(num)

	vecIntValue := make([]int, 0)
	for i := 0; i < numInt; i++ {
		fmt.Print("Enter integer " + strconv.Itoa(i+1) + ": ")
		intStr, _ := reader.ReadString('\n')
		intStr = strings.TrimSpace(intStr)
		intVal, _ := strconv.Atoi(intStr)
		vecIntValue = append(vecIntValue, intVal)
	}

	sort(vecIntValue)
}

func sort(vecIntValue []int) {
	for i := 1; i < len(vecIntValue); i++ {
		intVal := vecIntValue[i]
		j := i - 1
		for j >= 0 && vecIntValue[j] > intVal {
			vecIntValue[j+1] = vecIntValue[j]
			j--
		}
		vecIntValue[j+1] = intVal
		fmt.Println(vecIntValue)
	}
}

// Output:
// Enter the number of integers to be sorted: 5
// Enter integer 1: 5
// Enter integer 2: 2
// Enter integer 3: 4
// Enter integer 4: 6
// Enter integer 5: 1
// [5 2 4 6 1]
// [2 5 4 6 1]
// [2 4 5 6 1]
// [2 4 5 6 1]
// [1 2 4 5 6]
// 