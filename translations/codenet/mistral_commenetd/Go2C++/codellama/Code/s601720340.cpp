
#include <bits/stdc++.h>

using namespace std;

#define Logf(format, ...) fprintf(stderr, format, __VA_ARGS__)

// Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"

	"runtime"
	"runtime/pprof"
)

const magic = 1000000007

var cpuprofile, memprofile string

var N int
var p [200000]int

// find function checks if a given number n is present in the p slice
func find(n int) int {
	for i := 0; i < N; i++ {
		if n == p[i] {
			return 0
		}
	}
	return 1
}

// solve function contains the main logic of the problem
func solve() {
	// Create an Io instance for reading input
	io := NewIo()
	defer io.Flush()

	// Parse input using the NextInt function of the Io instance
	X := io.NextInt()
	Logf("%v\n", X)
	N := io.NextInt()
	Logf("%v\n", N)
	for i := 0; i < N; i++ {
		p[i] = io.NextInt()
	}
	Logf("p %v\n", p[0:10])

	// Check if X or its neighbors are present in the p slice
	for i := 0; i <= 100; i++ {
		if find(X-i) == 1 {
			fmt.Printf("%v\n", X-i)
			os.Exit(0)
		}
		if find(X+i) == 1 {
			fmt.Printf("%v\n", X+i)
			os.Exit(0)
		}
	}

	// Output generation part is not present in the code
	// // OUTPUT GENERATION PART
	// ans := 0
	// fmt.Printf("%v\n", ans)

	// If ans > 0, print "Yes" and exit; otherwise, print "No"
	// if ans > 0 {
	//   fmt.Printf("Yes\n")
	// } else {
	//   fmt.Printf("No\n")
	// }

	// main function initializes flags for CPU and memory profiling and calls the solve function
}

func main() {
	flag.Parse() // Parse command-line arguments

	if cpuprofile != "" { // If CPU profiling is specified, write the CPU profile to the file
		f, err := os.Create(cpuprofile)
		if err != nil {
			Logf("%v\n", err)
			os.Exit(1)
		}
		pprof.StartCPUProfile(f)
		defer pprof.StopCPUProfile()
	}

	solve() // Call the solve function

	if memprofile != "" { // If memory profiling is specified, write the memory profile to the file
		f, err := os.Create(memprofile)
		if err != nil {
			Logf("could not create memory profile: ", err)
			os.Exit(1)
		}
		defer f.Close() // error handling omitted for example
		runtime.GC() // Get up-to-date statistics
		if err := pprof.WriteHeapProfile(f); err != nil {
			Logf("could not write memory profile: ", err)
			os.Exit(1)
		}
	}
}

