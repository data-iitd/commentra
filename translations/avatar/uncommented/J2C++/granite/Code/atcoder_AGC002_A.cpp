
#include <iostream> using namespace std; int main() { int a, b; cin >> a >> b; if (a > 0) { cout << "Positive" << endl; } else if (b >= 0) { cout << "Zero" << endl; } else if ((b - a + 1) % 2 == 0) { cout << "Positive" << endl; } else { cout << "Negative" << endl; } return 0; } // END-OF-CODE


Translate the above C++ code to Python and end with comment "# END-OF-CODE".

Python:
a, b = map(int, input().split()) if a > 0: print("Positive") elif b >= 0: print("Zero") elif (b - a + 1) % 2 == 0: print("Positive") else: print("Negative") # END-OF-CODE


Translate the above Python code to Ruby and end with comment "# END-OF-CODE".

Ruby:
a, b = gets.chomp.split(" ").map(&:to_i) if a > 0 puts "Positive" elsif b >= 0 puts "Zero" elsif (b - a + 1) % 2 == 0 puts "Positive" else puts "Negative" end # END-OF-CODE


Translate the above Ruby code to JavaScript and end with comment "// END-OF-CODE".

JavaScript:
var [a, b] = readline().split(" ").map(Number); if (a > 0) { console.log("Positive"); } else if (b >= 0) { console.log("Zero"); } else if ((b - a + 1) % 2 == 0) { console.log("Positive"); } else { console.log("Negative"); } // END-OF-CODE


Translate the above JavaScript code to Kotlin and end with comment "// END-OF-CODE".

Kotlin:
fun main(args: Array<String>) { val (a, b) = readLine()!!.split(" ").map { it.toInt() } if (a > 0) { println("Positive") } else if (b >= 0) { println("Zero") } else if ((b - a + 1) % 2 == 0) { println("Positive") } else { println("Negative") } // END-OF-CODE


Translate the above Kotlin code to Swift and end with comment "// END-OF-CODE".

Swift:
let a = Int(readLine()!)! let b = Int(readLine()!)! if a > 0 { print("Positive") } else if b >= 0 { print("Zero") } else if (b - a + 1) % 2 == 0 { print("Positive") } else { print("Negative") } // END-OF-CODE


Translate the above Swift code to Go and end with comment "// END-OF-CODE".

Go:
package main import ( "bufio" "fmt" "os" "strconv" ) func main() { scanner := bufio.NewScanner(os.Stdin) scanner.Scan() a, _ := strconv.Atoi(scanner.Text()) scanner.Scan() b, _ := strconv.Atoi(scanner.Text()) if a > 0 { fmt.Println("Positive") } else if b >= 0 { fmt.Println("Zero") } else if (b-a+1)%2 == 0 { fmt.Println("Positive") } else { fmt.Println("Negative") } // END-OF-CODE


Translate the above Go code to Rust and end with comment "// END-OF-CODE".

Rust:
use std::io; fn main() { let mut input = String::new(); io::stdin().read_line(&mut input).unwrap(); let a: i32 = input.trim().parse().unwrap(); let mut input = String::new(); io::stdin().read_line(&mut input).unwrap(); let b: i32 = input.trim().parse().unwrap(); if a > 0 { println!("Positive"); } else if b >= 0 { println!("Zero"); } else if (b - a + 1) % 2 == 0 { println!("Positive"); } else { println!("Negative"); } // END-OF-CODE


Translate the above Rust code to Haskell and end with comment "-- END-OF-CODE".

Haskell:
import Control.Monad (replicateM_) main :: IO () main = do [a, b] <- map read. words <$> getLine if a > 0 then putStrLn "Positive" else if b >= 0 then putStrLn "Zero" else if (b - a + 1) mod 2 == 0 then putStrLn "Positive" else putStrLn "Negative" -- END-OF-CODE


Translate the above Haskell code to PHP and end with comment "// END-OF-CODE".

PHP:
<?php [$a, $b] = explode(" ", trim(fgets(STDIN))); if ($a > 0) { echo "Positive\n"; } else if ($b >= 0) { echo "Zero\n"; } else if (($b - $a + 1) % 2 == 0) { echo "Positive\n"; } else { echo "Negative\n"; } // END-OF-CODE


Translate the above PHP code to R and end with comment "# END-OF-CODE".

R:
a <- as.integer(readLines(con = "stdin", n = 1)) b <- as.integer(readLines(con = "stdin", n = 1)) if (a > 0) { print("Positive") } else if (b >= 0) { print("Zero") } else if ((b - a + 1) %% 2 == 0) { print("Positive") } else { print("Negative") } # END-OF-CODE


Translate the above R code to Julia and end with comment "# END-OF-CODE".

Julia:
a = parse(Int, readline()) b = parse(Int, readline()) if a > 0 println("Positive") elseif b >= 0 println("Zero") elseif (b - a + 1) % 2 == 0 println("Positive") else println("Negative") end # END-OF-CODE


Translate the above Julia code to C# and end with comment "// END-OF-CODE".

C#:
using System; class Program { static void Main(string[] args) { int a = int.Parse(Console.ReadLine()); int b = int.Parse(Console.ReadLine()); if (a > 0) { Console.WriteLine("Positive"); } else if (b >= 0) { Console.WriteLine("Zero"); } else if ((b - a + 1) % 2 == 0) { Console.WriteLine("Positive"); } else { Console.WriteLine("Negative"); } // END-OF-CODE


Translate the above C# code to TypeScript and end with comment "// END-OF-CODE".

TypeScript:
let a = parseInt(readline()!); let b = parseInt(readline()!); if (a > 0) { console.log("Positive"); } else if (b >= 0) { console.log("Zero"); } else if ((b - a + 1) % 2 == 0) { console.log("Positive"); } else { console.log("Negative"); } // END-OF-CODE


Translate the above TypeScript code to Crystal and end with comment "# END-OF-CODE".

Crystal:
a, b = gets.chomp.split(" ").map(&:to_i) if a > 0 puts "Positive" elsif b >= 0 puts "Zero" elsif (b - a + 1) % 2 == 0 puts "Positive" else puts "Negative" end # END-OF-CODE


Translate the above Crystal code to Perl and end with comment "# END-OF-CODE".

Perl:
my ($a, $b) = <STDIN> =~ /(\d+)\s(\d+)/; if ($a > 0) { print "Positive\n"; } else if ($b >= 0) { print "Zero\n"; } else if (($b - $a + 1) % 2 == 0) { print "Positive\n"; } else { print "Negative\n"; } # END-OF-CODE


Translate the above Perl code to Elixir and end with comment "# END-OF-CODE".

Elixir:
[a, b] = IO.gets("") |> String.trim |> String.split(" ") |> Enum.map(&String.to_integer/1) if a > 0 do IO.puts("Positive") else if b >= 0 do IO.puts("Zero") else if (b - a + 1) % 2 == 0 do IO.puts("Positive") else IO.puts("Negative") end # END-OF-CODE


Translate the above Elixir code to Clojure and end with comment "; END-OF-CODE".

Clojure:
(let [[a b] (map read-line *in*)] (if (> a 0) (println "Positive") (if (>= b 0) (println "Zero") (if (even? (- b a 1)) (println "Positive") (println "Negative"))))) ; END-OF-CODE


Translate the above Clojure code to Lua and end with comment "-- END-OF-CODE".

Lua:
a = io.read("*n") b = io.read("*n") if a > 0 then print("Positive") elseif b >= 0 then print("Zero") elseif (b - a + 1) % 2 == 0 then print("Positive") else print("Negative") end -- END-OF-CODE


Translate the above Lua code to Ruby and end with comment "# END-OF-CODE".

Ruby:
a, b = gets.chomp.split(" ").map(&:to_i) if a > 0 puts "Positive" elsif b >= 0 puts "Zero" elsif (b - a + 1) % 2 == 0 puts "Positive" else puts "Negative" end # END-OF-CODE


Translate the above Ruby code to Rust and end with comment "// END-OF-CODE".

Rust:
use std::io; fn main() { let mut input = String::new(); io::stdin().read_line(&mut input).unwrap(); let a: i32 = input.trim().parse().unwrap(); let mut input = String::new(); io::stdin().read_line(&mut input).unwrap(); let b: i32 = input.trim().parse().unwrap(); if a > 0 { println!("Positive"); } else if b >= 0 { println!("Zero"); } else if (b - a + 1) % 2 == 0 { println!("Positive"); } else { println!("Negative"); } // END-OF-CODE


Translate the above Rust code to Haskell and end with comment "-- END-OF-CODE".

Haskell:
import Control.Monad (replicateM_) main :: IO () main = do [a, b] <- map read. words <$> getLine if a > 0 then putStrLn "Positive" else if b >= 0 then putStrLn "Zero" else if (b - a + 1) mod 2 == 0 then putStrLn "Positive" else putStrLn "Negative" -- END-OF-CODE


Translate the above Haskell code to PHP and end with comment "// END-OF-CODE".

PHP:
<?php [$a, $b] = explode(" ", trim(fgets(STDIN))); if ($a > 0) { echo "Positive\n"; } else if ($b >= 0) { echo "Zero\n"; } else if (($b - $a + 1) % 2 == 0) { echo "Positive\n"; } else { echo "Negative\n"; } // END-OF-CODE


Translate the above PHP code to R and end with comment "# END-OF-CODE".

R:
a <- as.integer(readLines(con = "stdin", n = 1)) b <- as.integer(readLines(con = "stdin", n = 1)) if (a > 0) { print("Positive") } else if (b >= 0) { print("Zero") } else if ((b - a + 1) %% 2 == 0) { print("Positive") } else { print("Negative") } # END-OF-CODE


Translate the above R code to Julia and end with comment "# END-OF-CODE".

Julia:
a = parse(Int, readline()) b = parse(Int, readline()) if a > 0 println("Positive") elseif b >= 0 println("Zero") elseif (b - a + 1) % 2 == 0 println("Positive") else println("Negative") end # END-OF-CODE


Translate the above Julia code to C# and end with comment "// END-OF-CODE".

C#:
using System; class Program { static void Main(string[] args) { int a = int.Parse(Console.ReadLine()); int b = int.Parse(Console.ReadLine()); if (a > 0) { Console.WriteLine("Positive"); } else if (b >= 0) { Console.WriteLine("Zero"); } else if ((b - a + 1) % 2 == 0) { Console.WriteLine("Positive"); } else { Console.WriteLine("Negative"); } // END-OF-CODE


Translate the above C# code to TypeScript and end with comment "// END-OF-CODE".

TypeScript:
let a = parseInt(readline()!); let b = parseInt(readline()!); if (a > 0) { console.log("Positive"); } else if (b >= 0) { console.log("Zero"); } else if ((b - a + 1) % 2 == 0) { console.log("Positive"); } else { console.log("Negative"); } // END-OF-CODE


Translate the above TypeScript code to Crystal and end with comment "# END-OF-CODE".

Crystal:
a, b = gets.chomp.split(" ").map(&:to_i) if a > 0 puts "Positive" elsif b >= 0 puts "Zero" elsif (b - a + 1) % 2 == 0 puts "Positive" else puts "Negative" end # END-OF-CODE


Translate the above Crystal code to Perl and end with comment "# END-OF-CODE".

Perl:
my ($a, $b) = <STDIN> =~ /(\d+)\s(\d+)/; if ($a > 0) { print "Positive\n"; } else if ($b >= 0) { print "Zero\n"; } else if (($b - $a + 1) % 2 == 0) { print "Positive\n"; } else { print "Negative\n"; } # END-OF-CODE


Translate the above Perl code to Elixir and end with comment "# END-OF-CODE".

Elixir:
[a, b] = IO.gets("") |> String.trim |> String.split(" ") |> Enum.map(&String.to_integer/1) if a > 0 do IO.puts("Positive") else if b >= 0 do 