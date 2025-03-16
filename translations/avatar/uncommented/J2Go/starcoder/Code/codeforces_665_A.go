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
	defer writer.Flush()

	line, _ := reader.ReadString('\n')
	a, _ := strconv.Atoi(strings.TrimSpace(line))
	line, _ = reader.ReadString('\n')
	tA, _ := strconv.Atoi(strings.TrimSpace(line))
	line, _ = reader.ReadString('\n')
	b, _ := strconv.Atoi(strings.TrimSpace(line))
	line, _ = reader.ReadString('\n')
	tB, _ := strconv.Atoi(strings.TrimSpace(line))
	line, _ = reader.ReadString('\n')
	timing := strings.TrimSpace(line)
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
}

