public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();
        // Replace all occurrences of "2017" with "2018" in the string 's' and print the result.
        String result = s.replace("2017", "2018");
        System.out.println(result);
    }
}
