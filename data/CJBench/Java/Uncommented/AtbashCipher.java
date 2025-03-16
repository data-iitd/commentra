
import java.util.Scanner;
public class AtbashCipher {
    private String toConvert;
    public AtbashCipher() {
    }
    public AtbashCipher(String str) {
        this.toConvert = str;
    }
    public String getString() {
        return toConvert;
    }
    public void setString(String str) {
        this.toConvert = str;
    }
    private boolean isCapital(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }
    private boolean isSmall(char ch) {
        return ch >= 'a' && ch <= 'z';
    }
    public String convert() {
        StringBuilder convertedString = new StringBuilder();
        for (char ch : toConvert.toCharArray()) {
            if (isSmall(ch)) {
                convertedString.append((char) ('z' - (ch - 'a')));
            } else if (isCapital(ch)) {
                convertedString.append((char) ('Z' - (ch - 'A')));
            } else {
                convertedString.append(ch);
            }
        }
        return convertedString.toString();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputText = scanner.nextLine();
        AtbashCipher cipher = new AtbashCipher(inputText);
        String result = cipher.convert();
        System.out.println("Converted Text: " + result);
        scanner.close();
    }
}
