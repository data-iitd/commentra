// Read input from the user and split it into a list of strings
String[] p = input.split(" ");

// Convert the first four elements of the list to integers representing coordinates
int x1 = Integer.parseInt(p[0]);  // x-coordinate of the first point
int y1 = Integer.parseInt(p[1]);  // y-coordinate of the first point
int x2 = Integer.parseInt(p[2]);  // x-coordinate of the second point
int y2 = Integer.parseInt(p[3]);  // y-coordinate of the second point

// Calculate the differences in x and y coordinates between the two points
int DIF1 = x2 - x1;  // Difference in x-coordinates
int DIF2 = y2 - y1;  // Difference in y-coordinates

// Calculate the coordinates of the third point based on the differences
int x3 = x2 - DIF2;  // x-coordinate of the third point
int y3 = y2 + DIF1;  // y-coordinate of the third point

// Calculate the coordinates of the fourth point based on the differences
int x4 = x1 - DIF2;  // x-coordinate of the fourth point
int y4 = y1 + DIF1;  // y-coordinate of the fourth point

// Print the coordinates of the third and fourth points
System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);

