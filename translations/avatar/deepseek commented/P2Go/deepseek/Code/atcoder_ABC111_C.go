package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n, _ := strconv.Atoi(readLine(reader))
	x := parseIntArray(readLine(reader))

	a := []int{}
	b := []int{}
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			a = append(a, x[i])
		} else {
			b = append(b, x[i])
		}
	}

	cnta := make([]int, 100003)
	cntb := make([]int, 100003)

	vala, vala1, maxCnta, maxCnta1 := 0, 0, 0, 0
	for _, i := range a {
		cnta[i]++
		if cnta[i] > maxCnta {
			vala = i
			maxCnta = cnta[i]
		}
	}
	for _, i := range a {
		if cnta[i] > maxCnta1 && i != vala {
			maxCnta1 = cnta[i]
			vala1 = i
		}
	}

	valb, valb1, maxCntb, maxCntb1 := 0, 0, 0, 0
	for _, i := range b {
		cntb[i]++
		if cntb[i] > maxCntb {
			valb = i
			maxCntb = cntb[i]
		}
	}
	for _, i := range b {
		if cntb[i] > maxCntb1 && i != valb {
			maxCntb1 = cntb[i]
			valb1 = i
		}
	}

	if valb != vala {
		res := 0
		for _, i := range a {
			if i != vala {
				res++
			}
		}
		for _, i := range b {
			if i != valb {
				res++
			}
		}
		fmt.Fprintln(writer, res)
	} else {
		resa, resb, resa1, resb1 := 0, 0, 0, 0
		for _, i := range a {
			if i != vala {
				resa++
			}
			if i != vala1 {
				resa1++
			}
		}
		for _, i := range b {
			if i != valb {
				resb++
			}
			if i != valb1 {
				resb1++
			}
		}
		fmt.Fprintln(writer, min(resa+resb1, resa1+resb))
	}
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}

func parseIntArray(line string) []int {
	strArray := strings.Split(line, " ")
	intArray := make([]int, len(strArray))
	for i, str := range strArray {
		intArray[i], _ = strconv.Atoi(str)
	}
	return intArray
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
