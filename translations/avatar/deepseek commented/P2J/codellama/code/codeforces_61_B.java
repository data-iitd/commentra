import java.io.*;
import java.util.*;
import java.math.*;

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
public static boolean valid ( int i , int j , int n , int m ) {
    if ( i < n && i >= 0 && j >= 0 && j < m ) return true;
    return false;
}

// Function to calculate the sum of an arithmetic series from i to n
public static int sumn ( int i , int n ) {
    return ( n - i ) * ( i + n ) / 2;
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
public static double sqfun ( double a , double b , double c ) {
    return ( - b + Math.sqrt ( b * b - 4 * a * c ) ) / 2 * a;
}

// Function to read a single or multiple integer values from input
public static int[] value ( ) {
    return Arrays.stream ( input ( ).split ( " " ) ).mapToInt ( Integer::parseInt ).toArray ( );
}

// Function to read a single or multiple integer values from standard input
public static int[] values ( ) {
    return Arrays.stream ( new BufferedReader ( new InputStreamReader ( System.in ) ).readLine ( ).split ( " " ) ).mapToInt ( Integer::parseInt ).toArray ( );
}

// Function to read a list of integers from input
public static List<Integer> inlst ( ) {
    return Arrays.stream ( input ( ).split ( " " ) ).map ( Integer::parseInt ).collect ( Collectors.toList ( ) );
}

// Function to read a list of integers from standard input
public static List<Integer> inlsts ( ) {
    return Arrays.stream ( new BufferedReader ( new InputStreamReader ( System.in ) ).readLine ( ).split ( " " ) ).map ( Integer::parseInt ).collect ( Collectors.toList ( ) );
}

// Function to read a single integer from input
public static int inp ( ) {
    return Integer.parseInt ( input ( ) );
}

// Function to read a single integer from standard input
public static int inps ( ) {
    return Integer.parseInt ( new BufferedReader ( new InputStreamReader ( System.in ) ).readLine ( ) );
}

// Function to read a string from input
public static String instr ( ) {
    return input ( );
}

// Function to split a string into a list of words
public static List<String> stlst ( ) {
    return Arrays.stream ( input ( ).split ( " " ) ).collect ( Collectors.toList ( ) );
}

// Function to sanitize a string by converting it to lowercase and removing certain characters
public static String f ( String s ) {
    String r = "";
    for ( int i = 0 ; i < s.length ( ) ; i++ ) {
        if ( s.charAt ( i ) != '-' && s.charAt ( i ) != ';' && s.charAt ( i ) != '_' ) r += s.charAt ( i ).toLowerCase ( );
    }
    return r;
}

// Main logic of the program
public static void solve ( ) {
    List<String> l = new ArrayList<> ( );
    for ( int i = 0 ; i < 3 ; i++ ) {
        l.add ( f ( input ( ) ) );
    }
    Iterator<String> t = new Permutations ( l ).iterator ( );
    l = new ArrayList<> ( );
    while ( t.hasNext ( ) ) {
        l.add ( t.next ( ) );
    }
    for ( int i = 0 ; i < inp ( ) ; i++ ) {
        if ( f ( instr ( ) ).equals ( l.get ( i ) ) ) System.out.println ( "ACC" );
        else System.out.println ( "WA" );
    }
}

public static void main ( String[] args ) {
    solve ( );
}

