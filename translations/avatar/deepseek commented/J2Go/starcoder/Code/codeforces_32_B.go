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
	fmt.Print("Enter a string: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, "\r", "", -1)
	input = strings.Replace(input, ".", "0", -1)
	input = strings.Replace(input, " ", "1", -1)
	input = strings.Replace(input, "0", "2", -1)
	input = strings.Replace(input, "1", "3", -1)
	input = strings.Replace(input, "2", "4", -1)
	input = strings.Replace(input, "3", "5", -1)
	input = strings.Replace(input, "4", "6", -1)
	input = strings.Replace(input, "5", "7", -1)
	input = strings.Replace(input, "6", "8", -1)
	input = strings.Replace(input, "7", "9", -1)
	input = strings.Replace(input, "8", ".", -1)
	input = strings.Replace(input, "9", ".", -1)
	fmt.Println(input)
}

