/*
URL_HERE
*/
/*
This is the main Go file for solving a problem. Replace URL_HERE with the URL of the problem statement.
*/
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	fin, _ := os.Open("dataabc155A.txt")
	defer fin.Close()
	fout, _ := os.Create("output.txt")
	defer fout.Close()
	scanner := bufio.NewScanner(fin)
	scanner.Split(bufio.ScanWords)
	a, _ := strconv.Atoi(scanner.Text())
	b, _ := strconv.Atoi(scanner.Text())
	if a < b {
		for i := 0; i < b; i++ {
			fmt.Fprintf(fout, "%d ", a)
		}
		fmt.Fprintln(fout)
	} else {
		for i := 0; i < a; i++ {
			fmt.Fprintf(fout, "%d ", b)
		}
		fmt.Fprintln(fout)
	}
}

