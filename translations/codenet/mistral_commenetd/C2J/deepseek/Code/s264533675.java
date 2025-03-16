public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String str = scanner.nextLine();

        char[] charArray = str.toCharArray();
        charArray[5] = ' ';
        charArray[13] = ' ';

        System.out.println(new String(charArray));
    }
}
