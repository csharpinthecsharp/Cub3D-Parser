# Cub3D Parser
[Preview.webm](https://github.com/user-attachments/assets/ecaa9923-369e-4915-9b79-85adb29bfbd4)

A configuration file validator for the Cub3D project - a 3D game engine written in C, inspired by the classic Wolfenstein 3D.

## What This Does

This parser reads and validates `.cub` files that contain all the information needed to run the game: wall textures, colors, and the map layout. Think of it as a quality control system that makes sure everything is correct before the game starts.

## Quick Summary

The parser works in 4 main steps:
1. **Check the filename** - Is it a `.cub` file?
2. **Check the file exists** - Can we actually open it?
3. **Check it has everything** - Are all textures, colors, and map present?
4. **Validate the format** - Is everything written correctly and does the map make sense?

## Table of Contents

- [What This Does](#what-this-does)
- [Quick Summary](#quick-summary)
- [How It Works](#how-it-works)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Configuration File Format](#configuration-file-format)
- [Common Errors](#common-errors)

## How It Works

The parser goes through your configuration file in stages, like a security checkpoint that gets more thorough at each step.

**Stage 1: Filename Check**
The program first looks at what you typed. Did you give it a file that ends with `.cub`? If not, it stops here.

**Stage 2: File Access**
Next, it tries to open the file. Does the file actually exist? Can the program read it? If there's a problem, it tells you right away.

**Stage 3: Content Check**
Now it reads through the file to make sure all the required pieces are there: texture paths for each wall direction, floor and ceiling colors, and the map itself.

**Stage 4: Detailed Validation**
This is where it gets thorough. The parser checks four things:
- Are the texture file paths written correctly and do those files exist?
- Are the colors in the right format with valid numbers?
- Is everything organized properly in the file?
- Does the map make sense? (No holes in walls, one player starting position, proper boundaries)

The map validation uses a technique called "flood fill" - imagine pouring water on the map. If the water leaks out, there's a hole in your walls.

## Project Structure

Here's what's inside the project:

```
Cub3D-Parser/
├── includes/          Header files with structure definitions
├── parsing/           The parser code
│   ├── p_entry.c     Stages 1-3: Basic validation
│   ├── p_format.c    Stage 4: Detailed format checking
│   └── p_validate_format.c  Final verification step
├── libft/            Helper functions library
├── maps/             Example configuration files
├── Makefile          Instructions for building the program
└── main.c            Starting point of the program
```

## Getting Started

To build and run the parser:

```bash
# Build the program
make

# Run it with a configuration file
./cub3d maps/example.cub

# Clean up temporary files
make clean

# Remove everything and start fresh
make fclean

# Rebuild from scratch
make re
```

## Configuration File Format

A `.cub` file tells the game what textures to use, what colors for the floor and ceiling, and what the map looks like.

Here's an example:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

**What each part means:**

Texture Paths (which images to use for walls):
- `NO` - North-facing walls
- `SO` - South-facing walls
- `WE` - West-facing walls
- `EA` - East-facing walls

Colors (in Red, Green, Blue format):
- `F` - Floor color
- `C` - Ceiling color

Map symbols:
- `1` - A wall
- `0` - Empty walkable space
- `N`, `S`, `E`, or `W` - Where the player starts and which direction they face
- Space - Outside the map (must be surrounded by walls)

**Important rules:**
- The map must be completely surrounded by walls (1s)
- There must be exactly one player starting position
- Colors must be numbers between 0 and 255

## Common Errors

The parser will tell you exactly what's wrong. Here are the most common issues:

**File Problems:**
- Wrong file extension - Make sure your file ends with `.cub`
- File not found - Check the file path and spelling
- Can't access texture files - Make sure the texture paths in your file are correct

**Color Issues:**
- Numbers out of range - RGB values must be between 0 and 255
- Wrong format - Colors must be written as three numbers separated by commas (like `255,128,0`)

**Configuration Problems:**
- Missing elements - You need all four wall textures and both colors
- Duplicates - Each texture and color should only be defined once

**Map Errors:**
- Map not closed - The map must be completely surrounded by walls
- No player position - You need one `N`, `S`, `E`, or `W` for the player start
- Multiple players - You can only have one player starting position
- Invalid characters - Only use `1`, `0`, spaces, and one player direction letter
---

**Project by:** csharpinthecsharp  
**Language:** C  
**Purpose:** Configuration validator for Cub3D game engine
