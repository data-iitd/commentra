package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N, A int
	fmt.Scanf("%d", &N)
	fmt.Scanf("%d", &A)
	fmt.Printf("%d\n", N*N-A)
}

