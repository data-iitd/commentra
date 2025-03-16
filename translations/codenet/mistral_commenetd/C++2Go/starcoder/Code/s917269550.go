
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter x: ")
	x, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadString()), 10, 64)
	fmt.Print("Enter y: ")
	y, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadString()), 10, 64)
	if abs(x-y) <= 1 {
		fmt.Println("Brown")
	} else {
		fmt.Println("Alice")
	}
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

