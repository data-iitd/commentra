// Read the starting time and duration of activity A
a, at := 0, 0
fmt.Scan(&a, &at)

// Read the starting time and duration of activity B
b, bt := 0, 0
fmt.Scan(&b, &bt)

// Read the start time in hours and minutes, then convert it to total minutes
t1, t2 := 0, 0
fmt.Scan(&t1, &t2)
st := t2 + (t1 - 5) * 60 // Convert start time to minutes since 5:00

// Calculate the finish time for activity A
fin := st + at

// Initialize the current time and the answer counter
now, ans := 0, 0

// Loop until the current time exceeds the finish time or the maximum time limit (19:00 or 1140 minutes)
for now < fin && now < 1140 {
	// Check if activity B can start after the current time
	if now+bt > st {
		ans++ // Increment the count of possible starts for activity B
	}
	now += b // Move the current time forward by the duration of activity B
}

// Print the total number of times activity B can start
fmt.Println(ans)

