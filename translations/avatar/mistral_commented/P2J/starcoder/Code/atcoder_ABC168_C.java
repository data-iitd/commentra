// Assign values to variables a, b, h, and m using the input function and map function
Scanner sc = new Scanner(System.in);
int a = sc.nextInt();
int b = sc.nextInt();
int h = sc.nextInt();
int m = sc.nextInt();

// Import the math module for mathematical functions
import java.lang.Math;

// Calculate the angle C between hour hand and minute hand
double C = Math.abs(360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m);
if (C > 180) {
    // If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
    C = 360 - C;
}

// Calculate the cosine of angle C
double cosC = Math.cos(Math.toRadians(C));

// Calculate and print the length of the side of the right triangle formed by the hour and minute hands
System.out.println(Math.sqrt(a * a + b * b - 2 * a * b * cosC));

