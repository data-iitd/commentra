package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sheep, wolf := readInput()
	if wolf >= sheep {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

func readInput() (int, int) {
	var sheep, wolf int
	fmt.Scanf("%d %d", &sheep, &wolf)
	return sheep, wolf
}

