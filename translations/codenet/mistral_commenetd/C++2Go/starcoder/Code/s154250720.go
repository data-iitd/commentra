<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
	"fmt"
	"sort"
	"bufio"
	"os"
)

// Initialize arrays'maps' and 'num' with given size'maxn'
var maps [maxn]int
var num [maxn]int

// Main function starts here
func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)
	for {
		// Read a single line of input as a rune slice.
		// A rune is an alias for int32.
		// It is used to represent Unicode code points.
		// ReadRune returns the next rune in the input or
		// an error if there are no more runes to read.
		// The sequence of read runes from a line is terminated by
		// any of a newline, EOF, or an error.
<<<<<<< HEAD
		// The result is a slice of runes with newlines removed.
		// If the input has no newline, ReadRune returns err == nil,
		// not err == EOF.
		// Because ReadRune returns a slice of runes,
		// not bytes, programs that need to process a stream of
		// fixed-size bytes can use ReadRune directly instead of
		// creating a slice of size 1 and then calling Read.
		// ReadRune called on a Reader object returns an error
		// if the reader is in a bad state.
		// For compatibility, if a Reader's buffer has size zero,
		// it returns an error. (To work around this case,
		// use NewReaderSize).
		// If the size is non-zero, it returns ErrBufferFull instead of ErrNoProgress.
		// On success, the number of bytes read is returned and the error is nil.
		// Callers should always process the number of bytes returned
		// before considering the error err.
		// Do not count the error itself:
		// if it is nil, the caller has nothing further to do.
		// If err!= nil, the caller should stop processing.
		// An instance of this general case is that a Reader returning
		// EOF with a non-zero number of bytes read from the
		// underlying object will return a non-nil error from Read
		// regardless of what the caller has done with the bytes.
		// This instance is intended as a simple way to write
		// code that needs to read a fixed number of bytes or
		// to signal that an error has occurred and to wake up
		// a waiting reader.
		// In most cases, if the error is nil, the Reader is in a
		// valid state for another call to Read.
		// If the caller has already reached the end of the input,
		// Read returns the number of bytes read and nil.
		// If the caller has not reached the end of the input,
		// the error is ErrNoProgress and the number of bytes
		// read is undefined.
		// The Read method should call either ReadRune or ReadByte
		// in a loop:
		//     for {
		//         rune, size, err := reader.ReadRune()
		//         if err!= nil {
		//             return err
		//         }
		//         process(rune)
		//         if size == 0 {
		//             break
		//         }
		//     }
		// If there is an error or EOF, ReadRune returns the error
		// and a size of 0.
		// ReadByte is similar to ReadRune except that it returns
		// an int8 instead of a rune and does not return an error
		// for EOF.
		// func (b *Reader) ReadByte() (c byte, err error)
		// func (r *Reader) ReadRune() (ch rune, size int, err error)
=======
		// The result is a slice of runes with no delimiter.
		// There is no guarantee that the runes in result[0:n] are newline-terminated.
		// If there is an error, the result is nil and the error is of type *Error.
		// If the EOF is reached before any bytes are read, err will be set.
		// If the EOF is reached after not reading any bytes, err will be set to io.EOF.
		// Otherwise, err will be set to nil.
		// The line does not include the end-of-line bytes.
		// If the input has no newline, err will be set to io.EOF.
		// The caller should not assume that the runes are newline-terminated.
		// The input may contain invalid UTF-8.
		// When err == nil, len(line) > 0, and line does not end in '\n'.
>>>>>>> 98c87cb78a (data updated)
		line, err := reader.ReadBytes('\n')
		if err!= nil {
			break
		}
<<<<<<< HEAD
		// Convert the line read to a string
		lineStr := string(line)
		// Split the string to get the first integer
		lineStrSplit := strings.Split(lineStr, " ")
		// Convert the first integer to an integer
		n, _ := strconv.Atoi(lineStrSplit[0])
		// Initialize'maps' and 'num' arrays with input values
		for i := 1; i <= n; i++ {
			fmt.Sscanf(lineStrSplit[i], "%d", &maps[i])
			num[i] = maps[i] // copy input values to 'num' array
		}
		// Sort'maps' array in ascending order
		sort.Ints(maps[1:n+1])
		// Calculate the middle index'm' of sorted'maps' array
		m := n / 2
		// Process each element in 'num' array based on the middle index'm'
		for i := 1; i <= n; i++ {
			// If current element 'num[i]' is smaller than or equal to middle element'maps[m]'
			if num[i] <= maps[m] {
				// Print the next element in sorted'maps' array
				fmt.Printf("%d\n", maps[m+1])
			}
			// Otherwise print the current middle element'maps[m]'
			else {
				fmt.Printf("%d\n", maps[m])
			}
		}
	}
}

=======
		// Convert the line read to a string.
		// The line is a slice of bytes so we need to convert it to a string.
		// The string is made of valid UTF-8 characters,
		// each of which can be up to 4 bytes long.
		s := string(line)
		// Split the string into tokens using white space as the delimiter.
		// The default split delimiter is space, as defined by unicode.IsSpace.
		// Split slices s into all substrings separated by sep and returns a slice of the substrings between those separators.
		// If sep is empty, Split splits after each UTF-8 sequence.
		// It is equivalent to SplitN with a count of -1.
		//
		// When s does not contain any Unicode code points of class Zs,
		// Split returns a slice of length 1 whose only element is s.
		//
		// When s contains Unicode code points of class Zs,
		// Split splits s at each instance of a Unicode code point of class Zs and
		// returns a slice of the substrings between those code points.
		//
		// If sep is not empty, Split is equivalent to SplitN with a count of -1.
		//
		// If sep is empty, Split uses a copy of bufio.ScanWords as a split function.
		//
		// Split fails if sep is not empty and contains any Unicode code points of class C.
		//
		// Example:
		// s := "a,b,c"
		// s1 := strings.Split(s, ",")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "")
		// fmt.Println(s2) // ["a", ",", "b", ",", "c"]
		// s3 := strings.Split(s, "x")
		// fmt.Println(s3) // ["a,b,c"]
		//
		// Example:
		// s := "a man a plan a canal panama"
		// s1 := strings.Split(s, "a")
		// fmt.Println(s1) // ["", " ", " man ", " ", " plan ", " ", " canal panama"]
		// s2 := strings.Split(s, "a ")
		// fmt.Println(s2) // ["", "man ", "plan ", "canal panama"]
		// s3 := strings.Split(s, "a ")
		// fmt.Println(s3) // ["", "man ", "plan ", "canal panama"]
		//
		// Example:
		// s := "a...b...c"
		// s1 := strings.Split(s, ".")
		// fmt.Println(s1) // ["a", "", "b", "", "c"]
		// s2 := strings.Split(s, "...")
		// fmt.Println(s2) // ["a", "b", "c"]
		//
		// Example:
		// s := "a..b..c"
		// s1 := strings.Split(s, "..")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "...")
		// fmt.Println(s2) // ["a..b..c"]
		//
		// Example:
		// s := ".a..b..c."
		// s1 := strings.Split(s, ".")
		// fmt.Println(s1) // ["", "a", "", "b", "", "c", ""]
		// s2 := strings.Split(s, "..")
		// fmt.Println(s2) // ["", "a", "b", "c", ""]
		//
		// Example:
		// s := ".a..b..c."
		// s1 := strings.Split(s, ".")
		// fmt.Println(s1) // ["", "a", "", "b", "", "c", ""]
		// s2 := strings.Split(s, "..")
		// fmt.Println(s2) // ["", "a", "b", "c", ""]
		//
		// Example:
		// s := "..."
		// s1 := strings.Split(s, ".")
		// fmt.Println(s1) // ["", "", "", ""]
		// s2 := strings.Split(s, "..")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := ""
		// s1 := strings.Split(s, ".")
		// fmt.Println(s1) // [""]
		// s2 := strings.Split(s, "..")
		// fmt.Println(s2) // [""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", "b", "c"]
		// s2 := strings.Split(s, "abc")
		// fmt.Println(s2) // ["", "", ""]
		//
		// Example:
		// s := "abc"
		// s1 := strings.Split(s, "")
		// fmt.Println(s1) // ["a", 
>>>>>>> 98c87cb78a (data updated)
