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
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	number, _ := strconv.ParseInt(input, 10, 64)
	var result int64
	for number > 0 {
		result = result + number%10*int64(math.Pow(10, float64(len(fmt.Sprintf("%d", number))/2)))
		number = number / 10
	}
	fmt.Println(result)
}

