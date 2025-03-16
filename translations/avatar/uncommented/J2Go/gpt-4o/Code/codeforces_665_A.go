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
	writer := bufio.NewWriter(os.Stdout)

	// Read first line
	line1, _ := reader.ReadString('\n')
	tokens1 := strings.Fields(line1)
	a, _ := strconv.Atoi(tokens1[0])
	tA, _ := strconv.Atoi(tokens1[1])

	// Read second line
	line2, _ := reader.ReadString('\n')
	tokens2 := strings.Fields(line2)
	b, _ := strconv.Atoi(tokens2[0])
	tB, _ := strconv.Atoi(tokens2[1])

	// Read timing line
	timing, _ := reader.ReadString('\n')
	timing = strings.TrimSpace(timing)
	hrs, _ := strconv.Atoi(timing[:2])
	mins, _ := strconv.Atoi(timing[3:])

	simDeparture := hrs*60 + mins
	simArrival := simDeparture + tA
	counter := 0

	for i := 300; i < 1440; i += b {
		busDeparture := i
		busArrival := i + tB
		if busDeparture >= simArrival || simDeparture >= busArrival {
			continue
		}
		counter++
	}

	fmt.Fprintln(writer, counter)
	writer.Flush()
}

// <END-OF-CODE>
