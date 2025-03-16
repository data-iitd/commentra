package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	str := os.Args[1]
	if str[2] == str[3] && str[4] == str[5] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

