package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sheep, wolf := 0, 0
	fmt.Scanf("%d %d", &sheep, &wolf)
	if wolf >= sheep {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

