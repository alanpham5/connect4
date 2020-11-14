# connect4

## Overview
Normal Rules: each player takes turns dropping their pieces into 7 columns of 6 spots.<br/>
Player with 4 of their pieces in a row wins.<br/>
<br/>
To play: Run the main executable file.
<br/>
## Classes

**BaseGame.cpp/BaseGame.hpp:**
This is where the game engine lives. The BaseGame class is in charge of maintaining the gameboard,<br/>
displaying the gameboard, and determining if a player has won.

**ScoreKeeper.cpp/ScoreKeeper.hpp:**
ScoreKeeper holds the functions that determine if 4 identical pieces have been <br/>
connected vertically, horizontally, or diagonally.

**RandomAI.cpp/RandomAI.hpp:**
Picks a random legal move with zero logic whatsoever.

**MonteCarlo.cpp/MonteCarlo.hpp:**
MonteCarlo automates the actions of a player, given a game state, by using a light version of <br/>
the Monte Carlo Tree Search algorithm.

**MiniMax.cpp/MiniMax.hpp:**
MiniMax automates the actions of a player, given a game state, by using the MiniMax algorithm.

**MiniMaxLite.cpp/MiniMaxLite.hpp:**
MiniMax automates the actions of a player, given a game state, by using MiniMax <br/>
with alpha-beta pruning and a more basic hueristic evaluation function.


## Future Directions and Expected Changes

**Graphical User Interface?:**
Depending on whether new projects come to mind or not, a graphical user interface *may* be implemented.
