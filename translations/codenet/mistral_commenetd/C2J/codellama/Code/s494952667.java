
public class ReverseString {
    public static void main(String[] args) {
        String str = "Enter a string: ";
        int len = str.length();
        System.out.print("Reversed string: ");
        for (int i = len - 1; i >= 0; i--) {
            System.out.print(str.charAt(i));
        }
        System.out.println();
    }
}

