# So Long

## Objectives
This project aims to develop a basic computer graphics project using the MiniLibX library. By working on this project, you'll improve your skills in window management, event handling, colors, textures, and more. Additionally, it's an opportunity to enhance your proficiency in C programming, basic algorithms, and research skills.

## Description
You are required to create a basic 2D game where a character (e.g., a dolphin) escapes Earth after eating some fish. Customize the characters, collectibles, and environment according to your preference. The project must adhere to the following rules:

- Utilize the MiniLibX library, available either on school machines or by installing it from its sources.
- Provide a Makefile that compiles source files without relinking.
- The program should accept a map description file ending with the .ber extension as a parameter.

# Game Rules
- The player's objective is to collect all collectibles on the map and then escape by choosing the shortest possible route.
- Movement controls: W, A, S, D keys for up, down, left, and right directions.
- The player cannot move through walls.
- Display the current number of movements in the shell after each move.
- Implement a 2D view (top-down or profile) for the game.
- The game does not have to be real-time.

# Graphic Management
- Display the game image in a window.
- Ensure smooth window management (e.g., switching to another window, minimizing).
- Pressing ESC or clicking the window's cross must close the window and quit the program cleanly.

# Map
- The map consists of walls, collectibles, and free space.
- Characters used in the map: 0 (empty space), 1 (wall), C (collectible), E (map exit), P (player's starting position).
- The map must contain at least one exit, one collectible, and one starting position to be valid.
- Ensure the map is rectangular and surrounded by walls.
- Validate the presence of a valid path in the map.
- Parse any valid map respecting the above rules.

# Bonus
Implementing features such as making the player lose when touching an enemy patrol, adding sprite animation, or displaying the movement count directly on the screen.

# Usage
To compile and run the so_long program, follow these steps:

1. Clone the repository to your local machine:
  - git clone https://github.com/99berk/so_long.git

2. Navigate to the project directory:
  - cd <project_directory>

3. Compile the source files using the provided Makefile:
  - make

4. Run the program with a map description file (ending with .ber extension) as an argument:
  - ./so_long <map_file.ber>
