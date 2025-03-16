
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	xTemp := strings.Split(readLine(reader), " ")

	var x []int32

	for i := 0; i < int(n); i++ {
		xItemTemp, err := strconv.ParseInt(xTemp[i], 10, 64)
		checkError(err)
		xItem := int32(xItemTemp)
		x = append(x, xItem)
	}

	a := make([]int32, 0)
	b := make([]int32, 0)

	for i := 0; i < int(n); i++ {
		if i%2 == 0 {
			a = append(a, x[i])
		} else {
			b = append(b, x[i])
		}
	}

	cnta := make([]int32, 100002+1)
	cntb := make([]int32, 100002+1)

	for i := 0; i < len(a); i++ {
		cnta[a[i]]++
	}

	for i := 0; i < len(b); i++ {
		cntb[b[i]]++
	}

	vala := int32(0)
	vala1 := int32(0)
	maxCnta := int32(0)
	maxCnta1 := int32(0)

	for i := 0; i < 100002+1; i++ {
		if maxCnta < cnta[i] {
			vala = int32(i)
			maxCnta = cnta[i]
		}

		if maxCnta1 < cnta[i] && vala!= int32(i) {
			maxCnta1 = cnta[i]
			vala1 = int32(i)
		}
	}

	valb := int32(0)
	valb1 := int32(0)
	maxCntb := int32(0)
	maxCntb1 := int32(0)

	for i := 0; i < 100002+1; i++ {
		if maxCntb < cntb[i] {
			valb = int32(i)
			maxCntb = cntb[i]
		}

		if maxCntb1 < cntb[i] && valb!= int32(i) {
			maxCntb1 = cntb[i]
			valb1 = int32(i)
		}
	}

	if valb!= vala {
		res := int32(0)

		for i := 0; i < len(a); i++ {
			if a[i]!= vala {
				res++
			}
		}

		for i := 0; i < len(b); i++ {
			if b[i]!= valb {
				res++
			}
		}

		fmt.Println(res)
	} else {
		resa := int32(0)
		resb := int32(0)
		resa1 := int32(0)
		resb1 := int32(0)

		for i := 0; i < len(a); i++ {
			if a[i]!= vala {
				resa++
			}

			if a[i]!= vala1 {
				resa1++
			}
		}

		for i := 0; i < len(b); i++ {
			if b[i]!= valb {
				resb++
			}

			if b[i]!= valb1 {
				resb1++
			}
		}

		fmt.Println(int32(min(resa+resb1, resa1+resb)))
	}
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

func min(a, b int32) int32 {
	if a < b {
		return a
	}

	return b
}

