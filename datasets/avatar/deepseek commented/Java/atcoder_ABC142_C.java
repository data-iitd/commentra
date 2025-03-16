import java.util.* ; 

public class Main { 
    public static List < Integer > P ; 

    public static void main ( String args [ ] ) { 
        // Step 1: Read the input value N, which represents the number of elements.
        Scanner scanner = new Scanner ( System.in ) ; 
        int N = scanner.nextInt ( ) ; 

        // Step 2: Create a map idorder to store the elements and their corresponding positions.
        Map < Integer , Integer > idorder = new HashMap < > ( ) ; 

        // Step 3: Read each element and store its value and position in the map.
        for ( int i = 1 ; i <= N ; i ++ ) { 
            int A = scanner.nextInt ( ) ; 
            idorder.put ( A , i ) ; 
        } 

        // Step 4: Print the positions of the elements in the order they were read.
        for ( int i = 1 ; i <= N ; i ++ ) { 
            System.out.print ( idorder.get ( i ) ) ; 
            System.out.print ( " " ) ; 
        } 
    } 
}