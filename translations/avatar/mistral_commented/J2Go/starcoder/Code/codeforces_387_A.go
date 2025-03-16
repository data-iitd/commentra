
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

func main() {
	// Create a new Scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the first time (hh:mm): ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	s := strings.Split(input, ":")

	// Read the second time string from the console and split it into hour and minute parts
	fmt.Print("Enter the second time (hh:mm): ")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	t := strings.Split(input, ":")

	// Create time.Time objects `x` and `y` from the hour and minute parts of the first and second time strings, respectively
	x, _ := time.Parse("15:04", s[0]+" "+s[1])
	y, _ := time.Parse("15:04", t[0]+" "+t[1])

	// Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
	fmt.Println(x.Sub(y))
}

