package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var inputMethods = []string{"clipboard", "file", "key"}
var usingMethod = 0
var inputMethod = inputMethods[usingMethod]
var mod = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	var s string
	fmt.Fscan(reader, &s)

	pmin := 1000
	mmin := 0
	s = "0" + s

	for i := len(s) - 1; i >= 0; i-- {
		v, _ := strconv.Atoi(string(s[i]))
		npmin := min(pmin+10-(v+1), mmin+10-v)
		nmmin := min(pmin+v+1, mmin+v)
		pmin = npmin
		mmin = nmmin
	}
	fmt.Println(min(pmin, mmin))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Uncomment and implement the following functions if needed
/*
func inputClipboard() {
	// Implement clipboard input handling
}
*/

func pa(v interface{}) {
	// Implement print function if needed
}

func init() {
	if inputMethod == inputMethods[0] {
		// Handle clipboard input
	} else if inputMethod == inputMethods[1] {
		file, err := os.Open("inputFile.txt")
		if err != nil {
			panic(err)
		}
		defer file.Close()
		reader := bufio.NewReader(file)
		fmt.Fscan(reader, &s)
	} else {
		// Handle key input
	}
}

// Note: The clipboard handling and other input methods are not implemented in this translation.
