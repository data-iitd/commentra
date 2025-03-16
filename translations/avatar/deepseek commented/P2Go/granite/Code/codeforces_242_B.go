

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// Define functions to read input efficiently
var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(read())

	// Initialize variables to track the best candidate interval
	id := 0
	l, r := read_int(), read_int()

	// Process each interval
	for i := 1; i < n; i++ {
		li, ri := read_int(), read_int()
		// Check if the current interval completely covers the best candidate interval
		if li <= l && r <= ri {
			id = i
		}
		// Check if the current interval overlaps with the best candidate interval
		else if li < l || r < ri {
			id = n
		}
		// Update the boundaries of the best candidate interval
		if li < l {
			l = li
		}
		if ri > r {
			r = ri
		}
	}

	// Output the result
	fmt.Fprintln(out, -1 if id == n else id+1)
	out.Flush()
}

func read() string {
	line, _ := in.ReadString('\n')
	return strings.TrimSpace(line)
}

func read_int() int {
	x, _ := strconv.Atoi(read())
	return x
}

func read_ints() []int {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	xs := make([]int, len(parts))
	for i, part := range parts {
		xs[i], _ = strconv.Atoi(part)
	}
	return xs
}

func read_str() string {
	return read()
}

func read_strs() []string {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	return strings.Split(line, " ")
}

func read_str_array(n int) []string {
	xs := make([]string, n)
	for i := 0; i < n; i++ {
		xs[i] = read_str()
	}
	return xs
}

func read_int_array(n int) []int {
	xs := make([]int, n)
	for i := 0; i < n; i++ {
		xs[i] = read_int()
	}
	return xs
}

func read_int64() int64 {
	x, _ := strconv.ParseInt(read(), 10, 64)
	return x
}

func read_int64s() []int64 {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	xs := make([]int64, len(parts))
	for i, part := range parts {
		xs[i], _ = strconv.ParseInt(part, 10, 64)
	}
	return xs
}

func read_float64() float64 {
	x, _ := strconv.ParseFloat(read(), 64)
	return x
}

func read_float64s() []float64 {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	xs := make([]float64, len(parts))
	for i, part := range parts {
		xs[i], _ = strconv.ParseFloat(part, 64)
	}
	return xs
}

func read_uint64() uint64 {
	x, _ := strconv.ParseUint(read(), 10, 64)
	return x
}

func read_uint64s() []uint64 {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	xs := make([]uint64, len(parts))
	for i, part := range parts {
		xs[i], _ = strconv.ParseUint(part, 10, 64)
	}
	return xs
}

func read_line() string {
	line, _ := in.ReadString('\n')
	return line
}

func read_lines(n int) []string {
	var lines []string
	for i := 0; i < n; i++ {
		line, _ := in.ReadString('\n')
		lines = append(lines, line)
	}
	return lines
}

func read_line_array(n int) []string {
	lines := make([]string, n)
	for i := 0; i < n; i++ {
		line, _ := in.ReadString('\n')
		lines[i] = line
	}
	return lines
}

func read_byte() byte {
	b := make([]byte, 1)
	in.Read(b)
	return b[0]
}

func read_bytes() []byte {
	line, _ := in.ReadString('\n')
	return []byte(strings.TrimSpace(line))
}

func read_byte_array(n int) []byte {
	b := make([]byte, n)
	in.Read(b)
	return b
}

func read_bool() bool {
	b, _ := strconv.ParseBool(read())
	return b
}

func read_bools() []bool {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	xs := make([]bool, len(parts))
	for i, part := range parts {
		xs[i], _ = strconv.ParseBool(part)
	}
	return xs
}

func read_runes() []rune {
	line, _ := in.ReadString('\n')
	return []rune(strings.TrimSpace(line))
}

func read_rune_array(n int) []rune {
	r := make([]rune, n)
	in.Read(r)
	return r
}

func read_complex64() complex64 {
	c, _ := strconv.ParseComplex(read(), 64)
	return c
}

func read_complex64s() []complex64 {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	xs := make([]complex64, len(parts))
	for i, part := range parts {
		xs[i], _ = strconv.ParseComplex(part, 64)
	}
	return xs
}

func read_complex128() complex128 {
	c, _ := strconv.ParseComplex(read(), 128)
	return c
}

func read_complex128s() []complex128 {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	xs := make([]complex128, len(parts))
	for i, part := range parts {
		xs[i], _ = strconv.ParseComplex(part, 128)
	}
	return xs
}

func read_interface() interface{} {
	return read()
}

func read_interfaces() []interface{} {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	xs := make([]interface{}, len(parts))
	for i, part := range parts {
		xs[i] = part
	}
	return xs
}

func read_interface_array(n int) []interface{} {
	xs := make([]interface{}, n)
	for i := 0; i < n; i++ {
		xs[i] = read()
	}
	return xs
}

func read_map() map[string]string {
	m := make(map[string]string)
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	for _, part := range parts {
		key, value := strings.Split(part, ":")
		m[key] = value
	}
	return m
}

func read_maps() []map[string]string {
	var maps []map[string]string
	for {
		m := make(map[string]string)
		line, _ := in.ReadString('\n')
		line = strings.TrimSpace(line)
		if line == "" {
			break
		}
		parts := strings.Split(line, " ")
		for _, part := range parts {
			key, value := strings.Split(part, ":")
			m[key] = value
		}
		maps = append(maps, m)
	}
	return maps
}

func read_map_array(n int) []map[string]string {
	maps := make([]map[string]string, n)
	for i := 0; i < n; i++ {
		m := make(map[string]string)
		line, _ := in.ReadString('\n')
		line = strings.TrimSpace(line)
		parts := strings.Split(line, " ")
		for _, part := range parts {
			key, value := strings.Split(part, ":")
			m[key] = value
		}
		maps[i] = m
	}
	return maps
}

func read_map_interface() map[string]interface{} {
	m := make(map[string]interface{})
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	for _, part := range parts {
		key, value := strings.Split(part, ":")
		m[key] = value
	}
	return m
}

func read_map_interfaces() []map[string]interface{} {
	var maps []map[string]interface{}
	for {
		m := make(map[string]interface{})
		line, _ := in.ReadString('\n')
		line = strings.TrimSpace(line)
		if line == "" {
			break
		}
		parts := strings.Split(line, " ")
		for _, part := range parts {
			key, value := strings.Split(part, ":")
			m[key] = value
		}
		maps = append(maps, m)
	}
	return maps
}

func read_map_interface_array(n int) []map[string]interface{} {
	maps := make([]map[string]interface{}, n)
	for i := 0; i < n; i++ {
		m := make(map[string]interface{})
		line, _ := in.ReadString('\n')
		line = strings.TrimSpace(line)
		parts := strings.Split(line, " ")
		for _, part := range parts {
			key, value := strings.Split(part, ":")
			m[key] = value
		}
		maps[i] = m
	}
	return maps
}

func read_map_string() map[string]string {
	m := make(map[string]string)
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	for _, part := range parts {
		key, value := strings.Split(part, ":")
		m[key] = value
	}
	return m
}

func read_map_strings() []map[string]string {
	var maps []map[string]string
	for {
		m := make(map[string]string)
		line, _ := in.ReadString('\n')
		line = strings.TrimSpace(line)
		if line == "" {
			break
		}
		parts := strings.Split(line, " ")
		for _, part := range parts {
			key, value := strings.Split(part, ":")
			m[key] = value
		}
		maps = append(maps, m)
	}
	return maps
}

func read_map_string_array(n int) []map[string]string {
	maps := make([]map[string]string, n)
	for i := 0; i < n; i++ {
		m := make(map[string]string)
		line, _ := in.ReadString('\n')
		line = strings.TrimSpace(line)
		parts := strings.Split(line, " ")
		for _, part := range parts {
			key, value := strings.Split(part, ":")
			m[key] = value
		}
		maps[i] = m
	}
	return maps
}

func read_map_int() map[string]int {
	m := make(map[string]int)
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	for _, part := range parts {
		key, value := strings.Split(part, ":")
		m[key], _ = strconv.Atoi(value)
	}
	return m
}

func read_map_ints() []map[string]int {
	var maps []map[string]int
	for {
		m := make(map[string]int)
		line, _ := in.ReadString('\n')
		line = strings.TrimSpace(line)
		if line == "" {
			break
		}
		parts := strings.Split(line, " ")
		for _, part := range parts {
			key, value := strings.Split(part, ":")
			m[key], _ = strconv.Atoi(value)
		}
		maps = append(maps, m)
	}
	return maps
}

func read_map_int_array(n int) []map[string]int {
	maps := make([]map[string]int, n)
	for i := 0; i < n; i++ {
		m := make(map[string]int)
		line, _ := in.ReadString('\n')
		line = strings.TrimSpace(line)
		parts := strings.Split(line, " ")
		for _, part := range parts {
			key, value := strings.Split(part, ":")
			m[key], _ = strconv.Atoi(value)
		}
		maps[i] = m
	}
	return maps
}

func read_map_int64() map[string]int64 {
	m := make(map[string]int64)
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	for _, part := range parts {
		key, value := strings.Split(part, ":")
		m[key], _ = strconv.ParseInt(value, 10, 64)
	}
	return m
}

func read_map_int64s() []map[string]int64 {
	var maps []map[string]int64
	for {
		m := make(map[string]int64)
		line, _ := in.ReadString('\n')
		line = strings.TrimSpace(line)
		if line == "" {
			break
		}
		parts := strings.Split(line, " ")
		for _, part := range parts {
			key, value := strings.Split(part, ":")
			m[key], _ = strconv.ParseInt(value, 10, 64)
		}
		maps = append(maps, m)
	}
	return maps
}

func read_map_int64_array(n int) []ma