// Read input from the user and split it into a list of strings
p := strings.Split(fmt.Scanf("%s", &p), " ")

// Convert the first four elements of the list to integers representing coordinates
x1, _ := strconv.Atoi(p[0])  // x-coordinate of the first point
y1, _ := strconv.Atoi(p[1])  // y-coordinate of the first point
x2, _ := strconv.Atoi(p[2])  // x-coordinate of the second point
y2, _ := strconv.Atoi(p[3])  // y-coordinate of the second point

// Calculate the differences in x and y coordinates between the two points
DIF1 := x2 - x1  // Difference in x-coordinates
DIF2 := y2 - y1  // Difference in y-coordinates

// Calculate the coordinates of the third point based on the differences
x3 := x2 - DIF2  // x-coordinate of the third point
y3 := y2 + DIF1  // y-coordinate of the third point

// Calculate the coordinates of the fourth point based on the differences
x4 := x1 - DIF2  // x-coordinate of the fourth point
y4 := y1 + DIF1  // y-coordinate of the fourth point

// Print the coordinates of the third and fourth points
fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)

