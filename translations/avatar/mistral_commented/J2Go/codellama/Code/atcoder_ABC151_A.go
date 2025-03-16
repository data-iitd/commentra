
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new BufferedReader object to read input
	r := bufio.NewReader(os.Stdin)
	// Read a line of input and store it in a string variable
	s, _ := r.ReadString('\n')
	// Split the line of input into an array of strings using the space character as the delimiter
	sl := strings.Split(s, " ")
	// Declare a new RemRing object with the module as the first element of the array
	rr := RemRing(sl[0])
	// Declare a new array of integers to store the values of the input
	arr := make([]int, len(sl)-1)
	// Iterate over the array of strings and convert each string to an integer
	for i := 1; i < len(sl); i++ {
		arr[i-1], _ = strconv.Atoi(sl[i])
	}
	// Declare a new array of integers to store the results of the operations
	res := make([]int, len(arr))
	// Iterate over the array of integers and perform the operations
	for i := 0; i < len(arr); i++ {
		res[i] = rr.sum(arr[i], arr[i])
	}
	// Iterate over the array of integers and print the results
	for i := 0; i < len(res); i++ {
		fmt.Println(res[i])
	}
}

type RemRing struct {
	module int
}

func (rr RemRing) sum(a, b int) int {
	return (a + b + rr.module) % rr.module
}

func (rr RemRing) sub(a, b int) int {
	return (a - b + rr.module) % rr.module
}

func (rr RemRing) prod(a, b int) int {
	return (a * b) % rr.module
}

func (rr RemRing) div(a, b int) int {
	return (a * rr.inv(b)) % rr.module
}

func (rr RemRing) inv(a int) int {
	b := rr.module
	u := 1
	v := 0
	for b > 0 {
		t := a / b
		z := a
		a = b
		b = z % rr.module
		temp := u
		u = v
		v = temp - t*v
	}
	if u < 0 {
		u += rr.module
	}
	return u
}

