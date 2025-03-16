// Read the first time input in 'hh:mm' format and split it into hours and minutes
h1, m1 := strings.Split(fmt.Scanf("%d:%d", &h1, &m1), ":")

// Convert the first time into total minutes
m1 += h1 * 60

// Read the second time input in 'hh:mm' format and split it into hours and minutes
h2, m2 := strings.Split(fmt.Scanf("%d:%d", &h2, &m2), ":")

// Convert the second time into total minutes
m2 += h2 * 60

// Calculate the difference in minutes between the first and second time
m2 = m1 - m2

// Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
m2 %= 1440

// Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
fmt.Printf("%02d:%02d", m2 / 60, m2 % 60)

