
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Define the available input methods
	input_methods := []string{"clipboard", "file", "key"}
	using_method := 0 // Index to select the input method
	input_method := input_methods[using_method] // Select the input method based on the index

	// Define a lambda function for reading multiple integers from input
	IN := func() []int {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))
	}
	mod := 1000000007 // Define a modulus value for calculations

	// Define a function for reading multiple integers from input
	toInts := func(a []string) []int {
		res := make([]int, len(a))
		for i, v := range a {
			res[i], _ = strconv.Atoi(v)
		}
		return res
	}

	// Define a function for reading multiple integers from input
	toStrs := func(a []int) []string {
		res := make([]string, len(a))
		for i, v := range a {
			res[i] = strconv.Itoa(v)
		}
		return res
	}

	// Define a function for reading multiple integers from input
	toIntsLine := func() []int {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))
	}

	// Define a function for reading multiple integers from input
	toStrsLine := func() []string {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")
	}

	// Define a function for reading multiple integers from input
	toIntsLine2 := func() (int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1]
	}

	// Define a function for reading multiple integers from input
	toStrsLine2 := func() (string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1]
	}

	// Define a function for reading multiple integers from input
	toIntsLine3 := func() (int, int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1], toInts(strings.Split(s, " "))[2]
	}

	// Define a function for reading multiple integers from input
	toStrsLine3 := func() (string, string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1], strings.Split(s, " ")[2]
	}

	// Define a function for reading multiple integers from input
	toIntsLine4 := func() (int, int, int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1], toInts(strings.Split(s, " "))[2], toInts(strings.Split(s, " "))[3]
	}

	// Define a function for reading multiple integers from input
	toStrsLine4 := func() (string, string, string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1], strings.Split(s, " ")[2], strings.Split(s, " ")[3]
	}

	// Define a function for reading multiple integers from input
	toIntsLine5 := func() (int, int, int, int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1], toInts(strings.Split(s, " "))[2], toInts(strings.Split(s, " "))[3], toInts(strings.Split(s, " "))[4]
	}

	// Define a function for reading multiple integers from input
	toStrsLine5 := func() (string, string, string, string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1], strings.Split(s, " ")[2], strings.Split(s, " ")[3], strings.Split(s, " ")[4]
	}

	// Define a function for reading multiple integers from input
	toIntsLine6 := func() (int, int, int, int, int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1], toInts(strings.Split(s, " "))[2], toInts(strings.Split(s, " "))[3], toInts(strings.Split(s, " "))[4], toInts(strings.Split(s, " "))[5]
	}

	// Define a function for reading multiple integers from input
	toStrsLine6 := func() (string, string, string, string, string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1], strings.Split(s, " ")[2], strings.Split(s, " ")[3], strings.Split(s, " ")[4], strings.Split(s, " ")[5]
	}

	// Define a function for reading multiple integers from input
	toIntsLine7 := func() (int, int, int, int, int, int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1], toInts(strings.Split(s, " "))[2], toInts(strings.Split(s, " "))[3], toInts(strings.Split(s, " "))[4], toInts(strings.Split(s, " "))[5], toInts(strings.Split(s, " "))[6]
	}

	// Define a function for reading multiple integers from input
	toStrsLine7 := func() (string, string, string, string, string, string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1], strings.Split(s, " ")[2], strings.Split(s, " ")[3], strings.Split(s, " ")[4], strings.Split(s, " ")[5], strings.Split(s, " ")[6]
	}

	// Define a function for reading multiple integers from input
	toIntsLine8 := func() (int, int, int, int, int, int, int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1], toInts(strings.Split(s, " "))[2], toInts(strings.Split(s, " "))[3], toInts(strings.Split(s, " "))[4], toInts(strings.Split(s, " "))[5], toInts(strings.Split(s, " "))[6], toInts(strings.Split(s, " "))[7]
	}

	// Define a function for reading multiple integers from input
	toStrsLine8 := func() (string, string, string, string, string, string, string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1], strings.Split(s, " ")[2], strings.Split(s, " ")[3], strings.Split(s, " ")[4], strings.Split(s, " ")[5], strings.Split(s, " ")[6], strings.Split(s, " ")[7]
	}

	// Define a function for reading multiple integers from input
	toIntsLine9 := func() (int, int, int, int, int, int, int, int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1], toInts(strings.Split(s, " "))[2], toInts(strings.Split(s, " "))[3], toInts(strings.Split(s, " "))[4], toInts(strings.Split(s, " "))[5], toInts(strings.Split(s, " "))[6], toInts(strings.Split(s, " "))[7], toInts(strings.Split(s, " "))[8]
	}

	// Define a function for reading multiple integers from input
	toStrsLine9 := func() (string, string, string, string, string, string, string, string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1], strings.Split(s, " ")[2], strings.Split(s, " ")[3], strings.Split(s, " ")[4], strings.Split(s, " ")[5], strings.Split(s, " ")[6], strings.Split(s, " ")[7], strings.Split(s, " ")[8]
	}

	// Define a function for reading multiple integers from input
	toIntsLine10 := func() (int, int, int, int, int, int, int, int, int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1], toInts(strings.Split(s, " "))[2], toInts(strings.Split(s, " "))[3], toInts(strings.Split(s, " "))[4], toInts(strings.Split(s, " "))[5], toInts(strings.Split(s, " "))[6], toInts(strings.Split(s, " "))[7], toInts(strings.Split(s, " "))[8], toInts(strings.Split(s, " "))[9]
	}

	// Define a function for reading multiple integers from input
	toStrsLine10 := func() (string, string, string, string, string, string, string, string, string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1], strings.Split(s, " ")[2], strings.Split(s, " ")[3], strings.Split(s, " ")[4], strings.Split(s, " ")[5], strings.Split(s, " ")[6], strings.Split(s, " ")[7], strings.Split(s, " ")[8], strings.Split(s, " ")[9]
	}

	// Define a function for reading multiple integers from input
	toIntsLine11 := func() (int, int, int, int, int, int, int, int, int, int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1], toInts(strings.Split(s, " "))[2], toInts(strings.Split(s, " "))[3], toInts(strings.Split(s, " "))[4], toInts(strings.Split(s, " "))[5], toInts(strings.Split(s, " "))[6], toInts(strings.Split(s, " "))[7], toInts(strings.Split(s, " "))[8], toInts(strings.Split(s, " "))[9], toInts(strings.Split(s, " "))[10]
	}

	// Define a function for reading multiple integers from input
	toStrsLine11 := func() (string, string, string, string, string, string, string, string, string, string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1], strings.Split(s, " ")[2], strings.Split(s, " ")[3], strings.Split(s, " ")[4], strings.Split(s, " ")[5], strings.Split(s, " ")[6], strings.Split(s, " ")[7], strings.Split(s, " ")[8], strings.Split(s, " ")[9], strings.Split(s, " ")[10]
	}

	// Define a function for reading multiple integers from input
	toIntsLine12 := func() (int, int, int, int, int, int, int, int, int, int, int, int) {
		var s string
		fmt.Scan(&s)
		return toInts(strings.Split(s, " "))[0], toInts(strings.Split(s, " "))[1], toInts(strings.Split(s, " "))[2], toInts(strings.Split(s, " "))[3], toInts(strings.Split(s, " "))[4], toInts(strings.Split(s, " "))[5], toInts(strings.Split(s, " "))[6], toInts(strings.Split(s, " "))[7], toInts(strings.Split(s, " "))[8], toInts(strings.Split(s, " "))[9], toInts(strings.Split(s, " "))[10], toInts(strings.Split(s, " "))[11]
	}

	// Define a function for reading multiple integers from input
	toStrsLine12 := func() (string, string, string, string, string, string, string, string, string, string, string, string) {
		var s string
		fmt.Scan(&s)
		return strings.Split(s, " ")[0], strings.Split(s, " ")[1], strings.Split(s, " ")[2], strings.Split(s, " ")[3], strings.Split(s, " ")[4], strings.Split(s, " ")[5], strings.Split(s, " ")[6], strings.Split(s, " ")[7], strings.Split(s, " ")[8], strings.Split(s, " ")[9], strings.Split(s, " ")[10], strings.Split(s, " ")[11]
	}

	// Define a function for reading multiple integers from input
	toIntsLine13 := func() (int, int, int, int, int, int, int, int, int, int, int, int, int) {
		var s string
		fmt.Scan(&s)
		return toI