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
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	text = strings.Replace(text, "\n", "", -1)
	a, _ := strconv.Atoi(text)
	fmt.Print("Enter another number: ")
	text, _ = reader.ReadString('\n')
	text = strings.Replace(text, "\n", "", -1)
	b, _ := strconv.Atoi(text)
	if a > 0 {
		fmt.Println("Positive")
	} else if b >= 0 {
		fmt.Println("Zero")
	} else if (b-a+1)%2 == 0 {
		fmt.Println("Positive")
	} else {
		fmt.Println("Negative")
	}
}

