
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

var (
	read  func() string
	readline func() string
	readlines func() []string
)

func init() {
	read = func() string {
		scanner := bufio.NewScanner(os.Stdin)
		if!scanner.Scan() {
			return ""
		}
		return scanner.Text()
	}
	readline = func() string {
		scanner := bufio.NewScanner(os.Stdin)
		if!scanner.Scan() {
			return ""
		}
		return scanner.Text()
	}
	readlines = func() []string {
		var lines []string
		scanner := bufio.NewScanner(os.Stdin)
		for scanner.Scan() {
			lines = append(lines, scanner.Text())
		}
		return lines
	}
}

func main() {
	N, d, x := readlineInt64()
	ret := int64(0)
	for N > 0 {
		ret += d + (N-0.5)*x
		d = d + d/N + 5*x/(2*N)
		x = x + 2*x/N
		N--
	}
	fmt.Println(ret)
}

func readlineInt64() (int64, int64, int64) {
	line := readline()
	fields := strings.Split(line, " ")
	N, _ := strconv.ParseInt(fields[0], 10, 64)
	d, _ := strconv.ParseInt(fields[1], 10, 64)
	x, _ := strconv.ParseInt(fields[2], 10, 64)
	return N, d, x
}

func readlineInt() (int, int, int) {
	line := readline()
	fields := strings.Split(line, " ")
	N, _ := strconv.Atoi(fields[0])
	d, _ := strconv.Atoi(fields[1])
	x, _ := strconv.Atoi(fields[2])
	return N, d, x
}

func readlineUint64() (uint64, uint64, uint64) {
	line := readline()
	fields := strings.Split(line, " ")
	N, _ := strconv.ParseUint(fields[0], 10, 64)
	d, _ := strconv.ParseUint(fields[1], 10, 64)
	x, _ := strconv.ParseUint(fields[2], 10, 64)
	return N, d, x
}

func readlineUint() (uint, uint, uint) {
	line := readline()
	fields := strings.Split(line, " ")
	N, _ := strconv.Atoi(fields[0])
	d, _ := strconv.Atoi(fields[1])
	x, _ := strconv.Atoi(fields[2])
	return uint(N), uint(d), uint(x)
}

func debug(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugln(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func readlineStr() (string, string, string) {
	line := readline()
	fields := strings.Split(line, " ")
	return fields[0], fields[1], fields[2]
}

func readStrs() []string {
	line := readline()
	fields := strings.Split(line, " ")
	return fields
}

func readlineBytes() ([]byte, []byte, []byte) {
	line := readline()
	fields, _ := readFields(line)
	return fields[0], fields[1], fields[2]
}

func readBytes() [][]byte {
	line := readline()
	fields, _ := readFields(line)
	return fields
}

func readFields(line []byte) ([][]byte, int) {
	fields := bytes.Split(line, []byte{' '})
	return fields, len(fields)
}

func readlineInt64s() ([]int64, []int64, []int64) {
	line := readline()
	fields, _ := readInt64s(line)
	return fields[0], fields[1], fields[2]
}

func readInt64s() ([][]int64, int) {
	line := readline()
	fields, _ := readInt64s(line)
	return fields, len(fields)
}

func readInt64s(line []byte) ([][]int64, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]int64, len(fields))
	for i, field := range fields {
		ret[i], _ = readInt64s(field)
	}
	return ret, len(ret)
}

func readlineUint64s() ([]uint64, []uint64, []uint64) {
	line := readline()
	fields, _ := readUint64s(line)
	return fields[0], fields[1], fields[2]
}

func readUint64s() ([][]uint64, int) {
	line := readline()
	fields, _ := readUint64s(line)
	return fields, len(fields)
}

func readUint64s(line []byte) ([][]uint64, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]uint64, len(fields))
	for i, field := range fields {
		ret[i], _ = readUint64s(field)
	}
	return ret, len(ret)
}

func readlineUints() ([]uint, []uint, []uint) {
	line := readline()
	fields, _ := readUints(line)
	return fields[0], fields[1], fields[2]
}

func readUints() ([][]uint, int) {
	line := readline()
	fields, _ := readUints(line)
	return fields, len(fields)
}

func readUints(line []byte) ([][]uint, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]uint, len(fields))
	for i, field := range fields {
		ret[i], _ = readUints(field)
	}
	return ret, len(ret)
}

func readlineStrs() ([]string, []string, []string) {
	line := readline()
	fields, _ := readStrs(line)
	return fields[0], fields[1], fields[2]
}

func readStrs() ([][]string, int) {
	line := readline()
	fields, _ := readStrs(line)
	return fields, len(fields)
}

func readStrs(line []byte) ([][]string, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]string, len(fields))
	for i, field := range fields {
		ret[i], _ = readStrs(field)
	}
	return ret, len(ret)
}

func readlineBytes() ([][]byte, [][]byte, [][]byte) {
	line := readline()
	fields, _ := readBytes(line)
	return fields[0], fields[1], fields[2]
}

func readBytes() ([][]byte, int) {
	line := readline()
	fields, _ := readBytes(line)
	return fields, len(fields)
}

func readBytes(line []byte) ([][]byte, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]byte, len(fields))
	for i, field := range fields {
		ret[i], _ = readBytes(field)
	}
	return ret, len(ret)
}

func readlineInt() (int, int, int) {
	line := readline()
	fields, _ := readInts(line)
	return fields[0], fields[1], fields[2]
}

func readlineInts() ([]int, []int, []int) {
	line := readline()
	fields, _ := readInts(line)
	return fields[0], fields[1], fields[2]
}

func readInts() ([][]int, int) {
	line := readline()
	fields, _ := readInts(line)
	return fields, len(fields)
}

func readInts(line []byte) ([][]int, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]int, len(fields))
	for i, field := range fields {
		ret[i], _ = readInts(field)
	}
	return ret, len(ret)
}

func readlineUint() (uint, uint, uint) {
	line := readline()
	fields, _ := readUints(line)
	return fields[0], fields[1], fields[2]
}

func readlineUints() ([]uint, []uint, []uint) {
	line := readline()
	fields, _ := readUints(line)
	return fields[0], fields[1], fields[2]
}

func readUints() ([][]uint, int) {
	line := readline()
	fields, _ := readUints(line)
	return fields, len(fields)
}

func readUints(line []byte) ([][]uint, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]uint, len(fields))
	for i, field := range fields {
		ret[i], _ = readUints(field)
	}
	return ret, len(ret)
}

func readlineBools() ([]bool, []bool, []bool) {
	line := readline()
	fields, _ := readBools(line)
	return fields[0], fields[1], fields[2]
}

func readBools() ([][]bool, int) {
	line := readline()
	fields, _ := readBools(line)
	return fields, len(fields)
}

func readBools(line []byte) ([][]bool, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]bool, len(fields))
	for i, field := range fields {
		ret[i], _ = readBools(field)
	}
	return ret, len(ret)
}

func readlineBool() (bool, bool, bool) {
	line := readline()
	fields, _ := readBools(line)
	return fields[0], fields[1], fields[2]
}

func readlineBools() ([]bool, []bool, []bool) {
	line := readline()
	fields, _ := readBools(line)
	return fields[0], fields[1], fields[2]
}

func readBools() ([][]bool, int) {
	line := readline()
	fields, _ := readBools(line)
	return fields, len(fields)
}

func readBools(line []byte) ([][]bool, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]bool, len(fields))
	for i, field := range fields {
		ret[i], _ = readBools(field)
	}
	return ret, len(ret)
}

func readlineRunes() ([]rune, []rune, []rune) {
	line := readline()
	fields, _ := readRunes(line)
	return fields[0], fields[1], fields[2]
}

func readRunes() ([][]rune, int) {
	line := readline()
	fields, _ := readRunes(line)
	return fields, len(fields)
}

func readRunes(line []byte) ([][]rune, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]rune, len(fields))
	for i, field := range fields {
		ret[i], _ = readRunes(field)
	}
	return ret, len(ret)
}

func readlineFloat64() (float64, float64, float64) {
	line := readline()
	fields, _ := readFloat64s(line)
	return fields[0], fields[1], fields[2]
}

func readlineFloat64s() ([]float64, []float64, []float64) {
	line := readline()
	fields, _ := readFloat64s(line)
	return fields[0], fields[1], fields[2]
}

func readFloat64s() ([][]float64, int) {
	line := readline()
	fields, _ := readFloat64s(line)
	return fields, len(fields)
}

func readFloat64s(line []byte) ([][]float64, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]float64, len(fields))
	for i, field := range fields {
		ret[i], _ = readFloat64s(field)
	}
	return ret, len(ret)
}

func readlineFloat32() (float32, float32, float32) {
	line := readline()
	fields, _ := readFloat32s(line)
	return fields[0], fields[1], fields[2]
}

func readlineFloat32s() ([]float32, []float32, []float32) {
	line := readline()
	fields, _ := readFloat32s(line)
	return fields[0], fields[1], fields[2]
}

func readFloat32s() ([][]float32, int) {
	line := readline()
	fields, _ := readFloat32s(line)
	return fields, len(fields)
}

func readFloat32s(line []byte) ([][]float32, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]float32, len(fields))
	for i, field := range fields {
		ret[i], _ = readFloat32s(field)
	}
	return ret, len(ret)
}

func readlineComplex64() (complex64, complex64, complex64) {
	line := readline()
	fields, _ := readComplex64s(line)
	return fields[0], fields[1], fields[2]
}

func readlineComplex64s() ([]complex64, []complex64, []complex64) {
	line := readline()
	fields, _ := readComplex64s(line)
	return fields[0], fields[1], fields[2]
}

func readComplex64s() ([][]complex64, int) {
	line := readline()
	fields, _ := readComplex64s(line)
	return fields, len(fields)
}

func readComplex64s(line []byte) ([][]complex64, int) {
	fields := bytes.Split(line, []byte{' '})
	ret := make([][]complex64, len(fields))
	for i, field := range fields {
		ret[i], _ = readComplex64s(field)
	}
	return ret, len(ret)
}

func readlineComplex128() (complex128, complex128, complex128) {
	line := readline()
	fields, _ := readComplex128s(line)
	return fields[0], fields[1], fields[2]
}

func readlineComplex128s() ([]complex128, []complex128, []complex128) {
	line := readline()
	fields, _ := readComplex128s(line)
	return fields[0], fields[1], fields[2]
}

func readComplex128s() ([][