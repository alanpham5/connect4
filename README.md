# connect4

## Overview

Connect4 is a game where each player takes turns dropping their pieces into 7 columns of 6 spots.
This project is a self-started project intended to refresh myself about C++ and for self-leisure.

*This is still a work in progress.*

## Files

**main.cpp:** 
This is where the text-based interface lives. Running it will start a human vs. human game via the Terminal.

**BaseGame.cpp/BaseGame.hpp:**
This is where the game engine lives. The BaseGame class is in charge of maintaining the gameboard,
displaying the gameboard, and determining if a player has won.

**ScoreKeeper.cpp/ScoreKeeper.hpp:**
ScoreKeeper holds the functions that determine if 4 identical pieces have been connected vertically, horizontally,
or diagonally.


## Future Directions and Expected Changes

**AI opponents:**
A variety of artificial players with varying playing strategies will be implemented.
Potential Strategies: MiniMax (depth-first based), Monte Carlo (random sampling), Random move (for "easy mode")

**Graphical User Interface?:**
Depending on whether new projects come to mind or not, a graphical user interface *may* be implemented.
