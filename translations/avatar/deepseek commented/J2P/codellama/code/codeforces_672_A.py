
import sys 

def generate_string(): 
    string = "" 
    for i in range(1, 1001): 
        string += str(i) 
    return string 

def main(): 
    n = int(sys.stdin.readline().strip()) 
    print(generate_string()[n - 1]) 

if __name__ == "__main__": 
    main() 

