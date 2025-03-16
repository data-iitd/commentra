
public class Main {
    public static void main(String[] args) {
        char[] str = new char[30];
        System.out.println("Enter a string: ");
        String input = new Scanner(System.in).nextLine();
        for (int i = 0; i < input.length(); i++) {
            str[i] = input.charAt(i);
        }
        str[5] = ' ';
        str[13] = ' ';
        System.out.println(str);
    }
}

