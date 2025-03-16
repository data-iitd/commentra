
```python
# Function to generate a character array from the concatenation of numbers 1 to 1000
def generate_string():
    return ''.join(str(i) for i in range(1, 1001))

# Reading an integer input from the user
n = int(input())

# Printing the character at the (n-1)th index of the generated character array
print(generate_string()[n - 1])
```

