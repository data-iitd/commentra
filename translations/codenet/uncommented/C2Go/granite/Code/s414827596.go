
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
		line, _, err := reader.ReadLine()
		if err!= nil {
			break
		}
		fields := strings.Fields(string(line))
		a, _ := strconv.Atoi(fields[0])
		b, _ := strconv.Atoi(fields[1])
		c, _ := strconv.Atoi(fields[2])
		d, _ := strconv.Atoi(fields[3])
		e, _ := strconv.Atoi(fields[4])
		f, _ := strconv.Atoi(fields[5])
		y := float64(c*d-f*a) / float64(b*d-e*a)
		x := float64(c*e-f*b) / float64(a*e-d*b)
		if y <= 0 && y > -0.0005 {
			y = 0
		}
		if x <= 0 && x > -0.0005 {
			x = 0
		}
		fmt.Printf("%.3f %.3f\n", x, y)
	}
}

