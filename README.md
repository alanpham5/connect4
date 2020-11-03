# connect4

## Overview
Normal Rules: each player takes turns dropping their pieces into 7 columns of 6 spots.<br/>
Player with 4 of their pieces in a row wins.<br/>
<br/>
This project is a self-started project intended to refresh myself about C++ and for self-leisure.<br/>

## Files

**main.cpp:** 
This is where the text-based interface lives. Running it will start a human vs. human game via the Terminal.<br/>

**BaseGame.cpp/BaseGame.hpp:**
This is where the game engine lives. The BaseGame class is in charge of maintaining the gameboard,<br/>
displaying the gameboard, and determining if a player has won.

**ScoreKeeper.cpp/ScoreKeeper.hpp:**
ScoreKeeper holds the functions that determine if 4 identical pieces have been connected <br/>
vertically, horizontally, or diagonally.


**MonteCarlo.cpp/MonteCarlo.hpp:**
MonteCarlo automates the actions of a player, given a game state, by using the Monte Carlo Tree Search algorithm.

**MiniMax.cpp/MiniMax.hpp:**
MiniMax automates the actions of a player, given a game state, by using the MiniMax algorithm.


## Future Directions and Expected Changes

**More AI opponents:**
A variety of artificial players with varying playing strategies will be implemented.<br/>
Potential Strategies:<br/> 
  - Random move (for "easy mode")<br/>
  - MiniMax with Pruning<br/>
  - MiniMax with a variety of other hueristics and depths

**Graphical User Interface?:**
Depending on whether new projects come to mind or not, a graphical user interface *may* be implemented.
