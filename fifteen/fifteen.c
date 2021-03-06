/*
 * fifteen.c
 *
 * Implementing Game of Fifteen (board size d by d).
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// defining constants
#define DIM_MIN 3
#define DIM_MAX 9

// board defing through matrix size 
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
         // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int k = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {

        // fill the tiles in descending order

        board[i][j] = d * d -k;

        k++;

        }

    }

    //making the last tile completely blank

    board[d-1][d-1] = 0;

    // if there are an odd number of tiles, swap 1 and 2
     if ((d * d)%2 == 0)

    {

        board[d-1][d-2] = 2;

        board[d-1][d-3] = 1;

    }
}

/*
 * Printig the the board in its current state using draw function.
 */
void draw(void)

{
int i,j;
    for (i=0;i<d;i++)

    {

        for (j=0;j<d;j++) {

            if (board[i][j] == 99)  // checking blank position and printing blank space there
            {
                printf("0");
}
            else

            // printing the tiles in descending order
{
                printf("%d ",board[i][j]);
}
        }

        printf("\n");

    }

}

/*
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
 bool move(int tile)

{
//making procedure to move the tile

    for (int i = 0; i < d; i++)

    {

        for (int j = 0; j < d; j++)

        {

            if (board[i][j] == tile)

            {

                //check if the blank is to the right

                if (j+1 <= d-1 && board[i][j+1] == 0)

                {

                    board[i][j+1] = tile;

                    board[i][j] = 0;

                    return true;

                }

                // check if the blank is to the left

                else if (j-1 >= 0 && board[i][j-1] == 0)

                {

                    board[i][j-1] = tile;

                    board[i][j] = 0;

                    return true;

                }

                // checking if blank is above

                else if (i-1 >= 0 && board[i-1][j] ==0)

                {

                    board[i-1][j] = tile;

                    board[i][j] = 0;

                    return true;

                }

                // checking if blank is below

                else if (i+1 <= d-1 && board[i+1][j] == 0)

                {

                    board[i+1][j] = tile;

                    board[i][j] = 0;

                    return true;

                }

            

            }

        }

    }

    return false;

}


bool won(void)   
{

        

    if (board[d-1][d-1] != 0)
  return false;
  
     int p=1;
    for (int i = 0; i < d; i++)

    {

        for (int j = 0; j < d; j++)

        {

         return true;
           
            if (!(board[i][j]==p)&&!(i==d-1&&j==d-1)) //checking if loop matches with p or not
            return false;
            
                p++;
          }

    }
    return true;
}