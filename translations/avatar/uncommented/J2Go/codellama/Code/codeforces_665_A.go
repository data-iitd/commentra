
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, tA, b, tB int
	var hrs, mins int
	var simDeparture, simArrival int
	var counter int

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	tokens := strings.Split(line, " ")
	a, _ = strconv.Atoi(tokens[0])
	tA, _ = strconv.Atoi(tokens[1])
	scanner.Scan()
	line = scanner.Text()
	tokens = strings.Split(line, " ")
	b, _ = strconv.Atoi(tokens[0])
	tB, _ = strconv.Atoi(tokens[1])
	scanner.Scan()
	line = scanner.Text()
	tokens = strings.Split(line, ":")
	hrs, _ = strconv.Atoi(tokens[0])
	mins, _ = strconv.Atoi(tokens[1])
	simDeparture = hrs*60 + mins
	simArrival = simDeparture + tA
	for i := 300; i < 1440; i += b {
		busDeparture := i
		busArrival := i + tB
		if busDeparture >= simArrival || simDeparture >= busArrival {
			continue
		}
		counter++
	}
	fmt.Println(counter)
}

