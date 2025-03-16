
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read four integers from input
	a, _ := reader.readInt()
	b, _ := reader.readInt()
	c, _ := reader.readInt()
	d, _ := reader.readInt()

	// Calculate the maximum value from the products of the pairs and return it
	ans := max(a*c, b*d, a*d, b*c)

	// Print the result of the main function
	fmt.Println(ans)
}

func max(a, b, c, d int) int {
	m := a
	if m < b {
		m = b
	}
	if m < c {
		m = c
	}
	if m < d {
		m = d
	}
	return m
}

// Function to read a single integer from input
func (reader *bufio.Reader) readInt() (int, error) {
	res, err := reader.ReadBytes('\n')
	if err!= nil {
		return 0, err
	}
	i, err := strconv.Atoi(string(res))
	if err!= nil {
		return 0, err
	}
	return i, nil
}

// Function to read a single string from input
func (reader *bufio.Reader) readString() (string, error) {
	s, err := reader.ReadString('\n')
	if err!= nil {
		return "", err
	}
	s = strings.TrimRight(s, "\n")
	return s, nil
}

// Function to read a single rune from input
func (reader *bufio.Reader) readRune() (rune, error) {
	var buf []byte
	buf, err := reader.ReadBytes('\n')
	if err!= nil {
		return 0, err
	}
	return buf[0], nil
}

// Function to read a single byte from input
func (reader *bufio.Reader) readByte() (byte, error) {
	b, err := reader.ReadByte()
	if err!= nil {
		return 0, err
	}
	return b, nil
}

// Function to read a single float64 from input
func (reader *bufio.Reader) readFloat64() (float64, error) {
	return strconv.ParseFloat(reader.readLine(), 64)
}

// Function to read a single float32 from input
func (reader *bufio.Reader) readFloat32() (float32, error) {
	return float32(reader.readFloat64())
}

// Function to read a line of input and return it as a string
func (reader *bufio.Reader) readLine() string {
	str, _ := reader.ReadString('\n')
	str = strings.TrimRight(str, "\n")
	return str
}

// Function to read a line of input and return it as a byte slice
func (reader *bufio.Reader) readBytes() []byte {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return nil
	}
	line = line[0 : len(line)-1]
	return line
}

// Function to read a line of input and return it as a rune slice
func (reader *bufio.Reader) readRunes() []rune {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return nil
	}
	line = line[0 : len(line)-1]
	return []rune(string(line))
}

// Function to read a line of input and return it as an integer slice
func (reader *bufio.Reader) readIntSlice() []int {
	res := make([]int, 0)
	arr := reader.readRunes()
	var tmp int
	prefix := true
	for _, c := range arr {
		if c =='' {
			prefix = false
			continue
		}
		if prefix {
			tmp = 0
		}
		tmp = tmp*10 + int(c-'0')
		if!prefix {
			res = append(res, tmp)
			prefix = true
		}
	}
	return res
}

// Function to read a line of input and return it as a string slice
func (reader *bufio.Reader) readStringSlice() []string {
	res := make([]string, 0)
	arr := reader.readRunes()
	var tmp string
	prefix := true
	for _, c := range arr {
		if c =='' {
			prefix = false
			continue
		}
		if prefix {
			tmp = ""
		}
		tmp += string(c)
		if!prefix {
			res = append(res, tmp)
			prefix = true
		}
	}
	return res
}

// Function to read a line of input and return it as a 2D integer slice
func (reader *bufio.Reader) readIntMatrix(rows int) [][]int {
	res := make([][]int, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readIntSlice()
	}
	return res
}

// Function to read a line of input and return it as a 2D string slice
func (reader *bufio.Reader) readStringMatrix(rows int) [][]string {
	res := make([][]string, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readStringSlice()
	}
	return res
}

// Function to read a line of input and return it as a 2D rune slice
func (reader *bufio.Reader) readRunesMatrix(rows int) [][]rune {
	res := make([][]rune, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readRunes()
	}
	return res
}

// Function to read a line of input and return it as a 2D byte slice
func (reader *bufio.Reader) readBytesMatrix(rows int) [][]byte {
	res := make([][]byte, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readBytes()
	}
	return res
}

// Function to read a line of input and return it as a 2D float64 slice
func (reader *bufio.Reader) readFloat64Matrix(rows int) [][]float64 {
	res := make([][]float64, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readFloat64Slice()
	}
	return res
}

// Function to read a line of input and return it as a 2D float32 slice
func (reader *bufio.Reader) readFloat32Matrix(rows int) [][]float32 {
	res := make([][]float32, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readFloat32Slice()
	}
	return res
}

// Function to read a line of input and return it as a 2D complex64 slice
func (reader *bufio.Reader) readComplex64Matrix(rows int) [][]complex64 {
	res := make([][]complex64, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readComplex64Slice()
	}
	return res
}

// Function to read a line of input and return it as a 2D complex128 slice
func (reader *bufio.Reader) readComplex128Matrix(rows int) [][]complex128 {
	res := make([][]complex128, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readComplex128Slice()
	}
	return res
}

// Function to read a line of input and return it as a 2D bool slice
func (reader *bufio.Reader) readBoolMatrix(rows int) [][]bool {
	res := make([][]bool, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readBoolSlice()
	}
	return res
}

// Function to read a line of input and return it as a 3D integer slice
func (reader *bufio.Reader) readInt3DMatrix(rows, cols int) [][][]int {
	res := make([][][]int, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readIntMatrix(cols)
	}
	return res
}

// Function to read a line of input and return it as a 3D string slice
func (reader *bufio.Reader) readString3DMatrix(rows, cols int) [][][]string {
	res := make([][][]string, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readStringMatrix(cols)
	}
	return res
}

// Function to read a line of input and return it as a 3D rune slice
func (reader *bufio.Reader) readRunes3DMatrix(rows, cols int) [][][]rune {
	res := make([][][]rune, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readRunesMatrix(cols)
	}
	return res
}

// Function to read a line of input and return it as a 3D byte slice
func (reader *bufio.Reader) readBytes3DMatrix(rows, cols int) [][][]byte {
	res := make([][][]byte, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readBytesMatrix(cols)
	}
	return res
}

// Function to read a line of input and return it as a 3D float64 slice
func (reader *bufio.Reader) readFloat643DMatrix(rows, cols int) [][][]float64 {
	res := make([][][]float64, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readFloat64Matrix(cols)
	}
	return res
}

// Function to read a line of input and return it as a 3D float32 slice
func (reader *bufio.Reader) readFloat323DMatrix(rows, cols int) [][][]float32 {
	res := make([][][]float32, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readFloat32Matrix(cols)
	}
	return res
}

// Function to read a line of input and return it as a 3D complex64 slice
func (reader *bufio.Reader) readComplex643DMatrix(rows, cols int) [][][]complex64 {
	res := make([][][]complex64, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readComplex64Matrix(cols)
	}
	return res
}

// Function to read a line of input and return it as a 3D complex128 slice
func (reader *bufio.Reader) readComplex1283DMatrix(rows, cols int) [][][]complex128 {
	res := make([][][]complex128, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readComplex128Matrix(cols)
	}
	return res
}

// Function to read a line of input and return it as a 3D bool slice
func (reader *bufio.Reader) readBool3DMatrix(rows, cols int) [][][]bool {
	res := make([][][]bool, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readBoolMatrix(cols)
	}
	return res
}

// Function to read a line of input and return it as a 4D integer slice
func (reader *bufio.Reader) readInt4DMatrix(rows, cols, depth int) [][][][]int {
	res := make([][][][]int, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readInt3DMatrix(cols, depth)
	}
	return res
}

// Function to read a line of input and return it as a 4D string slice
func (reader *bufio.Reader) readString4DMatrix(rows, cols, depth int) [][][][]string {
	res := make([][][][]string, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readString3DMatrix(cols, depth)
	}
	return res
}

// Function to read a line of input and return it as a 4D rune slice
func (reader *bufio.Reader) readRunes4DMatrix(rows, cols, depth int) [][][][]rune {
	res := make([][][][]rune, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readRunes3DMatrix(cols, depth)
	}
	return res
}

// Function to read a line of input and return it as a 4D byte slice
func (reader *bufio.Reader) readBytes4DMatrix(rows, cols, depth int) [][][][]byte {
	res := make([][][][]byte, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readBytes3DMatrix(cols, depth)
	}
	return res
}

// Function to read a line of input and return it as a 4D float64 slice
func (reader *bufio.Reader) readFloat644DMatrix(rows, cols, depth int) [][][][][]float64 {
	res := make([][][][][]float64, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readFloat643DMatrix(cols, depth)
	}
	return res
}

// Function to read a line of input and return it as a 4D float32 slice
func (reader *bufio.Reader) readFloat324DMatrix(rows, cols, depth int) [][][][][]float32 {
	res := make([][][][][]float32, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readFloat323DMatrix(cols, depth)
	}
	return res
}

// Function to read a line of input and return it as a 4D complex64 slice
func (reader *bufio.Reader) readComplex644DMatrix(rows, cols, depth int) [][][][][]complex64 {
	res := make([][][][][]complex64, rows)
	for i := 0; i < rows; i++ {
		res[i] = reader.readComplex643DMatrix(cols, depth)
	}
	return res
}

// Function to read a line of