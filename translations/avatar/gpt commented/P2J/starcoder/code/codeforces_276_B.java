// Read input and convert it to a list of characters
String s = input();
char[] s_arr = s.toCharArray();

// Initialize a flag variable and a dictionary to count occurrences of each character
boolean x = true;
HashMap<Character, Integer> dt = new HashMap<Character, Integer>();

// Count the occurrences of each character in the input list
for (int i = 0; i < s_arr.length; i++) {
    char c = s_arr[i];
    if (dt.containsKey(c)) {
        dt.put(c, dt.get(c) + 1);  // Increment the count if the character is already in the dictionary
    } else {
        dt.put(c, 1);  // Initialize the count to 1 if the character is not in the dictionary
    }
}

// Initialize a counter for odd occurrences and a flag variable
int cnt = 0;
x = true;

// Check the counts of each character to determine the number of odd occurrences
for (Map.Entry<Character, Integer> entry : dt.entrySet()) {
    char key = entry.getKey();
    int value = entry.getValue();
    if (value % 2!= 0 && cnt < 1) {
        cnt += 1;  // Count the first odd occurrence
    } else if (value % 2!= 0 && cnt >= 1) {
        x = false;  // More than one odd occurrence found, set flag to False
        break;
    }
}

// Determine the output based on the number of odd occurrences and the length of the input
if (x) {
    System.out.println("First");  // If there are no more than one odd occurrences, print "First"
} else if (!x && s.length() % 2 == 0) {
    System.out.println("Second");  // If there are more than one odd occurrences and the length is even, print "Second"
} else if (!x && s.length() % 2!= 0) {
    System.out.println("First");  // If there are more than one odd occurrences and the length is odd, print "First"
}

