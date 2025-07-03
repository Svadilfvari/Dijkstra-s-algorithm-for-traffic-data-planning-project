# Dijkstra’s Algorithm for Traffic Data Planning

This project implements Dijkstra’s algorithm in C++ to compute the shortest path between metro stations in the Paris metro network. The goal is to use traffic data to plan optimal travel routes.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [File Structure](#file-structure)
- [How It Works](#how-it-works)
- [Usage](#usage)
- [Examples](#examples)
- [References](#references)

## Overview

This project is inspired by the original work of Edsger W. Dijkstra (1959), and applies the shortest-path algorithm in the context of public transportation routing, specifically the Paris metro system. It models the stations and their connections as a directed graph where the nodes are stations and the edges are travel times.

## Features

- Parses station and connection data from CSV files
- Builds a directed graph representing the metro network
- Computes shortest paths using Dijkstra's algorithm
- Supports queries using both station IDs and station names
- Displays the computed travel route and time

## File Structure

- `project.cpp`: Main C++ implementation file.
- `stations.csv`: Contains metadata about stations (names, addresses, IDs).
- `connections.csv`: Contains travel time between connected stations.
- `README.md`: This documentation file.

## How It Works

The project implements a class hierarchy:

1. **Generic_station_parser**: Parses station data and stores it in a hashmap.
2. **Generic_connection_parser**: Parses connections and stores travel times.
3. **Generic_mapper**: Adds logic to compute shortest paths.
4. **Network**: Inherits from all above and exposes a unified interface.

### Main Methods

- `read_stations`: Loads and maps station data.
- `read_connections`: Loads travel times between stations.
- `compute_travel`: Core implementation of Dijkstra's algorithm.
- `compute_and_display_travel`: Computes and prints the shortest path.
- `find_id_station`: Utility to resolve station names to IDs.

## Usage

1. Ensure `stations.csv` and `connections.csv` are in the correct format and available in the working directory.
2. Compile the project:
   ```bash
   g++ project.cpp -o traffic_planner
   ```
3. Run the executable:
  ```bash
./traffic_planner
 ```
4. Follow prompts or modify the main() logic to pass in station IDs or names.
## Examples

### Example 1: Using Station Names
 ```bash
/////Test with the names of the stations
From Villiers To Rome
Best route from station 1630 to station 1707:
From station 1630 to station 2509
From station 2509 to station 2452
From station 2452 to station 1707
```
### Example 2: Using Station IDs
 ```bash
Best route from station 2422 to station 2287:
From station 2422 to station 1744
From station 1744 to station 1985
From station 1985 to station 2080
From station 2080 to station 1703
From station 1703 to station 1676
From station 1676 to station 2486
From station 2486 to station 1675
From station 1675 to station 2485
From station 2485 to station 2297
From station 2297 to station 2247
From station 2247 to station 2382
From station 2382 to station 2424
From station 2424 to station 2287
```
# References

Dijkstra, E. W. (1959). A note on two problems in connexion with graphs. Numerische Mathematik, 1(1):269–271.

