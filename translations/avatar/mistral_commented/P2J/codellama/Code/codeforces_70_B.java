
// Importing the regular expression module for splitting the input string
import java.util.regex.Pattern;
import java.util.regex.Matcher;

// Taking the number of sentences n as input
int n = Integer.parseInt(input.nextLine());

// Initializing the answer counter ans and the sum of lengths of sentences sumL
int ans = 1, sumL = 0;

// Loop to split the input string into sentences based on punctuation marks
String[] sentences = input.nextLine().split("[.?!]");
for (String s : sentences) {
    // Stripping leading and trailing whitespaces from the sentence s
    s = s.trim();
    // Adding a dot at the end of the sentence if it doesn't already have one
    s += '.';

    // Calculating the length L of the sentence s
    int L = s.length();

    // Checking if the length of the sentence is greater than the number of sentences n
    if (L > n) {
        // Printing an error message and exiting the program if the condition is true
        System.out.println("Impossible");
        System.exit(0);
    }

    // Checking if the sum of lengths of all previous sentences and the current sentence is greater than n
    if (sumL + L + (sumL > 0)) {
        // Incrementing the answer counter ans if the condition is true
        ans++;
        // Updating the sum of lengths sumL with the length of the current sentence
        sumL = L;
    } else {
        // Updating the sum of lengths sumL with the length of the current sentence and the previous sentence's length if any
        sumL = sumL + L + (sumL > 0);
    }
}

// Printing the final answer
System.out.println(ans);

