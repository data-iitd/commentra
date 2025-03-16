package main

import (
	"fmt"
)

func revpos(p, q []int) []int {
	vec := []int{0, 0}
	for i := 0; i < len(vec); i++ {
		vec[i] = p[i] - q[i]
	}
	tmp := 0
	tmp = vec[0]
	vec[0] = vec[1]
	vec[1] = -tmp
	newpos := []int{0, 0}
	for i := 0; i < len(newpos); i++ {
		newpos[i] = q[i] + vec[i]
	}
	return newpos
}

func main() {
	var input [4]int
	for i := 0; i < 4; i++ {
		fmt.Scan(&input[i])
	}
	position := [4][2]int{
		{input[0], input[1]},
		{input[2], input[3]},
		{0, 0},
		{0, 0},
	}
	position[2] = revpos(position[0][:], position[1][:])
	position[3] = revpos(position[1][:], position[2][:])
	if position[0] == revpos(position[2][:], position[3][:]) {
		fmt.Println("OK")
	}
	output := [4]int{position[2][0], position[2][1], position[3][0], position[3][1]}
	for _, i := range output {
		fmt.Println(i)
	}
}
