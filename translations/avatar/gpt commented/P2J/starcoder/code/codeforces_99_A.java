// Read input from the user
String l = scanner.nextLine();

// Split the input string into two parts using '.' as the delimiter
String[] l = l.split("\\.");

// Convert the first part of the input into a list of characters
List<Character> s = new ArrayList<>();
for (char c : l[0].toCharArray()) {
    s.add(c);
}

// Convert the second part of the input into a list of characters
List<Character> p = new ArrayList<>();
for (char c : l[1].toCharArray()) {
    p.add(c);
}

// Extract the first character from the second part and convert it to an integer
int i = Integer.parseInt(p.get(0).toString());

// Check if the last character of the first part is '9'
if (s.get(s.size() - 1) == '9') {
    // If it is '9', print the message "GOTO Vasilisa."
    System.out.println("GOTO Vasilisa.");
}
// Check if the last character is not '9' and the integer i is less than 5
else if (s.get(s.size() - 1)!= '9' && i < 5) {
    // If both conditions are true, join the list of characters into a string and print it
    StringBuilder sb = new StringBuilder();
    for (char c : s) {
        sb.append(c);
    }
    System.out.println(sb.toString());
}
else {
    // If the last character is not '9' and i is 5 or more
    // Join the list of characters into a string, convert it to an integer, increment it by 1, and convert it back to a string
    StringBuilder sb = new StringBuilder();
    for (char c : s) {
        sb.append(c);
    }
    int n = Integer.parseInt(sb.toString());
    n++;
    System.out.println(n);
}

