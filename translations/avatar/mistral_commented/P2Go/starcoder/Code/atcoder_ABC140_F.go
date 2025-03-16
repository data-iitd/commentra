package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to read an integer from standard input
func readInt() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to read a list of integers from standard input
func readInts() []int {
	var ns []int
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		ns = append(ns, x)
	}
	return ns
}

// Function to read a string from standard input
func readString() string {
	var s string
	fmt.Scanf("%s", &s)
	return s
}

// Function to read a list of strings from standard input
func readStrings() []string {
	var ss []string
	var s string
	fmt.Scanf("%s", &s)
	ss = strings.Split(s, " ")
	return ss
}

// Function to print an integer to standard output
func printInt(n int) {
	fmt.Printf("%d\n", n)
}

// Function to print a list of integers to standard output
func printInts(ns []int) {
	for _, n := range ns {
		fmt.Printf("%d ", n)
	}
	fmt.Println()
}

// Function to print a string to standard output
func printString(s string) {
	fmt.Printf("%s\n", s)
}

// Function to print a list of strings to standard output
func printStrings(ss []string) {
	for _, s := range ss {
		fmt.Printf("%s ", s)
	}
	fmt.Println()
}

// Function to read an integer from standard input
func I() int {
	return readInt()
}

// Function to read a list of integers from standard input
func LI() []int {
	return readInts()
}

// Function to read a string from standard input
func S() string {
	return readString()
}

// Function to read a list of strings from standard input
func LS() []string {
	return readStrings()
}

// Function to print an integer to standard output
func P(n int) {
	printInt(n)
}

// Function to print a list of integers to standard output
func PS(ns []int) {
	printInts(ns)
}

// Function to print a string to standard output
func PS(s string) {
	printString(s)
}

// Function to print a list of strings to standard output
func PS(ss []string) {
	printStrings(ss)
}

// Function to read an integer from standard input
func readInt() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to read a list of integers from standard input
func readInts() []int {
	var ns []int
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		ns = append(ns, x)
	}
	return ns
}

// Function to read a string from standard input
func readString() string {
	var s string
	fmt.Scanf("%s", &s)
	return s
}

// Function to read a list of strings from standard input
func readStrings() []string {
	var ss []string
	var s string
	fmt.Scanf("%s", &s)
	ss = strings.Split(s, " ")
	return ss
}

// Function to print an integer to standard output
func printInt(n int) {
	fmt.Printf("%d\n", n)
}

// Function to print a list of integers to standard output
func printInts(ns []int) {
	for _, n := range ns {
		fmt.Printf("%d ", n)
	}
	fmt.Println()
}

// Function to print a string to standard output
func printString(s string) {
	fmt.Printf("%s\n", s)
}

// Function to print a list of strings to standard output
func printStrings(ss []string) {
	for _, s := range ss {
		fmt.Printf("%s ", s)
	}
	fmt.Println()
}

// Function to read an integer from standard input
func I() int {
	return readInt()
}

// Function to read a list of integers from standard input
func LI() []int {
	return readInts()
}

// Function to read a string from standard input
func S() string {
	return readString()
}

// Function to read a list of strings from standard input
func LS() []string {
	return readStrings()
}

// Function to print an integer to standard output
func P(n int) {
	printInt(n)
}

// Function to print a list of integers to standard output
func PS(ns []int) {
	printInts(ns)
}

// Function to print a string to standard output
func PS(s string) {
	printString(s)
}

// Function to print a list of strings to standard output
func PS(ss []string) {
	printStrings(ss)
}

// Function to read an integer from standard input
func readInt() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to read a list of integers from standard input
func readInts() []int {
	var ns []int
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		ns = append(ns, x)
	}
	return ns
}

// Function to read a string from standard input
func readString() string {
	var s string
	fmt.Scanf("%s", &s)
	return s
}

// Function to read a list of strings from standard input
func readStrings() []string {
	var ss []string
	var s string
	fmt.Scanf("%s", &s)
	ss = strings.Split(s, " ")
	return ss
}

// Function to print an integer to standard output
func printInt(n int) {
	fmt.Printf("%d\n", n)
}

// Function to print a list of integers to standard output
func printInts(ns []int) {
	for _, n := range ns {
		fmt.Printf("%d ", n)
	}
	fmt.Println()
}

// Function to print a string to standard output
func printString(s string) {
	fmt.Printf("%s\n", s)
}

// Function to print a list of strings to standard output
func printStrings(ss []string) {
	for _, s := range ss {
		fmt.Printf("%s ", s)
	}
	fmt.Println()
}

// Function to read an integer from standard input
func I() int {
	return readInt()
}

// Function to read a list of integers from standard input
func LI() []int {
	return readInts()
}

// Function to read a string from standard input
func S() string {
	return readString()
}

// Function to read a list of strings from standard input
func LS() []string {
	return readStrings()
}

// Function to print an integer to standard output
func P(n int) {
	printInt(n)
}

// Function to print a list of integers to standard output
func PS(ns []int) {
	printInts(ns)
}

// Function to print a string to standard output
func PS(s string) {
	printString(s)
}

// Function to print a list of strings to standard output
func PS(ss []string) {
	printStrings(ss)
}

// Function to read an integer from standard input
func readInt() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to read a list of integers from standard input
func readInts() []int {
	var ns []int
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		ns = append(ns, x)
	}
	return ns
}

// Function to read a string from standard input
func readString() string {
	var s string
	fmt.Scanf("%s", &s)
	return s
}

// Function to read a list of strings from standard input
func readStrings() []string {
	var ss []string
	var s string
	fmt.Scanf("%s", &s)
	ss = strings.Split(s, " ")
	return ss
}

// Function to print an integer to standard output
func printInt(n int) {
	fmt.Printf("%d\n", n)
}

// Function to print a list of integers to standard output
func printInts(ns []int) {
	for _, n := range ns {
		fmt.Printf("%d ", n)
	}
	fmt.Println()
}

// Function to print a string to standard output
func printString(s string) {
	fmt.Printf("%s\n", s)
}

// Function to print a list of strings to standard output
func printStrings(ss []string) {
	for _, s := range ss {
		fmt.Printf("%s ", s)
	}
	fmt.Println()
}

// Function to read an integer from standard input
func I() int {
	return readInt()
}

// Function to read a list of integers from standard input
func LI() []int {
	return readInts()
}

// Function to read a string from standard input
func S() string {
	return readString()
}

// Function to read a list of strings from standard input
func LS() []string {
	return readStrings()
}

// Function to print an integer to standard output
func P(n int) {
	printInt(n)
}

// Function to print a list of integers to standard output
func PS(ns []int) {
	printInts(ns)
}

// Function to print a string to standard output
func PS(s string) {
	printString(s)
}

// Function to print a list of strings to standard output
func PS(ss []string) {
	printStrings(ss)
}

// Function to read an integer from standard input
func readInt() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to read a list of integers from standard input
func readInts() []int {
	var ns []int
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		ns = append(ns, x)
	}
	return ns
}

// Function to read a string from standard input
func readString() string {
	var s string
	fmt.Scanf("%s", &s)
	return s
}

// Function to read a list of strings from standard input
func readStrings() []string {
	var ss []string
	var s string
	fmt.Scanf("%s", &s)
	ss = strings.Split(s, " ")
	return ss
}

// Function to print an integer to standard output
func printInt(n int) {
	fmt.Printf("%d\n", n)
}

// Function to print a list of integers to standard output
func printInts(ns []int) {
	for _, n := range ns {
		fmt.Printf("%d ", n)
	}
	fmt.Println()
}

// Function to print a string to standard output
func printString(s string) {
	fmt.Printf("%s\n", s)
}

// Function to print a list of strings to standard output
func printStrings(ss []string) {
	for _, s := range ss {
		fmt.Printf("%s ", s)
	}
	fmt.Println()
}

// Function to read an integer from standard input
func I() int {
	return readInt()
}

// Function to read a list of integers from standard input
func LI() []int {
	return readInts()
}

// Function to read a string from standard input
func S() string {
	return readString()
}

// Function to read a list of strings from standard input
func LS() []string {
	return readStrings()
}

// Function to print an integer to standard output
func P(n int) {
	printInt(n)
}

// Function to print a list of integers to standard output
func PS(ns []int) {
	printInts(ns)
}

// Function to print a string to standard output
func PS(s string) {
	printString(s)
}

// Function to print a list of strings to standard output
func PS(ss []string) {
	printStrings(ss)
}

// Function to read an integer from standard input
func readInt() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to read a list of integers from standard input
func readInts() []int {
	var ns []int
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		ns = append(ns, x)
	}
	r