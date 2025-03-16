package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var h int64
	fmt.Scan(&h)
	ans, cnt := int64(1), int64(1)
	for h != 1 {
		if h%2 != 0 {
			h--
		}
		h /= 2
		cnt *= 2
		ans += cnt
	}
	fmt.Println(ans + 1)
}

