package main

import (
	"fmt"
	"time"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	
	timeS := strings.Split(s, ":")
	timeT := strings.Split(t, ":")
	
	x, _ := time.Parse("15:04", s)
	y, _ := time.Parse("15:04", t)
	
	duration := y.Sub(x)
	
	fmt.Println(duration)
}
