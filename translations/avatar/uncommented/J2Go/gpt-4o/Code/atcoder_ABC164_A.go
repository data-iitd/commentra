package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	var scList []string
	for {
		var input string
		_, err := fmt.Scanln(&input)
		if err != nil {
			break
		}
		scList = append(scList, input)
	}

	numlist := strings.Split(scList[0], " ")
	Sheep := 0
	Wolve := 0
	fmt.Sscanf(numlist[0], "%d", &Sheep)
	fmt.Sscanf(numlist[1], "%d", &Wolve)

	if Wolve >= Sheep {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

// <END-OF-CODE>
