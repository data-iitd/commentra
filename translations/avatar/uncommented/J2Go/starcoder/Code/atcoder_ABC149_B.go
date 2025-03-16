package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Main struct {
	A, B, K, x, y int64
}

func main() {
	ins := new(Main)
	ins.readInput()
	ins.calc()
	ins.showResult()
}

func (ins *Main) readInput() {
	reader := bufio.NewReader(os.Stdin)
	ins.A, ins.B, ins.K = readLongs(reader)
}

func (ins *Main) calc() {
	ins.x = ins.A
	ins.y = ins.B
	ins.x -= ins.K
	if ins.x < 0 {
		ins.y += ins.x
		ins.x = 0
		if ins.y < 0 {
			ins.y = 0
		}
	}
}

func (ins *Main) showResult() {
	fmt.Println(ins.x, ins.y)
}

func readLongs(reader *bufio.Reader) (int64, int64, int64) {
	tokens := strings.Split(readLine(reader), " ")
	a, _ := strconv.ParseInt(tokens[0], 10, 64)
	b, _ := strconv.ParseInt(tokens[1], 10, 64)
	k, _ := strconv.ParseInt(tokens[2], 10, 64)
	return a, b, k
}

func readLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

