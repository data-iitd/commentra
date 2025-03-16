// Take input from the user and split it using a space as the delimiter
String[] p = input.split(" ");

// Extract the first four elements of the list p and convert them to integers
int x1 = Integer.parseInt(p[0]);
int y1 = Integer.parseInt(p[1]);
int x2 = Integer.parseInt(p[2]);
int y2 = Integer.parseInt(p[3]);

// Calculate the differences between the coordinates
int DIF1 = x2 - x1;
int DIF2 = y2 - y1;

// Calculate the coordinates of the other two points based on the given coordinates and the differences
int x3 = x2 - DIF2;
int y3 = y2 + DIF1;
int x4 = x1 - DIF2;
int y4 = y1 + DIF1;

// Print the calculated coordinates in the format x3 x4 y3 y4
System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);

