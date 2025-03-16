
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of sides of the polygon: ")
	n, _ := strconv.Atoi(reader.ReadLine())

	// Calculate the sum of the interior angles of a polygon with 'n' sides
	// The formula for the sum of interior angles is (n - 2) * 180
	sum := (n - 2) * 180
	fmt.Println("The sum of the interior angles of the polygon is:", sum)
}

