
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
	b, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
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
