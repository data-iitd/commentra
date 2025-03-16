import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int hcell, wcell, hpaint, wpaint, nblack, nwhite;
        
        // Read the number of cells in height and width
        hcell = scanner.nextInt();
        wcell = scanner.nextInt();
        
        // Read the height and width of the painted area
        hpaint = scanner.nextInt();
        wpaint = scanner.nextInt();
        
        // Calculate the number of black and white cells
        nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);
        nwhite = (hcell * wcell) - nblack;
        
        // Print the number of white cells
        System.out.println(nwhite);
        
        scanner.close();
    }
}

// <END-OF-CODE>
