package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	fmt.Printf("%c%d%c\n", line[0], len(line)-3, line[len(line)-2])
}

