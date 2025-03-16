
###
# Code
###

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
	checkError(err)

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 1024*1024)

	nMr := strings.Split(readLine(reader), " ")

	nTemp, err := strconv.ParseInt(nMr[0], 10, 64)
	checkError(err)
	n := int32(nTemp)

	mTemp, err := strconv.ParseInt(nMr[1], 10, 64)
	checkError(err)
	m := int32(mTemp)

	out := make([]int32, n)

	comp := make([]int32, n)

	for i := int32(0); i < n; i++ {
		comp[i] = int32(i+2)
	}

	for i := int32(0); i < m; i++ {
		lrx := strings.Split(readLine(reader), " ")

		lTemp, err := strconv.ParseInt(lrx[0], 10, 64)
		checkError(err)
		l := int32(lTemp)

		rTemp, err := strconv.ParseInt(lrx[1], 10, 64)
		checkError(err)
		r := int32(rTemp)

		xTemp, err := strconv.ParseInt(lrx[2], 10, 64)
		checkError(err)
		x := int32(xTemp)

		t := l
		for t <= r {
			if out[t-1] == 0 && t!= x {
				out[t-1] = x
			}

			nextVal := comp[t-1]
			comp[t-1] = r + 1
			if t >= x {
				comp[t-1] = x
			}

			t = nextVal
		}
	}

	for i := int32(0); i < n; i++ {
		fmt.Fprintf(writer, "%d ", out[i])
	}

	fmt.Fprintf(writer, "\n")

	writer.Flush()
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}