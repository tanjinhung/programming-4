# Event Flow

### Usecase 1 : Creating a user
---------------------------------
**actor**     : player  
**pre-ops**   : press create Profile button  
**post-ops**  : switch screen to Level Select  
**flow**      :   
1. Overlay profile creation screen.
2. Player inputs username and selects profile picture.
   1. Username is required.
      1. Cannot proceed if blank is provided
   2. Username cannot be duplicated.
      1. Warn user for duplication.
      2. Cannot proceed without changes.
3. Player confirms creation.
   1. Cenceling puts user back to Profile Menu.
4. System records data into database.

### Usecase 2 : Deleting a user
---------------------------------
**actor**     : player  
**pre-ops**   : press delete Profile button  
**post-ops**  : update the Profile Menu  
**flow**      :  
1. Player confirms deletion
   1. Cenceling puts user back to Profile Menu.
2. Search for entry in database.
3. Delete the entry.

### Usecase 3 : Creating play screen
------------------------------------
**actor**     : player  
**pre-ops**   : press any difficulty button  
**post-ops**  : switch screen to Play screen  
**flow**      :  
1. Sets the size of the grid to the difficulty.
2. Generate a puzzle that fits to the size of the grid.
3. Detemine the solvability of the puzzle.
   1. If unsolvable, go back to step 2.
4. Starts a stopwatch to record the time.
 
### Usecase 4 : Finishing a Game
----------------------------------
**actor**     : player  
**pre-ops**   : press the finish button  
**post-ops**  : *N/A*  
**flow**      :   
1. Pause the stopwatch.
2. Solve the puzzle and store solution in memory.
3. Verify the user-input solution to the solution in memory.
   1. If user-input solution is incorrect, show lose screen.
      1. Pressing retry button, puts player back to the play area, and unpause the stopwatch.
      2. Pressing exit button, puts player to Level Select.
   2. If user-input solution is correct, stop the stopwatch, show win screen.
      1. Pressing again button, puts player back to the play area, and go to *Usecase 3*.
      2. Pressing exit button, puts player to Level Select.

### Usecase 5 : Creating a Level
---------------------------------
**actor**     : player  
**pre-ops**   : press Level Editor  
**post-ops**  : go to main menu  
**flow**      :  
1. Player determine a size.
2. Display a grid of the size.
3. When player left click a square, place the square on the grid, and update the hints.
4. When player right click a square, removes the square on the grid, and update the hints.
5. When clear button is press, remove all squares on the grid, and update the hints.
6. When resize button is press, go to step 1.
7. When publish button is press, save the hints to file.

### Usecase 6 : Playing a Level
-----------------------------------
**actor**     : player  
**pre-ops**   : in a play screen  
**post-ops**  : *N/A*  
**flow**      :  
1. Display a grid of the appropriate difficulty.
2. When player left click a square, place the square on the grid.
   1. If there is a placeholder square on the grid, remove the placeholder and place a square.
3. When player right click a square, remove the (placeholder) square on the grid.
4. When player middle click a square, place a placeholder X on the grid.
   1. If there is a square on the grid, remove the square and place a placeholder. 
5. When clear button is press, remove all squares on the grid.
6. When reset button is press, go to *Usecase 3*.
7. When finish button is press, go to *Usecase 4*.