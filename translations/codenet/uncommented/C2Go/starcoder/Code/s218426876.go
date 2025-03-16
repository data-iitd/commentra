package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var sum int
	var flag bool
	var x string
	for {
		x, _ = os.Stdin.ReadString('\n')
		x = strings.TrimSpace(x)
		if x == "0" {
			break
		}
		for _, v := range x {
			sum += int(v - '0')
		}
		fmt.Println(sum)
		sum = 0
	}
}

