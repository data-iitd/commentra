package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var a, b int
	var res int
	var err error
	var input string

	fmt.Print("Enter a: ")
	input, err = os.ReadFile("stdin")
	if err != nil {
		fmt.Println(err)
		return
	}
	a, err = strconv.Atoi(input)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Print("Enter b: ")
	input, err = os.ReadFile("stdin")
	if err != nil {
		fmt.Println(err)
		return
	}
	b, err = strconv.Atoi(input)
	if err != nil {
		fmt.Println(err)
		return
	}

	res = a
	for a >= b {
		res += a / b
		a = a/b + a%b
	}
	fmt.Println(res)
}

