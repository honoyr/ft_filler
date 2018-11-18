# ft_filler
About Filler
Filler is an algorithmic game which consists in filling a grid of a known size in advance with pieces of random size and shapes, without the pieces being stacked more than one square above each other and without them exceeding the grid. If one of these conditions is not met, the game stops. Each successfully placed piece yields a number of points, and has only one player, the goal of the game could be to get the best score possible. However, it is with two players that the filler takes all his interest. Each player has for the purpose of placing as many pieces as possible while attempting to prevent his opponent from doing the same. At the end of the game, the one with the most points wins the match...

2018-07-04 16 07 41

On the left: the initial state of the grid, at the right: the result after the fight between two players.

The objective of this project. Writing a Filler playe

More specifically
In this game, two players fight each other. They play one after the other.
The goal is to collect as many points as possible by placing the highest number of pieces on the the game board.
The board is defined by X columns and N lines, it will then become X*N cells.
At the beginning of each turn, you will receive your game piece.
A game piece is defined by X columns and N lines, so it will be X*N cells. Inside each game piece, will be included a shape of one or many cells.
To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in your piece) covers the cell of a shape placed previously (your territory).
The shape must not exceed the dimensions of the board
When the game starts, the board already contains one shape.
The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed
THE BOARD

A board is a two-dimensional grid with an arbitrary number of rows and columns. To launch the game an initial board must be passed as an argument to the VM. This initial board must have a starting form for each player.

Here is an example of an initial board of 14 by 30 :

2018-07-04 16 16 29

THE TOKENS

The tokens are managed randomly by the VM:

2018-07-04 16 17 25

Here is an example on how a game will roll out:

2018-07-04 16 20 18

The makefile creates my player by the name dkotenko.filler 
