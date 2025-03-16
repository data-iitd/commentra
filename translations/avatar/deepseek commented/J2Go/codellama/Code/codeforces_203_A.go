package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading the number of test cases (t) and other required values
	x, _ := strconv.Atoi(nextString())
	t, _ := strconv.Atoi(nextString())
	a, _ := strconv.Atoi(nextString())
	b, _ := strconv.Atoi(nextString())
	da, _ := strconv.Atoi(nextString())
	db, _ := strconv.Atoi(nextString())

	// Variables to store calculated values
	first := 0
	second := 0

	// Flag to determine if a solution is found
	ok := false

	// Nested loop to calculate possible values of first and second
	for i := 0; i < t; i++ {
		first = a - (da * i)
		for j := 0; j < t; j++ {
			second = b - (db * j)
			if second+first == x || second == x || first == x || x == 0 {
				// Check if the sum of first and second equals x, or if either value equals x, or if x is zero
				ok = true
				break
			}
		}
		if ok {
			break
		}
	}

	// Print the result based on the flag
	if ok {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// Method to read the next integer from the input
func nextInt() int {
	s := nextString()
	x, _ := strconv.Atoi(s)
	return x
}

// Method to read the next token from the input
func nextString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := scanner.Text()
	return s
}

// Method to read the next line from the input
func nextLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := scanner.Text()
	return s
}

// Method to read the next integer array from the input
func nextIntArray() []int {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(nextString())
	}
	return a
}

// Method to read the next string array from the input
func nextStringArray() []string {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	a := make([]string, n)
	for i := 0; i < n; i++ {
		a[i] = nextString()
	}
	return a
}

// Method to read the next integer matrix from the input
func nextIntMatrix() [][]int {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = nextIntArray()
	}
	return m
}

// Method to read the next string matrix from the input
func nextStringMatrix() [][]string {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]string, n)
	for i := 0; i < n; i++ {
		m[i] = nextStringArray()
	}
	return m
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromReader(reader *bufio.Reader) [][]int {
	s, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nextString())
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = nextIntArray()
	}
	return m
}

// Method to read the next string matrix from the input
func nextStringMatrixFromReader(reader *bufio.Reader) [][]string {
	s, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nextString())
	m := make([][]string, n)
	for i := 0; i < n; i++ {
		m[i] = nextStringArray()
	}
	return m
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromScanner(scanner *bufio.Scanner) [][]int {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = nextIntArray()
	}
	return m
}

// Method to read the next string matrix from the input
func nextStringMatrixFromScanner(scanner *bufio.Scanner) [][]string {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]string, n)
	for i := 0; i < n; i++ {
		m[i] = nextStringArray()
	}
	return m
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFile(file *os.File) [][]int {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = nextIntArray()
	}
	return m
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFile(file *os.File) [][]string {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]string, n)
	for i := 0; i < n; i++ {
		m[i] = nextStringArray()
	}
	return m
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithName(fileName string) [][]int {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextIntMatrixFromFile(file)
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFileWithName(fileName string) [][]string {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextStringMatrixFromFile(file)
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithReader(reader *bufio.Reader) [][]int {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = nextIntArray()
	}
	return m
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFileWithReader(reader *bufio.Reader) [][]string {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]string, n)
	for i := 0; i < n; i++ {
		m[i] = nextStringArray()
	}
	return m
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithScanner(scanner *bufio.Scanner) [][]int {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = nextIntArray()
	}
	return m
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFileWithScanner(scanner *bufio.Scanner) [][]string {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]string, n)
	for i := 0; i < n; i++ {
		m[i] = nextStringArray()
	}
	return m
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithNameAndScanner(fileName string, scanner *bufio.Scanner) [][]int {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextIntMatrixFromFileWithScanner(scanner)
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFileWithNameAndScanner(fileName string, scanner *bufio.Scanner) [][]string {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextStringMatrixFromFileWithScanner(scanner)
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithNameAndReader(fileName string, reader *bufio.Reader) [][]int {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextIntMatrixFromFileWithReader(reader)
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFileWithNameAndReader(fileName string, reader *bufio.Reader) [][]string {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextStringMatrixFromFileWithReader(reader)
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithScannerAndReader(scanner *bufio.Scanner, reader *bufio.Reader) [][]int {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = nextIntArray()
	}
	return m
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFileWithScannerAndReader(scanner *bufio.Scanner, reader *bufio.Reader) [][]string {
	s := nextLine()
	n, _ := strconv.Atoi(nextString())
	m := make([][]string, n)
	for i := 0; i < n; i++ {
		m[i] = nextStringArray()
	}
	return m
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithNameScannerAndReader(fileName string, scanner *bufio.Scanner, reader *bufio.Reader) [][]int {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextIntMatrixFromFileWithScannerAndReader(scanner, reader)
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFileWithNameScannerAndReader(fileName string, scanner *bufio.Scanner, reader *bufio.Reader) [][]string {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextStringMatrixFromFileWithScannerAndReader(scanner, reader)
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithNameAndScannerAndReader(fileName string, scanner *bufio.Scanner, reader *bufio.Reader) [][]int {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextIntMatrixFromFileWithScannerAndReader(scanner, reader)
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFileWithNameAndScannerAndReader(fileName string, scanner *bufio.Scanner, reader *bufio.Reader) [][]string {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextStringMatrixFromFileWithScannerAndReader(scanner, reader)
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithNameAndScannerAndReaderAndWriter(fileName string, scanner *bufio.Scanner, reader *bufio.Reader, writer *bufio.Writer) [][]int {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextIntMatrixFromFileWithScannerAndReader(scanner, reader)
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFileWithNameAndScannerAndReaderAndWriter(fileName string, scanner *bufio.Scanner, reader *bufio.Reader, writer *bufio.Writer) [][]string {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextStringMatrixFromFileWithScannerAndReader(scanner, reader)
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithNameAndScannerAndReaderAndWriterAndBuffer(fileName string, scanner *bufio.Scanner, reader *bufio.Reader, writer *bufio.Writer, buffer *bytes.Buffer) [][]int {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextIntMatrixFromFileWithScannerAndReader(scanner, reader)
}

// Method to read the next string matrix from the input
func nextStringMatrixFromFileWithNameAndScannerAndReaderAndWriterAndBuffer(fileName string, scanner *bufio.Scanner, reader *bufio.Reader, writer *bufio.Writer, buffer *bytes.Buffer) [][]string {
	file, _ := os.Open(fileName)
	defer file.Close()
	return nextStringMatrixFromFileWithScannerAndReader(scanner, reader)
}

// Method to read the next integer matrix from the input
func nextIntMatrixFromFileWithNameAndScannerAndReaderAndWriterAndBufferAndBytes(fileName string, scanner *bufio.Scanner, reader *bufi