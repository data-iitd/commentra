
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	number, _ := strconv.Atoi(text)
	if number < 60 {
		fmt.Printf("0:0:%d\n", number)
	} else if number < 3600 {
		minutes := number / 60
		seconds := number % 60
		fmt.Printf("0:%d:%d\n", minutes, seconds)
	} else {
		hours := number / 3600
		minutes := (number % 3600) / 60
		seconds := (number % 3600) % 60
		fmt.Printf("%d:%d:%d\n", hours, minutes, seconds)
	}
}

