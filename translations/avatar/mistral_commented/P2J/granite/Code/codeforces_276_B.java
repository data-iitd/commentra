
// Initialize an empty list's' to store input elements
List<Character> s = new ArrayList<>();

// Initialize an empty map 'dt' to store the count of each unique element
Map<Character, Integer> dt = new HashMap<>();

// Set a boolean variable 'x' to true to indicate whether there is an odd count element in the list
boolean x = true;

// Iterate through each character 'i' in the list's'
for (char i : s) {
    // Check if the character 'i' already exists as a key in the map 'dt'
    if (dt.containsKey(i)) {
        // If it does, increment its value by 1
        dt.put(i, dt.get(i) + 1);
    } else {
        // If not, add it as a new key with a value of 1
        dt.put(i, 1);
    }
}

// Initialize a counter 'cnt' to 0 and set 'x' to true
int cnt = 0;
x = true;

// Iterate through each entry 'entry' in the map 'dt'
for (Map.Entry<Character, Integer> entry : dt.entrySet()) {
    // If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
    if (entry.getValue() % 2!= 0 && cnt < 1) {
        cnt++;
    }
    // If the value is odd and 'cnt' is already greater than or equal to 1, set 'x' to false and break the loop
    else if (entry.getValue() % 2!= 0 && cnt >= 1) {
        x = false;
        break;
    }
}

// After the loop, check the value of 'x'
if (x) {
    // If it is true, print "First"
    System.out.println("First");
} else if (!x && s.size() % 2 == 0) {
    // If it is false and the size of the list's' is even, print "Second"
    System.out.println("Second");
} else if (!x && s.size() % 2!= 0) {
    // If it is false and the size of the list's' is odd, print "First"
    System.out.println("First");
}

