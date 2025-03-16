
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
	fmt.Print("Enter A: ")
	text, _ := reader.ReadString('\n')
	A, _ := strconv.Atoi(strings.TrimSpace(text))
	fmt.Print("Enter B: ")
	text, _ = reader.ReadString('\n')
	B, _ := strconv.Atoi(strings.TrimSpace(text))

	if A < 13 && A >= 6 {
		fmt.Println(B / 2)
	}

	if A < 6 {
		fmt.Println(0)
	}

	if A >= 13 {
		fmt.Println(B)
	}
}

