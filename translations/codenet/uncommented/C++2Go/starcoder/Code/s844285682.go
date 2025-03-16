package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a int
	fmt.Scanf("%d", &a)
	fmt.Printf("%d:%d:%d\n", a/(60*60), a%(60*60)/60, a%(60*60)%60)
}

