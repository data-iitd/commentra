
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

	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	aTemp := strings.Split(nTemp, " ")
	a := make([]int64, n)
	for i := 0; i < int(n); i++ {
		aTemp[i], err = reader.ReadString('\n')
		checkError(err)
		a[i], err = strconv.ParseInt(strings.TrimSpace(aTemp[i]), 10, 64)
		checkError(err)
	}

	r := make([]string, 0)

	m := int64(0)
	for i := 1; i < int(n); i++ {
		if int(math.Abs(float64(a[m]))) < int(math.Abs(float64(a[i]))) {
			m = int64(i)
		}
	}

	for i := 0; i < int(n); i++ {
		if (a[m] >= 0)!= (a[i] >= 0) {
			r = append(r, fmt.Sprintf("%d %d", m+1, i+1))
		}
	}

	if a[m] >= 0 {
		for i := 1; i < int(n); i++ {
			r = append(r, fmt.Sprintf("%d %d", i+1, i+2))
		}
	} else {
		for i := n; i > 1; i-- {
			r = append(r, fmt.Sprintf("%d %d", i, i-1))
		}
	}

	fmt.Println(len(r))
	for _, val := range r {
		fmt.Println(val)
	}
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

