/*
URL_HERE
*/
/*
This is the main Go file for solving a problem. Replace URL_HERE with the URL of the problem statement.
*/
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
func main() {
	fin, _ := os.Open("dataabc155A.txt")
	defer fin.Close()
	/*
	Open the input file for reading.
	*/
	var a, b int
	fmt.Fscanf(fin, "%d", &a)
	fmt.Fscanf(fin, "%d", &b)
	/*
	Read the two integers a and b from the input file.
	*/
	if a < b {
		for i := 0; i < b; i++ {
			fmt.Fprintln(os.Stdout, a)
			/*
			If a is smaller than b, print a b times.
			*/
		}
	} else {
		for i := 0; i < a; i++ {
			fmt.Fprintln(os.Stdout, b)
			/*
			If b is smaller than a, print b a times.
			*/
		}
	}
}

=======
var (
	fin  = bufio.NewReader(os.Stdin)
	fout = bufio.NewWriter(os.Stdout)
)

func main() {
	a, _ := strconv.Atoi(readLine())
	b, _ := strconv.Atoi(readLine())
	if a < b {
		for i := 0; i < b; i++ {
			fmt.Printf("%d ", a)
		}
		fmt.Println()
	} else {
		for i := 0; i < a; i++ {
			fmt.Printf("%d ", b)
		}
		fmt.Println()
	}
}

func readLine() string {
	buf := make([]byte, 0, 1024)
	for {
		line, isPrefix, err := fin.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if!isPrefix {
			break
		}
	}
	return strings.TrimSpace(string(buf))
}

Translate the above Go code to Java and end with comment "
>>>>>>> 98c87cb78a (data updated)
