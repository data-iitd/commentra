
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read a line of input from stdin and save it to our variable, inputString
	inputString, _ := bufio.NewReader(os.Stdin).ReadString('\n')

	// Convert our string input into an integer using strconv.Atoi
	inputInt, _ := strconv.Atoi(strings.TrimSpace(inputString))

	// Print the result of (inputInt - 2) * 180
<<<<<<< HEAD
	fmt.Println((inputInt - 2) * 180)
=======
	fmt.Printf("%d\n", (inputInt-2)*180)
>>>>>>> 98c87cb78a (data updated)
}

