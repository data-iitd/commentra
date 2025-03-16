import random
import sys

# Private function to generate Perlin noise
def generate_main(width, height, octave_count, persistence, seed):
    # Create arrays to hold base noise, final Perlin noise, and noise layers for each octave
    base = [[0.0 for y in range(height)] for x in range(width)]
    perlin_noise = [[0.0 for y in range(height)] for x in range(width)]
    noise_layers = [[[0.0 for y in range(height)] for x in range(width)] for octave in range(octave_count)]

    # Initialize random number generator with the provided seed
    random.seed(seed)

    # Generate base noise values
    for x in range(width):
        for y in range(height):
            base[x][y] = random.random() # Fill base array with random floats

    # Generate noise layers for each octave
    for octave in range(octave_count):
        noise_layers[octave] = generate_main_layer(base, width, height, octave)

    # Initialize amplitude and total amplitude for combining noise layers
    amplitude = 1.0
    total_amplitude = 0.0

    # Combine noise layers using persistence and amplitude
    for octave in range(octave_count - 1, -1, -1):
        amplitude *= persistence # Decrease amplitude based on persistence
        total_amplitude += amplitude # Accumulate total amplitude
        for x in range(width):
            for y in range(height):
                perlin_noise[x][y] += noise_layers[octave][x][y] * amplitude # Combine noise layers

    # Normalize the final Perlin noise values
    for x in range(width):
        for y in range(height):
            perlin_noise[x][y] /= total_amplitude # Normalize by total amplitude
    return perlin_noise # Return the generated Perlin noise

# Private function to generate a single layer of Perlin noise for a specific octave
def generate_main_layer(base, width, height, octave):
    perlin_noise_layer = [[0.0 for y in range(height)] for x in range(width)]
    period = 1 << octave # Calculate period based on octave
    frequency = 1.0 / period # Calculate frequency based on period

    # Generate noise values for the current octave
    for x in range(width):
        x0 = (x / period) * period # Find the left coordinate
        x1 = (x0 + period) % width # Find the right coordinate
        horizontal_blend = (x - x0) * frequency # Calculate horizontal blend factor

        for y in range(height):
            y0 = (y / period) * period # Find the top coordinate
            y1 = (y0 + period) % height # Find the bottom coordinate
            vertical_blend = (y - y0) * frequency # Calculate vertical blend factor

            # Interpolate between the corners of the grid cell
            top = interpolate(base[x0][y0], base[x1][y0], horizontal_blend)
            bottom = interpolate(base[x0][y1], base[x1][y1], horizontal_blend)
            perlin_noise_layer[x][y] = interpolate(top, bottom, vertical_blend) # Final interpolation
    return perlin_noise_layer # Return the generated noise layer

# Private function to perform linear interpolation between two values
def interpolate(a, b, alpha):
    return a * (1 - alpha) + alpha * b # Linear interpolation formula

# Main function to execute the program
if __name__ == "__main__":
    # Read user input for noise parameters
    width = int(input())
    height = int(input())
    octave_count = int(input())
    persistence = float(input())
    seed = int(input())
    charset = input()

    # Generate Perlin noise based on user input
    perlin_noise = generate_main(width, height, octave_count, persistence, seed)

    # Convert character set to array and calculate step size for mapping noise values
    chars = list(charset)
    length = len(chars)
    step = 1.0 / length

    # Output the generated Perlin noise as characters
    for x in range(width):
        for y in range(height):
            value = step # Initialize value for character mapping
            noise_value = perlin_noise[x][y] # Get the noise value for the current position
            for c in chars:
                if noise_value <= value: # Check if noise value falls within the current range
                    sys.stdout.write(c) # Print the corresponding character
                    break # Exit the loop once a character is printed
                value += step # Move to the next range
        sys.stdout.write("\n") # Move to the next line after finishing a row

# 