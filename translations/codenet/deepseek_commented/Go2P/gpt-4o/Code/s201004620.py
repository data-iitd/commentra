# Declare a string variable S to store the weather input
S = input()

# Use a dictionary to determine the weather based on the input
weather_dict = {
    "Sunny": "Cloudy",
    "Cloudy": "Rainy",
    "Rainy": "Sunny"
}

# Print the corresponding weather if the input is valid
if S in weather_dict:
    print(weather_dict[S])

# <END-OF-CODE>
