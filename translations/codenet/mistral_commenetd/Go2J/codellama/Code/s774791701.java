
// Initialize an empty string variable named 's'
String s = "";

// Read a string input from the user using Scanner class
Scanner sc = new Scanner(System.in);
s = sc.nextLine();

// Declare a variable named 'price' with initial value 700
int price = 700;

// Iterate through each character 'c' in the string 's' using a for loop
for (int i = 0; i < s.length(); i++) {
	// Check if the current character 'c' is equal to 'o'
	if (s.charAt(i) == 'o') {
		// If yes, add 100 to the 'price' variable
		price += 100;
	}
}

// Print the final value of 'price' using System.out.println() function
System.out.println(price);

