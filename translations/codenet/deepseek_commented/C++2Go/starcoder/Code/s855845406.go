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
	fmt.Println("Enter the value of N")
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(input))
	fmt.Println("Enter the value of A")
	input, _ = reader.ReadString('\n')
	A, _ := strconv.Atoi(strings.TrimSpace(input))
	fmt.Println(N*N - A)
}

