
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize Scanner to read input
	scanner := bufio.NewScanner(os.Stdin)
	// Create an ArrayList to store input lines
	scList := make([]string, 0)

	// Continuously read input lines from the user until an exception occurs
	for i := 0; i >= 0; i++ {
		try {
			scList.add(scanner.nextLine())
		} catch (e) {
			break
		}
	}

	// Get the first line of input and split it into an array of strings
	numlist := strings.Split(scList[0], " ")

	// Parse the first element to get the number of sheep
	Sheep, _ := strconv.Atoi(numlist[0])

	// Parse the second element to get the number of wolves
	Wolve, _ := strconv.Atoi(numlist[1])

	// Check if the number of wolves is greater than or equal to the number of sheep
	if Wolve >= Sheep {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

