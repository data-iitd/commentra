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

	line1, _ := reader.ReadString('\n')
	line2 := strings.Split(line1, " ")
	a, _ := strconv.Atoi(line2[0])
	tA, _ := strconv.Atoi(line2[1])

	line3, _ := reader.ReadString('\n')
	line4 := strings.Split(line3, " ")
	b, _ := strconv.Atoi(line4[0])
	tB, _ := strconv.Atoi(line4[1])

	line5, _ := reader.ReadString('\n')
	timing := strings.Split(line5, ":")
	hrs, _ := strconv.Atoi(timing[0])
	mins, _ := strconv.Atoi(timing[1])
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

