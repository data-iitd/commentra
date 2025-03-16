

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
	for {
		input, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		input = strings.TrimSpace(input)
		if input == "" {
			continue
		}
		parts := strings.Split(input, " ")
		if len(parts)!= 6 {
			continue
		}
		a, err := strconv.Atoi(parts[0])
		if err!= nil {
			continue
		}
		b, err := strconv.Atoi(parts[1])
		if err!= nil {
			continue
		}
		c, err := strconv.Atoi(parts[2])
		if err!= nil {
			continue
		}
		d, err := strconv.Atoi(parts[3])
		if err!= nil {
			continue
		}
		e, err := strconv.Atoi(parts[4])
		if err!= nil {
			continue
		}
		f, err := strconv.Atoi(parts[5])
		if err!= nil {
			continue
		}
		x := float64(c*e-f*b) / float64(a*e-d*b)
		y := float64(c*d-f*a) / float64(b*d-e*a)
		if x <= 0.0005 {
			x = 0
		}
		if y <= 0.0005 {
			y = 0
		}
		fmt.Printf("%.3f %.3f\n", x, y)
	}
}

