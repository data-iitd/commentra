// Take input string from the user
String S = sc.next();

// Import the HashMap class from the java.util package
import java.util.HashMap;

// Create a HashMap object to count the frequency of each character in the string
HashMap<Character, Integer> c = new HashMap<Character, Integer>();

// Iterate over each character in the string
for (int i = 0; i < S.length(); i++) {
    // Check if the character is already present in the HashMap
    if (c.containsKey(S.charAt(i))) {
        // If the character is already present, increment its count
        c.put(S.charAt(i), c.get(S.charAt(i)) + 1);
    } else {
        // If the character is not present, add it to the HashMap with count 1
        c.put(S.charAt(i), 1);
    }
}

// Create a set of unique characters from the input string
Set<Character> Sa = new HashSet<Character>(c.keySet());

// Check if the number of unique characters is not equal to 2
if (Sa.size()!= 2) {
    // If there are not exactly 2 unique characters, print "No" and exit
    System.out.println("No");
    return;
}

// Iterate over each unique character in the set
for (Character i : Sa) {
    // Check if the count of the current character is not equal to 2
    if (c.get(i)!= 2) {
        // If any character does not appear exactly twice, print "No" and exit
        System.out.println("No");
        return;
    }
}

// If both conditions are satisfied, print "Yes"
System.out.println("Yes");

