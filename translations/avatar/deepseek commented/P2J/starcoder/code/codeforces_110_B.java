
LUCKY = "abcd"
// Define a string LUCKY containing the characters "abcd"

n = Integer.parseInt(input());
// Take an integer input n from the user

String s = "";
// Initialize an empty string s to store the result

for (int i = 0; i < n; i++) {
    // Loop n times to construct the string s
    s += LUCKY.charAt(i % 4);
    // Append a character from LUCKY to s based on the index i modulo 4
}

System.out.println(s);
// Print the final string s

