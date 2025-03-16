package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the text: ")
	text, _ := reader.ReadString('\n')
	text = strings.Replace(text, "\n", "", -1)
	cu := 0
	cl := 0
	for _, z := range text {
		if z >= 'a' && z <= 'z' {
			cl++
		} else {
			cu++
		}
	}
	if cu > cl {
		text = strings.ToUpper(text)
	} else {
		text = strings.ToLower(text)
	}
	fmt.Println(text)
}

