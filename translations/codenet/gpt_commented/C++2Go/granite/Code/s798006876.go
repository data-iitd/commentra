
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const MAX_N = 1e3
	data := make([]int, MAX_N)
	reader := bufio.NewReader(os.Stdin)

	for {
		m, nmi, nma, err := readInt(reader)
		if err!= nil {
			break
		}
		if nmi == 0 {
			break
		}
		for i := 0; i < m; i++ {
			data[i], err = readInt(reader)
			if err!= nil {
				break
			}
		}
		ma := 0
		ans := 0
		for i := nmi - 1; i < nma-1; i++ {
			if ma <= data[i]-data[i+1] {
				ans = i + 1
				ma = data[i] - data[i+1]
			}
		}
		fmt.Println(ans)
	}
}

func readInt(reader *bufio.Reader) (int, error) {
	var buf [64]byte
	rd := 0
	for {
		char, _, err := reader.ReadRune()
		if err!= nil {
			return 0, err
		}
		if char =='' {
			break
		}
		buf[rd] = char
		rd++
	}
	return strconv.Atoi(string(buf[:rd]))
}

