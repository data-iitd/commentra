public class Main {
    public static void main(String[] args) {
        // Take user input as a string 's'
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize an empty list 'res' to store the final result
        java.util.List<String> res = new java.util.ArrayList<>();

        // Define a list 'punctuation' containing all the punctuation marks
        java.util.List<String> punctuation = java.util.Arrays.asList(",", ".", "!", "?");

        // Iterate through each character 'i' in the string 's'
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);

            // If current character is a space and previous character is not empty,
            // append the space to the result list
            if (currentChar == ' ' && i >= 1) {
                if (i < s.length() && s.charAt(i - 1) != ' ') {
                    res.add(" ");
                }
            }

            // If current character is not a space and is a punctuation mark,
            // check if the previous character is empty, if yes then remove the last character from the result list
            // and append the current punctuation mark along with an empty string
            else if (punctuation.contains(String.valueOf(currentChar))) {
                if (res.size() > 0 && res.get(res.size() - 1).equals("")) {
                    res.remove(res.size() - 1);
                    res.add(String.valueOf(currentChar));
                    res.add("");
                } else {
                    res.add(String.valueOf(currentChar));
                }
            }

            // If current character is not a space and is not a punctuation mark,
            // simply append it to the result list
            else {
                res.add(String.valueOf(currentChar));
            }
        }

        // Join all the elements of the result list and print the final string
        StringBuilder resultString = new StringBuilder();
        for (String str : res) {
            resultString.append(str);
        }
        System.out.println(resultString.toString());
    }
}
