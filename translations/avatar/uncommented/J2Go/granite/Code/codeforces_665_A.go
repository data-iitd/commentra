
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	br := bufio.NewReader(os.Stdin)
	st := strings.Split(readLine(br), " ")
	a, _ := strconv.Atoi(st[0])
	tA, _ := strconv.Atoi(st[1])
	st = strings.Split(readLine(br), " ")
	b, _ := strconv.Atoi(st[0])
	tB, _ := strconv.Atoi(st[1])
	timing := readLine(br)
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
	fmt.Println(counter)
}

func readLine(br *bufio.Reader) string {
	str, _, err := br.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(str)
}

