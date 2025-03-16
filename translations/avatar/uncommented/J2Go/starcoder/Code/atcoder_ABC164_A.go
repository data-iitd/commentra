package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	scList := make([]string, 0)
	for i := 0; i >= 0; i++ {
		if scan.Scan() {
			scList = append(scList, scan.Text())
		} else {
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

