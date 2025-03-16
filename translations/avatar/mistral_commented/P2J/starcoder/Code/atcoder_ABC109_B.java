// Import the 'defaultdict' from the 'java.util' package
import java.util.HashMap;
import java.util.Map;

// Read the number of elements in the list from user input
int n = Integer.parseInt(input());

// Initialize an empty map's' with default value 0 using HashMap
Map<String, Integer> s = new HashMap<String, Integer>(){{
    put("", 0);
}};

// Create an empty list 'l' with length 'n' by reading elements from user input
String[] l = new String[n];
for(int i = 0; i < n; i++) {
    l[i] = input();
}

// Initialize a flag 'f' with value 'Yes'
String f = "Yes";

// Iterate through each element 'v' in the list 'l'
for(int i = 0; i < n; i++) {
    // Increment the count of 'v' in map's'
    s.put(l[i], s.get(l[i]) + 1);

    // Check if the count of 'v' in map's' is greater than or equal to 2
    if(s.get(l[i]) >= 2) {
        // If yes, set the flag 'f' to 'No'
        f = "No";
    }

    // Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
    if(i!= -1 && l[i - 1].charAt(l[i - 1].length() - 1)!= l[i].charAt(0)) {
        // If yes, set the flag 'f' to 'No'
        f = "No";
    }
}

// Print the final value of flag 'f'
System.out.println(f);

