public class ReverseString {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = scanner.nextLine();

        int len = str.length();

        System.out.print("Reversed string: ");

        for (int i = len - 1; i >= 0; i--) {
            System.out.print(str.charAt(i));
        }

        System.out.println();
    }
}
