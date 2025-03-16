<<<<<<< HEAD
/*
URL_HERE
*/
/*

*/
=======
_

package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fin := bufio.NewReader(os.Stdin)
	fout := bufio.NewWriter(os.Stdout)
	defer fout.Flush()

<<<<<<< HEAD
	a, _ := strconv.Atoi(strings.TrimSpace(readLine(fin)))
	b, _ := strconv.Atoi(strings.TrimSpace(readLine(fin)))

=======
	a, _ := strconv.Atoi(readLine(fin))
	b, _ := strconv.Atoi(readLine(fin))
>>>>>>> 98c87cb78a (data updated)
	if a < b {
		for i := 0; i < b; i++ {
			fmt.Fprint(fout, a, " ")
		}
<<<<<<< HEAD
		fmt.Fprintln(fout)
=======
>>>>>>> 98c87cb78a (data updated)
	} else {
		for i := 0; i < a; i++ {
			fmt.Fprint(fout, b, " ")
		}
<<<<<<< HEAD
		fmt.Fprintln(fout)
	}
=======
	}
	fmt.Fprintln(fout)
>>>>>>> 98c87cb78a (data updated)
}

func readLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
<<<<<<< HEAD
	return string(str)
=======
	return strings.TrimRight(string(str), "\r\n")
>>>>>>> 98c87cb78a (data updated)
}

