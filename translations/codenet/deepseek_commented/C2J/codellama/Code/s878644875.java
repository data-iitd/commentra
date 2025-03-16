
public class Main {
  public static void main(String[] args) {
    char[] s = new char[4]; // Declare character arrays to store input strings
    char[] t = new char[4];
    Scanner sc = new Scanner(System.in); // Create a Scanner object
    System.out.print("Enter the first string: "); // Prompt the user to enter a string
    s = sc.nextLine().toCharArray(); // Read the first string from the user and store it in s
    System.out.print("Enter the second string: "); // Prompt the user to enter a string
    t = sc.nextLine().toCharArray(); // Read the second string from the user and store it in t
    int hit = 0; // Initialize a counter for hits
    for (int i = 0; i < 3; i++) { // Compare characters in the strings
      if (s[i] == t[i]) hit++; // Increment the hit counter if characters match
    }
    System.out.println("Number of matching characters: " + hit); // Print the number of matching characters
  }
}

