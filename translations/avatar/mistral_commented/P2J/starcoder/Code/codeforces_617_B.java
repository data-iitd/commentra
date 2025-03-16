
// Import the Math class
import java.lang.Math;

// Read the input from the standard input
String a = new Scanner(System.in).next();

// Check if the string contains any '1' character
if (a.contains("1") == false) {
    // If it doesn't, print 0 and exit the program
    System.out.println(0);
    return;
}

// If the string contains at least one '1' character, we proceed to calculate the product of the number of zeros in each segment between consecutive '1' characters
int product_of_zeros = 1;
for (String i : a.split("1")) {
    product_of_zeros *= (i.length() - i.replace("0", "").length() + 1);
}

// Finally, print the result
System.out.println(product_of_zeros);

