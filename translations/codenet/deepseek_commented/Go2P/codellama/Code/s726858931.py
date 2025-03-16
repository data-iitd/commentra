
# Go:

# package main

# import (
	# "bufio"
	# "fmt"
	# "os"
	# "strconv"
# )

# var sc = bufio.NewScanner(os.Stdin)

# // Initializes the scanner to read from standard input efficiently.
# func scanInit() {
	# const cap = 1000 * 1024
	# var buf = make([]byte, cap)
	# sc.Buffer(buf, cap)
	# sc.Split(bufio.ScanWords)
	# return
# }

# // Reads an integer from the input.
# func nextInt() int {
	# sc.Scan()
	# i, e := strconv.Atoi(sc.Text())
	# if e != nil {
		# panic(e)
	# }
	# return i
# }

# // Reads a string from the input.
# func nextStr() string {
	# sc.Scan()
	# return sc.Text()
# }

# // Main function that executes the program logic.
# func main() {
	# scanInit()

	# // Read the input string.
	# s := nextStr()

	# // Initialize the character to check against the string.
	# c := 'a'

	# // Iterate through the alphabet to find the first missing character.
	# for j := 0; j < 26; j++ {
		# found := false
		# for i := 0; i < len(s); i++ {
			# if s[i] == byte(c) {
				# found = true
				# break
			# }
		# }
		# if found == false {
			# fmt.Println(string(c))
			# return
		# }
		# c++
	# }

	# // If no missing character is found, print "None".
	# fmt.Println("None")
# }

# 