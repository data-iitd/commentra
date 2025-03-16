package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var scList []string

	// The following for loop reads input lines from the console and stores them in the ArrayList
	for {
		scanner.Scan()
		line := scanner.Text()
		scList = append(scList, line)
		if len(line) == 0 {
			break
		}
	}

	// The following line extracts the first line of the input (which contains the number of sheep and wolves)
	numlist := strings.Split(scList[0], " ")

	// The following two lines parse the first two elements of the numlist array as integers representing the number of sheep and wolves
	Sheep, _ := strconv.Atoi(numlist[0])
	Wolve, _ := strconv.Atoi(numlist[1])

	// The following if statement checks if the number of wolves is greater than or equal to the number of sheep.
	// If so, it prints the message "unsafe" to the console. Otherwise, it prints the message "safe".
	if Wolve >= Sheep {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}
