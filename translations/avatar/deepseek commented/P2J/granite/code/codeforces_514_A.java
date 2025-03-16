

Scanner sc = new Scanner(System.in);  // Creating a Scanner object to read input from the user.
String ip = sc.nextLine();  // Reading the input from the user and storing it in the variable `ip`.
String st = "";  // Initializing an empty string `st`.
if (ip.length()!= 1) {  // Checking if the length of `ip` is not equal to 1.
    if (ip.charAt(0) == '9') {  // Checking if the first character of `ip` is "9".
        st = "9";  // Assigning "9" to `st`.
        ip = ip.substring(1);  // Removing the first character from `ip`.
    }
    for (int i = 0; i < ip.length(); i++) {  // Iterating over the remaining characters in `ip`.
        if (Character.getNumericValue(ip.charAt(i)) > 4) {  // Checking if the numeric value of the character is greater than 4.
            int n = 9 - Character.getNumericValue(ip.charAt(i));  // Calculating the difference between 9 and the numeric value.
            st += n;  // Appending the difference to `st`.
        } else {  // If the numeric value is not greater than 4.
            st += ip.charAt(i);  // Simply appending the character to `st`.
        }
    }
} else {  // If the length of `ip` is 1.
    st = ip;  // Assigning `ip` directly to `st`.
}
System.out.println(Integer.parseInt(st));  // Printing the integer value of `st`.
