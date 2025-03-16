
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter a string:")
	str, _ := reader.ReadString('\n')
	sum := 0
	for _, x := range str {
		num, _ := strconv.Atoi(string(x))
		sum += num
	}
	if sum%9 == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
