package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanLines)
	sc.Scan()
	numlist := strings.Split(sc.Text(), " ")
	Sheep, _ := strconv.Atoi(numlist[0])
	Wolve, _ := strconv.Atoi(numlist[1])
	if Wolve >= Sheep {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

