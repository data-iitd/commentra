
import math
import sys
from PIL import Image, ImageDraw

# read image width and steps from user input
image_width = int(sys.stdin.readline().strip())
steps = int(sys.stdin.readline().strip())

# generate the Koch snowflake image
image = get_main(image_width, steps)

# read file path from user input and save the image
file_path = sys.stdin.readline().strip()
image.save(file_path)

# 