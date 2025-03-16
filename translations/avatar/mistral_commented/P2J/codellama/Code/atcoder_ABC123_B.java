
// Import the java.util.Scanner class for user input
import java.util.Scanner;

// Initialize a new Scanner object called sc
Scanner sc = new Scanner(System.in);

// Initialize an empty list called menu
ArrayList<Integer> menu = new ArrayList<Integer>();

// Use a for loop to iterate 5 times
for (int i = 0; i < 5; i++) {
    // Take user input and assign it to the variable m
    int m = sc.nextInt();
    
    // Extract the last character of the string m to determine the exponent e
    int e = m % 10;
    
    // If e is 0, set it to 10
    if (e == 0) {
        e = 10;
    }
    
    // Append a list containing the integer value of m and the exponent e to the menu list
    menu.add(m);
    menu.add(e);
}

// Sort the menu list based on the exponent value using the sort() method with a lambda function as the key
menu.sort((a, b) -> a[1] - b[1]);

// Initialize a variable called ans to 0
int ans = 0;

// Use a for loop to iterate through the menu list starting from the second element (index 1)
for (int i = 1; i < menu.size(); i += 2) {
    // Calculate the number of full 10s that can be obtained by dividing the integer value by 10 and rounding up using the ceil() function from the math module
    int num_full_10s = (int) Math.ceil((double) menu.get(i) / 10);
    
    // Multiply this value by 10 and add it to the ans variable
    ans += num_full_10s * 10;
}

// Finally, print the sum of the first element in the menu list (which is the initial number) and the value of ans
System.out.println(menu.get(0) + ans);

