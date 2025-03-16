package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var scList []string

	for {
		scanner.Scan()
		line := scanner.Text()
		if line == "" {
			break
		}
		scList = append(scList, line)
	}

	numlist := strings.Split(scList[0], " ")
	Sheep, _ := strconv.Atoi(numlist[0])
	Wolve, _ := strconv.Atoi(numlist[1])

	if Wolve >= Sheep {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

