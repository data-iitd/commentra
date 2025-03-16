public class AbbreviateString {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.next();
        String t = s.charAt(0) + "" + (s.length() - 2) + s.charAt(s.length() - 1);
        System.out.println(t);
    }
}
