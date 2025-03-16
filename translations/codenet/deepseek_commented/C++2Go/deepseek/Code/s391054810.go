package main

import (
	"fmt"
)

func main() {
	var h, w, hh, ww int
	
	fmt.Scan(&h, &w, &hh, &ww)
	
	fmt.Println((h - hh) * (w - ww))
}

