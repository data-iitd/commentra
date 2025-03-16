
// Importing the Scanner class from the java.util package
import java.util.Scanner;

// Creating a Scanner object named 'input' to read the input from the user
Scanner input = new Scanner(System.in);

// Assigning the input to two variables 'a' and 'b' after splitting it by a space
String[] ab = input.nextLine().split(" ");
String a = ab[0];
String b = ab[1];

// Finding the maximum length between 'a' and 'b' and padding zeros to the shorter string
int x = Math.max(a.length(), b.length());
a = a.chars().mapToObj(i -> (char) i).collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append).reverse().toString();
b = b.chars().mapToObj(i -> (char) i).collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append).reverse().toString();
a = String.join("", Collections.nCopies(x - a.length(), "0")).concat(a);
b = String.join("", Collections.nCopies(x - b.length(), "0")).concat(b);

// Initializing an empty string's' and a counter 'c' for carrying
String s = "";
int c = 0;

// Iterating through each index 'i' in the range of the length of the padded strings 'x'
for (int i = 0; i < x; i++) {

    // Adding the current digits of 'a' and 'b' at the corresponding positions and carrying if necessary
    int d = Integer.parseInt(String.valueOf(b.charAt(i))) + Integer.parseInt(String.valueOf(a.charAt(x - i - 1))) + c;

    // If the sum is greater than 9, add the carry to the next digit and reset the carry to 0
    if (d > 9) {
        s += String.valueOf(d % 10);
        c = 1;
    }

    // If the sum is less than or equal to 9, add the digit to the result string's'
    else {
        s += String.valueOf(d);
        c = 0;
    }
}

// If there is still a carry left, add it to the result string's'
if (c == 1) {
    s += "1";
}

// Printing the final result after removing the leading zeros (if any)
System.out.println(Integer.parseInt(s.replaceAll("^0*", "")));

