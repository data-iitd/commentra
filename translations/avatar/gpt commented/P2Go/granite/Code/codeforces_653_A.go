
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

	// Read an integer input which represents the number of elements in the list
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	// Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
	lTemp, err := reader.ReadString('\n')
	checkError(err)
	lTemp = strings.TrimSpace(lTemp)
	l := strings.Split(lTemp, " ")
	var lSlice []int
	for _, lTempItem := range l {
		lItem, err := strconv.ParseInt(lTempItem, 10, 64)
		checkError(err)
		lSlice = append(lSlice, int(lItem))
	}

	// Sort the list in ascending order
	for i := 0; i < len(lSlice); i++ {
		for j := 0; j < len(lSlice)-i-1; j++ {
			if lSlice[j] > lSlice[j+1] {
				temp := lSlice[j]
				lSlice[j] = lSlice[j+1]
				lSlice[j+1] = temp
			}
		}
	}

	// Iterate through each element in the sorted list
	for _, i := range lSlice {
		// Check if both i + 1 and i + 2 exist in the list
		if contains(lSlice, i+1) && contains(lSlice, i+2) {
			// If the condition is met, print 'YES' and exit the loop
			fmt.Println("YES")
			return
		}
	}
	// If the loop completes without finding the condition, print 'NO'
	fmt.Println("NO")
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

