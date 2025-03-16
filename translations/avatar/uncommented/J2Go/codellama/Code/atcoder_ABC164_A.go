package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
	var scList []string
	for {
		scanner.Scan()
		scList = append(scList, scanner.Text())
		if err := scanner.Err(); err != nil {
			break
		}
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

