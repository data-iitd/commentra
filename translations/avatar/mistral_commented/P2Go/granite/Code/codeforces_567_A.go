
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

	var inp int
	fmt.Fscan(reader, &inp)

	var lista []int
	input := make([]string, inp)
	fmt.Fscanln(reader, &input)

	for i := 0; i < inp; i++ {
		temp, _ := strconv.Atoi(input[i])
		lista = append(lista, temp)
	}

	for i := 0; i < inp; i++ {
		if i == 0 {
			fmt.Printf("%d %d\n", lista[i+1]-lista[i], lista[inp-1]-lista[i])
			continue
		}

		if i == inp-1 {
			fmt.Printf("%d %d\n", lista[inp-1]-lista[inp-2], lista[inp-1]-lista[0])
			continue
		}

		if lista[i]-lista[i-1] > lista[i+1]-lista[i] {
			fmt.Printf("%d ", lista[i+1]-lista[i])
		} else {
			fmt.Printf("%d ", lista[i]-lista[i-1])
			if lista[inp-1]-lista[i] > lista[i]-lista[0] {
				fmt.Println(lista[inp-1] - lista[i])
			} else {
				fmt.Println(lista[i] - lista[0])
			}
		}
	}
}
