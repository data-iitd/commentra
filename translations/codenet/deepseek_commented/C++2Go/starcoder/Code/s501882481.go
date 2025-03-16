<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

<<<<<<< HEAD
// <START-OF-CODE>

func main() {
	var S string
	fmt.Scanf("%s", &S)
	if S == "Sunny" {
		fmt.Println("Cloudy")
	} else if S == "Cloudy" {
		fmt.Println("Rainy")
	} else {
		fmt.Println("Sunny")
=======
// Function to print a newline.
func print() {
	fmt.Println()
}

// Function to print multiple items.
func print(a...interface{}) {
	fmt.Fprintln(os.Stdout, a...)
}

// Function to read a single item.
func get() string {
	var s string
	fmt.Scanf("%s", &s)
	return s
}

// Function to read multiple items.
func get(a...interface{}) {
	fmt.Scanf("%s", a...)
}

// Function to read a vector of items.
func getv(a...interface{}) {
	for i := 0; i < len(a); i++ {
		fmt.Scanf("%s", &a[i])
	}
}

// Function to convert a string to a string representation.
func to_string(a interface{}) string {
	return fmt.Sprintf("%v", a)
}

// Function to convert a pair to a string representation.
func to_string(a interface{}, b interface{}) string {
	return fmt.Sprintf("{%v,%v}", a, b)
}

// Function to convert a vector to a string representation.
func to_string(a interface{}) string {
	s := fmt.Sprintf("%v", a)
	s = strings.Replace(s, " ", ",", -1)
	return s
}

// Function to print debug information with a line number.
func debug(a...interface{}) {
	s := []string{}
	s = append(s, to_string(a...))
	s = append(s, " (", to_string(get_line_number()), "):")
	print(strings.Join(s, " "))
}

// Function to get the line number.
func get_line_number() int {
	_, file, line, _ := runtime.Caller(1)
	return line
}

// Main function to execute the program.
func main() {
	var S string
	get(&S)
	if S == "Sunny" {
		print("Cloudy")
	} else if S == "Cloudy" {
		print("Rainy")
	} else {
		print("Sunny")
>>>>>>> 98c87cb78a (data updated)
	}
}

// 