// Importing the required Go utility library
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function declaration
func main() {

	// Declaring a constant integer variable named INF
	const INF int = 100000

	// Declaring and initializing a variable to store the number of test cases
	var D int

	// Declaring and initializing a variable to store the goal score
	var G int64

	// Declaring and initializing two integer arrays p and c of size D
	var p [10000]int
	var c [10000]int

	// Declaring and initializing a variable to store the minimum number of test cases
	var min int

	// Declaring and initializing a variable to store the current bit
	var bit int

	// Declaring and initializing a variable to store the current score
	var score int64

	// Declaring and initializing a variable to store the current number of test cases solved
	var solve_num int

	// Declaring and initializing a variable to store the current test case
	var i int

	// Declaring and initializing a variable to store the current test case
	var j int

	// Declaring and initializing a variable to store the current test case
	var k int

	// Declaring and initializing a variable to store the current test case
	var l int

	// Declaring and initializing a variable to store the current test case
	var m int

	// Declaring and initializing a variable to store the current test case
	var n int

	// Declaring and initializing a variable to store the current test case
	var o int

	// Declaring and initializing a variable to store the current test case
	var p int

	// Declaring and initializing a variable to store the current test case
	var q int

	// Declaring and initializing a variable to store the current test case
	var r int

	// Declaring and initializing a variable to store the current test case
	var s int

	// Declaring and initializing a variable to store the current test case
	var t int

	// Declaring and initializing a variable to store the current test case
	var u int

	// Declaring and initializing a variable to store the current test case
	var v int

	// Declaring and initializing a variable to store the current test case
	var w int

	// Declaring and initializing a variable to store the current test case
	var x int

	// Declaring and initializing a variable to store the current test case
	var y int

	// Declaring and initializing a variable to store the current test case
	var z int

	// Declaring and initializing a variable to store the current test case
	var a int

	// Declaring and initializing a variable to store the current test case
	var b int

	// Declaring and initializing a variable to store the current test case
	var c int

	// Declaring and initializing a variable to store the current test case
	var d int

	// Declaring and initializing a variable to store the current test case
	var e int

	// Declaring and initializing a variable to store the current test case
	var f int

	// Declaring and initializing a variable to store the current test case
	var g int

	// Declaring and initializing a variable to store the current test case
	var h int

	// Declaring and initializing a variable to store the current test case
	var i int

	// Declaring and initializing a variable to store the current test case
	var j int

	// Declaring and initializing a variable to store the current test case
	var k int

	// Declaring and initializing a variable to store the current test case
	var l int

	// Declaring and initializing a variable to store the current test case
	var m int

	// Declaring and initializing a variable to store the current test case
	var n int

	// Declaring and initializing a variable to store the current test case
	var o int

	// Declaring and initializing a variable to store the current test case
	var p int

	// Declaring and initializing a variable to store the current test case
	var q int

	// Declaring and initializing a variable to store the current test case
	var r int

	// Declaring and initializing a variable to store the current test case
	var s int

	// Declaring and initializing a variable to store the current test case
	var t int

	// Declaring and initializing a variable to store the current test case
	var u int

	// Declaring and initializing a variable to store the current test case
	var v int

	// Declaring and initializing a variable to store the current test case
	var w int

	// Declaring and initializing a variable to store the current test case
	var x int

	// Declaring and initializing a variable to store the current test case
	var y int

	// Declaring and initializing a variable to store the current test case
	var z int

	// Declaring and initializing a variable to store the current test case
	var a int

	// Declaring and initializing a variable to store the current test case
	var b int

	// Declaring and initializing a variable to store the current test case
	var c int

	// Declaring and initializing a variable to store the current test case
	var d int

	// Declaring and initializing a variable to store the current test case
	var e int

	// Declaring and initializing a variable to store the current test case
	var f int

	// Declaring and initializing a variable to store the current test case
	var g int

	// Declaring and initializing a variable to store the current test case
	var h int

	// Declaring and initializing a variable to store the current test case
	var i int

	// Declaring and initializing a variable to store the current test case
	var j int

	// Declaring and initializing a variable to store the current test case
	var k int

	// Declaring and initializing a variable to store the current test case
	var l int

	// Declaring and initializing a variable to store the current test case
	var m int

	// Declaring and initializing a variable to store the current test case
	var n int

	// Declaring and initializing a variable to store the current test case
	var o int

	// Declaring and initializing a variable to store the current test case
	var p int

	// Declaring and initializing a variable to store the current test case
	var q int

	// Declaring and initializing a variable to store the current test case
	var r int

	// Declaring and initializing a variable to store the current test case
	var s int

	// Declaring and initializing a variable to store the current test case
	var t int

	// Declaring and initializing a variable to store the current test case
	var u int

	// Declaring and initializing a variable to store the current test case
	var v int

	// Declaring and initializing a variable to store the current test case
	var w int

	// Declaring and initializing a variable to store the current test case
	var x int

	// Declaring and initializing a variable to store the current test case
	var y int

	// Declaring and initializing a variable to store the current test case
	var z int

	// Declaring and initializing a variable to store the current test case
	var a int

	// Declaring and initializing a variable to store the current test case
	var b int

	// Declaring and initializing a variable to store the current test case
	var c int

	// Declaring and initializing a variable to store the current test case
	var d int

	// Declaring and initializing a variable to store the current test case
	var e int

	// Declaring and initializing a variable to store the current test case
	var f int

	// Declaring and initializing a variable to store the current test case
	var g int

	// Declaring and initializing a variable to store the current test case
	var h int

	// Declaring and initializing a variable to store the current test case
	var i int

	// Declaring and initializing a variable to store the current test case
	var j int

	// Declaring and initializing a variable to store the current test case
	var k int

	// Declaring and initializing a variable to store the current test case
	var l int

	// Declaring and initializing a variable to store the current test case
	var m int

	// Declaring and initializing a variable to store the current test case
	var n int

	// Declaring and initializing a variable to store the current test case
	var o int

	// Declaring and initializing a variable to store the current test case
	var p int

	// Declaring and initializing a variable to store the current test case
	var q int

	// Declaring and initializing a variable to store the current test case
	var r int

	// Declaring and initializing a variable to store the current test case
	var s int

	// Declaring and initializing a variable to store the current test case
	var t int

	// Declaring and initializing a variable to store the current test case
	var u int

	// Declaring and initializing a variable to store the current test case
	var v int

	// Declaring and initializing a variable to store the current test case
	var w int

	// Declaring and initializing a variable to store the current test case
	var x int

	// Declaring and initializing a variable to store the current test case
	var y int

	// Declaring and initializing a variable to store the current test case
	var z int

	// Declaring and initializing a variable to store the current test case
	var a int

	// Declaring and initializing a variable to store the current test case
	var b int

	// Declaring and initializing a variable to store the current test case
	var c int

	// Declaring and initializing a variable to store the current test case
	var d int

	// Declaring and initializing a variable to store the current test case
	var e int

	// Declaring and initializing a variable to store the current test case
	var f int

	// Declaring and initializing a variable to store the current test case
	var g int

	// Declaring and initializing a variable to store the current test case
	var h int

	// Declaring and initializing a variable to store the current test case
	var i int

	// Declaring and initializing a variable to store the current test case
	var j int

	// Declaring and initializing a variable to store the current test case
	var k int

	// Declaring and initializing a 