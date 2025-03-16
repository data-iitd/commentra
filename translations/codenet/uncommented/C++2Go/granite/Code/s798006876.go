
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MAX_N = 1000

var data [MAX_N]int

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		m, nmi, nma, err := readLine(reader)
		if err!= nil {
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
		for i := nmi - 1; i < nma; i++ {
			if ma <= data[i]-data[i+1] {
				ans = i + 1
				ma = data[i] - data[i+1]
			}
		}
		fmt.Println(ans)
	}
}

func readLine(reader *bufio.Reader) (int, int, int, error) {
	line, err := reader.ReadString('\n')
	if err!= nil {
		return 0, 0, 0, err
	}
	fields := strings.Fields(line)
	m, err := strconv.Atoi(fields[0])
	if err!= nil {
		return 0, 0, 0, err
	}
	nmi, err := strconv.Atoi(fields[1])
	if err!= nil {
		return 0, 0, 0, err
	}
	nma, err := strconv.Atoi(fields[2])
	if err!= nil {
		return 0, 0, 0, err
	}
	return m, nmi, nma, nil
}

func readInt(reader *bufio.Reader) (int, error) {
	bytes, err := reader.ReadBytes('\n')
	if err!= nil {
		return 0, err
	}
	n, err := strconv.Atoi(string(bytes))
	if err!= nil {
		return 0, err
	}
	return n, nil
}

