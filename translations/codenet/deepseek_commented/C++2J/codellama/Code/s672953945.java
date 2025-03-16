//#include<bits/stdc++.h>
import java.util.*;
import java.lang.*;
import java.io.*;

/*
#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Bint = mp::cpp_int;
*/

class Solution {
    public static void main(String[] args) {
        // Vector to store strings and variables to store N and L
        ArrayList<String> v = new ArrayList<String>();
        int N,L;

        // Read the number of strings N and the length L from the standard input
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();

        // Read N strings from the standard input and store them in the vector v
        for(int i=0;i<N;i++){
            String s = sc.next();
            v.add(s);
        }

        // Sort the vector v in lexicographical order
        Collections.sort(v);

        // Concatenate and print the sorted strings without spaces
        for(int i=0;i<v.size();i++){
            System.out.print(v.get(i));
        }
        System.out.println();
    }
}

