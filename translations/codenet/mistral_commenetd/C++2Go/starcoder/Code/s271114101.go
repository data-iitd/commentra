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
	fmt.Println("Enter three integers:")
	a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	c, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	if (a+b == c) || (b+c == a) || (a+c == b) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

