package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	solver := AStationAndBus{}
	solver.solve(s)
}

type AStationAndBus struct{}

func (solver AStationAndBus) solve(s string) {
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
