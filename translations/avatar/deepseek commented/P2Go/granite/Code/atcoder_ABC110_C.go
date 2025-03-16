

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    // Define the main function to get input and print the result
    reader := bufio.NewReader(os.Stdin)
    // Create a bufio.Reader object to read input from the standard input
    s, _ := reader.ReadString('\n')
    // Read a string from the standard input until a newline character is encountered
    s = strings.TrimSpace(s)
    // Remove any leading or trailing whitespace from s
    t, _ := reader.ReadString('\n')
    // Read another string from the standard input until a newline character is encountered
    t = strings.TrimSpace(t)
    // Remove any leading or trailing whitespace from t
    sMap := make(map[string]int)
    // Create an empty map to store the frequency of characters in s
    for _, c := range s {
        // Iterate over each character in s
        sMap[string(c)]++
        // Increment the frequency count for the current character in sMap
    }
    // Sort the keys of sMap in ascending order
    keys := make([]string, 0, len(sMap))
    // Create an empty slice to store the keys of sMap
    for k := range sMap {
        // Iterate over each key in sMap
        keys = append(keys, k)
        // Append the key to the keys slice
    }
    sort.Strings(keys)
    // Sort the keys slice in ascending order
    sValues := make([]int, 0, len(sMap))
    // Create an empty slice to store the values of sMap
    for _, k := range keys {
        // Iterate over each key in the sorted keys slice
        sValues = append(sValues, sMap[k])
        // Append the value corresponding to the current key to the sValues slice
    }
    // Sort the values in sValues slice in ascending order
    tMap := make(map[string]int)
    // Create an empty map to store the frequency of characters in t
    for _, c := range t {
        // Iterate over each character in t
        tMap[string(c)]++
        // Increment the frequency count for the current character in tMap
    }
    // Sort the keys of tMap in ascending order
    keys = make([]string, 0, len(tMap))
    // Create an empty slice to store the keys of tMap
    for k := range tMap {
        // Iterate over each key in tMap
        keys = append(keys, k)
        // Append the key to the keys slice
    }
    sort.Strings(keys)
    // Sort the keys slice in ascending order
    tValues := make([]int, 0, len(tMap))
    // Create an empty slice to store the values of tMap
    for _, k := range keys {
        // Iterate over each key in the sorted keys slice
        tValues = append(tValues, tMap[k])
        // Append the value corresponding to the current key to the tValues slice
    }
    // Sort the values in tValues slice in ascending order
    if reflect.DeepEqual(sValues, tValues) {
        // Check if the sorted values of s and t are equal using reflect.DeepEqual
        fmt.Println("Yes")
        // Print "Yes" if the sorted values are equal
    } else {
        fmt.Println("No")
        // Print "No" if the sorted values are not equal
    }
}

