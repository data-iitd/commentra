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
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	parts := strings.Split(str, " ")

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	tokens := strings.Split(line, " ")

	a, _ := strconv.Atoi(tokens[0])
	b, _ := strconv.Atoi(tokens[1])
	u := ""
	u, _ = reader.ReadString('\n')
	u = strings.TrimSpace(u)

	if u == parts[0] {
		fmt.Println(strconv.Itoa(a-1) + " " + strconv.Itoa(b))
	} else {
		fmt.Println(strconv.Itoa(a) + " " + strconv.Itoa(b-1))
	}
}

