# Sea-based Natural Resource Exploration Project 🌊

## About The Project

This project is a software designed to help companies conducting marine natural resource exploration and extraction operations to divide their search areas into optimally sized parcels with the most appropriate number to maximize profit.

## Features

### Phase 1 - Seismic Research
- Reading coordinate points from web page
- Drawing closed areas by connecting coordinate points
- Surface area calculation and determination of resource reserve value

### Phase 2 - Drilling and Resource Extraction
- Optimal division of reserve areas into square parcels
- Platform placement optimization
- Cost and profit calculations

## Technologies Used

- C Programming Language
- Graphics.h Library

## Installation

1. Clone the project:
```bash
git clone https://github.com/MerttMetinn/Sea-based-natural-resource-exploration.git
```

2. Install required libraries:
- Graphics.h library
- GCC compiler

3. Compile and run the project:
```bash
gcc main.cpp -o main -lgraph
./main
```

## Usage

1. When the program runs, it asks for:
   - Unit drilling cost (between 1-10)
   - Unit platform cost
   - Line number to process

2. The program operates in two phases:
   - First phase visualizes the reserve area
   - Second phase performs optimal partitioning

3. Results displayed on screen:
   - Total number of platforms
   - Total number of drilling operations
   - Total cost
   - Profit amount

## Constraints

1. Drilling Areas:
   - Drilling is performed in all areas where reserve region boundaries pass through
   - Total drilling area is aimed to be minimized

2. Platform Placement:
   - One platform must be installed in each square area
   - The number of platforms is aimed to be minimized

3. Area Dimensions:
   - Square areas can be: 1x1, 2x2, 4x4, 8x8, or 16x16
   - Adjacent areas can only be one size larger or smaller

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) file for details.

## Contact

Mert Metin - [GitHub](https://github.com/MerttMetinn)
