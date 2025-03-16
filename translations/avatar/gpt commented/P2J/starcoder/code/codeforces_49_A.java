// Take input from the user
String a = sc.next();

// Define a list of vowels (both lowercase and uppercase)
List<String> vo = new ArrayList<String>();
vo.add("a");
vo.add("e");
vo.add("i");
vo.add("o");
vo.add("u");
vo.add("y");
vo.add("A");
vo.add("E");
vo.add("I");
vo.add("O");
vo.add("U");
vo.add("Y");

// Iterate through the input string in reverse order
for (int i = a.length() - 1; i >= 0; i--) {
    // Check if the current character is a space or a question mark
    if (a.charAt(i) =='' || a.charAt(i) == '?') {
        continue; // Skip to the next iteration if it is a space or '?'
    } else {
        // Check if the current character is a vowel
        if (vo.contains(a.charAt(i) + "")) {
            System.out.println("YES"); // Print "YES" if it is a vowel
        } else {
            System.out.println("NO"); // Print "NO" if it is not a vowel
        }
        break; // Exit the loop after processing the first non-space character
}

