

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
	xxs := strings.Split(readLine(reader), " ")
	x, t, a, b, da, db := mustParseInt64(xxs[0]), mustParseInt64(xxs[1]), mustParseInt64(xxs[2]), mustParseInt64(xxs[3]), mustParseInt64(xxs[4]), mustParseInt64(xxs[5])

	// Define the main function to perform the logic
	main := func() {
		// Check if the value of x is 0
		if x == 0 {
			fmt.Println("YES")
			return
		}

		// Calculate the maximum number of times a and b can be decremented within the time limit t
		aTime := int(min(int64(a/da), t-1))
		bTime := int(min(int64(b/db), t-1))

		// Iterate over all possible combinations of decrements for a and b within their respective limits
		for i := 0; i <= aTime; i++ {
			for j := 0; j <= bTime; j++ {
				// Check if either a or b (or their sum) equals x
				if a-int64(da*i) == x || b-int64(db*j) == x {
					fmt.Println("YES")
					return
				}
				if (a-int64(da*i))+(b-int64(db*j)) == x {
					fmt.Println("YES")
					return
				}
			}
		}

		// Print "NO" if no combination results in x
		fmt.Println("NO")
	}

	// Call the main function
	main()
}

// Read a single string from stdin
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	panic(err)
}

// Read all integers from stdin
func readInt64s(reader *bufio.Reader) []int64 {
	line := readLine(reader)
	xxs := strings.Split(line, " ")
	var ints []int64
	for _, xx := range xxs {
		x, err := strconv.ParseInt(xx, 10, 64)
		if err!= nil {
			panic(err)
		}
		ints = append(ints, x)
	}
	return ints
}

// Read a single integer from stdin
func readInt64(reader *bufio.Reader) int64 {
	ints := readInt64s(reader)
	if len(ints) == 0 {
		panic("No integers found")
	}
	return ints[0]
}

// Read all integers from stdin
func readInts(reader *bufio.Reader) []int {
	ints64 := readInt64s(reader)
	ints := make([]int, len(ints64))
	for i, ints64 := range ints64 {
		ints[i] = int(ints64)
	}
	return ints
}

// Read a single integer from stdin
func readInt(reader *bufio.Reader) int {
	ints := readInts(reader)
	if len(ints) == 0 {
		panic("No integers found")
	}
	return ints[0]
}

// Read all strings from stdin
func readStrings(reader *bufio.Reader) []string {
	line := readLine(reader)
	xxs := strings.Split(line, " ")
	return xxs
}

// Read a single string from stdin
func readString(reader *bufio.Reader) string {
	xxs := readStrings(reader)
	if len(xxs) == 0 {
		panic("No strings found")
	}
	return xxs[0]
}

// Read all floats from stdin
func readFloat64s(reader *bufio.Reader) []float64 {
	line := readLine(reader)
	xxs := strings.Split(line, " ")
	var floats []float64
	for _, xx := range xxs {
		x, err := strconv.ParseFloat(xx, 64)
		if err!= nil {
			panic(err)
		}
		floats = append(floats, x)
	}
	return floats
}

// Read a single float from stdin
func readFloat64(reader *bufio.Reader) float64 {
	floats := readFloat64s(reader)
	if len(floats) == 0 {
		panic("No floats found")
	}
	return floats[0]
}

// Read all floats from stdin
func readFloats(reader *bufio.Reader) []float32 {
	float64s := readFloat64s(reader)
	floats := make([]float32, len(float64s))
	for i, float64 := range float64s {
		floats[i] = float32(float64)
	}
	return floats
}

// Read a single float from stdin
func readFloat(reader *bufio.Reader) float32 {
	floats := readFloats(reader)
	if len(floats) == 0 {
		panic("No floats found")
	}
	return floats[0]
}

// Read all bytes from stdin
func readBytes(reader *bufio.Reader) []byte {
	line := readLine(reader)
	return []byte(line)
}

// Read a single byte from stdin
func readByte(reader *bufio.Reader) byte {
	bytes := readBytes(reader)
	if len(bytes) == 0 {
		panic("No bytes found")
	}
	return bytes[0]
}

// Read all runes from stdin
func readRunes(reader *bufio.Reader) []rune {
	line := readLine(reader)
	return []rune(line)
}

// Read a single rune from stdin
func readRune(reader *bufio.Reader) rune {
	runes := readRunes(reader)
	if len(runes) == 0 {
		panic("No runes found")
	}
	return runes[0]
}

// Read all uints from stdin
func readUint64s(reader *bufio.Reader) []uint64 {
	line := readLine(reader)
	xxs := strings.Split(line, " ")
	var uints []uint64
	for _, xx := range xxs {
		x, err := strconv.ParseUint(xx, 10, 64)
		if err!= nil {
			panic(err)
		}
		uints = append(uints, x)
	}
	return uints
}

// Read a single uint from stdin
func readUint64(reader *bufio.Reader) uint64 {
	uints := readUint64s(reader)
	if len(uints) == 0 {
		panic("No uints found")
	}
	return uints[0]
}

// Read all uints from stdin
func readUints(reader *bufio.Reader) []uint {
	uint64s := readUint64s(reader)
	uints := make([]uint, len(uint64s))
	for i, uint64 := range uint64s {
		uints[i] = uint(uint64)
	}
	return uints
}

// Read a single uint from stdin
func readUint(reader *bufio.Reader) uint {
	uints := readUints(reader)
	if len(uints) == 0 {
		panic("No uints found")
	}
	return uints[0]
}

// Read all bools from stdin
func readBools(reader *bufio.Reader) []bool {
	line := readLine(reader)
	xxs := strings.Split(line, " ")
	var bools []bool
	for _, xx := range xxs {
		x, err := strconv.ParseBool(xx)
		if err!= nil {
			panic(err)
		}
		bools = append(bools, x)
	}
	return bools
}

// Read a single bool from stdin
func readBool(reader *bufio.Reader) bool {
	bools := readBools(reader)
	if len(bools) == 0 {
		panic("No bools found")
	}
	return bools[0]
}

// Read all uints from stdin
func readInts64(reader *bufio.Reader) []int64 {
	line := readLine(reader)
	xxs := strings.Split(line, " ")
	var ints []int64
	for _, xx := range xxs {
		x, err := strconv.ParseInt(xx, 10, 64)
		if err!= nil {
			panic(err)
		}
		ints = append(ints, x)
	}
	return ints
}

// Read a single uint from stdin
func readInt64(reader *bufio.Reader) int64 {
	ints := readInts64(reader)
	if len(ints) == 0 {
		panic("No ints found")
	}
	return ints[0]
}

// Read all uints from stdin
func readInts(reader *bufio.Reader) []int {
	ints64 := readInts64(reader)
	ints := make([]int, len(ints64))
	for i, ints64 := range ints64 {
		ints[i] = int(ints64)
	}
	return ints
}

// Read a single uint from stdin
func readInt(reader *bufio.Reader) int {
	ints := readInts(reader)
	if len(ints) == 0 {
		panic("No ints found")
	}
	return ints[0]
}

// Read all uints from stdin
func readUints64(reader *bufio.Reader) []uint64 {
	line := readLine(reader)
	xxs := strings.Split(line, " ")
	var uints []uint64
	for _, xx := range xxs {
		x, err := strconv.ParseUint(xx, 10, 64)
		if err!= nil {
			panic(err)
		}
		uints = append(uints, x)
	}
	return uints
}

// Read a single uint from stdin
func readUint64(reader *bufio.Reader) uint64 {
	uints := readUints64(reader)
	if len(uints) == 0 {
		panic("No uints found")
	}
	return uints[0]
}

// Read all uints from stdin
func readUints(reader *bufio.Reader) []uint {
	uints64 := readUints64(reader)
	uints := make([]uint, len(uints64))
	for i, uints64 := range uints64 {
		uints[i] = uint(uints64)
	}
	return uints
}

// Read a single uint from stdin
func readUint(reader *bufio.Reader) uint {
	uints := readUints(reader)
	if len(uints) == 0 {
		panic("No uints found")
	}
	return uints[0]
}

// Read all uints from stdin
func readInts(reader *bufio.Reader) []int {
	ints64 := readInts64(reader)
	ints := make([]int, len(ints64))
	for i, ints64 := range ints64 {
		ints[i] = int(ints64)
	}
	return ints
}

// Read a single uint from stdin
func readInt(reader *bufio.Reader) int {
	ints := readInts(reader)
	if len(ints) == 0 {
		panic("No ints found")
	}
	return ints[0]
}

// Read all uints from stdin
func readUints(reader *bufio.Reader) []uint {
	uints64 := readUints64(reader)
	uints := make([]uint, len(uints64))
	for i, uints64 := range uints64 {
		uints[i] = uint(uints64)
	}
	return uints
}

// Read a single uint from stdin
func readUint(reader *bufio.Reader) uint {
	uints := readUints(reader)
	if len(uints) == 0 {
		panic("No uints found")
	}
	return uints[0]
}

// Read all uints from stdin
func readInts(reader *bufio.Reader) []int {
	ints64 := readInts64(reader)
	ints := make([]int, len(ints64))
	for i, ints64 := range ints64 {
		ints[i] = int(ints64)
	}
	return ints
}

// Read a single uint from stdin
func readInt(reader *bufio.Reader) int {
	ints := readInts(reader)
	if len(ints) == 0 {
		panic("No ints found")
	}
	return ints[0]
}

// Read all uints from stdin
func readUints(reader *bufio.Reader) []uint {
	uints64 := readUints64(reader)
	uints := make([]uint, len(uints64))
	for i, uints64 := range uints64 {
		uints[i] = uint(uints64)
	}
	return uints
}

// Read a single uint from stdin
func readUint(reader *bufio.Reader) uint {
	uints := readUints(reader)
	if len(uints) == 0 {
		panic("No uints found")
	}
	return uints[0]
}

// Read all uints from stdin
func readInts(reader *bufio.Reader) []int {
	ints64 := readInts64(reader)
	ints := make([]int, len(ints64))
	for i, ints64 := range ints64 {
		ints[i] = int(ints64)
	}
	return ints
}

// Read a single uint from stdin
func readInt(reader *bufio.Reader) int {
	ints := readInts(reader)
	if len(ints) == 0 {
		panic("No ints found")
	}
	return ints[0]
}

// Read all uints from stdin
func readUints(reader *bufio.Reader) []uint {
	uints64 := readUints64(reader)
	uints := make([]uint, len(uints64))
	for i, uints64 := range uints64 {
		uints[i] = uint(uints64)
	}
	return uints
}

// Read a single uint from stdin
func readUint(reader *bufio.Reader) uint {
	uints := readUints(reader)
	if len(uints) == 0 {
		panic("No uints found")
	}
	return uints[0]
}

// Read all uints from stdin
func readInts(reader *bufio.Reader) []int {
	ints64 := readInts64(reader)
	ints := make([]int, len(ints64))
	for i, ints64 := range ints64 {
		ints[i] = int(ints64)
	}
	return ints
}

// Read a single uint from stdin
func readInt(reader *bufio.Reader) int {
	ints := readInts(reader)
	if len(ints) == 0 {
		panic("No ints found")
	}
	return ints[0]
}

// Read all uints from stdin
func readUints(reader *bufio.Reader) []uint {
	uints64