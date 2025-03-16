

package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	s := readString()
	d := make([]byte, 0, len(s))
	for _, c := range s {
		switch c {
		case '0':
			d = append(d, '0')
		case '1':
			d = append(d, '1')
		case 'B':
			if len(d) > 0 {
				d = d[:len(d)-1]
			}
		}
	}
	fmt.Fprintln(w, string(d))
	w.Flush()
}

func readString() string {
	s, _ := r.ReadString('\n')
	return s[:len(s)-1]
}

func readInt() int {
	n, _ := fmt.Fscanf(r, "%d")
	return n
}

func readInt64() int64 {
	n, _ := fmt.Fscanf(r, "%d")
	return n
}

func readFloat64() float64 {
	n, _ := fmt.Fscanf(r, "%f")
	return n
}

func readLine() string {
	s, _ := r.ReadString('\n')
	return s
}

func main() {
	s := readString()
	d := make([]byte, 0, len(s))
	for _, c := range s {
		switch c {
		case '0':
			d = append(d, '0')
		case '1':
			d = append(d, '1')
		case 'B':
			if len(d) > 0 {
				d = d[:len(d)-1]
			}
		}
	}
	fmt.Println(string(d))
}

func readString() string {
	s, _ := r.ReadString('\n')
	return s[:len(s)-1]
}

func readInt() int {
	n, _ := fmt.Fscanf(r, "%d")
	return n
}

func readInt64() int64 {
	n, _ := fmt.Fscanf(r, "%d")
	return n
}

func readFloat64() float64 {
	n, _ := fmt.Fscanf(r, "%f")
	return n
}

func readLine() string {
	s, _ := r.ReadString('\n')
	return s
}

