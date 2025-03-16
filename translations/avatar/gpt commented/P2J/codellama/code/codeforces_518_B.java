
// Read two strings from input
Scanner sc = new Scanner(System.in);
String s = sc.next();
String t = sc.next();

// Initialize dictionaries to store frequency counts of characters in both strings
HashMap<Character, Integer> freqs = new HashMap<Character, Integer>();
HashMap<Character, Integer> freqt = new HashMap<Character, Integer>();

// Initialize counters for matching characters
int yay = 0;
int whoops = 0;

// Count the frequency of each character in the first string 's'
for (int i = 0; i < s.length(); i++) {
    char letra = s.charAt(i);
    if (freqs.containsKey(letra)) {
        freqs.put(letra, freqs.get(letra) + 1);  // Increment count if character already exists
    } else {
        freqs.put(letra, 1);    // Initialize count if character is new
    }
}

// Count the frequency of each character in the second string 't'
for (int i = 0; i < t.length(); i++) {
    char letra = t.charAt(i);
    if (freqt.containsKey(letra)) {
        freqt.put(letra, freqt.get(letra) + 1);  // Increment count if character already exists
    } else {
        freqt.put(letra, 1);    // Initialize count if character is new
    }
}

// Compare character frequencies from both strings to count exact matches
for (char letra : freqs.keySet()) {
    while (freqs.get(letra) > 0 && freqt.containsKey(letra) && freqt.get(letra) > 0) {
        yay += 1;  // Increment the count of exact matches
        freqs.put(letra, freqs.get(letra) - 1);  // Decrease the count in the first string
        freqt.put(letra, freqt.get(letra) - 1);  // Decrease the count in the second string
    }
}

// Compare remaining characters for case-insensitive matches
for (char letra : freqs.keySet()) {
    while (freqs.get(letra) > 0) {
        // Check for a lowercase letter in 's' and its uppercase counterpart in 't'
        if (Character.isLowerCase(letra) && freqt.containsKey(Character.toUpperCase(letra)) && freqt.get(Character.toUpperCase(letra)) > 0) {
            whoops += 1;  // Increment the count of case-insensitive matches
            freqs.put(letra, freqs.get(letra) - 1);  // Decrease the count in the first string
            freqt.put(Character.toUpperCase(letra), freqt.get(Character.toUpperCase(letra)) - 1);  // Decrease the count in the second string
        }
        // Check for an uppercase letter in 's' and its lowercase counterpart in 't'
        else if (Character.isUpperCase(letra) && freqt.containsKey(Character.toLowerCase(letra)) && freqt.get(Character.toLowerCase(letra)) > 0) {
            whoops += 1;  // Increment the count of case-insensitive matches
            freqs.put(letra, freqs.get(letra) - 1);  // Decrease the count in the first string
            freqt.put(Character.toLowerCase(letra), freqt.get(Character.toLowerCase(letra)) - 1);  // Decrease the count in the second string
        } else {
            break;  // Exit the loop if no more matches can be found
        }
    }
}

// Print the results: number of exact matches and case-insensitive matches
System.out.println(yay + " " + whoops);

