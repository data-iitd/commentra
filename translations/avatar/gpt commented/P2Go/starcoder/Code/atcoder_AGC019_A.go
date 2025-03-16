package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a line of input
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(line), "\r\n")
	}
	panic(err)
}

// Function to read a line of input and return a slice of integers
func readInts() []int {
	line := readLine()
	return parseIntSlice(line)
}

// Function to read a line of input and return a slice of integers
func parseIntSlice(line string) []int {
	var slice []int
	for _, str := range strings.Split(line, " ") {
		if str!= "" {
			num, err := strconv.Atoi(str)
			if err!= nil {
				panic(err)
			}
			slice = append(slice, num)
		}
	}
	return slice
}

// Function to read a line of input and return a slice of integers
func readFloats() []float64 {
	line := readLine()
	return parseFloatSlice(line)
}

// Function to read a line of input and return a slice of integers
func parseFloatSlice(line string) []float64 {
	var slice []float64
	for _, str := range strings.Split(line, " ") {
		if str!= "" {
			num, err := strconv.ParseFloat(str, 64)
			if err!= nil {
				panic(err)
			}
			slice = append(slice, num)
		}
	}
	return slice
}

// Function to read a line of input and return a slice of strings
func readStrings() []string {
	line := readLine()
	return parseStringSlice(line)
}

// Function to read a line of input and return a slice of strings
func parseStringSlice(line string) []string {
	var slice []string
	for _, str := range strings.Split(line, " ") {
		if str!= "" {
			slice = append(slice, str)
		}
	}
	return slice
}

// Function to read a line of input and return a slice of runes
func readRunes() []rune {
	line := readLine()
	return []rune(line)
}

// Function to read a line of input and return a slice of runes
func parseRuneSlice(line string) []rune {
	var slice []rune
	for _, str := range strings.Split(line, " ") {
		if str!= "" {
			slice = append(slice, []rune(str)[0])
		}
	}
	return slice
}

// Function to read a line of input and return a slice of runes
func readRunesLine() []rune {
	return readRunes()
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLine(line string) []rune {
	return parseRuneSlice(line)
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrim() []rune {
	return []rune(strings.TrimSpace(readLine()))
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrim(line string) []rune {
	return []rune(strings.TrimSpace(line))
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplit(sep string) []rune {
	return []rune(strings.TrimSpace(readLine()))
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplit(line string, sep string) []rune {
	return []rune(strings.TrimSpace(line))
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSlice(sep string) []string {
	return strings.Split(strings.TrimSpace(readLine()), sep)
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSlice(line string, sep string) []string {
	return strings.Split(strings.TrimSpace(line), sep)
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrim(sep string) []string {
	return strings.Split(strings.TrimSpace(readLine()), sep)
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrim(line string, sep string) []string {
	return strings.Split(strings.TrimSpace(line), sep)
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoin(sep string) string {
	return strings.Join(strings.Split(strings.TrimSpace(readLine()), sep), "")
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrimJoin(line string, sep string) string {
	return strings.Join(strings.Split(strings.TrimSpace(line), sep), "")
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoinTrim(sep string) string {
	return strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(readLine()), sep), ""))
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrimJoinTrim(line string, sep string) string {
	return strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(line), sep), ""))
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoinTrimSplit(sep string, n int) []string {
	return strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(readLine()), sep), "")), sep)
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrimJoinTrimSplit(line string, sep string, n int) []string {
	return strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(line), sep), "")), sep)
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoinTrimSplitTrim(sep string, n int) []string {
	return strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(readLine()), sep), "")), sep)
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrimJoinTrimSplitTrim(line string, sep string, n int) []string {
	return strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(line), sep), "")), sep)
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoinTrimSplitTrimJoin(sep string, n int) string {
	return strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(readLine()), sep), "")), sep), "")
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrimJoinTrimSplitTrimJoin(line string, sep string, n int) string {
	return strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(line), sep), "")), sep), "")
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrim(sep string, n int) string {
	return strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(readLine()), sep), "")), sep), ""))
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrim(line string, sep string, n int) string {
	return strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(line), sep), "")), sep), ""))
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrimSplit(sep string, n int) []string {
	return strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(readLine()), sep), "")), sep), "")), sep)
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrimSplit(line string, sep string, n int) []string {
	return strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(line), sep), "")), sep), "")), sep)
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrimSplitTrim(sep string, n int) []string {
	return strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(readLine()), sep), "")), sep), "")), sep)
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrimSplitTrim(line string, sep string, n int) []string {
	return strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(line), sep), "")), sep), "")), sep)
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrimSplitTrimJoin(sep string, n int) string {
	return strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(readLine()), sep), "")), sep), "")), sep), "")
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrimSplitTrimJoin(line string, sep string, n int) string {
	return strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(line), sep), "")), sep), "")), sep), "")
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrimSplitTrimJoinTrim(sep string, n int) string {
	return strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(readLine()), sep), "")), sep), "")), sep), ""))
}

// Function to read a line of input and return a slice of runes
func parseRuneSliceLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrimSplitTrimJoinTrim(line string, sep string, n int) string {
	return strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(line), sep), "")), sep), "")), sep), ""))
}

// Function to read a line of input and return a slice of runes
func readRunesLineTrimSplitSliceTrimJoinTrimSplitTrimJoinTrimSplitTrimJoinTrimSplit(sep string, n int) []string {
	return strings.Split(strings.TrimSpace(strings.Join(strings.Split(strings.TrimSpace(