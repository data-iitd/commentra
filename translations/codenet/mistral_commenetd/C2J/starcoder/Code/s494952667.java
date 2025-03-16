import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = sc.next();
        int len = str.length();
        System.out.print("Reversed string: ");
        for(int i = len-1; i >= 0; i--){
            System.out.print(str.charAt(i));
        }
        System.out.println();
    }
}
