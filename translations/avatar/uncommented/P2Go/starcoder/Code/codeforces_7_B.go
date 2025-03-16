package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var t, m int
	var alocuente []int
	var ind int
	var op []string
	var pos int
	var i, j int
	var cnt int
	var err error
	var input string
	var reader *bufio.Reader
	reader = bufio.NewReader(os.Stdin)
	input, err = reader.ReadString('\n')
	if err!= nil {
		fmt.Println(err)
	}
	input = strings.TrimSuffix(input, "\n")
	t, err = strconv.Atoi(input)
	if err!= nil {
		fmt.Println(err)
	}
	input, err = reader.ReadString('\n')
	if err!= nil {
		fmt.Println(err)
	}
	input = strings.TrimSuffix(input, "\n")
	m, err = strconv.Atoi(input)
	if err!= nil {
		fmt.Println(err)
	}
	alocuente = make([]int, m)
	ind = 1
	for i = 0; i < t; i++ {
		input, err = reader.ReadString('\n')
		if err!= nil {
			fmt.Println(err)
		}
		input = strings.TrimSuffix(input, "\n")
		op = strings.Split(input, " ")
		if op[0] == "alloc" {
			pos = 0
			for j = 0; j < m; j++ {
				if alocuente[j] == 0 {
					pos += 1
					if pos == int(op[1]) {
						alocuente[j-int(op[1])+1:j+1] = make([]int, int(op[1]))
						for k := 0; k < int(op[1]); k++ {
							alocuente[j-int(op[1])+1+k] = ind
						}
						fmt.Println(ind)
						ind++
						break
					}
				} else {
					pos = 0
			} else {
				fmt.Println("NULL")
			}
		}
		if op[0] == "erase" {
			pos = 0
			if int(op[1]) == 0 || int(op[1]) > m || int(op[1]) not in alocuente {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			} else {
				for j = 0; j < m; j++ {
					if int(op[1]) > 0 && alocuente[j] == int(op[1]) {
						alocuente[j] = 0
			}
		}
		if op[0] == "defragment" {
			cnt = 0
			cnt = len(alocuente) - len(alocuente)
			for j = 0; j < m; j++ {
				if alocuente[j] == 0 {
					alocuente = append(alocuente[:j], alocuente[j+1:]...)
					alocuente = append(alocuente, 0)
					cnt--
					if cnt == 0 {
						break
					}
				}
			}
	}
}

