import json
import os
from abc import ABC, abstractmethod
from typing import List
from warnings import warn
import glob
from transformers import PreTrainedTokenizerFast


'''
# approaches in compose_prompt
# -EOS debugging and clean
    <END-OF-CODE>
# could be multiple eos in outputs, better pick minimum one
# class HFTorchDecoder(DecoderBase):
    -starcoder (StarCoderInfill  or VLlmDecoder())

-granite models-
    -llama and starcoder similar 
    -EOS - <|endoftext|>
    -VLlmDecoder like codellama ?

self.context_window_length =max_length #4090
'''

# cache_dir = os.getcwd() + "/huggingface"
cache_dir = "/home/codetrans/Project"+ "/huggingface"
os.environ["TRANSFORMERS_CACHE"] = cache_dir

import anthropic
import anthropic_request
import google.generativeai as genai

import openai
import torch
from transformers import (
    AutoModelForCausalLM,
    AutoModelForSeq2SeqLM,
    AutoTokenizer,
    StoppingCriteria,
    StoppingCriteriaList,
)
from openai_request import make_auto_request
from vllm import LLM, SamplingParams

EOS = ["<|endoftext|>", "<|endofmask|>", "</s>","<END-OF-CODE>",("\n"*11)]

#J2P
EOS.append("4. Java")
EOS.append("###$###")

# P2J
# EOS+=["###$###"]
EOS+=["4. Python"]

# function to build prompt accroding to various model instruction formats
def compose_prompt(model:str, prompt_type: str, source_lang: str, target_lang: str, code: str) -> str:

    # base 
    # prompt = f'''{source_lang}:\n{code}\n\nTranslate the above {source_lang} code to {target_lang} and end with comment \"<END-OF-CODE>\".\n\n{target_lang}:\n'''

    if model == "DeepSeek-Coder-V2-Lite-Instruct":
        prompt = f"{source_lang}:\n{code}\n\nTranslate the above {source_lang} code to {target_lang}."

    else:
        prompt = f'''{source_lang}:\n{code}\n\nTranslate the above {source_lang} code to {target_lang} and end with comment \"<END-OF-CODE>\".\n\n{target_lang}:\n'''
    
    # prompt = f"{source_lang}:\n{code}\n\nGenerate comments in the above {source_lang} code."
    #use source_lang cond with autocot2d
    #final_v1_1 similar to v1 
    if prompt_type=="autocot2d" and source_lang=="Python":#autocot2d_p2j
        prompt='''###$###
1. Python Code:
l = [ ]
limit = 10000000000
def gen ( number , four , seven ) :
    global debug
    debug = True
    status = "bad"
    if ( number > limit ) :
        return
    if ( number > 0 and four == seven ) :
        l.append ( number )
    gen ( number * 10 + 4 , four + 1 , seven )
    gen ( number * 10 + 7 , four , seven + 1 )

debug= False
status = "good"
def main ( ) :
    gen ( 0 , 0 , 0 )
    l.sort ( )
    n = int ( input ( ) )
    ans = 0
    for val in l :
        if ( val >= n ) :
            ans = val
            break
    print ( ans )

1. Sample Input:
9

1. Expected Output:
47


1. Steps: Let's think step by step.

Step 1: First of all identify global variables and their types. Global variables are variables that are not inside scope of function and class declarations, present in the above Python Code-
Global variables: l, limit, debug, status

Step 2: Identify classes and functions declarations present in the above Python Code-
Identified classes and functions declarations in the Python code:
def gen ( number , four , seven ) :

def main ( ) :

Step 3: Considering Step 1 and Step 2, the corresponding Java Code should have declarations of these classes, functions and Global variables -
Identified classes, functions and Global variables declarations in the Java code:
public class Main {
    static ArrayList<Long> l;
    static long limit;
    static boolean debug;
    static String status;

    public static void gen(long number, int four, int seven);

    public static void main ( String [ ] args );

}

Step 4: Complete translation of the above Python code to Java code by considering identified classes, functions and Global variables declarations in Step 3. Consider above sample input and output format information to handle input and output related code properly in the generated Java code. While generating the Java code, keep track of required library imports to be added in the Java Code. Make sure your generated code is syntactically correct-
1. Java Code:
import java.util.*;

public class Main{
    static ArrayList<Long> l;
    static long limit;
    static boolean debug;
    static String status;

    public static void gen(long number, int four, int seven) {
        Main.debug = True;
        String status = "bad";
        if (number > limit) return;
        if (number > 0 && four == seven) {
            l.add(number);
        }
        gen(number * 10 + 4, four + 1, seven);
        gen(number * 10 + 7, four, seven + 1);
    }

    public static void main(String[] args) {
        l = new ArrayList<>();
        limit = 10000000000L;
        debug= False;
        status = "good";

        gen(0, 0, 0);
        Collections.sort(l);
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long ans = 0;
        for (long val : l) {
            if (val >= n) {
                ans = val;
                break;
            }
        }
        System.out.println(ans);
    }
}

###$###
2. Python Code:
class BIT :
    def __init__ ( self , N ) :
        self.size = N
        self.tree = [ 0 ] * ( N + 1 )
        self.depth = n.bit_length ( )
    def _bitsum ( self , i ) :
        ret = 0
        while i :
            ret += self.tree [ i ]
            i ^= i & - i
        return ret
    def bitsum ( self , l , r = None ) :
        if r is None :
            return self._bitsum ( l )
        else :
            return self._bitsum ( r ) - self._bitsum ( l )
    def bitadd ( self , i , x ) :
        i += 1
        while i <= self.size :
            self.tree [ i ] += x
            i += i & - i
        return
n = int ( input ( ) )
m = n * ( n + 1 ) // 4
a = list ( map ( int , input ( ).split ( ) ) )
d = dict ( )
_a = sorted ( set ( a + [ 0 ] ) )
for i , x in enumerate ( _a ) :
    d [ x ] = i
a = [ d [ x ] for x in a ]
def check ( X ) :
    b = [ 0 ] + [ ( y >= X ) * 2 - 1 for y in a ]
    for i in range ( n ) :
        b [ i + 1 ] += b [ i ]
    c = min ( b )
    b = [ x - c for x in b ]
    bit = BIT ( max ( b ) + 2 )
    ans = 0
    for x in b :
        ans += bit.bitsum ( x + 1 )
        bit.bitadd ( x , 1 )
    return ans >= m
t = [ len ( _a ) , 0 ]
while t [ 0 ] - t [ 1 ] > 1 :
    mid = ( t [ 0 ] + t [ 1 ] ) // 2
    t [ check ( mid ) ] = mid
print ( _a [ t [ 1 ] ] )

2. Sample Input:
1
1

2. Expected Output:
1


2. Steps: Let's think step by step.

Step 1: First of all identify global variables and their types. Global variables are variables that are not inside scope of function and class declarations, present in the above Python Code-
Global variables: n, m, a, d, _a, t

Step 2: Identify classes and functions declarations present in the above Python Code-
Identified classes and functions declarations in the Python code:
class BIT :
    def __init__ ( self , N ) :
        self.size = N
        self.tree = [ 0 ] * ( N + 1 )
        self.depth = N.bit_length ( )

    def _bitsum ( self , i ) :

    def bitsum ( self , l , r = None ) :

    def bitadd ( self , i , x ) :

def check ( X ) :


Step 3: Considering Step 1 and Step 2, the corresponding Java Code should have declarations of these classes, functions and Global variables -
Identified classes, functions and Global variables declarations in the Java code:
public class Main {
    static int n;
    static long m;
    static int[] a;
    static Map<Integer, Integer> d;
    static List<Integer> _a;
    static int[] t;

    public static class BIT {
        public int size;
        public long [] tree;
        public int depth;

        public BIT(int N);

        public long _bitsum(int i);

        public long bitsum(int l, int r);

        public long bitsum(int l);

        public void bitadd(int i, int x);

        }

    public static boolean check(int X);

    public static void main ( String [ ] args );

}

Step 4: Complete translation of the above Python code to Java code by considering identified classes, functions and Global variables declarations in Step 3. Consider above sample input and output format information to handle input and output related code properly in the generated Java code. While generating the Java code, keep track of required library imports to be added in the Java Code. Make sure your generated code is syntactically correct-
2. Java Code:
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main{
    static int n;
    static long m;
    static int[] a;
    static Map<Integer, Integer> d;
    static List<Integer> _a;
    static int[] t;

    public static class BIT {
        public int size;
        public long [] tree;
        public int depth;

        public BIT(int N) {
            this.size = N;
            this.tree = new long[N + 1];
            this.depth = Integer.toBinaryString(N).length();
        }

        public long _bitsum(int i) {
            long ret = 0;
            while (i > 0) {
                ret += this.tree[i];
                i ^= i & -i;
            }
            return ret;
        }

        public long bitsum(int l, int r) {
            return this._bitsum(r) - this._bitsum(l);
        }

        public long bitsum(int l) {
            return this._bitsum(l);
        }

        public void bitadd(int i, int x) {
            i += 1;
            while (i <= this.size) {
                this.tree[i] += x;
                i += i & -i;
            }
            return;
        }
    }


    public static boolean check(int X) {
        int[] b = new int[n + 1];
        b[0] = 0;
        for (int i = 0; i < n; i++) {
            b[i + 1] = (a[i] >= X ? 2 : 0) - 1;
        }
        for (int i = 0; i < n; i++) {
            b[i + 1]+= b[i];
        }
        int c = Arrays.stream(b).min().getAsInt();
        for (int i = 0; i < b.length; i++) {
            b[i] -= c;
        }
        BIT bit = new BIT(Arrays.stream(b).max().getAsInt() + 2);
        long ans = 0;
        for (int x : b) {
            ans += (long) bit.bitsum(x + 1);
            bit.bitadd(x, 1);
        }
        return ans >= m;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = (long) n * (n + 1) / 4;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        d = new HashMap<>();
        Set<Integer> set = new HashSet<>();
        for (int x : a) {
            set.add(x);
        }
        set.add(0);
        _a = new ArrayList<>(set);
        Collections.sort(_a);
        for (int i = 0; i < _a.size(); i++) {
            d.put(_a.get(i), i);
        }
        for (int i = 0; i < a.length; i++) {
            a[i] = d.get(a[i]);
        }

        t = new int[]{ _a.size(), 0 };

        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2;
            if (check(mid)) {
                t[1] = mid;
            } else {
                t[0] = mid;
            }
        }
        System.out.println(_a.get(t[1]));
    }
}

###$###
3. Python Code:
'''
        prompt+=code
    if prompt_type=="autocot2d_p2j_v4":#imp formulation with type -final_v3
        prompt='''###$###
1. Python Code:
l = [ ]
limit = 10000000000
def gen ( number , four , seven ) :
    global debug
    debug = True
    status = "bad"
    if ( number > limit ) :
        return
    if ( number > 0 and four == seven ) :
        l.append ( number )
    gen ( number * 10 + 4 , four + 1 , seven )
    gen ( number * 10 + 7 , four , seven + 1 )

debug= False
status = "good"
def main ( ) :
    gen ( 0 , 0 , 0 )
    l.sort ( )
    n = int ( input ( ) )
    ans = 0
    for val in l :
        if ( val >= n ) :
            ans = val
            break
    print ( ans )

1. Sample Input:
9

1. Expected Output:
47


1. Steps: Let's think step by step.

Step 1: First of all identify global variables. Global variables are variables that are in global scope and not inside scope of any function and class present in the above Python Code-
Global variables: l, limit, debug, status

Step 2: Identify declarations of classes and functions present in the above Python Code-
Identified declarations of classes and functions in the Python code:
def gen ( number , four , seven ) :

def main ( ) :

Step 3: By considering above Step 1 and Step 2, identify declarations of these classes, functions and Global variables should be presented in the corresponding Java Code-
Identified declarations of classes, functions and Global variables in the Java code:
public class Main {
    static ArrayList<Long> l;
    static long limit;
    static boolean debug;
    static String status;
    
    public static void gen(long number, int four, int seven);

    public static void main ( String [ ] args );
}

Step 4: Complete translation of the above Python code to Java code by filling definitions of identified declarations of classes, functions and Global variables in Step 3. Consider above sample input and output format information to handle input and output related code properly in the generated Java code. While generating the Java code, keep track of required library imports to be added in the Java Code. Make sure your generated code is syntactically correct-
1. Java Code:
import java.util.*;

public class Main{
    static ArrayList<Long> l;
    static long limit;
    static boolean debug;
    static String status;

    public static void gen(long number, int four, int seven) {
        Main.debug = True;
        String status = "bad";
        if (number > limit) return;
        if (number > 0 && four == seven) {
            l.add(number);
        }
        gen(number * 10 + 4, four + 1, seven);
        gen(number * 10 + 7, four, seven + 1);
    }

    public static void main(String[] args) {
        l = new ArrayList<>();
        limit = 10000000000L;
        debug= False;
        status = "good";

        gen(0, 0, 0);
        Collections.sort(l);
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long ans = 0;
        for (long val : l) {
            if (val >= n) {
                ans = val;
                break;
            }
        }
        System.out.println(ans);            
    }  
}

###$###
2. Python Code:
class BIT :
    def __init__ ( self , N ) :
        self.size = N
        self.tree = [ 0 ] * ( N + 1 )
        self.depth = n.bit_length ( )
    def _bitsum ( self , i ) :
        ret = 0
        while i :
            ret += self.tree [ i ]
            i ^= i & - i
        return ret
    def bitsum ( self , l , r = None ) :
        if r is None :
            return self._bitsum ( l )
        else :
            return self._bitsum ( r ) - self._bitsum ( l )
    def bitadd ( self , i , x ) :
        i += 1
        while i <= self.size :
            self.tree [ i ] += x
            i += i & - i
        return
n = int ( input ( ) )
m = n * ( n + 1 ) // 4
a = list ( map ( int , input ( ).split ( ) ) )
d = dict ( )
_a = sorted ( set ( a + [ 0 ] ) )
for i , x in enumerate ( _a ) :
    d [ x ] = i
a = [ d [ x ] for x in a ]
def check ( X ) :
    b = [ 0 ] + [ ( y >= X ) * 2 - 1 for y in a ]
    for i in range ( n ) :
        b [ i + 1 ] += b [ i ]
    c = min ( b )
    b = [ x - c for x in b ]
    bit = BIT ( max ( b ) + 2 )
    ans = 0
    for x in b :
        ans += bit.bitsum ( x + 1 )
        bit.bitadd ( x , 1 )
    return ans >= m
t = [ len ( _a ) , 0 ]
while t [ 0 ] - t [ 1 ] > 1 :
    mid = ( t [ 0 ] + t [ 1 ] ) // 2
    t [ check ( mid ) ] = mid
print ( _a [ t [ 1 ] ] )

1. Sample Input:
1
1

1. Expected Output:
1


1. Steps: Let's think step by step.

Step 1: First of all identify global variables. Global variables are variables that are in global scope and not inside scope of any function and class present in the above Python Code-
Global variables: n, m, a, d, _a, t

Step 2: Identify declarations of classes and functions present in the above Python Code-
Identified declarations of classes and functions in the Python code:
class BIT :
    def __init__ ( self , N ) :
        self.size = N
        self.tree = [ 0 ] * ( N + 1 )
        self.depth = N.bit_length ( )
        
    def _bitsum ( self , i ) :

    def bitsum ( self , l , r = None ) :

    def bitadd ( self , i , x ) :

def check ( X ) :

Step 3: By considering above Step 1 and Step 2, identify declarations of these classes, functions and Global variables should be presented in the corresponding Java Code-
Identified declarations of classes, functions and Global variables in the Java code:
public class Main {
    static int n;
    static long m;
    static List<Integer> a;
    static Map<Integer, Integer> d;
    static List<Integer> _a;
    static int[] t;

    public static class BIT {
        public int size;
        public long [] tree;
        public int depth;

        public BIT(int N);

        public long _bitsum(int i);

        public long bitsum(int l, int r);
    
        public long bitsum(int l);
        
        public void bitadd(int i, int x);
        
        }
        
    public static boolean check(int X);

}

Step 4: Complete translation of the above Python code to Java code by filling definitions of identified declarations of classes, functions and Global variables in Step 3. Consider above sample input and output format information to handle input and output related code properly in the generated Java code. While generating the Java code, keep track of required library imports to be added in the Java Code. Make sure your generated code is syntactically correct-
2. Java Code:
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main{
    static int n;
    static long m;
    static int[] a;
    static Map<Integer, Integer> d;
    static List<Integer> _a;
    static int[] t;

    public static class BIT {
        public int size;
        public long [] tree;
        public int depth;

        public BIT(int N) {
            this.size = N;
            this.tree = new long[N + 1];
            this.depth = Integer.toBinaryString(N).length();
        }

        public long _bitsum(int i) {
            long ret = 0;
            while (i > 0) {
                ret += this.tree[i];
                i ^= i & -i;
            }
            return ret;
        }

        public long bitsum(int l, int r) {
            return this._bitsum(r) - this._bitsum(l);
        }

        public long bitsum(int l) {
            return this._bitsum(l);
        }

        public void bitadd(int i, int x) {
            i += 1;
            while (i <= this.size) {
                this.tree[i] += x;
                i += i & -i;
            }
            return;
        }
    }


    public static boolean check(int X) {
        int[] b = new int[n + 1];
        b[0] = 0;
        for (int i = 0; i < n; i++) {
            b[i + 1] = (a[i] >= X ? 2 : 0) - 1;
        }
        for (int i = 0; i < n; i++) {
            b[i + 1]+= b[i];
        }
        int c = Arrays.stream(b).min().getAsInt();
        for (int i = 0; i < b.length; i++) {
            b[i] -= c;
        }
        BIT bit = new BIT(Arrays.stream(b).max().getAsInt() + 2);
        long ans = 0;
        for (int x : b) {
            ans += (long) bit.bitsum(x + 1);
            bit.bitadd(x, 1);
        }
        return ans >= m;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = (long) n * (n + 1) / 4;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        d = new HashMap<>();
        Set<Integer> set = new HashSet<>();
        for (int x : a) {
            set.add(x);
        }
        set.add(0);
        _a = new ArrayList<>(set);
        Collections.sort(_a);
        for (int i = 0; i < _a.size(); i++) {
            d.put(_a.get(i), i);
        }
        for (int i = 0; i < a.length; i++) {
            a[i] = d.get(a[i]);
        }

        t = new int[]{ _a.size(), 0 };

        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2;
            if (check(mid)) {
                t[1] = mid;
            } else {
                t[0] = mid;
            }
        }
        System.out.println(_a.get(t[1]));
    }
}

###$###
3. Python Code:
'''
        prompt+=code
    
    if prompt_type=="mapping" and source_lang=="Java": #mapping
        prompt='''
        
You are a helpful code translating assistant. You task is to convert the given java code to python code. You are given two examples for few shot learning purpose. The examples describes how to do the java translation to python translation. in this example, a java code is given that needs to be translated. you need to follow four steps in chain of thought process to correctly translate the java code to python.
!!!!!!!!!


###$###
example_1. 
###$###

Java Code:

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner as = new Scanner(System.in); 
        int def = as.nextInt();  
        int[] and = new int[def]; 
        
        for (int i = 0; i < def; i++) {
            and[i] = as.nextInt();
        }

        ArrayLogic or = new ArrayLogic();  
        boolean lambda = or.hasConsecutiveIncreasingTriplets(and);  
        
        System.out.println(lambda);
    }
}

class ArrayLogic {
    public boolean hasConsecutiveIncreasingTriplets(int[] pass) {  
        for (int i = 0; i < pass.length - 2; i++) {
            if (pass[i] < pass[i + 1] && pass[i + 1] < pass[i + 2]) {
                return true;
            }
        }
        return false;
    }
}


1. Sample Input:
5
10 8 6 4 2

1. Expected Output:
false


1. Steps: Let's think step by step.


Step 1: First of all identify all the global and local variables present in the java code. 

The list of variables in java =  [as, def, i, hasConsecutiveIncreasingTriplets, or, lambda, pass] 

The list of reserved words we can not use as variables in python is given as follows.

These are reserved words = [and, as, assert, async, await, del, elif, except, False, finally, from, global, in, is, lambda, None, nonlocal, not, or, pass, True, with, yield, min, max, list, dict, set, str, int, float, input, print, sum, len, open, map, filter, super, range, type, zip, sorted]

now this is the importtant part: check one by one, take a variable from list of variables in java and see if it belongs to list of reserved words.

1) as belongs to list of reserved words. change as -> as_
2) def belong to list of reserved words. change def -> def_
3) and belong to list of reserved words. change and -> and_
4) or belong to list of reserved words. change or -> or_
5) lambda belong to list of reserved words. change lambda -> lambda_
6) pass belong to list of reserved words. change pass -> pass_



Step 2: Now step by step understand each chunk from java and convert that chunk to python language. We will do this kind of conversion, chunk by chunk for all the chunks in java, then in step 3 we will finally merge all the translated chunks in proper manner to form the whole translated code.

Java_1: import chunk from java

import java.util.*;

python_1: import chunk from python

import sys


java_2: Constructor (Main Function Setup) in java

public static void main(String[] args) {
    Scanner as = new Scanner(System.in);  // 'as' is a reserved keyword in Python


python_2: Constructor (Main Function Setup) in python

def _init_(self):
    self.as_ = input  # Renamed 'as' to 'as_'



java_3: Reading Input Size in java 

int def = as.nextInt();  // 'def' is a reserved keyword in Python

python_3: Reading Input Size in python

def_ = int(self.as_())  # Renamed 'def' to 'def_'


java_4: Array Initialization in java

int[] and = new int[def];  // 'and' is a reserved keyword in Python


python_4: Array Initialization in python

and_ = [0] * def_  # Renamed 'and' to 'and_'



java_5: Input Loop for Array Population in java

for (int i = 0; i < def; i++) {
    and[i] = as.nextInt();
}

python_5: Input Loop for Array Population in python

for i in range(def_):
    and_[i] = int(self.as_())


java_6: Creating an Instance of ArrayLogic Class in java

ArrayLogic or = new ArrayLogic();  // 'or' is a reserved keyword in Python

python_6: Creating an Instance of ArrayLogic Class in python

or_ = ArrayLogic()  # Renamed 'or' to 'or_'


java_7: Calling the Method to Check Triplets for java

boolean lambda = or.hasConsecutiveIncreasingTriplets(and);  // 'lambda' is a reserved keyword in Python


python_7: Calling the Method to Check Triplets for python

lambda_ = or_.has_consecutive_increasing_triplets(and_)  # Renamed 'lambda' to 'lambda_'


java_8: Printing the Result in java

System.out.println(lambda);

python_8: Printing the Result in python

print(lambda_)


java_9: ArrayLogic Class Definition in java

class ArrayLogic {
    public boolean hasConsecutiveIncreasingTriplets(int[] pass) {  // 'pass' is a reserved keyword in Python


python_9: ArrayLogic Class Definition in python

class ArrayLogic:
    def has_consecutive_increasing_triplets(self, pass_):  # Renamed 'pass' to 'pass_'



java_10: Loop to Check for Consecutive Increasing Triplets in java

for (int i = 0; i < pass.length - 2; i++) {
    if (pass[i] < pass[i + 1] && pass[i + 1] < pass[i + 2]) {
        return true;
    }
}


python_10: Loop to Check for Consecutive Increasing Triplets in python

for i in range(len(pass_) - 2):
    if pass_[i] < arr[i + 1] and pass_[i + 1] < pass_[i + 2]:
        return True


java_11: Main Method Execution in java

public static void main(String[] args) {


python_11: Main Method Execution in python

if _name_ == "_main_":
    main_instance = Main()
    main_instance.run()

java_12 : main class in java

public class Main { 
}

python_12: main class in python

Class Main:

Step 3: Complete translation of the above Java code to Python code by considering variable names, identified classes and functions declarations in Step 1 and 2. Use the translated chunks from the step 2 and merge them properly to form the whole translated code while keeping in mind that you may need to generate few more lines of code to make the chunks compatible with each other. Do not simply merge the chunks from step 2 to form a code. it might not work. While generating the Python code, keep track of required library imports to be added in the Python Code. Make sure your generated code is syntactically correct-
1. Complete Python Code:

from collections import defaultdict
import sys

class Main:
    def _init_(self):
        self.as_ = input  # Renamed 'as' to 'as_'
    
    def run(self):
        def_ = int(self.as_())  # Renamed 'def' to 'def_'
        and_ = [0] * def_  # Renamed 'and' to 'and_'
        
        for i in range(def_):
            and_[i] = int(self.as_())
        
        or_ = ArrayLogic()  # Renamed 'or' to 'or_'
        lambda_ = or_.has_consecutive_increasing_triplets(and_)  # Renamed 'lambda' to 'lambda_'
        
        print(lambda_)

class ArrayLogic:
    def has_consecutive_increasing_triplets(self, pass_):  # Renamed 'pass' to 'pass_'
        for i in range(len(pass_) - 2):
            if pass_[i] < pass_[i + 1] and pass_[i + 1] < pass_[i + 2]:
                return True
        return False

if _name_ == "_main_":
    main_instance = Main()
    main_instance.run()

    
###$###
example_2. 
###$### 
 
Java Code:
'''
        prompt+=code
        
    if prompt_type=="mapping_j2p" and source_lang=="Java": #mapping
        prompt='''
Task: Translate the following Java code into Python.

### Guidelines:
1. First, identify the classes and function blocks present in the Java code.
2. Map each class and all function blocks from Java to Python while ensuring structural integrity like shown in below example.
3. Translate the logic while maintaining the same functionality and handling of inputs and outputs.
4. Ensure the Python code is syntactically correct and includes necessary imports.

###$###
1. Java Code:
package com.thealgorithms.datastructures.graphs;

import java.util.ArrayList;
import java.util.Scanner;

class Cycle {

    private final int nodes;
    private final int edges;
    private int[][] adjacencyMatrix;
    private boolean[] visited;
    ArrayList<ArrayList<Integer>> cycles = new ArrayList<ArrayList<Integer>>();

    Cycle() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the no. of nodes: ");
        nodes = in.nextInt();
        System.out.print("Enter the no. of Edges: ");
        edges = in.nextInt();

        adjacencyMatrix = new int[nodes][nodes];
        visited = new boolean[nodes];

        for (int i = 0; i < nodes; i++) {
            visited[i] = false;
        }

        System.out.println("Enter the details of each edges <Start Node> <End Node>");

        for (int i = 0; i < edges; i++) {
            int start;
            int end;
            start = in.nextInt();
            end = in.nextInt();
            adjacencyMatrix[start][end] = 1;
        }
        in.close();
    }

    public void start() {
        for (int i = 0; i < nodes; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            dfs(i, i, temp);
            for (int j = 0; j < nodes; j++) {
                adjacencyMatrix[i][j] = 0;
                adjacencyMatrix[j][i] = 0;
            }
        }
    }

    private void dfs(Integer start, Integer curr, ArrayList<Integer> temp) {
        temp.add(curr);
        visited[curr] = true;
        for (int i = 0; i < nodes; i++) {
            if (adjacencyMatrix[curr][i] == 1) {
                if (i == start) {
                    cycles.add(new ArrayList<Integer>(temp));
                } else {
                    if (!visited[i]) {
                        dfs(start, i, temp);
                    }
                }
            }
        }

        if (temp.size() > 0) {
            temp.remove(temp.size() - 1);
        }
        visited[curr] = false;
    }

    public void printAll() {
        for (int i = 0; i < cycles.size(); i++) {
            for (int j = 0; j < cycles.get(i).size(); j++) {
                System.out.print(cycles.get(i).get(j) + " -> ");
            }
            System.out.println(cycles.get(i).get(0));
            System.out.println();
        }
    }
}

public final class Cycles {
    private Cycles() {
    }

    public static void main(String[] args) {
        Cycle c = new Cycle();
        c.start();
        c.printAll();
    }
}

1.1. Sample Input
3
3
0 1
1 2
2 0

1.1. Expected Output
0 -> 1 -> 2 -> 0

1 -> 2 -> 0 -> 1

2 -> 0 -> 1 -> 2

1.2. Sample Input
1
1
0 0

1.2. Expected Output
0 -> 0


1. Steps: Let's think step by step.

Step 1: Identify classes and blocks of functions present in the Java Code and mapping of these classes and function blocks in Python Code-

step 1: Identified class in the Java Code and their map in the Python Code and it maintain the name similarity of class in both Java and Python
Java Class:
class Cycle {

Python Class:

class Cycle:

step 2: Identified function blocks in the Java Code and their map in the Python Code

block 1. Java:
Cycle() {
    Scanner in = new Scanner(System.in);
    System.out.print("Enter the no. of nodes: ");
    nodes = in.nextInt();
    System.out.print("Enter the no. of Edges: ");
    edges = in.nextInt();

    adjacencyMatrix = new int[nodes][nodes];
    visited = new boolean[nodes];

    for (int i = 0; i < nodes; i++) {
        visited[i] = false;
    }

    System.out.println("Enter the details of each edges <Start Node> <End Node>");

    for (int i = 0; i < edges; i++) {
        int start;
        int end;
        start = in.nextInt();
        end = in.nextInt();
        adjacencyMatrix[start][end] = 1;
    }
    in.close();
}

block 1. Python:
def __init__(self):
    
    self.nodes = int(input("Enter the number of nodes: "))
    self.edges = int(input("Enter the number of edges: "))

   
    self.adjacency_matrix = [[0] * self.nodes for _ in range(self.nodes)]
    self.visited = [False] * self.nodes
    self.cycles = []

   
    print("Enter the details of each edge <Start Node> <End Node>")
    for _ in range(self.edges):
        start, end = map(int, input().split())
        self.adjacency_matrix[start][end] = 1

block 2. Java:
public void start() {
    for (int i = 0; i < nodes; i++) {
        ArrayList<Integer> temp = new ArrayList<>();
        dfs(i, i, temp);
        for (int j = 0; j < nodes; j++) {
            adjacencyMatrix[i][j] = 0;
            adjacencyMatrix[j][i] = 0;
        }
    }
}

block 2. Python:
def start(self):
    for i in range(self.nodes):
        temp = []
        self.dfs(i, i, temp)
        for j in range(self.nodes):
            self.adjacency_matrix[i][j] = 0
            self.adjacency_matrix[j][i] = 0

block 3. Java:
private void dfs(Integer start, Integer curr, ArrayList<Integer> temp) {
    temp.add(curr);
    visited[curr] = true;
    for (int i = 0; i < nodes; i++) {
        if (adjacencyMatrix[curr][i] == 1) {
            if (i == start) {
                cycles.add(new ArrayList<Integer>(temp));
            } else {
                if (!visited[i]) {
                    dfs(start, i, temp);
                }
            }
        }
    }

    if (temp.size() > 0) {
        temp.remove(temp.size() - 1);
    }
    visited[curr] = false;
}

block 3. Python:
def dfs(self, start, curr, temp):
    temp.append(curr)
    self.visited[curr] = True

    for i in range(self.nodes):
        if self.adjacency_matrix[curr][i] == 1:
            if i == start:
                self.cycles.append(list(temp))
            elif not self.visited[i]:
                self.dfs(start, i, temp)

    if temp:
        temp.pop()
    self.visited[curr] = False



block 4. Java:
public static void main(String[] args) {
    Cycle c = new Cycle();
    c.start();
    c.printAll();
}

block 4. Python:
if __name__ == "__main__":
    c = Cycle()
    c.start()
    c.print_all()

    
Step 2: Complete the translation of the Java code to Python code, mapping identified classes and function blocks, and handle input/output properly in Python. Track necessary library imports for Python. Ensure syntax correctness in the generated code
1. Complete Python Code:
class Cycle:
    def __init__(self):
        # Taking input for nodes and edges
        self.nodes = int(input("Enter the number of nodes: "))
        self.edges = int(input("Enter the number of edges: "))

        # Initialize adjacency matrix and visited list
        self.adjacency_matrix = [[0] * self.nodes for _ in range(self.nodes)]
        self.visited = [False] * self.nodes
        self.cycles = []

        # Input for edges
        print("Enter the details of each edge <Start Node> <End Node>")
        for _ in range(self.edges):
            start, end = map(int, input().split())
            self.adjacency_matrix[start][end] = 1

    def start(self):
        for i in range(self.nodes):
            temp = []
            self.dfs(i, i, temp)
            for j in range(self.nodes):
                self.adjacency_matrix[i][j] = 0
                self.adjacency_matrix[j][i] = 0

    def dfs(self, start, curr, temp):
        temp.append(curr)
        self.visited[curr] = True

        for i in range(self.nodes):
            if self.adjacency_matrix[curr][i] == 1:
                if i == start:
                    self.cycles.append(list(temp))
                elif not self.visited[i]:
                    self.dfs(start, i, temp)

        if temp:
            temp.pop()
        self.visited[curr] = False

    def print_all(self):
        for cycle in self.cycles:
            print(" -> ".join(map(str, cycle)) + " -> " + str(cycle[0]))
            print()

# Main function
if __name__ == "__main__":
    c = Cycle()
    c.start()
    c.print_all()

###$###
2. Java Code:
'''
        prompt+=code
        
    if prompt_type == "compact_comments_j2p" and source_lang == "Java":
        prompt = '''
### Task: Compact the comments in the given Java code like shown in below example.



1. Example of Java Code with Comments:

package com.thealgorithms.backtracking;

import java.util.LinkedList;
import java.util.List;

/**
 * Finds all permutations of given array
 * @author Alan Piao (<a href="https://github.com/cpiao3">Git-Alan Piao</a>)
 */
public final class Permutation {
    private Permutation() {
    }

    /**
     * Find all permutations of given array using backtracking
     * @param arr the array.
     * @param <T> the type of elements in the array.
     * @return a list of all permutations.
     */
    public static <T> List<T[]> permutation(T[] arr) {
        T[] array = arr.clone();
        List<T[]> result = new LinkedList<>();
        backtracking(array, 0, result);
        return result;
    }

    /**
     * Backtrack all possible orders of a given array
     * @param arr the array.
     * @param index the starting index.
     * @param result the list contains all permutations.
     * @param <T> the type of elements in the array.
     */
    private static <T> void backtracking(T[] arr, int index, List<T[]> result) {
        if (index == arr.length) {
            result.add(arr.clone());
        }
        for (int i = index; i < arr.length; i++) {
            swap(index, i, arr);
            backtracking(arr, index + 1, result);
            swap(index, i, arr);
        }
    }

    /**
     * Swap two element for a given array
     * @param a first index
     * @param b second index
     * @param arr the array.
     * @param <T> the type of elements in the array.
     */
    private static <T> void swap(int a, int b, T[] arr) {
        T temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}

2. Example of Compacted code of above Java Code:
package com.thealgorithms.backtracking;

import java.util.LinkedList;
import java.util.List;

/**
 * Finds all permutations of an array using backtracking.
 */
public final class Permutation {
    private Permutation() {
    }

    /**
     * Finds permutations of an array.
     */
    public static <T> List<T[]> permutation(T[] arr) {
        T[] array = arr.clone();
        List<T[]> result = new LinkedList<>();
        backtracking(array, 0, result);
        return result;
    }

    /**
     * Recursively generates permutations.
     */
    private static <T> void backtracking(T[] arr, int index, List<T[]> result) {
        if (index == arr.length) {
            result.add(arr.clone());
        }
        for (int i = index; i < arr.length; i++) {
            swap(index, i, arr);
            backtracking(arr, index + 1, result);
            swap(index, i, arr);
        }
    }

    /**
     * Swaps two elements in an array.
     */
    private static <T> void swap(int a, int b, T[] arr) {
        T temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}

##############

3. Java Code:
        
'''

        prompt+=code

    if prompt_type=="autocot2d_j2p" and source_lang=="Java":#v2-j2p
        prompt='''###$###
1. Java Code:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        FastScanner input = new FastScanner();
        int n = input.nextInt();
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            int val = input.nextInt();
            map.put(val, map.getOrDefault(val, 0) + 1);
        }
        
        int max = Integer.MIN_VALUE;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            Integer value = entry.getValue();
            max = Math.max(max, value);
        }
        
        System.out.println(max + " " + map.size());
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() throws IOException {
            return br.readLine();
        }
    }
}

1. Sample Input:
1
1

1. Expected Output:
1 1


1. Steps: Let's think step by step.

Step 1: First of all identify classes and functions declarations present in the above Java Code-
Identified classes and functions declarations in the Java code:
public class Main { 
    public static void main ( String [ ] args );
    static class FastScanner { 
        String next ( );
        int nextInt ( );
        long nextLong ( );
        double nextDouble ( );
        String nextLine ( ) throws IOException; 
    }
}

Step 2: Considering Step 1, classes and functions declarations should be presented in the corresponding Python Code-
Identified classes and functions declarations in the Python code:
Class Main:
    def main(self):

    class FastScanner:
        def __init__(self):

        def next(self):

        def nextInt(self):

        def nextLong(self):

        def nextDouble(self):

        def nextLine(self):


Step 3: Complete translation of the above Java code to Python code by considering identified classes and functions declarations in Step 2 only. Consider above sample input and output format information to handle input and output related code properly in the generated Python code. While generating the Python code, keep track of required library imports to be added in the Python Code. Make sure your generated code is syntactically correct-
1. Python Code:
import sys

class Main:
    def main(self):
        input = self.FastScanner()
        n = input.nextInt()
        map = {}
        for i in range(n):
            val = input.nextInt()
            map[val] = map.get(val, 0) + 1
        max = -1
        for entry in map.items():
            value = entry[1]
            max = max if max > value else value
        print(max, len(map))

    class FastScanner:
        def __init__(self):
            self.buf = sys.stdin.readline
            self.tokens = None

        def next(self):
            while self.tokens is None or len(self.tokens) == 0:
                self.tokens = self.buf().split()
            if (self.tokens is None or len(self.tokens) == 0):
                return ''
            token = self.tokens[0]
            self.tokens = self.tokens[1:]
            return token

        def nextInt(self):
            return int(self.next())

        def nextLong(self):
            return int(self.next())

        def nextDouble(self):
            return float(self.next)

        def nextLine(self):
            return self.buf()

if __name__ == "__main__":
    obj = Main()
    obj.main()


###$###
2. Java Code:
import java.util.Scanner ;

public class Main {
    public static void main ( String [ ] args ) {
        Scanner in_ = new Scanner ( System.in ) ;
        int F = in_.nextInt ( ) ;
        int T = in_.nextInt ( ) ;
        int S = in_.nextInt ( ) ;
        int q = in_.nextInt ( ) ;
        long previous = S ;
        int answer = 0 ; 
        while ( previous < T ) {
            answer ++ ; previous *= q ; 
        }
        answer*=F;
        System.out.println ( answer ) ; 
} }

2. Sample Input:
4
5 2 2

2. Expected Output:
8


2. Steps: Let's think step by step.

Step 1: First of all identify classes and functions declarations present in the above Java Code-
Identified classes and functions declarations in the Java code:
public class Main {
    public static void main ( String [ ] args );
}

Step 2: Considering Step 1, classes and functions declarations should be presented in the corresponding Python Code-
Identified classes and functions declarations in the Python code:
Class Main:
    def main(self):


Step 3: Complete translation of the above Java code to Python code by considering identified classes and functions declarations in Step 2 only. Consider above sample input and output format information to handle input and output related code properly in the generated Python code. While generating the Python code, keep track of required library imports to be added in the Python Code. Make sure your generated code is syntactically correct-
2. Python Code:
class Main:
    def main(self):
        F=int(input().strip())
        T, S, q = map ( int, input ( ).split ( ) )
        previous = S
        answer = 0
        while ( previous < T ):
            answer+=1
            previous *= q
        answer*=F
        print( answer )

if __name__ == "__main__":
    obj = Main()
    obj.main()

###$###
3. Java Code:
'''
        prompt+=code
    if prompt_type=="autocot2d" and source_lang=="Java":#v1-j2p
        prompt='''
###$###
1. Java Code:
import java.io.BufferedReader ; 
import java.io.IOException ; 
import java.io.InputStreamReader ; 
import java.util.* ; 

public class Main { 
public static void main ( String [ ] args ) { 
FastScanner input = new FastScanner ( ) ; 
int n = input.nextInt ( ) ; 
HashMap < Integer , Integer > map = new HashMap < > ( ) ; 
for ( int i = 0 ; i < n ; i ++ ) { 
int val = input.nextInt ( ) ; 
map.put ( val , map.getOrDefault ( val , 0 ) + 1 ) ;
} 
int max = Integer.MIN_VALUE ; 
for ( Map.Entry < Integer , Integer > entry : map.entrySet ( ) ) { 
Integer value = entry.getValue ( ) ;
max = Math.max ( max , value ) ;
} 
System.out.println ( max + " " + map.size ( ) ) ; 
}
static class FastScanner { 
BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
StringTokenizer st = new StringTokenizer ( "" ) ;

String next ( ) { while ( ! st.hasMoreTokens ( ) ) {
try { st = new StringTokenizer ( br.readLine ( ) ) ;
} catch ( IOException e ) {
e.printStackTrace ( ) ; 
} } 
return st.nextToken ( ) ;
} 
int nextInt ( ) {
return Integer.parseInt ( next ( ) ) ;
} 
long nextLong ( ) { 
return Long.parseLong ( next ( ) ) ; 
} 
double nextDouble ( ) {
return Double.parseDouble ( next ( ) ) ; 
} 
String nextLine ( ) throws IOException {
return br.readLine ( ) ; 
} } }

1. Sample Input:
1
1

1. Expected Output:
1 1


1. Steps: Let's think step by step.

Step 1: First of all identify classes and functions declarations present in the above Java Code-
Identified classes and functions declarations in the Java code:
public class Main { 
public static void main ( String [ ] args );
static class FastScanner { 
String next ( );
int nextInt ( );
long nextLong ( );
double nextDouble ( );
String nextLine ( ) throws IOException; 
}
}

Step 2: Considering Step 1, classes and functions declarations should be presented in the corresponding Python Code-
Identified classes and functions declarations in the Python code:
Class Main:
    def main(self):

    class FastScanner:
        def __init__(self):

        def has_next(self):

        def next_int(self):

        def next_str(self):


Step 3: Complete translation of the above Java code to Python code by considering identified classes and functions declarations in Step 2. Consider above sample input and output format information to handle input and output related code properly in the generated Python code. While generating the Python code, keep track of required library imports to be added in the Python Code. Make sure your generated code is syntactically correct-
1. Python Code:
import sys

class Main:
    def main(self):
        input = self.FastScanner()
        n = input.next_int()
        map = {}
        for i in range(n):
            val = input.next_int()
            map[val] = map.get(val, 0) + 1
        max = -1
        for entry in map.items():
            value = entry[1]
            max = max if max > value else value
        print(max, len(map))
        
    class FastScanner:
        def __init__(self):
            self.buf = sys.stdin.readline
            self.tokens = None
    
        def has_next(self):
            while self.tokens is None or len(self.tokens) == 0:
                self.tokens = self.buf().split()
            #some warning need if no input or below line 
            if (self.tokens is None or len(self.tokens) == 0):
                return False
            return True
    
        def next_int(self):
            if not self.has_next():
                return None
            val = self.tokens.pop(0)
            return int(val)
    
        def next_str(self):
            if not self.has_next():
                return None
            val = self.tokens.pop(0)
            return val

if __name__ == "__main__":
    obj = Main()
    obj.main()

###$###
2. Java Code:
import java.util.Scanner ;

public class Main {
    public static void main ( String [ ] args ) {
        Scanner in_ = new Scanner ( System.in ) ;
        int F = in_.nextInt ( ) ;
        int T = in_.nextInt ( ) ;
        int S = in_.nextInt ( ) ;
        int q = in_.nextInt ( ) ;
        long previous = S ;
        int answer = 0 ; 
        while ( previous < T ) {
            answer ++ ; previous *= q ; 
        }
        answer*=F;
        System.out.println ( answer ) ; 
} }

2. Sample Input:
4
5 2 2

2. Expected Output:
8


2. Steps: Let's think step by step.

Step 1: First of all identify classes and functions declarations present in the above Java Code-
Identified classes and functions declarations in the Java code:
public class Main {
    public static void main ( String [ ] args );
}

Step 2: Considering Step 1, classes and functions declarations should be presented in the corresponding Python Code-
Identified classes and functions declarations in the Python code:
Class Main:
    def main(self):


Step 3: Complete translation of the above Java code to Python code by considering identified classes and functions declarations in Step 2. Consider above sample input and output format information to handle input and output related code properly in the generated Python code. While generating the Python code, keep track of required library imports to be added in the Python Code. Make sure your generated code is syntactically correct-
2. Python Code:
class Main:
    def main(self):
        F=int(input().strip())
        T , S , q = map ( int , input ( ).split ( ) )
        previous = S
        answer = 0
        while ( previous < T ):
            answer+=1
            previous *= q
        answer*=F
        print( answer )

if __name__ == "__main__":
    obj = Main()
    obj.main()

###$###
3. Java Code:
'''
        prompt+=code
    if prompt_type == 'gpt' or prompt_type == 'gemini':
        prompt = f'You are a code translation expert. Translate the {source_lang} code below to {target_lang}\n\n{source_lang}\n{code}\n\n{target_lang}\n'

    if prompt_type == 'claude':
        prompt = f'\n```Translate the {source_lang} code below to {target_lang}\n\n{source_lang}\n{code}\n\n{target_lang}\n```\n'

    if prompt_type == 'codellama':
        prompt = f'<s>[INST] <<SYS>> You are a code translation expert. <</SYS>>\n\nTranslate the {source_lang} code below to {target_lang} and end with comment \"<END-OF-CODE>\"\n\n[/INST]\n\n{source_lang}:\n{code}\n\n{target_lang}:\n'

    if prompt_type == 'octocoder':
        prompt = f'Question: You are a code translation expert. Translate the {source_lang} code below to {target_lang} and end with comment \"<END-OF-CODE>\"\n\n{source_lang}\n{code}\n\nAnswer:\n {target_lang}\n'

    if prompt_type == 'dolphin' or prompt_type == 'mistral-hermes':
        prompt = f"""<|im_start|>system
                You are a code translation expert.<|im_end|>
                <|im_start|>user
                Can you translate the following {source_lang} code into {target_lang} and end with comment \"<END-OF-CODE>\"?
                ```{source_lang}
                {code}
                ```
                <|im_end|>
                <|im_start|>assistant
                ```{target_lan}
                """

    if prompt_type == 'starcoder':
        prompt = f"<fim_prefix>{source_lang}:\n{code}\n{target_lang}:\n<fim_suffix><fim_middle>"
                

    if prompt_type == 'solar':
        prompt = f"""<s> ### User:
        Can you translate the {source_lang} code below to {target_lang} and end with comment \"<END-OF-CODE>\"?
        ```{source_lang}
        {code}
        ```

        ### Assistant:
        Sure!
        ```{target_lang}
        """       

    if prompt_type == 'wizardcoder':
        prompt = f"""You are a code translation expert. Below is an instruction that describes a code translation task. Write a response that appropriately completes the request.

        ### Instruction:
        Write {target_lang} code that translates the following {source_lang} code and end with comment\"<END-OF-CODE>\":
        {code}

        ### Response:"""    

    if prompt_type == "deepseek":
        prompt = f'''You are an AI programming assistant, utilizing the DeepSeek Coder model, developed by DeepSeek Company, and you only answer questions related to computer science. For politically sensitive questions, security and privacy issues, and other non-computer science questions, you will refuse to answer.
        ### Instruction:
        Translate the following {source_lang} code to {target_lang}.\n\n{source_lang}\n{code}

        ### Response:
        '''

    if prompt_type == "phi":   
         prompt = f'Instruct: You are a code translation expert. Translate the {source_lang} code below to {target_lang} and end with comment \"<END-OF-CODE>\"\n\n{source_lang}\n{code}\n\nOutput:\n {target_lang}\n'   

    if prompt_type == 'magic':
        
        prompt = f"""You are an exceptionally intelligent coding assistant that consistently delivers accurate and reliable responses to user instructions.

        @@ Instruction
        You are a code translation expert. Translate the {source_lang} code below to {target_lang} and end with comment \"<END-OF-CODE>\"\n\n{source_lang}\n{code}\n'

        @@ Response
        {target_lang}
        """     

    if prompt_type == 'vicuna':
        prompt = f"""### System Prompt
                     You are a code translation expert.

                    ### User Message
                    Translate the {source_lang} code below to {target_lang} and end with comment \"<END-OF-CODE>\"\n\n{source_lang}\n{code}\n

                    ### Assistant
                   """

    return prompt


# Adopted from https://github.com/huggingface/transformers/pull/14897
class EndOfFunctionCriteria(StoppingCriteria):
    def __init__(self, start_length, eos, tokenizer, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.start_length = start_length
        self.eos = eos
        self.tokenizer = tokenizer
        self.end_length = {}

    def __call__(self, input_ids, scores, **kwargs):
        """Returns true if all generated sequences contain any of the end-of-function strings."""
        decoded_generations = self.tokenizer.batch_decode(
            input_ids[:, self.start_length :]
        )
        done = []
        for index, decoded_generation in enumerate(decoded_generations):
            finished = any(
                [stop_string in decoded_generation for stop_string in self.eos]
            )
            if (
                finished and index not in self.end_length
            ):  # ensures first time we see it
                for stop_string in self.eos:
                    if stop_string in decoded_generation:
                        self.end_length[index] = len(
                            input_ids[
                                index,  # get length of actual generation
                                self.start_length : -len(
                                    self.tokenizer.encode(
                                        stop_string,
                                        add_special_tokens=False,
                                        return_tensors="pt",
                                    )[0]
                                ),
                            ]
                        )
            done.append(finished)
        return all(done)


class DecoderBase(ABC):
    def __init__(
        self,
        name: str,
        batch_size: int = 1,
        temperature: float = 0.8,
        conversational: bool = False,
        tensor_parallel_size: int = 1        
    ) -> None:
        print("Initializing a decoder model: {} ...".format(name))
        self.name = name
        self.batch_size = batch_size
        self.temperature = temperature
        self.eos = EOS
        self.skip_special_tokens = False
        self.conversational = conversational
        self.tensor_parallel_size = tensor_parallel_size

    @abstractmethod
    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        pass


    def __repr__(self) -> str:
        return self.name

    def __str__(self) -> str:
        return self.name

# NOTE: in order to use Gemini, the GEMINI_KEY environment variable must be set 
class GeminiDecoder(DecoderBase, ABC):
    def __init__(self, name: str, **kwargs) -> None:
        super().__init__(name, **kwargs)
   
        genai.configure(api_key=os.environ.get('GEMINI_KEY'))

        self.model = genai.GenerativeModel(name)

    def codegen(self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024) -> List[str]:
        if do_sample:
            assert self.temperature > 0, "Temperature must be positive for sampling"

        batch_size = min(self.batch_size, num_samples)
        if not do_sample:
            assert batch_size == 1, "Sampling only supports batch size of 1"

        outputs = []
        for _ in range(batch_size):
            try:
                response = self.model.generate_content(prompt, 
                                                    generation_config=genai.types.GenerationConfig(
                                                        # Only one candidate for now.
                                                        candidate_count=num_samples,
                                                        max_output_tokens=max_length,
                                                        temperature=self.temperature)
                                                        )
                outputs.append(response.text)                                        
            except:  
                outputs.append('GEMINI API ERROR')    
            

        return outputs    


# NOTE: in order to use Claude, the ANTHROPIC_KEY environment variable must be set 
class AnthropicDecoder(DecoderBase, ABC):
    def __init__(self, name: str, **kwargs) -> None:
        super().__init__(name, **kwargs)
        self.client = anthropic.Anthropic(api_key=os.getenv("ANTHROPIC_KEY"))


class AnthropicMessageDecoder(AnthropicDecoder):
    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if do_sample:
            assert self.temperature > 0, "Temperature must be positive for sampling"

        batch_size = min(self.batch_size, num_samples)
        if not do_sample:
            assert batch_size == 1, "Sampling only supports batch size of 1"

        outputs = []
        for _ in range(batch_size):
            message = anthropic_request.make_auto_request(
                client=self.client,
                model=self.name,
                system="You are a code translation expert.",
                messages=[
                    {
                        "role": "user",
                        "content": prompt
                    }
                ],
                max_tokens=max_length,
                temperature=self.temperature,
                stop_sequences=["\n```\n"],
            )
            outputs.append(message.content[0].text)

        return outputs

class VLlmDecoder(DecoderBase):
    def __init__(self, name: str, **kwargs) -> None:
        super().__init__(name, **kwargs)

        kwargs = {"tensor_parallel_size": self.tensor_parallel_size}
        if "CodeLlama" in name:
            kwargs["dtype"] = "bfloat16"
        elif "CodeBooga" in name:
            kwargs["dtype"] = "float16"
        elif "WizardCoder" in name:
            kwargs["dtype"] = "float16"
        elif "deepseek" in name:
            kwargs["dtype"] = "bfloat16"
        elif "mixtral" in name.lower():
            kwargs["dtype"] = "bfloat16"
        elif "solar" in name:
            kwargs["dtype"] = "float16"
        elif "mistral" in name.lower():
            kwargs["dtype"] = "bfloat16"
        elif "phi" in name.lower():
            kwargs["dtype"] = "float16"
            kwargs["trust_remote_code"] = True

              
        self.path = name
   
        self.llm = LLM(model=self.path, **kwargs)

        self.context_window_length = self.llm.get_tokenizer().model_max_length
        if self.context_window_length > 30000:

            # find config file 
            p = [x for x in os.listdir(cache_dir) if x.find(name.split('/')[-1])>0]
            p = [x for x in p if os.path.isdir(f'{cache_dir}/{x}')][0]
            self.path = f'{cache_dir}/{p}'

            config_path = None
            for path in glob.glob(f'{self.path}/**/config.json', recursive=True):
                config_path = path

            if config_path:
                with open(config_path) as fin:
                    config_data = json.load(fin)

                if 'n_positions' in config_data:
                    self.context_window_length = config_data['n_positions']
                elif 'max_position_embeddings' in config_data:
                    self.context_window_length = config_data['max_position_embeddings']
                else:
                    print('Model has unclear context_window_length, setting to 1024')
                    self.context_window_length = 1024
            else:
                print('Model has unclear context_window_length, setting to 1024')
                self.context_window_length = 1024   

  


    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if do_sample:
            assert self.temperature > 0, "Temperature must be greater than 0!"
        batch_size = min(self.batch_size, num_samples)

        vllm_outputs = self.llm.generate(
            [prompt] * batch_size,
            SamplingParams(
                temperature=self.temperature,
                max_tokens=min(max_length, self.context_window_length),
                top_p=0.95 if do_sample else 1.0,
                stop=self.eos,
            ),
            use_tqdm=False,
        )

        gen_strs = [x.outputs[0].text.replace("\t", "    ") for x in vllm_outputs]
        return gen_strs


# chatml format
class ChatML(VLlmDecoder):
    def __init__(self, name: str, **kwargs) -> None:
        kwargs["conversational"] = True
        super().__init__(name, **kwargs)
        self.eos += ["\n```"]


    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if do_sample:
            assert self.temperature > 0, "Temperature must be greater than 0!"

        return VLlmDecoder.codegen(self, prompt, do_sample, num_samples, max_length)


class HFTorchDecoder(DecoderBase):
    def __init__(self, name: str, **kwargs):
        super().__init__(name=name, **kwargs)
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        
        self.tokenizer = None  # Initialize tokenizer to None
        self.model = None  # Initialize model to None
        
        kwargs = {
            "trust_remote_code": name
            in {
                "bigcode/santacoder",
                "Salesforce/codegen2-1B",
                "Salesforce/codegen2-3_7B",
                "Salesforce/codegen2-7B",
                "Salesforce/codegen2-16B",
                "deepseek-ai/deepseek-coder-1.3b-base",
                "deepseek-ai/deepseek-coder-6.7b-base",
                "deepseek-ai/deepseek-coder-33b-base",
                "deepseek-ai/deepseek-coder-1.3b-instruct",
                "deepseek-ai/deepseek-coder-6.7b-instruct",
                "deepseek-ai/deepseek-coder-33b-instruct",
                "deepseek-ai/DeepSeek-Coder-V2-Lite-Instruct",
                "granite-8b-code-instruct-128k",
                "mistralai/mistral-7b-instruct-v0.2",
                "starcoder"
                
                
            }
        }

        if "codegen-" in name:  # use fp16 for codegen models
            kwargs["torch_dtype"] = torch.float16
        if "codegen2-" in name:  # avoid warning of trust remote code
            kwargs["revision"] = "main"
            if "16b" in name.lower():
                kwargs["device_map"] = "auto"
        if "starcoder" in name:
            kwargs["device_map"] = "auto"
            kwargs["torch_dtype"] = torch.bfloat16
            kwargs["trust_remote_code"] = True
            self.skip_special_tokens = True
            model_path="/home/codetrans/models/starcoder"
            cache_dir=f"/home/codetrans/Project/data/{name}_data"
            # os.makedirs(cache_dir, exist_ok=True)
            print(kwargs)
            
            self.tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
            self.model = AutoModelForCausalLM.from_pretrained(model_path, **kwargs)
            print(f'#############################################{name}')
            self.skip_special_tokens = True
            
        if "granite" in name:
            # from accelerate import infer_auto_device_map
            # device_map_ = infer_auto_device_map(my_model, max_memory={0: "10GiB", 1: "10GiB", "cpu": "30GiB"})
            if ("20b" in name):
                kwargs["torch_dtype"] = torch.bfloat16
            # not in 8b possible
            kwargs["device_map"] ="auto" #"auto"
            model_path=f"/home/codetrans/models/{name}"
            cache_dir_granite=f"/home/codetrans/Project/data/{name}_data"
            os.makedirs(cache_dir_granite, exist_ok=True)
            # kwargs["cache_dir"]=cache_dir_starcoder
            self.tokenizer = AutoTokenizer.from_pretrained(model_path, use_auth_token=True, cache_dir=cache_dir_granite)
            self.model = AutoModelForCausalLM.from_pretrained(
        		model_path,use_auth_token=True,cache_dir=cache_dir_granite,**kwargs)
            self.model.eval()
            
        if "deepseek" in name:
            kwargs["device_map"] = "auto"
            kwargs["torch_dtype"] = torch.bfloat16
            kwargs["trust_remote_code"] = True
            self.skip_special_tokens = True
            model_path=f"/home/codetrans/models/DeepSeek-Coder-V2-Lite-Instruct"
            cache_dir_deepseek=f"/home/codetrans/Project/data/{name}_data"
            # cache_dir_codellama=f"/home/scai/mtech/aib232067/scratch/code_llm/AJAY/Project/data/{name}_data"
            # os.makedirs(cache_dir_codellama, exist_ok=True)
            print(kwargs)
            # self.tokenizer = PreTrainedTokenizerFast(tokenizer_file="/home/codetrans/models/DeepSeek-Coder-V2-Lite-Instruct/tokenizer.json")
            self.tokenizer = AutoTokenizer.from_pretrained(model_path, local_files_only=True)
            self.model = AutoModelForCausalLM.from_pretrained(model_path,cache_dir=cache_dir_deepseek, **kwargs)
            print(f'#############################################{name}')
            self.skip_special_tokens = True
            
        if "mistral" in name:
            kwargs["device_map"] = "auto"
            kwargs["torch_dtype"] = torch.bfloat16
            kwargs["trust_remote_code"] = True
            self.skip_special_tokens = True
            model_path=f"/home/codetrans/models/mistral-7b-instruct-v0.2"
           
            print(kwargs)
            
            self.tokenizer = AutoTokenizer.from_pretrained(model_path, local_files_only=True)
            self.model = AutoModelForCausalLM.from_pretrained(model_path, **kwargs)
            print(f'#############################################{name}')
            self.skip_special_tokens = True
            
        if "granite-8b-code-instruct-128k" in name:
            
            kwargs["torch_dtype"] = torch.float16
            kwargs["device_map"] = "auto"
            self.skip_special_tokens = True
            model_path = f"/home/codetrans/models/{name}"
            cache_dir_new_model = f"/home/codetrans/Project/data/{name}_data"
            os.makedirs(cache_dir_new_model, exist_ok=True)
            self.tokenizer = AutoTokenizer.from_pretrained(model_path, use_auth_token=True, cache_dir=cache_dir_new_model)
            self.model = AutoModelForCausalLM.from_pretrained(model_path, use_auth_token=True, cache_dir=cache_dir_new_model, **kwargs)
            

        	
        if "CodeLlama" in name:
            # if "34b" in name.lower():
            #     kwargs["device_map"] = "auto"
            kwargs["torch_dtype"] = torch.bfloat16
            kwargs["device_map"] ="auto" #"auto"
            self.skip_special_tokens = True
            model_path=f"/home/codetrans/models/{name}"
            cache_dir_codellama=f"/home/codetrans/Project/data/{name}_data"
            os.makedirs(cache_dir_codellama, exist_ok=True)
            self.tokenizer = AutoTokenizer.from_pretrained(model_path, use_auth_token=True, cache_dir=cache_dir_codellama)
            self.model = AutoModelForCausalLM.from_pretrained( model_path,use_auth_token=True,cache_dir=cache_dir_codellama,**kwargs)
            self.model.generation_config.eos_token_id=self.tokenizer.eos_token_id
            self.model.generation_config.pad_token_id = self.tokenizer.pad_token_id

        if "CodeBooga" in name:
            kwargs["torch_dtype"] = torch.float16
            kwargs["device_map"] = "auto"
            self.skip_special_tokens = True
        #if "Mistral-7B-codealpaca-lora" == name:
        #    kwargs["torch_dtype"] = torch.float16
        #    self.skip_special_tokens = True
        elif "mistral" in name or "zephyr-7b-beta" in name:
            kwargs["device_map"] = "auto"
            kwargs["torch_dtype"] = torch.bfloat16
            self.skip_special_tokens = True
        if "deepseek" in name:
            kwargs["device_map"] = "auto"
            kwargs["torch_dtype"] = torch.bfloat16
            self.skip_special_tokens = True
        if "/phi" in name:
            kwargs["torch_dtype"] = torch.float16
            kwargs["trust_remote_code"] = True
            self.skip_special_tokens = True

        print(f"{kwargs} = ")

        # self.tokenizer = AutoTokenizer.from_pretrained(name)
        # self.model = AutoModelForCausalLM.from_pretrained(name, **kwargs)
        if name in {"StabilityAI/stablelm-base-alpha-7b"}:
            print("Switching to float16 ...")
            self.model = self.model.half()
            self.skip_special_tokens = True

        if kwargs["device_map"] != "auto":
            self.model = self.model.to(self.device)
            
        # Add a check to ensure the tokenizer is loaded
        if self.tokenizer is None:
            raise ValueError(f"Tokenizer not initialized for model '{name}'")


        self.context_window_length = self.tokenizer.model_max_length
        if self.context_window_length > 1000000:
            if hasattr(self.model.config, 'n_positions'):
                self.context_window_length = self.model.config.n_positions
            elif hasattr(self.model.config, 'max_position_embeddings'):
                self.context_window_length = self.model.config.max_position_embeddings
            else:
                print('Model has unclear context_window_length, setting to 1024')
                self.context_window_length = 4090#1024

    @torch.inference_mode()
    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if self.temperature == 0:
            do_sample = False
            num_samples == 1

        input_tokens = self.tokenizer.encode(prompt, return_tensors="pt").to(
            self.device
        )
        scores = StoppingCriteriaList(
            [
                EndOfFunctionCriteria(
                    start_length=len(input_tokens[0]),
                    eos=self.eos,
                    tokenizer=self.tokenizer,
                )
            ]
        )
        kwargs = {}
        if do_sample:
            kwargs["top_p"] = 0.95
            kwargs["temperature"] = self.temperature
            # kwargs["temperature"] = max(self.temperature, 1e-2)
        else:
            # Ensure irrelevant parameters are not set for deterministic behavior
            kwargs["top_p"] = None
            kwargs["temperature"] = None

        if ("granite" in self.name or "CodeLlama" in self.name): #like strcoder infill code
            self.context_window_length =max_length #4090

            if len(input_tokens[0]) >= self.context_window_length :
                outputs = []
                for _ in range(num_samples):
                    outputs.append('MODEL MAX LENGTH EXCEEDED')
                return outputs    

        raw_outputs = self.model.generate(
            input_tokens,
            max_new_tokens=min(max_length, self.context_window_length - len(input_tokens[0])),
            stopping_criteria=scores,
            do_sample=do_sample,
            output_scores=True,
            return_dict_in_generate=True,
            num_return_sequences=min(self.batch_size, num_samples),
            pad_token_id=self.tokenizer.eos_token_id,#"CodeLlama" in name
            **kwargs,
        )  # remove warning
        gen_seqs = raw_outputs.sequences[:, len(input_tokens[0]) :]
        gen_strs = self.tokenizer.batch_decode(
            gen_seqs, skip_special_tokens=self.skip_special_tokens
        )
        outputs = []
        # removes eos tokens.
        for output in gen_strs:
            min_index = 10000
            for eos in self.eos:
                if eos in output:
                    # could be multiple eos in outputs, better pick minimum one
                    min_index = min(min_index, output.index(eos))
            outputs.append(output[:min_index])
        return outputs

# class DeepSeekInstruct(HFTorchDecoder):
#     @torch.inference_mode()
#     def codegen(
#         self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
#     ) -> List[str]:
#         if self.temperature == 0:
#             assert not do_sample
#             assert num_samples == 1
#         self.context_window_length = max_length
#         input_tokens = self.tokenizer.apply_chat_template(
#             [
#                 {
#                     "role": "user",
#                     "content": f"{prompt}",
#                 }
#             ],
#             return_tensors="pt",
#         ).to(self.device)
#         print(self.eos)
#         scores = StoppingCriteriaList(
#             [
#                 EndOfFunctionCriteria(
#                     start_length=len(input_tokens[0]),
#                     eos=self.eos,
#                     tokenizer=self.tokenizer,
#                 )
#             ]
#         )
#         kwargs = {}
#         if do_sample:
#             kwargs["top_p"] = 0.95
#             kwargs["temperature"] = self.temperature
        

#         print(f'####################### max new tokens {min(max_length, self.context_window_length - len(input_tokens[0]))}')
#         print(max_length,self.context_window_length,len(input_tokens[0]))
#         print(self.batch_size, num_samples)
#         raw_outputs = self.model.generate(
#             input_tokens,
#             max_new_tokens=min(max_length, self.context_window_length - len(input_tokens[0])),
#             do_sample=do_sample,
#             output_scores=True,
#             return_dict_in_generate=True,
#             stopping_criteria=scores,
#             top_k=15,
#             num_return_sequences=min(self.batch_size, num_samples),
#             eos_token_id=100001,
#             **kwargs,
#         )  # remove warning
#         gen_seqs = raw_outputs.sequences[:, len(input_tokens[0]) :]
#         print(f'len of generation {gen_seqs.shape}')
#         print(f'len of generation {gen_seqs}')
#         gen_strs = self.tokenizer.batch_decode(
#             gen_seqs, skip_special_tokens=self.skip_special_tokens
#         )
#         # print(f'##################{len(gen_strs)}')
#         return gen_strs

class DeepSeekInstruct(HFTorchDecoder):
    @torch.inference_mode()
    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if self.temperature == 0:
            do_sample = False
            num_samples = 1

        input_tokens = self.tokenizer.apply_chat_template(
            [
                {
                    "role": "user",
                    "content": f"{prompt}",
                }
            ],
            return_tensors="pt",
        ).to(self.device)
        scores = StoppingCriteriaList(
            [
                EndOfFunctionCriteria(
                    start_length=len(input_tokens[0]),
                    eos=self.eos,
                    tokenizer=self.tokenizer,
                )
            ]
        )
        kwargs = {}
        if do_sample:
            kwargs["top_p"] = 0.95
            kwargs["temperature"] = self.temperature
        else:
            # Ensure irrelevant parameters are not set for deterministic behavior
            kwargs["top_p"] = None
            kwargs["temperature"] = None

        #print(self.tokenizer.eos_token_id)
        raw_outputs = self.model.generate(
            input_tokens,
            max_new_tokens=min(max_length, self.context_window_length - len(input_tokens[0])),
            do_sample=do_sample,
            output_scores=True,
            return_dict_in_generate=True,
            stopping_criteria=scores,
            top_k=15,
            num_return_sequences=min(self.batch_size, num_samples),
            pad_token_id=self.tokenizer.eos_token_id,
            eos_token_id=self.tokenizer.eos_token_id,
            **kwargs,
        )  # remove warning
        gen_seqs = raw_outputs.sequences[:, len(input_tokens[0]) :]
        gen_strs = self.tokenizer.batch_decode(
            gen_seqs, skip_special_tokens=self.skip_special_tokens
        )
        return gen_strs

from openai import OpenAI

class DeepSeekV3Decoder(DecoderBase):
    def __init__(self, name: str, **kwargs) -> None:
        super().__init__(name, **kwargs)
        # Initialize the OpenAI client with the given API key and base URL
        self.client = OpenAI(api_key="<API key>", base_url="https://api.deepseek.com")

    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if do_sample:
            assert self.temperature >= 0, "Temperature must be positive for sampling"

        batch_size = min(self.batch_size, num_samples)
        assert batch_size <= 20, "Use larger batch size could blow up the memory!"

        # Construct the prompt and use OpenAI API to generate responses
        fmt = "text"
        ret = self.client.chat.completions.create(
            model="deepseek-chat",
            messages=[
                {"role": "system", "content": "You are a helpful assistant"},
                {"role": "user", "content": prompt},
            ],
            max_tokens=max_length,
            temperature=self.temperature,
            n=batch_size,
            stream=False,
            response_format={"type": fmt},
        )

        outputs = []
        for item in ret.choices:
            content = item.message.content
            # If the response is in JSON format
            if fmt == "json_object":
                try:
                    json_data = json.loads(content)
                    if json_data.get("code", None) is not None:
                        outputs.append(prompt + "\n" + json_data["code"])
                        continue

                    print(f"'code' field not found in: {json_data}")
                except Exception as e:
                    print(e)
            outputs.append(content)

        return outputs
    
# NOTE: in order to use gpt, the OPENAI_API_KEY environment variable must be set 
class OpenAIChatDecoder(DecoderBase):
    def __init__(self, name: str, **kwargs) -> None:
        super().__init__(name, **kwargs)
        self.client = openai.OpenAI(api_key="<API key>")

    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if do_sample:
            assert self.temperature >= 0, "Temperature must be positive for sampling"

        batch_size = min(self.batch_size, num_samples)
        assert batch_size <= 20, "Use larger batch size could blow up the memory!"

        # construct prompt
        fmt = "text"

        ret = make_auto_request(
            self.client,
            message=prompt,
            model=self.name,
            max_tokens=max_length,
            temperature=self.temperature,
            n=batch_size,
            response_format={"type": fmt},
        )


        outputs = []
        for item in ret.choices:
            content = item.message.content
            # if json serializable
            if fmt == "json_object":
                try:
                    json_data = json.loads(content)
                    if json_data.get("code", None) is not None:
                        outputs.append(prompt + "\n" + json_data["code"])
                        continue

                    print(f"'code' field not found in: {json_data}")
                except Exception as e:
                    print(e)
            outputs.append(content)

        return outputs


class IncoderDecoder(HFTorchDecoder):
    def __init__(self, name: str, **kwargs) -> None:
        super().__init__(name, **kwargs)
        self.infill_ph = "<|mask:0|>"
        self.extra_end = "<|mask:1|><|mask:0|>"
        self.extra_eos = [
            "<|endofmask|>",
            "<|/ file",
            "</cell>",
            "</text>",
            "</code>",
            "<|",
            "</CODE>",
        ]
        self.eos = self.eos + self.extra_eos

    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        input = prompt + self.infill_ph + self.extra_end
        input_tokens = self.tokenizer.encode(input, return_tensors="pt").to(self.device)
        scores = StoppingCriteriaList(
            [
                EndOfFunctionCriteria(
                    start_length=len(input_tokens[0]),
                    eos=self.eos,
                    tokenizer=self.tokenizer,
                )
            ]
        )


        raw_outputs = self.model.generate(
            input_tokens,
            max_new_tokens=min(max_length, self.context_window_length - len(input_tokens[0])),
            stopping_criteria=scores,
            do_sample=do_sample,
            top_p=0.95,
            top_k=None,
            temperature=self.temperature,
            num_return_sequences=min(self.batch_size, num_samples),
            output_scores=True,
            return_dict_in_generate=True,
        )
        gen_seqs = raw_outputs.sequences[:, len(input_tokens[0]) :]
        gen_strs = self.tokenizer.batch_decode(
            gen_seqs, skip_special_tokens=self.skip_special_tokens
        )
        outputs = []
        # removes eos tokens.
        for output in gen_strs:
            min_index = 10000
            for eos in self.eos:
                if eos in output:
                    min_index = min(min_index, output.index(eos))
            outputs.append(output[:min_index])
        return outputs


class Codegen2Decoder(HFTorchDecoder):
    def __init__(self, name: str, **kwargs) -> None:
        super().__init__(name, **kwargs)
        self.infill_ph = "<mask_1>"
        # taken from: https://huggingface.co/Salesforce/codegen2-16B
        self.extra_end = "<|endoftext|><sep><mask_1>"
        self.extra_eos = ["<eom>"]
        self.eos = self.eos + self.extra_eos

    @torch.inference_mode()
    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if self.temperature == 0:
            assert not do_sample
            assert num_samples == 1

        input = prompt + self.infill_ph + self.extra_end
        input_tokens = self.tokenizer.encode(input, return_tensors="pt").to(self.device)
        scores = StoppingCriteriaList(
            [
                EndOfFunctionCriteria(
                    start_length=len(input_tokens[0]),
                    eos=self.eos,
                    tokenizer=self.tokenizer,
                )
            ]
        )


        raw_outputs = self.model.generate(
            input_tokens,
            max_new_tokens=min(max_length, self.context_window_length - len(input_tokens[0])),
            stopping_criteria=scores,
            do_sample=do_sample,
            top_p=0.95,
            top_k=None,
            temperature=self.temperature,
            output_scores=True,
            return_dict_in_generate=True,
            num_return_sequences=min(self.batch_size, num_samples),
            pad_token_id=self.tokenizer.eos_token_id,
        )
        gen_seqs = raw_outputs.sequences[:, len(input_tokens[0]) :]
        gen_strs = self.tokenizer.batch_decode(
            gen_seqs, skip_special_tokens=self.skip_special_tokens
        )
        outputs = []
        # removes eos tokens.
        for output in gen_strs:
            min_index = 10000
            for eos in self.eos:
                if eos in output:
                    min_index = min(min_index, output.index(eos))
            outputs.append(output[:min_index])
        return outputs


class SantaCoder(HFTorchDecoder):
    def __init__(self, name: str, **kwargs) -> None:
        super().__init__(name, **kwargs)
        self.prefix_token = "<fim-prefix>"
        self.suffix_token = "<fim-suffix>\n<fim-middle>"
        self.extra_eos = ["<|endofmask|>"]
        self.eos = self.eos + self.extra_eos

    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if self.temperature == 0:
            assert not do_sample
            assert num_samples == 1

        input = self.prefix_token + prompt + self.suffix_token
        input_tokens = self.tokenizer.encode(input, return_tensors="pt").to(self.device)
        scores = StoppingCriteriaList(
            [
                EndOfFunctionCriteria(
                    start_length=len(input_tokens[0]),
                    eos=self.eos,
                    tokenizer=self.tokenizer,
                )
            ]
        )

        if len(input_tokens[0]) >= self.context_window_length:
            outputs = []
            for _ in range(num_samples):
                outputs.append('MODEL MAX LENGTH EXCEEDED')
            return outputs

        raw_outputs = self.model.generate(
            input_tokens,
            max_new_tokens=min(max_length, int((self.context_window_length - len(input_tokens[0])) * 0.9)),
            stopping_criteria=scores,
            do_sample=do_sample,
            top_p=0.95,
            top_k=None,
            temperature=self.temperature,
            num_return_sequences=min(self.batch_size, num_samples),
            output_scores=True,
            return_dict_in_generate=True,
            pad_token_id=self.tokenizer.eos_token_id,
        )
        gen_seqs = raw_outputs.sequences[:, len(input_tokens[0]) :]
        gen_strs = self.tokenizer.batch_decode(
            gen_seqs,
            skip_special_tokens=self.skip_special_tokens,
        )
        outputs = []
        # removes eos tokens.
        for output in gen_strs:
            min_index = 10000
            for eos in self.eos:
                if eos in output:
                    min_index = min(min_index, output.index(eos))
            outputs.append(output[:min_index])
        return outputs

# class StarCoderInfill(HFTorchDecoder):
#     @torch.inference_mode()
#     def codegen(
#         self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
#     ) -> List[str]:
#         if self.temperature == 0:
#             do_sample = False
#             num_samples = 1

#         input_tokens = self.tokenizer.apply_chat_template(
#             [
#                 {"role": "user", "content": f"{prompt}"}
#             ],
#             chat_template="<user>: {content}\n<assistant>:",
#             return_tensors="pt"
#         ).to(self.device)
#         scores = StoppingCriteriaList(
#             [
#                 EndOfFunctionCriteria(
#                     start_length=len(input_tokens[0]),
#                     eos=self.eos,
#                     tokenizer=self.tokenizer,
#                 )
#             ]
#         )
#         kwargs = {}
#         if do_sample:
#             kwargs["top_p"] = 0.95
#             kwargs["temperature"] = self.temperature
#         else:
#             # Ensure irrelevant parameters are not set for deterministic behavior
#             kwargs["top_p"] = None
#             kwargs["temperature"] = None

#         #print(self.tokenizer.eos_token_id)
#         raw_outputs = self.model.generate(
#             input_tokens,
#             max_new_tokens=min(max_length, self.context_window_length - len(input_tokens[0])),
#             do_sample=do_sample,
#             output_scores=True,
#             return_dict_in_generate=True,
#             stopping_criteria=scores,
#             top_k=15,
#             num_return_sequences=min(self.batch_size, num_samples),
#             pad_token_id=self.tokenizer.eos_token_id,
#             eos_token_id=self.tokenizer.eos_token_id,
#             **kwargs,
#         )  # remove warning
#         gen_seqs = raw_outputs.sequences[:, len(input_tokens[0]) :]
#         gen_strs = self.tokenizer.batch_decode(
#             gen_seqs, skip_special_tokens=self.skip_special_tokens
#         )
#         return gen_strs

class StarCoderInfill(HFTorchDecoder):
    def __init__(self, name: str, **kwargs) -> None:
        super().__init__(name, **kwargs)
        self.prefix_token = "<fim_prefix>"
        self.suffix_token = "<fim_suffix><fim_middle>"

    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if self.temperature == 0:
            do_sample = False
            num_samples = 1

        input = prompt 
        input_tokens = self.tokenizer.encode(input, return_tensors="pt").to(self.device)
        scores = StoppingCriteriaList(
            [
                EndOfFunctionCriteria(
                    start_length=len(input_tokens[0]),
                    eos=self.eos,
                    tokenizer=self.tokenizer,
                )
            ]
        )

        kwargs = {}
        if do_sample:
            kwargs["top_p"] = 0.95
            # top_k default to 50
            kwargs["temperature"] = max(self.temperature, 1e-2)
        else:
            # Ensure irrelevant parameters are not set for deterministic behavior
            kwargs["top_p"] = None
            kwargs["temperature"] = None
        
        self.context_window_length =max_length #4090
 

        if len(input_tokens[0]) >= self.context_window_length :
            outputs = []
            for _ in range(num_samples):
                outputs.append('MODEL MAX LENGTH EXCEEDED')
            return outputs

        raw_outputs = self.model.generate(
            input_tokens,
            max_new_tokens=min(max_length, int((self.context_window_length  - len(input_tokens[0])))),#0.9 round-off error
            stopping_criteria=scores,
            do_sample=do_sample,
            num_return_sequences=min(self.batch_size, num_samples),
            output_scores=True,
            return_dict_in_generate=True,
            repetition_penalty=1.0,
            pad_token_id=self.tokenizer.eos_token_id,
            **kwargs #prev only in HFcoder
        )
        gen_seqs = raw_outputs.sequences[:, len(input_tokens[0]) :]
        gen_strs = self.tokenizer.batch_decode(
            gen_seqs,
            skip_special_tokens=self.skip_special_tokens
        )
        # return gen_strs
        outputs = []
        # removes eos tokens.
        for output in gen_strs:
            min_index = 10000
            for eos in self.eos:
                if eos in output:
                    min_index = min(min_index, output.index(eos))
            outputs.append(output[:min_index])
        return outputs


class CodeT5P(DecoderBase):
    def __init__(self, name: str, **kwargs):
        super().__init__(name=name, **kwargs)
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        assert name in {
            "Salesforce/codet5p-2b",
            "Salesforce/codet5p-6b",
            "Salesforce/codet5p-16b",
            "Salesforce/instructcodet5p-16b",
        }
        self.tokenizer = AutoTokenizer.from_pretrained(name)
        self.model = AutoModelForSeq2SeqLM.from_pretrained(
            name,
            trust_remote_code=True,  # False for 220m and 770m models
            torch_dtype=torch.float16,
            low_cpu_mem_usage=True,
        )
        self.model.eval()
        self.model.to(self.device)

        self.skip_special_tokens = True

        self.context_window_length = self.tokenizer.model_max_length
        if self.context_window_length > 1000000:
            if hasattr(self.model.config, 'n_positions'):
                self.context_window_length = self.model.config.n_positions
            elif hasattr(self.model.config, 'max_position_embeddings'):
                self.context_window_length = self.model.config.max_position_embeddings
            else:
                print('Model has unclear context_window_length, setting to 1024')
                self.context_window_length = 1024 


    @torch.inference_mode()
    def codegen(
        self, prompt: str, do_sample: bool = True, num_samples: int = 200, max_length: int = 1024
    ) -> List[str]:
        if self.temperature == 0:
            assert not do_sample
            assert num_samples == 1

        prompt = prompt.replace("    ", "\t")
        input_tokens = self.tokenizer(prompt, return_tensors="pt").to(self.device)
        scores = StoppingCriteriaList(
            [
                EndOfFunctionCriteria(
                    start_length=len(input_tokens[0]),
                    eos=self.eos,
                    tokenizer=self.tokenizer,
                )
            ]
        )


        max_new_tokens = min(max_length, self.context_window_length - len(input_tokens[0]))     

        while max_new_tokens > 0:
            try:
                raw_outputs = self.model.generate(
                    **input_tokens,
                    decoder_input_ids=input_tokens["input_ids"],
                    max_new_tokens=max_new_tokens,
                    stopping_criteria=scores,
                    do_sample=do_sample,
                    top_p=0.95,
                    top_k=None,
                    temperature=self.temperature,
                    output_scores=True,
                    return_dict_in_generate=True,
                    num_return_sequences=min(self.batch_size, num_samples),
                    pad_token_id=self.tokenizer.eos_token_id,
                    decoder_start_token_id=self.tokenizer.pad_token_id,
                )  # remove warning
            except RuntimeError as e:  # catch torch OOM
                if "CUDA out of memory" in str(e):
                    old_max_new_tokens = max_new_tokens
                    max_new_tokens = int(max_new_tokens * 0.8)
                    print(
                        f"OOM, reducing max_new_tokens from {old_max_new_tokens} to {max_new_tokens}"
                    )
                    continue
                else:
                    raise e

            break
        gen_seqs = raw_outputs.sequences[:, len(input_tokens[0]) :]
        gen_strs = self.tokenizer.batch_decode(
            gen_seqs, skip_special_tokens=self.skip_special_tokens
        )
        outputs = []
        # removes eos tokens.
        for output in gen_strs:
            min_index = 10000
            for eos in self.eos:
                if eos in output:
                    # could be multiple eos in outputs, better pick minimum one
                    min_index = min(min_index, output.index(eos))
            outputs.append(output[:min_index].replace("\t", "    "))
        return outputs


def make_model(name: str, batch_size: int = 1, temperature: float = 0.8, ngpus: int = 1):
    print("name",name)
    if name == "codegen-2b":
        return HFTorchDecoder(
            batch_size=batch_size,
            name="Salesforce/codegen-2B-mono",
            temperature=temperature,
        )
    elif name == "codegen-6b":
        return HFTorchDecoder(
            batch_size=batch_size,
            name="Salesforce/codegen-6B-mono",
            temperature=temperature,
        )
    elif name == "codegen-16b":
        return HFTorchDecoder(
            batch_size=batch_size,
            name="Salesforce/codegen-16B-mono",
            temperature=temperature,
        )
    elif name == "codegen2-1b":
        return Codegen2Decoder(
            batch_size=batch_size,
            name="Salesforce/codegen2-1B",
            temperature=temperature,
        )
    elif name == "codegen2-3b":
        return Codegen2Decoder(
            batch_size=batch_size,
            name="Salesforce/codegen2-3_7B",
            temperature=temperature,
        )
    elif name == "codegen2-7b":
        return Codegen2Decoder(
            batch_size=batch_size,
            name="Salesforce/codegen2-7B",
            temperature=temperature,
        )
    elif name == "codegen2-16b":
        warn(
            "codegen2-16b checkpoint is `unfinished` at this point (05/11/2023) according to their paper. "
            "So it might not make sense to use it."
        )
        return Codegen2Decoder(
            batch_size=batch_size,
            name="Salesforce/codegen2-16B",
            temperature=temperature,
        )
    elif name == "polycoder":
        return HFTorchDecoder(
            batch_size=batch_size,
            name="NinedayWang/PolyCoder-2.7B",
            temperature=temperature,
        )
    elif name == "santacoder":
        return SantaCoder(
            batch_size=batch_size, name="bigcode/santacoder", temperature=temperature
        )
    elif name == "incoder-1b":
        return IncoderDecoder(
            batch_size=batch_size, name="facebook/incoder-1B", temperature=temperature
        )
    elif name == "incoder-6b":
        return IncoderDecoder(
            batch_size=batch_size, name="facebook/incoder-6B", temperature=temperature
        )
    elif name == "stablelm-7b":
        return HFTorchDecoder(
            batch_size=batch_size,
            name="StabilityAI/stablelm-base-alpha-7b",
            temperature=temperature,
        )
    elif name.startswith("gpt-3.5-") or name.startswith("gpt-4o-mini"):
        return OpenAIChatDecoder(
            batch_size=batch_size,
            name=name,
            temperature=temperature,
            conversational=True,
        )
    elif name.startswith("deepseek-v3"):
        return DeepSeekV3Decoder(
            batch_size=batch_size,
            name=name,
            temperature=temperature,
            conversational=True,
        )
    elif name.startswith("claude"):
        return AnthropicMessageDecoder(
            batch_size=batch_size,
            name=name,
            temperature=temperature,
        )
    elif name.startswith("gemini"):
        return GeminiDecoder(
            batch_size=batch_size,
            name=name,
            temperature=temperature,
        )    
    elif name == "gptneo-2b":
        return HFTorchDecoder(
            batch_size=batch_size,
            name="EleutherAI/gpt-neo-2.7B",
            temperature=temperature,
        )
    elif name == "gpt-j":
        return HFTorchDecoder(
            batch_size=batch_size, name="EleutherAI/gpt-j-6B", temperature=temperature
        )
    elif name.startswith("starcoder"):
        # return VLlmDecoder( #why ?
        #     batch_size=batch_size,
        #     name=f"bigcode/{name}",
        #     temperature=temperature,
        #     tensor_parallel_size=ngpus,
        # )
        return StarCoderInfill( 
            batch_size=batch_size,
            name=f"{name}",
            temperature=temperature,
            conversational=True,
        )
    elif name.startswith("granite"):
        return HFTorchDecoder(
            batch_size=batch_size, name=name, temperature=temperature
        )
    elif name.startswith("codellama"):#CodeLlama-13b-Instruct-hf
        assert name.endswith("hf")
        nb = name.split("-")[-3]
        return HFTorchDecoder(
            batch_size=batch_size, name=f"CodeLlama-{nb}-Instruct-hf", temperature=temperature
        )
    elif name.startswith("code-llama-"):
        assert name.endswith("b")
        nb = name.split("-")[-1]
        return VLlmDecoder(
            batch_size=batch_size,
            name=f"codellama/CodeLlama-{nb}-Instruct-hf",
            temperature=temperature,
        )
    elif name == "codet5p-2b":
        return CodeT5P(
            batch_size=batch_size,
            name="Salesforce/codet5p-2b",
            temperature=temperature,
        )
    elif name == "codet5p-6b":
        return CodeT5P(
            batch_size=batch_size,
            name="Salesforce/codet5p-6b",
            temperature=temperature,
        )
    elif name == "codet5p-16b":
        return CodeT5P(
            batch_size=batch_size,
            name="Salesforce/codet5p-16b",
            temperature=temperature,
        )
    elif name.startswith("deepseek-coder"):
        import re

        # format deepseek-coder-{nb}b*
        #pattern = re.compile(r"deepseek-coder-(\d+\.?\d*)b(.*)")
        #matches = pattern.findall(name)[0]
       # nb = float(matches[0])
        #if nb.is_integer():
          #  nb = int(nb)

        if "instruct" in name:
            return DeepSeekInstruct(
                batch_size=batch_size,
                name=f"{name}",
                temperature=temperature,
                conversational=True,
            )
        else:
            nb = re.search(r"(\d+\.?\d*)", name).group(0)
            return VLlmDecoder(
                batch_size=batch_size,
                name=f"deepseek-ai/deepseek-coder-{nb}b-base",
                temperature=temperature,
                tensor_parallel_size=ngpus,
            )
    elif name == "wizardcoder-33b":
        return VLlmDecoder(
            batch_size=batch_size,
            name="WizardLM/WizardCoder-33B-V1.1",
            temperature=temperature,
            conversational=True,
            tensor_parallel_size=ngpus,
        )    
    elif name == "wizardcoder-34b":
        return VLlmDecoder(
            batch_size=batch_size,
            name="WizardLM/WizardCoder-Python-34B-V1.0",
            temperature=temperature,
            conversational=True,
            tensor_parallel_size=ngpus,
        )
    elif name == "wizardcoder-15b":
        return VLlmDecoder(
            batch_size=batch_size,
            name="WizardLM/WizardCoder-15B-V1.0",
            temperature=temperature,
            conversational=True,
            tensor_parallel_size=ngpus,
        )
    elif name == "wizardcoder-7b":
        return VLlmDecoder(
            batch_size=batch_size,
            name="WizardLM/WizardCoder-Python-7B-V1.0",
            temperature=temperature,
            conversational=True,
            tensor_parallel_size=ngpus,
        )
    elif name == "mistral-7b-codealpaca":
        return HFTorchDecoder(
            batch_size=batch_size,
            name="Nondzu/Mistral-7B-codealpaca-lora",
            temperature=temperature,
        )
    elif name == "zephyr-7b":
        return HFTorchDecoder(
            batch_size=batch_size,
            name="HuggingFaceH4/zephyr-7b-beta",
            temperature=temperature,
        )
    elif name == "codebooga-34b":
        return HFTorchDecoder(
            batch_size=batch_size,
            name="oobabooga/CodeBooga-34B-v0.1",
            temperature=temperature,
        )
    elif name == "phind-code-llama-34b-v2":
        return VLlmDecoder(    
            batch_size=batch_size,
            name="Phind/Phind-CodeLlama-34B-v2",
            temperature=temperature,
            tensor_parallel_size=ngpus,
        )
    elif name.startswith("mistral-7b"):
        return HFTorchDecoder(
            batch_size=batch_size,
            name=f"{name}",
            temperature=temperature,
            conversational=True
        )
    elif name == "dolphin-2.6":
        return ChatML(
            batch_size=batch_size,
            name="cognitivecomputations/dolphin-2.6-mixtral-8x7b",
            temperature=temperature,
            tensor_parallel_size=ngpus,
            # max_new_tokens=512 + 256,
        )
    elif name == "solar-10.7b-instruct":
        return ChatML(
            batch_size=batch_size,
            name="upstage/SOLAR-10.7B-Instruct-v1.0",
            temperature=temperature,
            conversational=True,
        )
    elif name == "mistral-hermes-codepro-7b":
        return ChatML(
            batch_size=batch_size,
            name="beowolx/MistralHermes-CodePro-7B-v1",
            temperature=temperature,
            # max_new_tokens=512 + 256,
        )
    elif name == "phi-2":
        return VLlmDecoder(    
            batch_size=batch_size,
            name="microsoft/phi-2",
            temperature=temperature,
            tensor_parallel_size=ngpus,
        )
    elif name == "mixtral-8x7b-instruct":
        return VLlmDecoder(
            batch_size=batch_size,
            name="mistralai/Mixtral-8x7B-Instruct-v0.1",
            temperature=temperature,
            tensor_parallel_size=ngpus,
        )
    elif name == "octocoder":
        return VLlmDecoder(
            batch_size=batch_size,
            name="bigcode/octocoder",
            temperature=temperature,
            tensor_parallel_size=ngpus,
        )
    elif name == "magicoder-s-ds-6.7b":
        return VLlmDecoder(
            batch_size=batch_size,
            name="ise-uiuc/Magicoder-S-DS-6.7B",
            temperature=temperature,
            tensor_parallel_size=ngpus,
        )
    elif name == "magicoder-s-cl-7b":
        return VLlmDecoder(
            batch_size=batch_size,
            name="ise-uiuc/Magicoder-S-CL-7B",
            temperature=temperature, 
            tensor_parallel_size=ngpus, 
        )
        
    elif name == "granite-8b-code-instruct-128k":
        return HFTorchDecoder(
            batch_size=batch_size,
            name="granite-8b-code-instruct-128k",  # Specify the exact name of the new model
            temperature=temperature,
        )

    raise ValueError(f"Invalid model name: {name}")
