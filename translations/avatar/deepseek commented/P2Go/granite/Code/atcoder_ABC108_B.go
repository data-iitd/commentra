
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	p, _ := reader.ReadString('\n')
	p = p[:len(p)-1]
	p_split := strings.Split(p, " ")
	x1, _ := strconv.Atoi(p_split[0])
	y1, _ := strconv.Atoi(p_split[1])
	x2, _ := strconv.Atoi(p_split[2])
	y2, _ := strconv.Atoi(p_split[3])
	DIF1 := x2 - x1
	DIF2 := y2 - y1
	x3 := x2 - DIF2
	y3 := y2 + DIF1
	x4 := x1 - DIF2
	y4 := y1 + DIF1
	fmt.Println(strconv.Itoa(x3) + " " + strconv.Itoa(y3) + " " + strconv.Itoa(x4) + " " + strconv.Itoa(y4))
}
