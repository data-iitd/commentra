import java.util.*;

public class HelloWorld {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int height = in.nextInt();
        int width = in.nextInt();
        String input_str = in.next();
        for(int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();
        for(int i = 0; i < height; i++) {
            System.out.printf("#%s#\n", input_str);
        }
        for(int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();
    }
}
