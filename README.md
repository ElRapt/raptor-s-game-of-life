
# Raptor's Game of Life

![GitHub](https://img.shields.io/github/license/ElRapt/raptor-s-game-of-life)
![Language](https://img.shields.io/badge/Language-C++-darkblue)
![Builder](https://img.shields.io/badge/Builder-CMake-yellow)
![GUI](https://img.shields.io/badge/GUI-SFML-red)
![Size](https://img.shields.io/badge/Size-1MB-yellowgreen)

## Description
This repository contains a custom implementation of Conway's Game of Life in C++, using CMake. The project includes automated build and test configurations.

## Features
- **Aging Cells**: Cells in the grid age as the game progresses, affecting their color and making them more prone to death by natural causes.
- **Mersenne Twister Random Number Generation**: Utilizes the Mersenne Twister algorithm for generating high-quality pseudo-random numbers, providing more unpredictable and natural patterns in the game grid.
- **Hexagonal Grids**: Cells are arranged in a hexagonal pattern, adding a unique twist to the game dynamics.
- **Pausable**: The game can be paused and resumed by pressing the 'P' key.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Installation

### Prerequisites
- C++ compiler (supporting C++11 or above)
- CMake (Version 3.10 or higher)
- SFML library

### Steps
1. Clone the repository
   ```bash
   git clone https://github.com/YourUsername/raptor-s-game-of-life.git
   ```
2. Navigate into the project directory
   ```bash
   cd raptor-s-game-of-life
   ```
3. Create a build directory and navigate into it
   ```bash
   mkdir build && cd build
   ```
4. Run CMake and build the project
   ```bash
   cmake ..
   make
   ```

## Usage

Run the executable generated in the `build` directory:
```bash
./RaptorsGameOfLife
```

## Contributing
Feel free to submit pull requests or open issues to improve the project. Please adhere to the existing coding style and comment your changes.

## License
This project is licensed under the MIT License. See the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgements
- [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

