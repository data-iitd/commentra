
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

	// Ask user for the number of elements in the list
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	// Get the list of numbers from user input
	numberTemp, err := reader.ReadString('\n')
	checkError(err)
	numberTemp = strings.TrimSpace(numberTemp)
	number := strings.Split(numberTemp, " ")

	// Initialize variables h1 and h2 to 0
	h1 := int64(0)
	h2 := int64(0)

	// Iterate through the list of numbers
	for i := 0; i < int(n); i++ {
		// Check if the current number is not 4 and not 7
		if _, ok := map[int64]bool{4: true, 7: true}[int64(strings.TrimSpace(number[i]))];!ok {
			// Print "NO" and break the loop if the condition is met
			fmt.Println("NO")
			os.Exit(0)
		}

		// If the index is less than half the length of the list, add the number to h1
		if i < int(n)/2 {
			h1 += int64(strings.TrimSpace(number[i]))
		}

		// If the index is greater than or equal to half the length of the list, add the number to h2
		else {
			h2 += int64(strings.TrimSpace(number[i]))
		}
	}

	// Check if h1 and h2 are equal, print "YES"
	if h1 == h2 {
		fmt.Println("YES")
	}
	// If h1 and h2 are not equal, print "NO"
	else {
		fmt.Println("NO")
	}
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

