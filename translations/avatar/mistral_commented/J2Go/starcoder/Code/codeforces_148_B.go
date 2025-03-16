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
	fmt.Print("Enter VP: ")
	VP, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Print("Enter VD: ")
	VD, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Print("Enter T: ")
	T, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Print("Enter F: ")
	F, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Print("Enter C: ")
	C, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)

	if VD <= VP {
		fmt.Println("0")
		return
	}

	var answer int
	start := T

	for {
		x := start * VP / (VD - VP)
		if (start+x)*VP >= C {
			break
		}
		start += 2 * x + F
		answer++
	}

	fmt.Println(answer)
}

