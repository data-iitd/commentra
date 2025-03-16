
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read an integer input N (not used in further calculations)
	N, _ := strconv.Atoi(readerreadLine(reader))

	// Read a list of integers from input and convert them to a list of integers
	a := readLine(reader)
	a = strings.Split(a, " ")
	var a_i []int
	for _, num := range a {
		num_i, _ := strconv.Atoi(num)
		a_i = append(a_i, num_i)
	}

	// Calculate the total using the XOR operation across all elements in the list 'a'
	total := 0
	for _, num := range a_i {
		total ^= num
	}

	// For each element in the list 'a', compute the XOR with 'total' and print the results
	// The results are converted to strings and joined with a space for output
	fmt.Println(strings.Join(func() []string {
		var res []string
		for _, num := range a_i {
			res = append(res, strconv.Itoa(num^total))
		}
		return res
	}(), " "))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}

func readInt(bytes []byte) (int, error) {
	return strconv.Atoi(string(bytes))
}

func readInt64(bytes []byte) (int64, error) {
	return strconv.ParseInt(string(bytes), 10, 64)
}

func readFloat64(bytes []byte) (float64, error) {
	return strconv.ParseFloat(string(bytes), 64)
}

func readNInt64s(reader *bufio.Reader, n int) ([]int64, error) {
	res := make([]int64, n)
	str, err := reader.ReadBytes('\n')
	if err == nil {
		words := strings.Split(string(str), " ")
		for index, word := range words {
			num, err := strconv.ParseInt(word, 10, 64)
			if err!= nil {
				return res, err
			}
			res[index] = num
		}
	}
	return res, err
}

func readInt64s(reader *bufio.Reader) ([]int64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return []int64{}, err
	}

	words := strings.Split(string(line), " ")

	var res []int64

	for _, word := range words {
		num, err := strconv.ParseInt(word, 10, 64)
		if err!= nil {
			return []int64{}, err
		}
		res = append(res, num)
	}

	return res, nil
}

func readUInt64s(reader *bufio.Reader) ([]uint64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return []uint64{}, err
	}

	words := strings.Split(string(line), " ")

	var res []uint64

	for _, word := range words {
		num, err := strconv.ParseUint(word, 10, 64)
		if err!= nil {
			return []uint64{}, err
		}
		res = append(res, num)
	}

	return res, nil
}

func readFloat64s(reader *bufio.Reader) ([]float64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return []float64{}, err
	}

	words := strings.Split(string(line), " ")

	var res []float64

	for _, word := range words {
		num, err := strconv.ParseFloat(word, 64)
		if err!= nil {
			return []float64{}, err
		}
		res = append(res, num)
	}

	return res, nil
}

func readLineInt64s(reader *bufio.Reader) ([]int64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return []int64{}, err
	}

	words := strings.Split(string(line), " ")

	var res []int64

	for _, word := range words {
		num, err := strconv.ParseInt(word, 10, 64)
		if err!= nil {
			return []int64{}, err
		}
		res = append(res, num)
	}

	return res, nil
}

func readLineUInt64s(reader *bufio.Reader) ([]uint64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return []uint64{}, err
	}

	words := strings.Split(string(line), " ")

	var res []uint64

	for _, word := range words {
		num, err := strconv.ParseUint(word, 10, 64)
		if err!= nil {
			return []uint64{}, err
		}
		res = append(res, num)
	}

	return res, nil
}

func readLineFloat64s(reader *bufio.Reader) ([]float64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return []float64{}, err
	}

	words := strings.Split(string(line), " ")

	var res []float64

	for _, word := range words {
		num, err := strconv.ParseFloat(word, 64)
		if err!= nil {
			return []float64{}, err
		}
		res = append(res, num)
	}

	return res, nil
}

func readLineStrings(reader *bufio.Reader) ([]string, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return []string{}, err
	}

	words := strings.Split(string(line), " ")

	var res []string

	for _, word := range words {
		res = append(res, word)
	}

	return res, nil
}

func readLineRunes(reader *bufio.Reader) ([]rune, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return []rune{}, err
	}

	return []rune(string(line)), nil
}

func readLineBools(reader *bufio.Reader) ([]bool, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return []bool{}, err
	}

	words := strings.Split(string(line), " ")

	var res []bool

	for _, word := range words {
		wordAsBool, err := strconv.ParseBool(word)
		if err!= nil {
			return []bool{}, err
		}
		res = append(res, wordAsBool)
	}

	return res, nil
}

func readLineBytes(reader *bufio.Reader) ([]byte, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return []byte{}, err
	}

	return line, nil
}

func readLineByteSlices(reader *bufio.Reader) ([][]byte, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]byte{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]byte

	for _, word := range words {
		res = append(res, []byte(word))
	}

	return res, nil
}

func readLineRuneSlices(reader *bufio.Reader) ([][]rune, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]rune{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]rune

	for _, word := range words {
		res = append(res, []rune(word))
	}

	return res, nil
}

func readLineBoolSlices(reader *bufio.Reader) ([][]bool, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]bool{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]bool

	for _, word := range words {
		wordAsBool, err := strconv.ParseBool(word)
		if err!= nil {
			return [][]bool{}, err
		}
		res = append(res, []bool{wordAsBool})
	}

	return res, nil
}

func readLineInt64Slices(reader *bufio.Reader) ([][]int64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]int64{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]int64

	for _, word := range words {
		num, err := strconv.ParseInt(word, 10, 64)
		if err!= nil {
			return [][]int64{}, err
		}
		res = append(res, []int64{num})
	}

	return res, nil
}

func readLineUInt64Slices(reader *bufio.Reader) ([][]uint64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]uint64{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]uint64

	for _, word := range words {
		num, err := strconv.ParseUint(word, 10, 64)
		if err!= nil {
			return [][]uint64{}, err
		}
		res = append(res, []uint64{num})
	}

	return res, nil
}

func readLineFloat64Slices(reader *bufio.Reader) ([][]float64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]float64{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]float64

	for _, word := range words {
		num, err := strconv.ParseFloat(word, 64)
		if err!= nil {
			return [][]float64{}, err
		}
		res = append(res, []float64{num})
	}

	return res, nil
}

func readLineStringSlices(reader *bufio.Reader) ([][]string, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]string{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]string

	for _, word := range words {
		res = append(res, []string{word})
	}

	return res, nil
}

func readLineRuneSlices(reader *bufio.Reader) ([][]rune, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]rune{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]rune

	for _, word := range words {
		res = append(res, []rune(word))
	}

	return res, nil
}

func readLineBoolSlices(reader *bufio.Reader) ([][]bool, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]bool{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]bool

	for _, word := range words {
		wordAsBool, err := strconv.ParseBool(word)
		if err!= nil {
			return [][]bool{}, err
		}
		res = append(res, []bool{wordAsBool})
	}

	return res, nil
}

func readLineInt64Slices(reader *bufio.Reader) ([][]int64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]int64{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]int64

	for _, word := range words {
		num, err := strconv.ParseInt(word, 10, 64)
		if err!= nil {
			return [][]int64{}, err
		}
		res = append(res, []int64{num})
	}

	return res, nil
}

func readLineUInt64Slices(reader *bufio.Reader) ([][]uint64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]uint64{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]uint64

	for _, word := range words {
		num, err := strconv.ParseUint(word, 10, 64)
		if err!= nil {
			return [][]uint64{}, err
		}
		res = append(res, []uint64{num})
	}

	return res, nil
}

func readLineFloat64Slices(reader *bufio.Reader) ([][]float64, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]float64{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]float64

	for _, word := range words {
		num, err := strconv.ParseFloat(word, 64)
		if err!= nil {
			return [][]float64{}, err
		}
		res = append(res, []float64{num})
	}

	return res, nil
}

func readLineStringSlices(reader *bufio.Reader) ([][]string, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]string{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]string

	for _, word := range words {
		res = append(res, []string{word})
	}

	return res, nil
}

func readLineRuneSlices(reader *bufio.Reader) ([][]rune, error) {
	line, err := reader.ReadBytes('\n')
	if err!= nil {
		return [][]rune{}, err
	}

	words := strings.Split(string(line), " ")

	var res [][]rune

	for _, word := range words {
		res = append(res, []rune(word))
	}

	return res,