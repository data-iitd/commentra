
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the initial speed of the police car (VP): ")
	VP, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Println("Enter the initial speed of the thief car (VD): ")
	VD, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Println("Enter the initial head start time (T): ")
	T, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Println("Enter the time it takes for the police car to refuel (F): ")
	F, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Println("Enter the distance to catch the thief (C): ")
	C, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)

	if VD <= VP {
		fmt.Println("0")
		return
	}

	answer := 0
	start := T

	for {
		x := start * VP / (VD - VP)
		if (start + x) * VP >= C {
			break
		}
		start += 2 * x + F
		answer++
	}

	fmt.Println(answer)
}

