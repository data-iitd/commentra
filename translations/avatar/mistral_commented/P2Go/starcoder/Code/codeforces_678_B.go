// Function to check if a year is a leap year
func leapyear(n int) string {
	// Check if the year is a leap year by checking if it satisfies the conditions
	if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
		// If the conditions are met, return "y" to indicate that the year is a leap year
		return "y"
	} else {
		// If the conditions are not met, return "n" to indicate that the year is not a leap year
		return "n"
	}
}

// Take an integer input from the user
var n int
fmt.Scanf("%d", &n)

// Initialize a variable 'd' to keep track of the day of the week for the given year
var d string = "f"

// Check if the given year is a leap year
if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
	// If the year is a leap year, set the answer to "ly"
	ans := "ly"
} else {
	// If the year is not a leap year, set the answer to "nly"
	ans := "nly"
}

// Keep updating the day of the week and the year until we find the correct answer
for {
	// Check if the given year is a leap year
	if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
		// If the year is a leap year, update the day of the week accordingly
		if (d == "m") {
			d = "w"
			n += 1
		} else if (d == "t") {
			d = "th"
			n += 1
		} else if (d == "w") {
			d = "f"
			n += 1
		} else if (d == "th") {
			d = "sa"
			n += 1
		} else if (d == "f") {
			d = "s"
			n += 1
		} else if (d == "sa") {
			d = "m"
			n += 1
		} else if (d == "s") {
			d = "t"
			n += 1
	} else {
		// If the year is not a leap year, update the day of the week accordingly
		if (d == "m") {
			d = "t"
			n += 1
		} else if (d == "t") {
			d = "w"
			n += 1
		} else if (d == "w") {
			d = "th"
			n += 1
		} else if (d == "th") {
			d = "f"
			n += 1
		} else if (d == "f") {
			d = "sa"
			n += 1
		} else if (d == "sa") {
			d = "s"
			n += 1
		} else if (d == "s") {
			d = "m"
			n += 1
	}

	// Check if we have found the correct answer
	if (d == "f" && ans == "ly" && leapyear(n) == "y") {
		// If we have found the correct answer, break out of the loop
		break
	} else if (d == "f" && ans == "nly" && leapyear(n) == "n") {
		// If we have found the correct answer, break out of the loop
		break
	}
}

// Print the result
fmt.Println(n)

