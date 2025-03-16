package main

import (
	"fmt"
	"os"
)

func main() {
	// Create a new Scanner object for reading input
	sc := new(Scanner)
	sc.in = os.Stdin
	sc.out = os.Stdout
	sc.sc = bufio.NewScanner(sc.in)
	sc.sc.Split(bufio.ScanWords)
	sc.init()

	// Read the number of elements (n) and the threshold (k) from input
	n := sc.nextInt()
	k := sc.nextInt()

	// Initialize an array to hold the input values
	bb := make([]int, n)

	// Read n integers into the bb array
	for i := 0; i < n; i++ {
		bb[i] = sc.nextInt()
	}

	// Initialize an array to hold the results and a counter for the results
	aa := make([]int, n)
	m := 0

	// Process the input array in reverse order
	for a := n - 1; a >= 0; a-- {
		j := 0
		// While there are still counts left for the current index in bb
		for bb[a] > 0 {
			// Check if the current index in aa is valid
			if aa[j] >= a+k {
				bb[a]--
			}
			j++
		}
		// Shift elements in aa to make space for the current index
		for j_ := m; j_ > j; j_-- {
			aa[j_] = aa[j_-1]
		}
		aa[j] = a
	}

	// Output the results, incrementing by 1 for 1-based indexing
	for i := 0; i < n; i++ {
		fmt.Printf("%d ", aa[i]+1)
	}
	fmt.Println()
}

// Scanner is a struct for reading input
type Scanner struct {
	in  io.Reader
	out io.Writer
	sc  *bufio.Scanner
}

// init initializes the Scanner object
func (sc *Scanner) init() {
	sc.sc.Split(bufio.ScanWords)
}

// nextInt returns the next integer from input
func (sc *Scanner) nextInt() int {
	sc.sc.Scan()
	i, _ := strconv.Atoi(sc.sc.Text())
	return i
}

// nextFloat returns the next float from input
func (sc *Scanner) nextFloat() float64 {
	sc.sc.Scan()
	f, _ := strconv.ParseFloat(sc.sc.Text(), 64)
	return f
}

// nextString returns the next string from input
func (sc *Scanner) nextString() string {
	sc.sc.Scan()
	return sc.sc.Text()
}

// nextLine returns the next line from input
func (sc *Scanner) nextLine() string {
	sc.sc.Scan()
	return sc.sc.Text()
}

// nextIntList returns a list of integers from input
func (sc *Scanner) nextIntList() []int {
	var list []int
	sc.sc.Scan()
	for _, s := range strings.Split(sc.sc.Text(), " ") {
		i, _ := strconv.Atoi(s)
		list = append(list, i)
	}
	return list
}

// nextFloatList returns a list of floats from input
func (sc *Scanner) nextFloatList() []float64 {
	var list []float64
	sc.sc.Scan()
	for _, s := range strings.Split(sc.sc.Text(), " ") {
		f, _ := strconv.ParseFloat(s, 64)
		list = append(list, f)
	}
	return list
}

// nextStringList returns a list of strings from input
func (sc *Scanner) nextStringList() []string {
	var list []string
	sc.sc.Scan()
	for _, s := range strings.Split(sc.sc.Text(), " ") {
		list = append(list, s)
	}
	return list
}

// nextLineList returns a list of strings from input, one per line
func (sc *Scanner) nextLineList() []string {
	var list []string
	for sc.sc.Scan() {
		list = append(list, sc.sc.Text())
	}
	return list
}

// nextIntMatrix returns a matrix of integers from input
func (sc *Scanner) nextIntMatrix() [][]int {
	var matrix [][]int
	for sc.sc.Scan() {
		var row []int
		for _, s := range strings.Split(sc.sc.Text(), " ") {
			i, _ := strconv.Atoi(s)
			row = append(row, i)
		}
		matrix = append(matrix, row)
	}
	return matrix
}

// nextFloatMatrix returns a matrix of floats from input
func (sc *Scanner) nextFloatMatrix() [][]float64 {
	var matrix [][]float64
	for sc.sc.Scan() {
		var row []float64
		for _, s := range strings.Split(sc.sc.Text(), " ") {
			f, _ := strconv.ParseFloat(s, 64)
			row = append(row, f)
		}
		matrix = append(matrix, row)
	}
	return matrix
}

// nextStringMatrix returns a matrix of strings from input
func (sc *Scanner) nextStringMatrix() [][]string {
	var matrix [][]string
	for sc.sc.Scan() {
		var row []string
		for _, s := range strings.Split(sc.sc.Text(), " ") {
			row = append(row, s)
		}
		matrix = append(matrix, row)
	}
	return matrix
}

// nextLineMatrix returns a matrix of strings from input, one per line
func (sc *Scanner) nextLineMatrix() [][]string {
	var matrix [][]string
	for sc.sc.Scan() {
		var row []string
		row = append(row, sc.sc.Text())
		matrix = append(matrix, row)
	}
	return matrix
}

// print prints an integer to the output
func (sc *Scanner) print(i int) {
	fmt.Fprintf(sc.out, "%d", i)
}

// println prints an integer to the output with a newline
func (sc *Scanner) println(i int) {
	fmt.Fprintf(sc.out, "%d\n", i)
}

// print prints a float to the output
func (sc *Scanner) print(f float64) {
	fmt.Fprintf(sc.out, "%f", f)
}

// println prints a float to the output with a newline
func (sc *Scanner) println(f float64) {
	fmt.Fprintf(sc.out, "%f\n", f)
}

// print prints a string to the output
func (sc *Scanner) print(s string) {
	fmt.Fprint(sc.out, s)
}

// println prints a string to the output with a newline
func (sc *Scanner) println(s string) {
	fmt.Fprintln(sc.out, s)
}

// print prints an integer array to the output
func (sc *Scanner) print(a []int) {
	fmt.Fprintf(sc.out, "%d", a[0])
	for _, v := range a[1:] {
		fmt.Fprintf(sc.out, " %d", v)
	}
}

// println prints an integer array to the output with a newline
func (sc *Scanner) println(a []int) {
	fmt.Fprintf(sc.out, "%d\n", a[0])
	for _, v := range a[1:] {
		fmt.Fprintf(sc.out, "%d ", v)
	}
	fmt.Fprintln(sc.out)
}

// print prints a float array to the output
func (sc *Scanner) print(a []float64) {
	fmt.Fprintf(sc.out, "%f", a[0])
	for _, v := range a[1:] {
		fmt.Fprintf(sc.out, " %f", v)
	}
}

// println prints a float array to the output with a newline
func (sc *Scanner) println(a []float64) {
	fmt.Fprintf(sc.out, "%f\n", a[0])
	for _, v := range a[1:] {
		fmt.Fprintf(sc.out, "%f ", v)
	}
	fmt.Fprintln(sc.out)
}

// print prints a string array to the output
func (sc *Scanner) print(a []string) {
	fmt.Fprint(sc.out, a[0])
	for _, v := range a[1:] {
		fmt.Fprint(sc.out, " ", v)
	}
}

// println prints a string array to the output with a newline
func (sc *Scanner) println(a []string) {
	fmt.Fprint(sc.out, a[0])
	for _, v := range a[1:] {
		fmt.Fprint(sc.out, " ", v)
	}
	fmt.Fprintln(sc.out)
}

// print prints an integer matrix to the output
func (sc *Scanner) print(a [][]int) {
	for _, row := range a {
		fmt.Fprint(sc.out, row[0])
		for _, v := range row[1:] {
			fmt.Fprint(sc.out, " ", v)
		}
		fmt.Fprintln(sc.out)
	}
}

// println prints an integer matrix to the output with a newline
func (sc *Scanner) println(a [][]int) {
	for _, row := range a {
		fmt.Fprint(sc.out, row[0])
		for _, v := range row[1:] {
			fmt.Fprint(sc.out, " ", v)
		}
		fmt.Fprintln(sc.out)
	}
}

// print prints a float matrix to the output
func (sc *Scanner) print(a [][]float64) {
	for _, row := range a {
		fmt.Fprint(sc.out, row[0])
		for _, v := range row[1:] {
			fmt.Fprint(sc.out, " ", v)
		}
		fmt.Fprintln(sc.out)
	}
}

// println prints a float matrix to the output with a newline
func (sc *Scanner) println(a [][]float64) {
	for _, row := range a {
		fmt.Fprint(sc.out, row[0])
		for _, v := range row[1:] {
			fmt.Fprint(sc.out, " ", v)
		}
		fmt.Fprintln(sc.out)
	}
}

// print prints a string matrix to the output
func (sc *Scanner) print(a [][]string) {
	for _, row := range a {
		fmt.Fprint(sc.out, row[0])
		for _, v := range row[1:] {
			fmt.Fprint(sc.out, " ", v)
		}
		fmt.Fprintln(sc.out)
	}
}

// println prints a string matrix to the output with a newline
func (sc *Scanner) println(a [][]string) {
	for _, row := range a {
		fmt.Fprint(sc.out, row[0])
		for _, v := range row[1:] {
			fmt.Fprint(sc.out, " ", v)
		}
		fmt.Fprintln(sc.out)
	}
}

// flush flushes the output
func (sc *Scanner) flush() {
	sc.out.(*bufio.Writer).Flush()
}

// 