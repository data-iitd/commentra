public class ReverseString {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String str = scanner.next();
        
        int len = str.length();
        
        for (int i = len - 1; i >= 0; i--) {
            System.out.print(str.charAt(i));
        }
        System.out.println();
    }
}
