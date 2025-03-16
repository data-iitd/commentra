
package main

import (
  "fmt"
  "math/big"
  "os"
  "strconv"
)

func main() {
  var str string
  var dotIndex int

  // Reading a line of input from the console and storing it in the string str
  fmt.Scanln(&str)

  // Finding the index of the last occurrence of '.' character in the string
  for i := 0; i < len(str); i++ {
    if str[i] == '.' {
      dotIndex = i
      break
    }
  }

  // Checking if the character before the '.' character is '9'
  if str[dotIndex-1] == '9' {
    fmt.Println("GOTO Vasilisa.")
  }

  // Checking if the character after the '.' character is a digit greater than 4
  else if str[dotIndex+1] > '4' {
    var _str string

    // Creating a substring of the string str from the beginning to the index of '.' character
    for i := 0; i < dotIndex; i++ {
      _str += string(str[i])
    }

    // Performing big integer addition and printing the result
    fmt.Println(big.NewInt(0).Add(big.NewInt(0).SetString(_str, 10), big.NewInt(1)))
  }

  // Printing the substring of the string str from the beginning to the index of '.' character
  else {
    for i := 0; i < dotIndex; i++ {
      fmt.Print(str[i])
    }

    // Printing a newline character at the end of the substring
    fmt.Println()
  }
}

