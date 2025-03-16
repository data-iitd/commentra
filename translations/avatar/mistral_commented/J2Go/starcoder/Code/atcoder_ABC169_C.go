
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a: ")
	a, _ := strconv.ParseInt(strings.Replace(strings.Replace(reader.ReadString(), "\n", "", -1), "\r", "", -1), 10, 64)
	fmt.Print("Enter b: ")
	b := strings.Replace(strings.Replace(reader.ReadString(), "\n", "", -1), "\r", "", -1)
	bChar := []rune(b)
	length := len(bChar)
	bStr := ""
	for i := 0; i < length; i++ {
		if bChar[i]!= '.' {
			bStr += string(bChar[i])
		}
	}
	bInt, _ := strconv.ParseInt(bStr, 10, 64)
	result := (a * bInt) / 100
	fmt.Println(result)
}

