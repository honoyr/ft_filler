

# About Filler
Filler is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one
square above each other and without them exceeding the grid. If one of these conditions
is not met, the game stops.
Each successfully placed piece yields a number of points, and has only one player, the
goal of the game could be to get the best score possible. However, it is with two players
that the filler takes all his interest. Each player has for the purpose of placing as many
pieces as possible while attempting to prevent his opponent from doing the same. At the
end of the game, the one with the most points wins the match...

<img width="602" alt="2018-07-04 16 07 41" src="https://user-images.githubusercontent.com/33597605/42278732-6e016fb8-7fa4-11e8-8947-f150ab3597f9.png">

On the left: the initial state of the grid, at the right: the result after the fight between
two players.

The objective of this project. Writing a Filler playe

# More specifically

- In this game, two players fight each other. They play one after the other.
- The goal is to collect as many points as possible by placing the highest number of
pieces on the the game board.
- The board is defined by X columns and N lines, it will then become X*N cells.
- At the beginning of each turn, you will receive your game piece.
- A game piece is defined by X columns and N lines, so it will be X*N cells. Inside
each game piece, will be included a shape of one or many cells.
- To be able to place a piece on the board, it is mandatory that one, and only one
cell of the shape (in your piece) covers the cell of a shape placed previously (your
territory).
- The shape must not exceed the dimensions of the board
- When the game starts, the board already contains one shape.
- The game stops at the first error: either when a game piece cannot be placed
anymore or it has been wrongly placed

THE BOARD

A board is a two-dimensional grid with an arbitrary number of rows and columns. To
launch the game an initial board must be passed as an argument to the VM. This initial
board must have a starting form for each player.

Here is an example of an initial board of 14 by 30 :

<img width="602" alt="2018-07-04 16 16 29" src="https://user-images.githubusercontent.com/33597605/42279181-a5d629be-7fa5-11e8-98a9-b844d282f3d5.png">

 THE TOKENS
 
 The tokens are managed randomly by the VM:

<img width="602" alt="2018-07-04 16 17 25" src="https://user-images.githubusercontent.com/33597605/42279222-c6e30eec-7fa5-11e8-8ffd-d7545cdb9355.png">

Here is an example on how a game will roll out:

<img width="562" alt="2018-07-04 16 20 18" src="https://user-images.githubusercontent.com/33597605/42279355-2e7a390e-7fa6-11e8-9b32-0cc0c250121e.png">



The makefile creates my player by the name dgonor.filler
<img width="880" alt="2018-07-04 16 33 05" src="https://user-images.githubusercontent.com/33597605/42280003-2b8ecd02-7fa8-11e8-89ac-01e7d62fd3c2.png">


# Start

![ezgif-2-077a097293](https://user-images.githubusercontent.com/33597605/42281884-82700e4c-7fad-11e8-8ffe-f4587cfc7c19.gif)

![ezgif-2-b83740b1c5](https://user-images.githubusercontent.com/33597605/42281739-2317c2a0-7fad-11e8-93e2-a26ceb9e4be6.gif)

![ezgif-2-b93a2f0de1](https://user-images.githubusercontent.com/33597605/42281771-39f6b044-7fad-11e8-868c-159a24312233.gif)
