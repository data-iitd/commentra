package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	infile := bufio.NewReader(os.Stdin)
	arr := []rune(readString(infile))
	N := len(arr)
	set := make(map[string]bool)
	var K int
	fmt.Fscan(infile, &K)
	res := 0

	for k := 0; k < K; k++ {
		input := readString(infile)
		a := 0
		b := 0
		for i := 0; i < N; i++ {
			if arr[i] == rune(input[0]) {
				a++
			} else if arr[i] == rune(input[1]) {
				b++
			} else {
				res += int(math.Min(float64(a), float64(b)))
				a = 0
				b = 0
			}
		}
		res += int(math.Min(float64(a), float64(b)))
	}
	fmt.Println(res)
}

func readString(r *bufio.Reader) string {
	str, _ := r.ReadString('\n')
	return str[:len(str)-1]
}

