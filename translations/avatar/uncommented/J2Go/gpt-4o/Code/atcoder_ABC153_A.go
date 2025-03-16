package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	str := strings.Fields(input)

	h, _ := strconv.Atoi(str[0])
	a, _ := strconv.Atoi(str[1])
	num := 0

	for h > 0 {
		h -= a
		num++
	}

	fmt.Println(num)
}

// <END-OF-CODE>
