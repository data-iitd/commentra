def main():
    ave = 0.0
    
    for i in range(5):
        a = float(input())
        if a <= 40:
            ave += 40
        else:
            ave += a
            
    ave /= 5.0
    
    print(f"{ave:.0f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
