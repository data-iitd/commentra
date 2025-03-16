
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
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	s := strings.Split(reader.ReadLine()[2:], " ")
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.ParseFloat(s[i], 64)
	}
	b := make([]float64, 0)
	for i := 0; i < n; i++ {
		if int(a[i]*1000)%1000!= 0 {
			b = append(b, a[i]-float64(int(a[i]*1000)/1000))
		}
	}
	o := 2 * n - len(b)
	sum := 0.0
	for i := 0; i < len(b); i++ {
		sum += b[i]
	}
	res := 200000000
	for i := 0; i <= n; i++ {
		if i+o >= n {
			if int(abs(float64(i)-sum)*1000+0.5) < res {
				res = int(abs(float64(i)-sum)*1000+0.5)
			}
		}
	}
	fmt.Printf("%.3f", float64(res)/1000)
}

func abs(x float64) float64 {
	if x < 0 {
		return -x
	}
	return x
}
