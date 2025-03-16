// Take input string from the user
Scanner sc = new Scanner(System.in);
String S = sc.nextLine();

// Import the HashMap class from the java.util package to count occurrences of characters
import java.util.HashMap;

// Create a HashMap object to count the frequency of each character in the string
HashMap<Character, Integer> c = new HashMap<>();

// Create a set of unique characters from the input string
Set<Character> Sa = new HashSet<>();

// Add each character in the input string to the set
for (int i = 0; i < S.length(); i++) {
    Sa.add(S.charAt(i));
}

// Check if the number of unique characters is not equal to 2
if (Sa.size() != 2) {
    // If there are not exactly 2 unique characters, print "No" and exit
    System.out.println("No");
    return;
}

// Iterate over each unique character in the set
for (Character i : Sa) {
    // Check if the count of the current character is not equal to 2
    if (c.get(i) != 2) {
        // If any character does not appear exactly twice, print "No" and exit
        System.out.println("No");
        return;
    }
}

// If both conditions are satisfied, print "Yes"
System.out.println("Yes");


Translate the above Java code to C++ and end with comment "