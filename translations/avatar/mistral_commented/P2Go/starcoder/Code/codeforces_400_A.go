
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single value as a tuple
func readValue() (a int, b int) {
	fmt.Scan(&a, &b)
	return
}

// Function to read multiple values as a tuple
func readValues() (a int, b int) {
	a, b = readValue()
	return
}

// Function to read a single value as a list
func readList() []int {
	var lst []int
	for {
		var tmp int
		fmt.Scan(&tmp)
		lst = append(lst, tmp)
		if tmp == 0 {
			break
		}
	}
	return lst
}

// Function to read multiple values as a list
func readLists() [][]int {
	var lst [][]int
	for {
		var tmp []int
		for {
			var a int
			fmt.Scan(&a)
			tmp = append(tmp, a)
			if a == 0 {
				break
			}
		}
		lst = append(lst, tmp)
		if len(tmp) == 0 {
			break
		}
	}
	return lst
}

// Function to read a single value as a string
func readString() string {
	var tmp string
	fmt.Scan(&tmp)
	return tmp
}

// Function to read a single value as a string
func readStrings() []string {
	var lst []string
	for {
		var tmp string
		fmt.Scan(&tmp)
		lst = append(lst, tmp)
		if tmp == "" {
			break
		}
	}
	return lst
}

// Function to read a single value as an integer
func readInt() int {
	var tmp int
	fmt.Scan(&tmp)
	return tmp
}

// Function to read a single value as an integer
func readInts() []int {
	var lst []int
	for {
		var tmp int
		fmt.Scan(&tmp)
		lst = append(lst, tmp)
		if tmp == 0 {
			break
		}
	}
	return lst
}

// Function to read a single value as a float
func readFloat() float64 {
	var tmp float64
	fmt.Scan(&tmp)
	return tmp
}

// Function to read a single value as a float
func readFloats() []float64 {
	var lst []float64
	for {
		var tmp float64
		fmt.Scan(&tmp)
		lst = append(lst, tmp)
		if tmp == 0 {
			break
		}
	}
	return lst
}

// Function to read a single line as a string
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a single line as a string
func readLines() []string {
	var lst []string
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		lst = append(lst, strings.TrimSpace(line))
	}
	return lst
}

// Function to read a single value as a string
func readString() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a single value as a string
func readStrings() []string {
	var lst []string
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		lst = append(lst, strings.TrimSpace(line))
	}
	return lst
}

// Function to read a single value as an integer
func readInt() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	i, _ := strconv.Atoi(strings.TrimSpace(line))
	return i
}

// Function to read a single value as an integer
func readInts() []int {
	var lst []int
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		i, _ := strconv.Atoi(strings.TrimSpace(line))
		lst = append(lst, i)
	}
	return lst
}

// Function to read a single value as a float
func readFloat() float64 {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	f, _ := strconv.ParseFloat(strings.TrimSpace(line), 64)
	return f
}

// Function to read a single value as a float
func readFloats() []float64 {
	var lst []float64
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		f, _ := strconv.ParseFloat(strings.TrimSpace(line), 64)
		lst = append(lst, f)
	}
	return lst
}

// Function to read a single line as a string
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a single line as a string
func readLines() []string {
	var lst []string
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		lst = append(lst, strings.TrimSpace(line))
	}
	return lst
}

// Function to read a single value as a string
func readString() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a single value as a string
func readStrings() []string {
	var lst []string
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		lst = append(lst, strings.TrimSpace(line))
	}
	return lst
}

// Function to read a single value as an integer
func readInt() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	i, _ := strconv.Atoi(strings.TrimSpace(line))
	return i
}

// Function to read a single value as an integer
func readInts() []int {
	var lst []int
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		i, _ := strconv.Atoi(strings.TrimSpace(line))
		lst = append(lst, i)
	}
	return lst
}

// Function to read a single value as a float
func readFloat() float64 {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	f, _ := strconv.ParseFloat(strings.TrimSpace(line), 64)
	return f
}

// Function to read a single value as a float
func readFloats() []float64 {
	var lst []float64
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		f, _ := strconv.ParseFloat(strings.TrimSpace(line), 64)
		lst = append(lst, f)
	}
	return lst
}

// Function to read a single line as a string
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a single line as a string
func readLines() []string {
	var lst []string
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		lst = append(lst, strings.TrimSpace(line))
	}
	return lst
}

// Function to read a single value as a string
func readString() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a single value as a string
func readStrings() []string {
	var lst []string
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		lst = append(lst, strings.TrimSpace(line))
	}
	return lst
}

// Function to read a single value as an integer
func readInt() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	i, _ := strconv.Atoi(strings.TrimSpace(line))
	return i
}

// Function to read a single value as an integer
func readInts() []int {
	var lst []int
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		i, _ := strconv.Atoi(strings.TrimSpace(line))
		lst = append(lst, i)
	}
	return lst
}

// Function to read a single value as a float
func readFloat() float64 {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	f, _ := strconv.ParseFloat(strings.TrimSpace(line), 64)
	return f
}

// Function to read a single value as a float
func readFloats() []float64 {
	var lst []float64
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		f, _ := strconv.ParseFloat(strings.TrimSpace(line), 64)
		lst = append(lst, f)
	}
	return lst
}

// Function to read a single line as a string
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a single line as a string
func readLines() []string {
	var lst []string
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		lst = append(lst, strings.TrimSpace(line))
	}
	return lst
}

// Function to read a single value as a string
func readString() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a single value as a string
func readStrings() []string {
	var lst []string
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		lst = append(lst, strings.TrimSpace(line))
	}
	return lst
}

// Function to read a single value as an integer
func readInt() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	i, _ := strconv.Atoi(strings.TrimSpace(line))
	return i
}

// Function to read a single value as an integer
func readInts() []int {
	var lst []int
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		i, _ := strconv.Atoi(strings.TrimSpace(line))
		lst = append(lst, i)
	}
	return lst
}

// Function to read a single value as a float
func readFloat() float64 {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	f, _ := strconv.ParseFloat(strings.TrimSpace(line), 64)
	return f
}

// Function to read a single value as a float
func readFloats() []float64 {
	var lst []float64
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		f, _ := strconv.ParseFloat(strings.TrimSpace(line), 64)
		lst = append(lst, f)
	}
	return lst
}

// Function to read a single line as a string
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a single line as a string
func readLines() []string {
	var lst []string
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		lst = append(lst, strings.TrimSpace(line))
	}
	return lst
}

// Function to read a single value as a string
func readString() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n'