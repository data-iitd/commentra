
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

// Define a helper function to read a single string from standard input
func readString(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    for i := 0; i < len(s); i++ {
        if s[i] == '\n' {
            return s[:i]
        }
    }
    return s
}

// Define a helper function to read a single integer from standard input
func readNum(reader *bufio.Reader) (a int) {
    bs, _ := reader.ReadBytes('\n')
    n := 0
    for i := 0; i < len(bs); i++ {
        if bs[i] == '\n' {
            break
        }
        n = n*10 + int(bs[i]-'0')
    }
    return n
}

// Define a helper function to read a single integer from standard input
func readTwoNums(reader *bufio.Reader) (a int, b int) {
    res := readNNums(reader, 2)
    a, b = res[0], res[1]
    return
}

// Define a helper function to read N integers from standard input
func readNNums(reader *bufio.Reader, n int) []int {
    res := make([]int, n)
    x := 0
    bs, _ := reader.ReadBytes('\n')
    for i := 0; i < n; i++ {
        for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
            x++
        }
        x = readInt(bs, x, &res[i])
    }
    return res
}

// Define a helper function to read a single integer from a byte slice
func readInt(bytes []byte, from int, val *int) int {
    i := from
    sign := 1
    if bytes[i] == '-' {
        sign = -1
        i++
    }
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp := int(bytes[i]-'0')
        *val = *val*10 + tmp
        i++
    }
    *val *= sign
    return i
}

// Define a helper function to read a list of integers from standard input
func readInt64s(reader *bufio.Reader) []int64 {
    list := make([]int64, 0, 10)
    for {
        x := readNum(reader)
        if x == 0 {
            break
        }
        list = append(list, x)
    }
    return list
}

// Define a helper function to read a list of strings from standard input
func readStrings(reader *bufio.Reader) []string {
    res := make([]string, 0, 10)
    for {
        line := readString(reader)
        if line == "" {
            break
        }
        res = append(res, line)
    }
    return res
}

// Define a helper function to read a grid of characters from standard input
func readGrid(reader *bufio.Reader, n int, m int) [][]byte {
    grid := make([][]byte, n)
    for i := 0; i < n; i++ {
        grid[i] = readBytes(reader, m)
    }
    return grid
}

// Define a helper function to read a grid of integers from standard input
func readIntGrid(reader *bufio.Reader, n int, m int) [][]int {
    grid := make([][]int, n)
    for i := 0; i < n; i++ {
        grid[i] = readNNums(reader, m)
    }
    return grid
}

// Define a helper function to read a grid of strings from standard input
func readStringGrid(reader *bufio.Reader, n int, m int) [][]string {
    grid := make([][]string, n)
    for i := 0; i < n; i++ {
        grid[i] = readNStrings(reader, m)
    }
    return grid
}

// Define a helper function to read a single byte slice from standard input
func readBytes(reader *bufio.Reader, n int) []byte {
    res := make([]byte, n)
    x := 0
    for i := 0; i < n; i++ {
        res[i] = readByte(reader)
    }
    return res
}

// Define a helper function to read a single byte from standard input
func readByte(reader *bufio.Reader) byte {
    res, _ := reader.ReadByte()
    return res
}

// Define a helper function to read a single string from standard input
func readString(reader *bufio.Reader) string {
    res := readNBytes(reader, 1000)
    i := 0
    for i < len(res) && res[i] <='' {
        i++
    }
    return string(res[i:])
}

// Define a helper function to read a single string from standard input
func readNum(reader *bufio.Reader) (a int) {
    bs, _ := reader.ReadBytes('\n')
    n := 0
    for i := 0; i < len(bs); i++ {
        if bs[i] == '\n' {
            break
        }
        n = n*10 + int(bs[i]-'0')
    }
    return n
}

// Define a helper function to read a single integer from standard input
func readTwoNums(reader *bufio.Reader) (a int, b int) {
    res := readNNums(reader, 2)
    a, b = res[0], res[1]
    return
}

// Define a helper function to read N integers from standard input
func readNNums(reader *bufio.Reader, n int) []int {
    res := make([]int, n)
    x := 0
    bs, _ := reader.ReadBytes('\n')
    for i := 0; i < n; i++ {
        for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
            x++
        }
        x = readInt(bs, x, &res[i])
    }
    return res
}

// Define a helper function to read a single integer from a byte slice
func readInt(bytes []byte, from int, val *int) int {
    i := from
    sign := 1
    if bytes[i] == '-' {
        sign = -1
        i++
    }
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp := int(bytes[i]-'0')
        *val = *val*10 + tmp
        i++
    }
    *val *= sign
    return i
}

// Define a helper function to read a list of integers from standard input
func readInt64s(reader *bufio.Reader) []int64 {
    list := make([]int64, 0, 10)
    for {
        x := readNum(reader)
        if x == 0 {
            break
        }
        list = append(list, x)
    }
    return list
}

// Define a helper function to read a list of strings from standard input
func readStrings(reader *bufio.Reader) []string {
    res := make([]string, 0, 10)
    for {
        line := readString(reader)
        if line == "" {
            break
        }
        res = append(res, line)
    }
    return res
}

// Define a helper function to read a grid of characters from standard input
func readGrid(reader *bufio.Reader, n int, m int) [][]byte {
    grid := make([][]byte, n)
    for i := 0; i < n; i++ {
        grid[i] = readBytes(reader, m)
    }
    return grid
}

// Define a helper function to read a grid of integers from standard input
func readIntGrid(reader *bufio.Reader, n int, m int) [][]int {
    grid := make([][]int, n)
    for i := 0; i < n; i++ {
        grid[i] = readNNums(reader, m)
    }
    return grid
}

// Define a helper function to read a grid of strings from standard input
func readStringGrid(reader *bufio.Reader, n int, m int) [][]string {
    grid := make([][]string, n)
    for i := 0; i < n; i++ {
        grid[i] = readNStrings(reader, m)
    }
    return grid
}

// Define a helper function to read a single byte slice from standard input
func readBytes(reader *bufio.Reader, n int) []byte {
    res := make([]byte, n)
    x := 0
    for i := 0; i < n; i++ {
        res[i] = readByte(reader)
    }
    return res
}

// Define a helper function to read a single byte from standard input
func readByte(reader *bufio.Reader) byte {
    res, _ := reader.ReadByte()
    return res
}

// Define a helper function to read a single string from standard input
func readString(reader *bufio.Reader) string {
    res := readNBytes(reader, 1000)
    i := 0
    for i < len(res) && res[i] <='' {
        i++
    }
    return string(res[i:])
}

// Define a helper function to read a single string from standard input
func readNum(reader *bufio.Reader) (a int) {
    bs, _ := reader.ReadBytes('\n')
    n := 0
    for i := 0; i < len(bs); i++ {
        if bs[i] == '\n' {
            break
        }
        n = n*10 + int(bs[i]-'0')
    }
    return n
}

// Define a helper function to read a single integer from standard input
func readTwoNums(reader *bufio.Reader) (a int, b int) {
    res := readNNums(reader, 2)
    a, b = res[0], res[1]
    return
}

// Define a helper function to read N integers from standard input
func readNNums(reader *bufio.Reader, n int) []int {
    res := make([]int, n)
    x := 0
    bs, _ := reader.ReadBytes('\n')
    for i := 0; i < n; i++ {
        for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
            x++
        }
        x = readInt(bs, x, &res[i])
    }
    return res
}

// Define a helper function to read a single integer from a byte slice
func readInt(bytes []byte, from int, val *int) int {
    i := from
    sign := 1
    if bytes[i] == '-' {
        sign = -1
        i++
    }
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp := int(bytes[i]-'0')
        *val = *val*10 + tmp
        i++
    }
    *val *= sign
    return i
}

// Define a helper function to read a list of integers from standard input
func readInt64s(reader *bufio.Reader) []int64 {
    list := make([]int64, 0, 10)
    for {
        x := readNum(reader)
        if x == 0 {
            break
        }
        list = append(list, x)
    }
    return list
}

// Define a helper function to read a list of strings from standard input
func readStrings(reader *bufio.Reader) []string {
    res := make([]string, 0, 10)
    for {
        line := readString(reader)
        if line == "" {
            break
        }
        res = append(res, line)
    }
    return res
}

// Define a helper function to read a grid of characters from standard input
func readGrid(reader *bufio.Reader, n int, m int) [][]byte {
    grid := make([][]byte, n)
    for i := 0; i < n; i++ {
        grid[i] = readBytes(reader, m)
    }
    return grid
}

// Define a helper function to read a grid of integers from standard input
func readIntGrid(reader *bufio.Reader, n int, m int) [][]int {
    grid := make([][]int, n)
    for i := 0; i < n; i++ {
        grid[i] = readNNums(reader, m)
    }
    return grid
}

// Define a helper function to read a grid of strings from standard input
func readStringGrid(reader *bufio.Reader, n int, m int) [][]string {
    grid := make([][]string, n)
    for i := 0; i < n; i++ {
        grid[i] = readNStrings(reader, m)
    }
    return grid
}

// Define a helper function to read a single byte slice from standard input
func readBytes(reader *bufio.Reader, n int) []byte {
    res := make([]byte, n)
    x := 0
    for i := 0; i < n; i++ {
        res[i] = readByte(reader)
    }
    return res
}