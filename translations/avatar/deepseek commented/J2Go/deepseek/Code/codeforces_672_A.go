package main

import (
	"bufio"
	"fmt"
	"os"
)

// This function generates a string of numbers from 1 to 1000
func generateString() string {
	var sb strings.Builder
	for i := 1; i <= 1000; i++ {
		sb.WriteString(strconv.Itoa(i))
	}
	return sb.String()
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter an integer: ")
	n, _ := strconv.Atoi(readLine(reader))
	str := generateString()
	fmt.Println(string(str[n - 1]))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		return ""
	}
	return string(str)
}
