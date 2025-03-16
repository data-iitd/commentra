package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	sc := bufio.NewScanner(in)
	sc.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	n, _ := strconv.Atoi(sc.Text())
	s, _ := strconv.Atoi(sc.Text())
	max := 0
	for n > 0 {
		f, _ := strconv.Atoi(sc.Text())
		t, _ := strconv.Atoi(sc.Text())
		if max < f+t {
			max = f + t
		}
		n--
	}
	fmt.Println(max)
}

