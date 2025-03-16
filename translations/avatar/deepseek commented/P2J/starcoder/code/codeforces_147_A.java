s = input();  // Take input string from user
res = new ArrayList<Character>();  // Initialize an empty list to store the result
punctuation = new char[] {',', '.', '!', '?'};  // Define a list of punctuation marks

// Iterate over each character in the input string
for (int i = 0; i < s.length(); i++) {
    if (i >= 1) {  // Check if it's not the first character
        if (s.charAt(i) =='') {  // Check if the current character is a space
            if (res.get(res.size() - 1)!='') {  // Check if the last character in res is not a space
                res.add(s.charAt(i));  // Append the current space to res
            } else {
                continue;  // Skip the current space if the last character is also a space
            }
        } else {  // If the current character is not a space
            if (Arrays.asList(punctuation).contains(s.charAt(i))) {  // Check if the current character is a punctuation mark
                if (res.get(res.size() - 1) =='') {  // Check if the last character in res is a space
                    res.remove(res.size() - 1);  // Remove the last character (space) from res
                }
                res.add(s.charAt(i));  // Append the punctuation mark to res
                res.add(' ');  // Append a space after the punctuation mark
            } else {
                res.add(s.charAt(i));  // Append the character to res if it's not a punctuation mark
            }
        }
    } else {  // For the first character
        if (s.charAt(i) =='') {  // Check if the first character is a space
            continue;  // Skip the first space
        }
        if (Arrays.asList(punctuation).contains(s.charAt(i))) {  // Check if the first character is a punctuation mark
            continue;  // Skip the first punctuation mark
        } else {
            res.add(s.charAt(i));  // Append the first character to res
        }
    }
}

// Join the list res into a string and print it
System.out.println(String.valueOf(res));

