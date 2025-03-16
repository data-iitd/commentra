
// Assign values to variables a, b, h, and m using the Scanner class
Scanner scanner = new Scanner(System.in);
int a = scanner.nextInt();
int b = scanner.nextInt();
int h = scanner.nextInt();
int m = scanner.nextInt();

// Calculate the angle C between hour hand and minute hand
double C = Math.abs(360 / 60.0 * m - 360 / 12.0 * h - 360 / 12.0 / 60.0 * m);
if (C > 180) {
    // If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
    C = 360 - C;
}

// Calculate the cosine of angle C
double cosC = Math.cos(Math.toRadians(C));

// Calculate and print the length of the side of the right triangle formed by the hour and minute hands
System.out.println(Math.sqrt(a * a + b * b - 2 * a * b * cosC));

