

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func generateString() string {
	sb := &strings.Builder{}
	for i := 1; i <= 1000; i++ {
		sb.WriteString(strconv.Itoa(i))
	}
	return sb.String()
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	n, _ := reader.ReadString('\n')
	nInt, _ := strconv.Atoi(n)
	fmt.Println(generateString()[nInt-1])
}

