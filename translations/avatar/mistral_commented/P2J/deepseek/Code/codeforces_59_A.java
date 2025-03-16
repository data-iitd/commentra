public class Main {
    public static void main(String[] args) {
        // Get the text input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String txt = scanner.nextLine();

        // Initialize the count of uppercase and lowercase characters
        int cu = 0;
        int cl = 0;

        // Iterate through each character in the text input
        for (char z : txt.toCharArray()) {
            // If the character is lowercase, increment the lowercase count
            if (Character.isLowerCase(z)) {
                cl += 1;
            }
            // If the character is uppercase, increment the uppercase count
            else {
                cu += 1;
            }
        }

        // Determine the output based on the count of uppercase and lowercase characters
        if (cu > cl) {
            // If there are more uppercase characters than lowercase characters, convert the entire text to uppercase
            String out = txt.toUpperCase();
            System.out.println(out);
        } else {
            // If there are more lowercase characters than uppercase characters, convert the entire text to lowercase
            String out = txt.toLowerCase();
            System.out.println(out);
        }
    }
}
