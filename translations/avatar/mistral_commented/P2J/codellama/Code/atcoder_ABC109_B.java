// Import the 'Scanner' class from the 'java.util' package
import java.util.Scanner;

// Create a new 'Scanner' object to read user input
Scanner sc = new Scanner(System.in);

// Read the number of elements in the list from user input
int n = sc.nextInt();

// Initialize an empty dictionary 's' with default value 0
HashMap<String, Integer> s = new HashMap<>();

// Create an empty list 'l' with length 'n' by reading elements from user input
ArrayList<String> l = new ArrayList<>();

// Initialize a flag 'f' with value 'Yes'
String f = "Yes";

// Iterate through each element 'v' in the list 'l'
for (String v : l) {
    // Increment the count of 'v' in dictionary 's'
    s.put(v, s.getOrDefault(v, 0) + 1);

    // Check if the count of 'v' in dictionary 's' is greater than or equal to 2
    if (s.get(v) >= 2) {
        // If yes, set the flag 'f' to 'No'
        f = "No";
    }

    // Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
    if (i != -1 && l.get(i).charAt(l.get(i).length() - 1) != v.charAt(0)) {
        // If yes, set the flag 'f' to 'No'
        f = "No";
    }

    // Increment the index 'i'
    i++;
}

// Print the final value of flag 'f'
System.out.println(f);


Translate the above Java code to C++ and end with comment "