
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
	fmt.Print("Enter input: ")
	text, _ := reader.ReadString('\n')
	text = strings.TrimSpace(text)
	parts := strings.Split(text, ".")
	s := strings.Split(parts[0], "")
	p := strings.Split(parts[1], "")
	i, _ := strconv.Atoi(p[0])
	if s[len(s)-1] == "9" {
		fmt.Println("GOTO Vasilisa.")
	} else if s[len(s)-1]!= "9" && i < 5 {
		fmt.Println(strings.Join(s, ""))
	} else {
		s = strings.Join(s, "")
		i, _ = strconv.Atoi(s)
		i++
		s = strconv.Itoa(i)
		fmt.Println(s)
	}
}
