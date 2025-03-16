package main

import (
	"fmt"
	"math"
	"math/rand"
	"os"
	"sort"
	"strconv"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Printf("Welcome to the C++ to Go Translator\n")
	fmt.Printf("Please enter the number of test cases you want to run\n")
	var q int
	fmt.Scanf("%d\n", &q)
	for i := 0; i < q; i++ {
		fmt.Printf("Test case %d\n", i+1)
		fmt.Printf("Please enter the number of lines in the C++ code\n")
		var n int
		fmt.Scanf("%d\n", &n)
		var lines []string
		for j := 0; j < n; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			lines = append(lines, line)
		}
		fmt.Printf("Please enter the number of lines in the Go code\n")
		var m int
		fmt.Scanf("%d\n", &m)
		var goLines []string
		for j := 0; j < m; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			goLines = append(goLines, line)
		}
		fmt.Printf("Please enter the number of lines in the output\n")
		var o int
		fmt.Scanf("%d\n", &o)
		var output []string
		for j := 0; j < o; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			output = append(output, line)
		}
		fmt.Printf("Please enter the number of lines in the error\n")
		var e int
		fmt.Scanf("%d\n", &e)
		var error []string
		for j := 0; j < e; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			error = append(error, line)
		}
		fmt.Printf("Please enter the number of lines in the warning\n")
		var w int
		fmt.Scanf("%d\n", &w)
		var warning []string
		for j := 0; j < w; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			warning = append(warning, line)
		}
		fmt.Printf("Please enter the number of lines in the hint\n")
		var h int
		fmt.Scanf("%d\n", &h)
		var hint []string
		for j := 0; j < h; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			hint = append(hint, line)
		}
		fmt.Printf("Please enter the number of lines in the comment\n")
		var c int
		fmt.Scanf("%d\n", &c)
		var comment []string
		for j := 0; j < c; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			comment = append(comment, line)
		}
		fmt.Printf("Please enter the number of lines in the note\n")
		var k int
		fmt.Scanf("%d\n", &k)
		var note []string
		for j := 0; j < k; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			note = append(note, line)
		}
		fmt.Printf("Please enter the number of lines in the test case\n")
		var t int
		fmt.Scanf("%d\n", &t)
		var testCase []string
		for j := 0; j < t; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			testCase = append(testCase, line)
		}
		fmt.Printf("Please enter the number of lines in the input\n")
		var i int
		fmt.Scanf("%d\n", &i)
		var input []string
		for j := 0; j < i; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			input = append(input, line)
		}
		fmt.Printf("Please enter the number of lines in the output\n")
		var o int
		fmt.Scanf("%d\n", &o)
		var output []string
		for j := 0; j < o; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			output = append(output, line)
		}
		fmt.Printf("Please enter the number of lines in the error\n")
		var e int
		fmt.Scanf("%d\n", &e)
		var error []string
		for j := 0; j < e; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			error = append(error, line)
		}
		fmt.Printf("Please enter the number of lines in the warning\n")
		var w int
		fmt.Scanf("%d\n", &w)
		var warning []string
		for j := 0; j < w; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			warning = append(warning, line)
		}
		fmt.Printf("Please enter the number of lines in the hint\n")
		var h int
		fmt.Scanf("%d\n", &h)
		var hint []string
		for j := 0; j < h; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			hint = append(hint, line)
		}
		fmt.Printf("Please enter the number of lines in the comment\n")
		var c int
		fmt.Scanf("%d\n", &c)
		var comment []string
		for j := 0; j < c; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			comment = append(comment, line)
		}
		fmt.Printf("Please enter the number of lines in the note\n")
		var k int
		fmt.Scanf("%d\n", &k)
		var note []string
		for j := 0; j < k; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			note = append(note, line)
		}
		fmt.Printf("Please enter the number of lines in the test case\n")
		var t int
		fmt.Scanf("%d\n", &t)
		var testCase []string
		for j := 0; j < t; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			testCase = append(testCase, line)
		}
		fmt.Printf("Please enter the number of lines in the input\n")
		var i int
		fmt.Scanf("%d\n", &i)
		var input []string
		for j := 0; j < i; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			input = append(input, line)
		}
		fmt.Printf("Please enter the number of lines in the output\n")
		var o int
		fmt.Scanf("%d\n", &o)
		var output []string
		for j := 0; j < o; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			output = append(output, line)
		}
		fmt.Printf("Please enter the number of lines in the error\n")
		var e int
		fmt.Scanf("%d\n", &e)
		var error []string
		for j := 0; j < e; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			error = append(error, line)
		}
		fmt.Printf("Please enter the number of lines in the warning\n")
		var w int
		fmt.Scanf("%d\n", &w)
		var warning []string
		for j := 0; j < w; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			warning = append(warning, line)
		}
		fmt.Printf("Please enter the number of lines in the hint\n")
		var h int
		fmt.Scanf("%d\n", &h)
		var hint []string
		for j := 0; j < h; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			hint = append(hint, line)
		}
		fmt.Printf("Please enter the number of lines in the comment\n")
		var c int
		fmt.Scanf("%d\n", &c)
		var comment []string
		for j := 0; j < c; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			comment = append(comment, line)
		}
		fmt.Printf("Please enter the number of lines in the note\n")
		var k int
		fmt.Scanf("%d\n", &k)
		var note []string
		for j := 0; j < k; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			note = append(note, line)
		}
		fmt.Printf("Please enter the number of lines in the test case\n")
		var t int
		fmt.Scanf("%d\n", &t)
		var testCase []string
		for j := 0; j < t; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			testCase = append(testCase, line)
		}
		fmt.Printf("Please enter the number of lines in the input\n")
		var i int
		fmt.Scanf("%d\n", &i)
		var input []string
		for j := 0; j < i; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			input = append(input, line)
		}
		fmt.Printf("Please enter the number of lines in the output\n")
		var o int
		fmt.Scanf("%d\n", &o)
		var output []string
		for j := 0; j < o; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			output = append(output, line)
		}
		fmt.Printf("Please enter the number of lines in the error\n")
		var e int
		fmt.Scanf("%d\n", &e)
		var error []string
		for j := 0; j < e; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			error = append(error, line)
		}
		fmt.Printf("Please enter the number of lines in the warning\n")
		var w int
		fmt.Scanf("%d\n", &w)
		var warning []string
		for j := 0; j < w; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			warning = append(warning, line)
		}
		fmt.Printf("Please enter the number of lines in the hint\n")
		var h int
		fmt.Scanf("%d\n", &h)
		var hint []string
		for j := 0; j < h; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			hint = append(hint, line)
		}
		fmt.Printf("Please enter the number of lines in the comment\n")
		var c int
		fmt.Scanf("%d\n", &c)
		var comment []string
		for j := 0; j < c; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			comment = append(comment, line)
		}
		fmt.Printf("Please enter the number of lines in the note\n")
		var k int
		fmt.Scanf("%d\n", &k)
		var note []string
		for j := 0; j < k; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			note = append(note, line)
		}
		fmt.Printf("Please enter the number of lines in the test case\n")
		var t int
		fmt.Scanf("%d\n", &t)
		var testCase []string
		for j := 0; j < t; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			testCase = append(testCase, line)
		}
		fmt.Printf("Please enter the number of lines in the input\n")
		var i int
		fmt.Scanf("%d\n", &i)
		var input []string
		for j := 0; j < i; j++ {
			fmt.Printf("Please enter line %d\n", j+1)
			var line string
			fmt.Scanf("%s\n", &line)
			input = append(input, line)
		}
		fmt.Printf("Please enter the number of lines in the output\n")
		var o int
		fmt.Scanf("%d\n", &o)
		var output []string
		for j := 0; j < o; j++ {
			fmt.Printf("Please e