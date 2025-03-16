
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        
        // Step 1: Read the input value `n` which represents the number of elements.
        Integer n = Integer.valueOf ( sc.nextLine ( ) ) ; 
        
        // Step 2: Read the values of `v` (values) and store them in a list `vList`.
        String vStr = sc.nextLine ( ) ; 
        Map < Integer , Integer > vList = str2List ( vStr ) ; 
        
        // Step 3: Read the values of `c` (costs) and store them in a list `cList`.
        String cStr = sc.nextLine ( ) ; 
        Map < Integer , Integer > cList = str2List ( cStr ) ; 
        
        // Step 4: Initialize a variable `max` to keep track of the maximum profit.
        Integer max = 0 ; 
        
        // Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
        for ( Integer i = 0 ; i < n ; i ++ ) { 
            Integer profit = vList.get ( i ) - cList.get ( i ) ; 
            if ( profit > 0 ) { 
                max += profit ; 
            } 
        } 
        
        // Step 6: Print the maximum profit.
        System.out.println ( max ) ; 
    } 
    
    // Helper method to convert a string of space-separated integers into a map with index as key and integer value as value.
    static Map < Integer , Integer > str2List ( String str ) { 
        String [ ] vArrStr = str.split ( " " ) ; 
        Map < Integer , Integer > ret = new HashMap < > ( ) ; 
        Integer key = 0 ; 
        for ( String val : vArrStr ) { 
            ret.put ( key , Integer.valueOf ( val ) ) ; 
            key ++ ; 
        } 
        return ret ; 
    } 
}

