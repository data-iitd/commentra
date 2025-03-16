package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input which represents the number of elements in the lists
	var n int
	fmt.Scan(&n)

	// Read three lists of integers from input
	var a, b, c []int
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)

	// Initialize variables to hold the sum of each list
	var x, y, z int

	// Calculate the sum of elements in list 'a'
	for _, v := range a {
		x += v
	}

	// Calculate the sum of elements in list 'b'
	for _, v := range b {
		y += v
	}

	// Calculate the sum of elements in list 'c'
	for _, v := range c {
		z += v
	}

	// Print the absolute difference between the sums of list 'a' and list 'b'
	fmt.Println(abs(x - y))

	// Print the absolute difference between the sums of list 'b' and list 'c'
	fmt.Println(abs(y - z))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func (s *Scanner) Scan(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.Scan(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) Scan(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) Text() string {
	return s.text
}

func (s *Scanner) Err() error {
	return s.err
}

func (s *Scanner) Bytes() []byte {
	return s.bytes
}

func (s *Scanner) Split(split SplitFunc) {
	s.split = split
}

func (s *Scanner) ScanBytes(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanBytes(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanBytes(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanRunes(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanRunes(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanRunes(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanWords(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanWords(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanWords(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanLines(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanLines(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanLines(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) Buffer(buf []byte, max int) {
	s.buf = buf
	s.max = max
}

func (s *Scanner) Split(split SplitFunc) {
	s.split = split
}

func (s *Scanner) Text() string {
	return s.text
}

func (s *Scanner) Err() error {
	return s.err
}

func (s *Scanner) Bytes() []byte {
	return s.bytes
}

func (s *Scanner) Split(split SplitFunc) {
	s.split = split
}

func (s *Scanner) Scan(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.Scan(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) Scan(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanBytes(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanBytes(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanBytes(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanRunes(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanRunes(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanRunes(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanWords(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanWords(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanWords(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanLines(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanLines(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanLines(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) Buffer(buf []byte, max int) {
	s.buf = buf
	s.max = max
}

func (s *Scanner) Split(split SplitFunc) {
	s.split = split
}

func (s *Scanner) Text() string {
	return s.text
}

func (s *Scanner) Err() error {
	return s.err
}

func (s *Scanner) Bytes() []byte {
	return s.bytes
}

func (s *Scanner) Split(split SplitFunc) {
	s.split = split
}

func (s *Scanner) Scan(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.Scan(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) Scan(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanBytes(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanBytes(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanBytes(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanRunes(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanRunes(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanRunes(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanWords(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanWords(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanWords(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanLines(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanLines(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanLines(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) Buffer(buf []byte, max int) {
	s.buf = buf
	s.max = max
}

func (s *Scanner) Split(split SplitFunc) {
	s.split = split
}

func (s *Scanner) Text() string {
	return s.text
}

func (s *Scanner) Err() error {
	return s.err
}

func (s *Scanner) Bytes() []byte {
	return s.bytes
}

func (s *Scanner) Split(split SplitFunc) {
	s.split = split
}

func (s *Scanner) Scan(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.Scan(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) Scan(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanBytes(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanBytes(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanBytes(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanRunes(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanRunes(e)
		if err != nil {
			return
		}
		n++
	}
	return
}

func (s *Scanner) ScanRunes(a interface{}) error {
	var err error
	switch v := a.(type) {
	case *int:
		*v, err = strconv.Atoi(s.Text())
	case *[]int:
		*v = strings.Split(s.Text(), " ")
	default:
		err = fmt.Errorf("unsupported type %T", v)
	}
	return err
}

func (s *Scanner) ScanWords(a ...interface{}) (n int, err error) {
	n = 0
	for _, e := range a {
		err = s.ScanWords(e)
		if e