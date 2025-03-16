
// Take input from the user
Scanner scanner = new Scanner(System.in);
String s = scanner.nextLine();

// Initialize an empty list to store the result
List<String> res = new ArrayList<>();

// Define a list of punctuation marks to check against
String[] punctuation = {",", ".", "!", "?"};

// Iterate through each character in the input string
for (int i = 0; i < s.length(); i++) {
    // Check if the current index is greater than or equal to 1
    if (i >= 1) {
        // If the current character is a space
        if (s.charAt(i) =='') {
            // Only append a space if the last element in res is not a space
            if (!res.get(res.size() - 1).equals(" ")) {
                res.add(s.charAt(i) + "");
            } else {
                continue;  // Skip if the last element is already a space
            }
        } else {
            // If the current character is a punctuation mark
            if (Arrays.asList(punctuation).contains(s.charAt(i) + "")) {
                // If the last element in res is a space, remove it
                if (res.get(res.size() - 1).equals(" ")) {
                    res.remove(res.size() - 1);
                }
                // Append the punctuation mark to the result
                res.add(s.charAt(i) + "");
                // Append a space after the punctuation
                res.add(" ");
            } else {
                // If the current character is not punctuation, append it to the result
                res.add(s.charAt(i) + "");
            }
        }
    } else {
        // For the first character, handle it separately
        if (s.charAt(i) =='') {
            continue;  // Skip if it's a space
        }
        if (Arrays.asList(punctuation).contains(s.charAt(i) + "")) {
            continue;  // Skip if it's a punctuation mark
        } else {
            // Append the first character to the result if it's not a space or punctuation
            res.add(s.charAt(i) + "");
        }
    }
}

// Join the list into a single string and print the result
System.out.println(String.join("", res));
