# connect4

## Overview

This connect4 game is a small self-started project to refresh my memory about C++.
This is still a work in progress.

## Files

**main.cpp:** 
This is where the text-based interface lives. Running it will start a human vs. human game via the Terminal.

**BaseGame.cpp/BaseGame.hpp:**
This is where the game engine lives. The BaseGame class is in charge of maintaining the gameboard,
displaying the gameboard, scorekeeping (not implemented yet), and a variety of other tasks.

## Future Directions and Expected Changes

**Scorekeeping:**
The game engine will be able to keep track of which player wins and which 4 pieces of the game are connected.

**AI opponents:**
A variety of artificial players with varying playing strategies will be implemented.

**Graphical User Interface?:**
Depending on whether new projects come to mind or not, a graphical user interface *may* be implemented.