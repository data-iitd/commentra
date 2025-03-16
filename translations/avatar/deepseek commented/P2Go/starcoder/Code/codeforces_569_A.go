
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
	fmt.Println("Enter the values of t, s, q")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, ",", "", -1)
	input = strings.Replace(input, " ", "", -1)
	t, s, q := split(input)
	ans := 0
	for s < t {
		s *= q
		ans++
	}
	fmt.Println(ans)
}

func split(input string) (int, int, int) {
	var t, s, q int
	str := strings.Split(input, " ")
	t, _ = strconv.Atoi(str[0])
	s, _ = strconv.Atoi(str[1])
	q, _ = strconv.Atoi(str[2])
	return t, s, q
}

