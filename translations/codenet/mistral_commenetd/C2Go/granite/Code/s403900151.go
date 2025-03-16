
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	for {
		n, r, err := readThreeNumbers(reader)
		if err!= nil {
			break
		}

		a := make([]int, n)
		for i := 0; i < n; i++ {
			a[i] = i + 1
		}

		for i := 0; i < r; i++ {
			p, c, err := readThreeNumbers(reader)
			if err!= nil {
				break
			}

			b := make([]int, c)
			for j := 0; j < c; j++ {
				b[j] = a[n-p-c+1+j]
			}

			for j := 0; j < p-1; j++ {
				a[n-p+j+1] = a[n-p+j]
			}

			for j := n - p - c + 1, k := 0; k < c; j, k = j+1, k+1 {
				a[j] = b[k]
			}

			fmt.Println(a[n-1])
		}
	}
}

func readThreeNumbers(reader *bufio.Reader) (int, int, error) {
	line, err := reader.ReadString('\n')
	if err!= nil {
		return 0, 0, err
	}

	parts := strings.Split(line, " ")
	if len(parts)!= 3 {
		return 0, 0, fmt.Errorf("invalid input")
	}

	n, err := strconv.Atoi(parts[0])
	if err!= nil {
		return 0, 0, err
	}

	r, err := strconv.Atoi(parts[1])
	if err!= nil {
		return 0, 0, err
	}

	p, err := strconv.Atoi(parts[2])
	if err!= nil {
		return 0, 0, err
	}

	return n, r, nil
}

