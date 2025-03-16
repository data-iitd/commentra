package main

import "fmt"

func main() {
	// Declare variables to hold the number of sheep and wolves
	var sheep int
	var wolf int

	// Read the number of sheep and wolves from user input
	fmt.Scanf("%d %d", &sheep, &wolf)

	// Check if the number of wolves is greater than or equal to the number of sheep
	if wolf >= sheep {
		// If there are more wolves than sheep, it's unsafe
		fmt.Println("unsafe")
	} else {
		// If there are fewer wolves than sheep, it's safe
		fmt.Println("safe")
	}
}

