package main

import (
	"fmt"
)

func main() {
	var sheep, wolf int
	fmt.Scan(&sheep, &wolf)

	if wolf >= sheep {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

