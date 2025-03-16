
// Take user input as a string's'
Scanner sc = new Scanner(System.in);
String s = sc.nextLine();

// Initialize an empty list'res' to store the final result
List<String> res = new ArrayList<>();

// Define a list 'punctuation' containing all the punctuation marks
List<String> punctuation = Arrays.asList(",", ".", "!", "?");

// Iterate through each character 'i' in the string's'
for (int i = 0; i < s.length(); i++) {

    // If current character is a space and previous character is not empty,
    // append the space to the result list
    if (i >= 1) {
        if (s.charAt(i) =='') {
            if (!res.get(res.size() - 1).equals("")) {
                // Append space to the result list
                res.add(s.charAt(i) + "");
            } else {
                continue;
            }
        }
    }

    // If current character is not a space and is a punctuation mark,
    // check if the previous character is empty, if yes then pop the last character from the result list
    // and append the current punctuation mark along with an empty string
    else if (punctuation.contains(s.charAt(i) + "")) {
        if (res.get(res.size() - 1).equals("")) {
            res.remove(res.size() - 1);
            res.add(s.charAt(i) + "");
            res.add("");
        } else {
            res.add(s.charAt(i) + "");
        }
    }

    // If current character is not a space and is not a punctuation mark,
    // simply append it to the result list
    else {
        res.add(s.charAt(i) + "");
    }
}

// Join all the elements of the result list and print the final string
System.out.println(String.join("", res));
