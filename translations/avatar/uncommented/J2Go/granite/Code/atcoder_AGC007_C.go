
package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.ParseFloat(reader.ReadLine(), 64)
	d, _ := strconv.ParseFloat(reader.ReadLine(), 64)
	x, _ := strconv.ParseFloat(reader.ReadLine(), 64)
	ans := big.NewFloat(0.0)
	for N > 0.5 {
		adnum := big.NewFloat(d + x*(N-0.5))
		ans = ans.Add(ans, adnum)
		d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
		x = (1.0+(2.0/N))*x
		N--
	}
	fmt.Println(ans)
}

