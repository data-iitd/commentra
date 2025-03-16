package main

import (
	"fmt"
)

func revpos(p, q [2]int) [2]int {
	vec := [2]int{0, 0}
	for i := 0; i < len(vec); i++ {
		vec[i] = p[i] - q[i]
	}
	tmp := vec[0]
	vec[0] = vec[1]
	vec[1] = -tmp
	newpos := [2]int{0, 0}
	for i := 0; i < len(newpos); i++ {
		newpos[i] = q[i] + vec[i]
	}
	return newpos
}

func main() {
	var input [4]int
	for i := 0; i < len(input); i++ {
		fmt.Scan(&input[i])
	}

	position := [4][2]int{}
	position[0][0] = input[0]
	position[0][1] = input[1]
	position[1][0] = input[2]
	position[1][1] = input[3]
	position[2] = revpos(position[0], position[1])
	position[3] = revpos(position[1], position[2])

	if position[0] == revpos(position[2], position[3]) {
		fmt.Println("OK")
	}

	output := [4]int{}
	output[0] = position[2][0]
	output[1] = position[2][1]
	output[2] = position[3][0]
	output[3] = position[3][1]

	for _, i := range output {
		fmt.Println(i)
	}
}

// <END-OF-CODE>
