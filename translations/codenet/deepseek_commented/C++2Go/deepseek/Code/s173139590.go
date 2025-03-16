package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)

	var acCount, waCount, tleCount, reCount int

	for i := 0; i < n; i++ {
		result, _ := reader.ReadString('\n')
		result = strings.TrimSpace(result)

		switch result {
		case "AC":
			acCount++
		case "WA":
			waCount++
		case "TLE":
			tleCount++
		case "RE":
			reCount++
		}
	}

	fmt.Println("AC x", acCount)
	fmt.Println("WA x", waCount)
	fmt.Println("TLE x", tleCount)
	fmt.Println("RE x", reCount)
}
