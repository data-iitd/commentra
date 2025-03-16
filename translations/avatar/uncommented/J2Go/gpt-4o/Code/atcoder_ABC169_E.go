package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	const num = 998244353
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1]) // Convert string to int

	ai := make([]int, n)
	bi := make([]int, n)

	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		tokens := bufio.NewScanner(bufio.NewReaderString(line))
		tokens.Split(bufio.ScanWords)

		tokens.Scan()
		ai[i], _ = strconv.Atoi(tokens.Text())
		tokens.Scan()
		bi[i], _ = strconv.Atoi(tokens.Text())
	}

	sort.Ints(ai)
	sort.Ints(bi)

	if n%2 == 1 {
		result := bi[n/2] - ai[n/2] + 1
		fmt.Fprintln(writer, result)
	} else {
		b := float64(ai[n/2]+ai[n/2-1]) / 2
		c := float64(bi[n/2]+bi[n/2-1]) / 2
		result := int(2*(c-b) + 1)
		fmt.Fprintln(writer, result)
	}
}

// <END-OF-CODE>
