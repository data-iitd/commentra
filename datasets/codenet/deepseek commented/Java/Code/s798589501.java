import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
    
    // Create a Scanner object to read input from the user
    Scanner s = new Scanner(System.in);
    
    // Read the era (E) and the year (Y) from the user
    int E = s.nextInt();   
    int Y = s.nextInt();

    // Check the value of E and perform actions based on its value
    if (E == 0){
        // Determine the era and print the corresponding era character and the adjusted year
        if (Y <= 1911){
            System.out.print("M");
            System.out.println(Y - 1867);
        }else if(Y <= 1925){
            System.out.print("T");
            System.out.println(Y - 1911);
        }else if(Y <= 1988){
            System.out.print("S");
            System.out.println(Y - 1925);
        }else{
            System.out.print("H");
            System.out.println(Y - 1988);
        }
    } else if(E == 1){
        // Print the year in the Meiji era
        System.out.println(1867 + Y);
    } else if(E == 2){
        // Print the year in the Taisho era
        System.out.println(1911 + Y);
    } else if(E == 3){
        // Print the year in the Showa era
        System.out.println(1925 + Y);
    } else{
        // Print the year in the Heisei era
        System.out.println(1988 + Y);
    }
}
}
