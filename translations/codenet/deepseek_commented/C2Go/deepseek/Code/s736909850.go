package main

import (
	"fmt"  // Step 1: Import the fmt package to use Println and Scan functions.
)

func main() {  // Step 2: Define the main function which is the entry point of the program.
	var sheep, wolf int  // Step 3: Declare two integer variables, sheep and wolf, to store the number of sheep and wolves.

	fmt.Scan(&sheep, &wolf)  // Step 4: Use the Scan function to read the number of sheep and wolves from the user.

	if wolf >= sheep {  // Step 5: Check if the number of wolves is greater than or equal to the number of sheep.
		fmt.Println("unsafe")  // Step 6: If the condition is true, print "unsafe".
	} else {
		fmt.Println("safe")  // Step 7: Otherwise, print "safe".
	}
}
