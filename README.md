# game-of-life
conway's game of life 

This is a simple version of Conway's Game of Life written in C. It obeys standard rules of the GoL:
1. A cell surrounded by 3 living cells will always remain or become alive. 
2. A living cell surounded by 2 living cells will remain alive. 
3. A cell surrounded by more than 3 living cells will die. 
4. A cell surrounded by less than 2 living cells will also die. 

As of May 5, this is a functional version. It can take commands via command line with the flags -h for setting the height and -w 
for setting the width. All unflagged numbers are treated as coordinates of initial living cells, as long as they are paired. 
