<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define the data type for an integer
type int int

// Define the data type for a string
type string string

// Define the data type for a boolean
type bool bool

// Define the data type for a slice of integers
type intSlice []int

// Define the data type for a slice of strings
type stringSlice []string

// Define the data type for a slice of booleans
type boolSlice []bool

// Define the data type for a map of integers
type intMap map[int]int

// Define the data type for a map of strings
type stringMap map[string]string

// Define the data type for a map of booleans
type boolMap map[bool]bool

// Define the data type for a 2D slice of integers
type int2D [][]int

// Define the data type for a 2D slice of strings
type string2D [][]string

// Define the data type for a 2D slice of booleans
type bool2D [][]bool

// Define the data type for a 3D slice of integers
type int3D [][][]int

// Define the data type for a 3D slice of strings
type string3D [][][]string

// Define the data type for a 3D slice of booleans
type bool3D [][][]bool

// Define the data type for a 4D slice of integers
type int4D [][][][]int

// Define the data type for a 4D slice of strings
type string4D [][][][]string

// Define the data type for a 4D slice of booleans
type bool4D [][][][]bool

// Define the data type for a 5D slice of integers
type int5D [][][][][]int

// Define the data type for a 5D slice of strings
type string5D [][][][][]string

// Define the data type for a 5D slice of booleans
type bool5D [][][][][]bool

// Define the data type for a 6D slice of integers
type int6D [][][][][][]int

// Define the data type for a 6D slice of strings
type string6D [][][][][][]string

// Define the data type for a 6D slice of booleans
type bool6D [][][][][][]bool

// Define the data type for a 7D slice of integers
type int7D [][][][][][][]int

// Define the data type for a 7D slice of strings
type string7D [][][][][][][]string

// Define the data type for a 7D slice of booleans
type bool7D [][][][][][][]bool

// Define the data type for a 8D slice of integers
type int8D [][][][][][][][]int

// Define the data type for a 8D slice of strings
type string8D [][][][][][][][]string

// Define the data type for a 8D slice of booleans
type bool8D [][][][][][][][]bool

// Define the data type for a 9D slice of integers
type int9D [][][][][][][][][]int

// Define the data type for a 9D slice of strings
type string9D [][][][][][][][][]string

// Define the data type for a 9D slice of booleans
type bool9D [][][][][][][][][]bool

// Define the data type for a 10D slice of integers
type int10D [][][][][][][][][][]int

// Define the data type for a 10D slice of strings
type string10D [][][][][][][][][][]string

// Define the data type for a 10D slice of booleans
type bool10D [][][][][][][][][][]bool

// Define the data type for a 11D slice of integers
type int11D [][][][][][][][][][][]int

// Define the data type for a 11D slice of strings
type string11D [][][][][][][][][][][]string

// Define the data type for a 11D slice of booleans
type bool11D [][][][][][][][][][][]bool

// Define the data type for a 12D slice of integers
type int12D [][][][][][][][][][][][]int

// Define the data type for a 12D slice of strings
type string12D [][][][][][][][][][][][]string

// Define the data type for a 12D slice of booleans
type bool12D [][][][][][][][][][][][]bool

// Define the data type for a 13D slice of integers
type int13D [][][][][][][][][][][][][]int

// Define the data type for a 13D slice of strings
type string13D [][][][][][][][][][][][][]string

// Define the data type for a 13D slice of booleans
type bool13D [][][][][][][][][][][][][]bool

// Define the data type for a 14D slice of integers
type int14D [][][][][][][][][][][][][][]int

// Define the data type for a 14D slice of strings
type string14D [][][][][][][][][][][][][][]string

// Define the data type for a 14D slice of booleans
type bool14D [][][][][][][][][][][][][][]bool

// Define the data type for a 15D slice of integers
type int15D [][][][][][][][][][][][][][][]int

// Define the data type for a 15D slice of strings
type string15D [][][][][][][][][][][][][][][]string

// Define the data type for a 15D slice of booleans
type bool15D [][][][][][][][][][][][][][][]bool

// Define the data type for a 16D slice of integers
type int16D [][][][][][][][][][][][][][][][]int

// Define the data type for a 16D slice of strings
type string16D [][][][][][][][][][][][][][][][]string

// Define the data type for a 16D slice of booleans
type bool16D [][][][][][][][][][][][][][][][]bool

// Define the data type for a 17D slice of integers
type int17D [][][][][][][][][][][][][][][][][]int

// Define the data type for a 17D slice of strings
type string17D [][][][][][][][][][][][][][][][][]string

// Define the data type for a 17D slice of booleans
type bool17D [][][][][][][][][][][][][][][][][]bool

// Define the data type for a 18D slice of integers
type int18D [][][][][][][][][][][][][][][][][][]int

// Define the data type for a 18D slice of strings
type string18D [][][][][][][][][][][][][][][][][][]string

// Define the data type for a 18D slice of booleans
type bool18D [][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 19D slice of integers
type int19D [][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 19D slice of strings
type string19D [][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 19D slice of booleans
type bool19D [][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 20D slice of integers
type int20D [][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 20D slice of strings
type string20D [][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 20D slice of booleans
type bool20D [][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 21D slice of integers
type int21D [][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 21D slice of strings
type string21D [][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 21D slice of booleans
type bool21D [][][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 22D slice of integers
type int22D [][][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 22D slice of strings
type string22D [][][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 22D slice of booleans
type bool22D [][][][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 23D slice of integers
type int23D [][][][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 23D slice of strings
type string23D [][][][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 23D slice of booleans
type bool23D [][][][][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 24D slice of integers
type int24D [][][][][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 24D slice of strings
type string24D [][][][][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 24D slice of booleans
type bool24D [][][][][][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 25D slice of integers
type int25D [][][][][][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 25D slice of strings
type string25D [][][][][][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 25D slice of booleans
type bool25D [][][][][][][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 26D slice of integers
type int26D [][][][][][][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 26D slice of strings
type string26D [][][][][][][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 26D slice of booleans
type bool26D [][][][][][][][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 27D slice of integers
type int27D [][][][][][][][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 27D slice of strings
type string27D [][][][][][][][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 27D slice of booleans
type bool27D [][][][][][][][][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 28D slice of integers
type int28D [][][][][][][][][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 28D slice of strings
type string28D [][][][][][][][][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 28D slice of booleans
type bool28D [][][][][][][][][][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 29D slice of integers
type int29D [][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 29D slice of strings
type string29D [][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 29D slice of booleans
type bool29D [][][][][][][][][][][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 30D slice of integers
type int30D [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 30D slice of strings
type string30D [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 30D slice of booleans
type bool30D [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]bool

// Define the data type for a 31D slice of integers
type int31D [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int

// Define the data type for a 31D slice of strings
type string31D [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string

// Define the data type for a 31D slice of booleans
type bool31D [][][][][][][][][][][][][][][][][][][][