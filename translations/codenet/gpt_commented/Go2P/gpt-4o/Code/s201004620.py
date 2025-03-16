# Declare a variable to hold the weather condition input
S = input()

# Use a dictionary to determine the next weather condition based on the input
weather_conditions = {
    "Sunny": "Cloudy",
    "Cloudy": "Rainy",
    "Rainy": "Sunny"
}

# Print the next weather condition based on the input
if S in weather_conditions:
    print(weather_conditions[S])

# <END-OF-CODE>
