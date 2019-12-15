#include <stdio.h>
#include <stdbool.h>

// 2D array of the game board
char *grid[7][7];
char *board[7][7];

int main(){
  // local variables
  // startRow and start Col are the starting rows and collums that are chosen to be worked with
  // row and col refers to the rows and collums in the 2D arrays
  // numGuesses, numAlive, numGuessed are all counters to count the number of guesses, number of hit ship coordinates, and already guessed coordinates
  // String extend refers to if the user chooses to place the ship down the grid or to the right of the grid
  // bool a and b is used as a condition for the do/while loops
  int startRow, startCol, row, col, numGuesses = 0, numHit = 0;
  char extend[1];
  bool a = true;
  bool b = true;
  // print out the game board
  printf("---------------  Welcome to Battleship!  ---------------\n");
  printf("r\\c\t0\t1\t2\t3\t4\t5\t6\n");

  // reads/prints in the 2D array with "-"
	for (int i = 0; i < 7; i++) {
		printf("%d", i);
		for(int j = 0; j < 7; j++) {
      grid[i][j] = "\t-";
			printf("%s", grid[i][j]);
		}
		printf("\n");
	}

  do {
    // Prompts user to insert ships of length 2
    printf("Please enter coordinates for ship of length 2:\n");
    printf("Starting Row (0-6):\n");
    scanf("%d", &startRow);
    printf("Starting Column (0-6)\n");
    scanf("%d", &startCol);
    grid[startRow][startCol] = "\tS";
    printf("From the starting point, extend down or right? (d/r):\n");
    scanf("%s", &extend);

    // if user chooses to place ship vertically down
    if (extend[0] == 'd') {
      grid[startRow+1][startCol] = "\tS";
      printf("r\\c\t0\t1\t2\t3\t4\t5\t6\n");
      // prints in the 2D array with "-"
      for (int i = 0; i < 7; i++) {
        printf("%d", i);
        for(int j = 0; j < 7; j++) {
          printf("%s", grid[i][j]);
        }
        printf("\n");
      }
      a = false;
    }
    // if user chooses to place the ship horizontally right
    else {
      grid[startRow][startCol+1] = "\tS";
      printf("r\\c\t0\t1\t2\t3\t4\t5\t6\n");
      // prints in the 2D array with "-"
      for (int i = 0; i < 7; i++) {
        printf("%d", i);
        for(int j = 0; j < 7; j++) {
          printf("%s", grid[i][j]);
        }
        printf("\n");
      }
      a = false;
    }
  } while(a); // while true

// Prompts user to insert ships of length 3
  do {
    printf("Please enter coordinates for ship of length 3:\n");
    printf("Starting Row (0-6):\n");
    scanf("%d", &startRow);
    printf("Starting Column (0-6)\n");
    scanf("%d", &startCol);
    grid[startRow][startCol] = "\tS";
    printf("From the starting point, extend down or right? (d/r):\n");
    scanf("%s", &extend);

    // if user chooses to place ship vertically down
    if (extend[0] == 'd') {
      grid[startRow+1][startCol] = "\tS";
      grid[startRow+2][startCol] = "\tS";
      printf("r\\c\t0\t1\t2\t3\t4\t5\t6\n");
      // prints in the 2D array with "-"
      for (int i = 0; i < 7; i++) {
        printf("%d", i);
        for(int j = 0; j < 7; j++) {
          printf("%s", grid[i][j]);
        }
        printf("\n");
      }
      a = false;
    }
    // if user chooses to place the ship horizontally right
    else {
      grid[startRow][startCol+1] = "\tS";
      grid[startRow][startCol+2] = "\tS";
      printf("r\\c\t0\t1\t2\t3\t4\t5\t6\n");
      // reads/prints in the 2D array with "-"
      for (int i = 0; i < 7; i++) {
        printf("%d", i);
        for(int j = 0; j < 7; j++) {
          printf("%s", grid[i][j]);
        }
        printf("\n");
      }
      a = false;
    }
  } while(a);

  // Prompts user to insert ships of length 4
    do {
      printf("Please enter coordinates for ship of length 4:\n");
      printf("Starting Row (0-6):\n");
      scanf("%d", &startRow);
      printf("Starting Column (0-6)\n");
      scanf("%d", &startCol);
      grid[startRow][startCol] = "\tS";
      printf("From the starting point, extend down or right? (d/r):\n");
      scanf("%s", &extend);

      // if user chooses to place ship vertically down
      if (extend[0] == 'd') {
        grid[startRow+1][startCol] = "\tS";
        grid[startRow+2][startCol] = "\tS";
        grid[startRow+3][startCol] = "\tS";
        printf("r\\c\t0\t1\t2\t3\t4\t5\t6\n");
        // prints in the 2D array with "-"
        for (int i = 0; i < 7; i++) {
          printf("%d", i);
          for(int j = 0; j < 7; j++) {
            printf("%s", grid[i][j]);
          }
          printf("\n");
        }
        a = false;
      }
      // if user chooses to place the ship horizontally right
      else {
        grid[startRow][startCol+1] = "\tS";
        grid[startRow][startCol+2] = "\tS";
        grid[startRow][startCol+3] = "\tS";
        printf("r\\c\t0\t1\t2\t3\t4\t5\t6\n");
        // prints in the 2D array with "-"
        for (int i = 0; i < 7; i++) {
          printf("%d", i);
          for(int j = 0; j < 7; j++) {
            printf("%s", grid[i][j]);
          }
          printf("\n");
        }
        a = false;
      }
    } while(a);

// user guesses where the ships are

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("Here's the final game grid...\n\n");
printf("---------------  Begin!  ---------------\n\n");

printf("r\\c\t0\t1\t2\t3\t4\t5\t6\n");

// reads/prints in the 2D array with "-"
for (int i = 0; i < 7; i++) {
  printf("%d", i);
  for(int j = 0; j < 7; j++) {
    board[i][j] = "\t-";
    printf("%s", board[i][j]);
  }
  printf("\n");
}
printf("-------------------------------------------------------------------\n");

// prompts the user to guess where the ships are
do {
  numGuesses++;
  printf("Guess number %d...", numGuesses);
  printf("Guess a row (0-6):\n");
  scanf("%d", &row);
  printf("Guess a column (0-6):\n");
  scanf("%d", &col);

  // if ship at particular coordinate has a ship, than shows an "X" on the printed board for hit and if the coordinates was not already guessed
  if (grid[row][col] == "\tS") {
			board[row][col] = "\tX";
      printf("HIT!\n\n");
      // hit counter increases
      numHit++;

      printf("r\\c\t0\t1\t2\t3\t4\t5\t6\n");

      // prints in the 2D array with "-"
      for (int i = 0; i < 7; i++) {
        printf("%d", i);
        for(int j = 0; j < 7; j++) {
          printf("%s", board[i][j]);
        }
        printf("\n");
      }
  }
  // if ship not at particular coordinate has a ship, than shows an "m" on the printed board for miss
  else {
    board[row][col] = "\tm";
    printf("MISS!\n\n");

  printf("r\\c\t0\t1\t2\t3\t4\t5\t6\n");

  // prints in the 2D array with "-"
  for (int i = 0; i < 7; i++) {
    printf("%d", i);
    for(int j = 0; j < 7; j++) {
      printf("%s", board[i][j]);
    }
    printf("\n");
  }
}

// if all ships are sunk, game over
if (numHit > 8)
  b = false;

} while(b);

  printf("Congratulations, you've sunk all the battleships!\n");
  printf("You made a total of %d guesses.\n\n", numGuesses);
  printf("Thanks for playing! Goodbye.\n");
  return 0;
}
