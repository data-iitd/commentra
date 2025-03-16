
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
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	str = strings.Replace(str, ".", "", 1)
	dotIndex := strings.LastIndex(str, ".")
	if str[dotIndex-1] == '9' {
		fmt.Println("GOTO Vasilisa.")
	} else if str[dotIndex+1] > '4' {
		str = str[:dotIndex]
		fmt.Println(addOne(str))
	} else {
		fmt.Println(str[:dotIndex])
	}
}

func addOne(str string) string {
	var result int
	for _, v := range str {
		result += int(v - '0')
	}
	result += 1
	return strconv.Itoa(result)
}

