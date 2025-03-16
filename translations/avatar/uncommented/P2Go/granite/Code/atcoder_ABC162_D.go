
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)
	s := readLine(reader)
	rNum := 0
	gNum := 0
	bNum := 0
	for i := 0; i < int(n); i++ {
		if string(s[i]) == "R" {
			rNum++
		} else if string(s[i]) == "G" {
			gNum++
		} else if string(s[i]) == "B" {
			bNum++
		}
	}
	sum := 0
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		for i := 0; i < int(n-2*step); i++ {
			s := string(s[i]) + string(s[i+step]) + string(s[i+step*2])
			if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
				sum++
			}
		}
	}
	fmt.Println(rNum * gNum * bNum - sum)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	panic(err)
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}
