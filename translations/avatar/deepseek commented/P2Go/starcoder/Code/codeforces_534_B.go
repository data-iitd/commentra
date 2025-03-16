
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
	v1, v2, t, d := readInput(reader)
	distance := 0
	a := 1
	v := v1
	for i := 0; i < t; i++ {
		if v-v2 > (t-i-1)*d {
			a *= -1
			v = (t-i-1)*d + v2
		}
		distance += v
		v += a*d
	}
	fmt.Println(distance)
}

func readInput(reader *bufio.Reader) (int, int, int, int) {
	v1, v2, t, d := 0, 0, 0, 0
	fmt.Fscanln(reader, &v1, &v2, &t, &d)
	return v1, v2, t, d
}

