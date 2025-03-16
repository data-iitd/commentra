
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	A, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	B, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	H, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	M, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	AA := float64(A)
	BB := float64(B)
	HH := float64(H)
	MM := float64(M)
	ans2 := math.Pow(AA, 2) + math.Pow(BB, 2)
	mkaku := MM * 6
	hkaku := HH * 30 + MM/2
	kaku := mkaku - hkaku
	dkaku := math.Abs(math.ToRadians(kaku))
	AA2 := math.Pow(AA, 2)
	BB2 := math.Pow(BB, 2)
	CC := AA2 + BB2
	DD := math.Cos(dkaku) * 2 * AA * BB
	ans2 = CC - DD
	ans := math.Sqrt(ans2)
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	panic(err)
}