package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var scList []string
	var numlist []string
	var Sheep int
	var Wolve int

	// The following for loop reads input lines from the console and stores them in the scList slice
	for i := 0; i >= 0; i++ {
		scList = append(scList, os.Args[i])
	}

	// The following line extracts the first line of the input (which contains the number of sheep and wolves)
	numlist = strings.Split(scList[0], " ")

	// The following two lines parse the first two elements of the numlist slice as integers representing the number of sheep and wolves
	Sheep, _ = strconv.Atoi(numlist[0])
	Wolve, _ = strconv.Atoi(numlist[1])

	// The following if statement checks if the number of wolves is greater than or equal to the number of sheep.
	// If so, it prints the message "unsafe" to the console. Otherwise, it prints the message "safe".
	if Wolve >= Sheep {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

