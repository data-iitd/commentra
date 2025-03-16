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
	fmt.Println("Enter the number of events (n) and the starting time (s):")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	n, s := strings.Split(input, " ")
	n, _ = strconv.Atoi(n)
	s, _ = strconv.Atoi(s)
	fmt.Println("Enter the finish time (f) and the time taken (t) for each event:")
	c := 0
	for i := 0; i < n; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSuffix(input, "\n")
		f, t := strings.Split(input, " ")
		f, _ = strconv.Atoi(f)
		t, _ = strconv.Atoi(t)
		x := t - (s - f)
		if x > c {
			c = x
	}
	fmt.Println("The total time including the maximum additional time is:", s+c)
}

