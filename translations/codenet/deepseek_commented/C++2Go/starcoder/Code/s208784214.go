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
	// Step 1: Read input values
	// We read two integer values from the standard input and store them in variables N and A.
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter N: ")
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(input))
	fmt.Print("Enter A: ")
	input, _ = reader.ReadString('\n')
	A, _ := strconv.Atoi(strings.TrimSpace(input))

	// Step 2: Perform the required operation
	// We check if the remainder of N divided by 500 is less than or equal to A.
	// If the condition is true, we print "Yes"; otherwise, we print "No".
<<<<<<< HEAD
	fmt.Println((N % 500 <= A) && "Yes" || "No")
=======
	fmt.Println(N%500 <= A)
>>>>>>> 98c87cb78a (data updated)

	// Step 3: Return from the main function
	// We return 0 to indicate successful execution of the program.
	return
}

