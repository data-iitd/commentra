package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Global variables
var (
    input_methods = []string{ "clipboard", "file", "key" }
    using_method  = 0
    input_method  = input_methods[using_method]
    isTest        = false
)

// Function to read input from clipboard
func input_clipboard() (ret string) {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Paste input: ")
    text, _ := reader.ReadString('\n')
    ret = strings.TrimSpace(text)
    return
}

// Function to read input from file
func input_file() (ret string) {
    file, _ := os.Open("inputFile.txt")
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        ret = scanner.Text()
    }
    return
}

// Function to read input from keyboard
func input_key() (ret string) {
    fmt.Print("Enter input: ")
    fmt.Scanf("%s", &ret)
    return
}

// Function to read input
func input() (ret string) {
    if isTest {
        ret = input_clipboard()
    } else {
        switch input_method {
        case "clipboard":
            ret = input_clipboard()
        case "file":
            ret = input_file()
        case "key":
            ret = input_key()
        }
    }
    return
}

// Function to read input as a list of integers
func IN() (ret []int) {
    ret = make([]int, 0)
    text := input()
    for _, v := range strings.Split(text, " ") {
        ret = append(ret, int(v))
    }
    return
}

// Main function
func main() {
    // Read input string's'
    s := input()

    // Initialize variables 'pp' and 'na'
    pp, na := 0, 0

    // Iterate through each character in the input string's'
    for i, c := range s[:len(s)-1] {
        // Calculate current character value 'cc'
        cc := na + int(c)
        na = 0

        // Update 'pp' based on the current character value 'cc'
        if cc <= 4 {
            pp += cc
        } else {
            // If current character is the last character, add 1 to 'pp'
            if i == len(s)-1 {
                pp += 1
            }
            // Otherwise, add 10 - 'cc' to 'pp'
            pp += 10 - cc
    }

    // Print the result 'pp'
    fmt.Println(pp)
}

// 