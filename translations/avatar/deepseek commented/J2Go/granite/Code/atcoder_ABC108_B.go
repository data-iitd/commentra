
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func revpos(p []int, q []int) []int {
	vec := make([]int, 2)
	for i := 0; i < 2; i++ {
		vec[i] = p[i] - q[i]
	}
	tmp := vec[0]
	vec[0] = vec[1]
	vec[1] = -tmp
	newpos := make([]int, 2)
	for i := 0; i < 2; i++ {
		newpos[i] = q[i] + vec[i]
	}
	return newpos
}

func main() {
	scan := bufio.NewScanner(os.Stdin)
	input := make([]int, 4)
	for i := 0; i < 4; i++ {
		scan.Scan()
		num, _ := strconv.Atoi(scan.Text())
		input[i] = num
	}
	position := make([][]int, 4)
	position[0] = make([]int, 2)
	position[0][0] = input[0]
	position[0][1] = input[1]
	position[1] = make([]int, 2)
	position[1][0] = input[2]
	position[1][1] = input[3]
	position[2] = revpos(position[0], position[1])
	position[3] = revpos(position[1], position[2])
	if position[0][0] == revpos(position[2], position[3])[0] && position[0][1] == revpos(position[2], position[3])[1] {
		fmt.Println("OK")
	}
	output := make([]int, 4)
	output[0] = position[2][0]
	output[1] = position[2][1]
	output[2] = position[3][0]
	output[3] = position[3][1]
	for _, i := range output {
		fmt.Println(i)
	}
}

