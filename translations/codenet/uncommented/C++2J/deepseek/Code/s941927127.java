public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String W = scanner.nextLine();
        
        char[] charArray = W.toCharArray();
        java.util.Arrays.sort(charArray);
        
        for (int i = 0; i < charArray.length; i += 2) {
            if (i + 1 >= charArray.length || charArray[i] != charArray[i + 1]) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
