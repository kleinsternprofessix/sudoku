#include <iostream>
#include <cctype>
#include <random>

#define N 9             //For loop index
#define IN 90           //Array length index
#define seed_length 10  //seed length index

void zero_hold_grid(int (&hold_grid)[IN]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            hold_grid[(i*10)+j] = 0;
        }
    }
}

void display_grid(int *new_grid){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << new_grid[(10 * i) + j] << ' ';
        }
        std::cout << '\n';
    }
}

void copy_grid(int (&grid_one)[IN], const int (&grid_two)[IN])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid_one[(i*10)+j] = grid_two[(i*10)+j];
        }
    }
}

void mirror_vertically(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //1
    //mirror the whole grid vertically
    int j = 8;

    for (int i = 0; i < N; i++)//row that has to be moved
    {
        for (int k = 0; k < N; k++)//loop through the row
        {
            hold_grid[(i * 10)+k] = new_grid[(j * 10) + k];
        };
        j--; //destination in the hold row
    };

    copy_grid(new_grid, hold_grid);
}

void mirror_horizontally(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //2
    //mirror the whole grid horizontally
    int j = 8;

    for (int i = 0; i < N; i++)//column that has to be moved
    {
        for (int k = 0; k < N; k++)//loop through the column
        {
            hold_grid[(k * 10)+i] = new_grid[(k * 10) + j];
        };
        j--; //destination in the hold column
    };

    copy_grid(new_grid, hold_grid);
}

void mirror_diagonally(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //3
    //mirror the whole grid diagonally

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // swap values
            hold_grid[(i * 10)+j] = new_grid[(j * 10)+i];
            hold_grid[(j * 10)+i] = new_grid[(i * 10)+j];
        }
    }

    copy_grid(new_grid, hold_grid);
}

void permutation(int first, int second, int (&new_grid)[IN]){
    //4,5,6
    //swap every 1 with every 9 etc
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {  
            if (new_grid[(i * 10)+j] == first)// swap value one
            {
                new_grid[(i * 10)+j] = second;
            }
            else
                if (new_grid[(i * 10)+j] == second)//swap value two
                {
                    new_grid[(i * 10)+j] = first;
                }
        }
    }
}

void swap_columns(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //7
    //swap column 1 and 3 in each 3x9 block
    int col_1 = 0;
    int col_2 = 2;

    //just copy: 1,4,7
    for (int i = 1; i < 8; i+=3)//select column
    {
        for (int j = 0; j < N; j++)//iterate through columns
        {
            hold_grid[(j*10)+i] = new_grid[(j*10)+i];
        }
    }
    //ergo: 0,2..3,5..6,8 
    for (int i = 0; i < 3; i++)//three swaps needed
    {
        for (int j = 0; j < N; j++)//iterate through columns
        {
            hold_grid[(j*10)+col_1] = new_grid[(j*10)+col_2];
            hold_grid[(j*10)+col_2] = new_grid[(j*10)+col_1];
        }
        col_1 += 3;
        col_2 += 3;
    }
    
    copy_grid(new_grid, hold_grid);
}

void swap_rows(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //8
    //swap row 1 and 3 in each 9x3 block
    int row_1 = 0;
    int row_2 = 2;

    //just copy: 1,4,7
    for (int i = 1; i < 8; i+=3)//select row
    {
        for (int j = 0; j < N; j++)//iterate through rows
        {
            hold_grid[(i*10)+j] = new_grid[(i*10)+j];
        }
    }
    //ergo: 0,2..3,5..6,8 
    for (int i = 0; i < 3; i++)//three swaps needed
    {
        for (int j = 0; j < N; j++)//iterate through rows
        {
            hold_grid[(row_1*10)+j] = new_grid[(row_2*10)+j];
            hold_grid[(row_2*10)+j] = new_grid[(row_1*10)+j];
        }
        row_1 += 3;
        row_2 += 3;
    }

    copy_grid(new_grid, hold_grid);
}

void swap_horizontal_blocks(int (&new_grid)[IN], int (&hold_grid)[IN]){ 
    //9
    //swap 3x9 block 1 (rows 0,1,2) and 2 (rows 3,4,5)
    int k = 2;

    //fill unswaped rows
    for (int i = 6; i < N; i++)
    {
        for (int j = 0; j < N; j++)//iterate through rows
        {
            hold_grid[(i*10)+j] = new_grid[(i*10)+j];
        }
    }
    //swap rows
    for (int i = 0; i < 6; i++)
    {
        if (k < 5)
            k++;
        else
            k = 0;
        for (int j = 0; j < N; j++)//iterate through rows
        {
            hold_grid[(i*10)+j] = new_grid[(k*10)+j];
        }
    }

    copy_grid(new_grid, hold_grid);
}

void swap_vertical_blocks(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //0
    //swap 9x3 block 1 (cols 0,1,2) and 2 (cols 3,4,5)
    int k = 2;

    //fill unswaped columns
    for (int i = 6; i < 9; i++)
    {
        for (int j = 0; j < N; j++)//iterate through columns
        {
            hold_grid[(j*10)+i] = new_grid[(j*10)+i];
        }
    }
    //swap columns
    for (int i = 0; i < 6; i++)
    {   
        if (k < 5)
            k++;
        else
            k = 0;
        for (int j = 0; j < N; j++)//iterate through columns
        {
            hold_grid[(j*10)+i] = new_grid[(j*10)+k];
        }
    }

    copy_grid(new_grid, hold_grid);
}

void seed_handler(const int (&standard_grid)[IN], int (&new_grid)[IN]){
    //Player has to enter a 10 digit long seed(0-9), with every number appearing only one time
    char seed[seed_length];
    int hold_grid[IN] = {0};
    
    copy_grid(new_grid, standard_grid);

    std::cout << "This programm generates the sudoku based on a 10 digit long seed.\nPlease enter your seed: \n";
    std::cin >> seed;

    //Going through the swap functions, depending on the seed values
    for(std::size_t i = 0; i < seed_length; i++){
        switch (seed[i])
        {
        case '1':
            mirror_vertically(new_grid, hold_grid);
            zero_hold_grid(hold_grid);
            break;
        case '2':
            mirror_horizontally(new_grid, hold_grid);
            zero_hold_grid(hold_grid);
            break;
        case '3': 
            mirror_diagonally(new_grid, hold_grid);
            zero_hold_grid(hold_grid);
            break;
        case '4':
            permutation(9, 1, new_grid);
            break;
        case '5':
            permutation(8, 2, new_grid);
            break;
        case '6':
            permutation(7, 3, new_grid);
            break;
        case '7': 
            swap_columns(new_grid, hold_grid);
            zero_hold_grid(hold_grid);
            break;
        case '8':
            swap_rows(new_grid, hold_grid);
            zero_hold_grid(hold_grid);
            break;
        case '9':
            swap_horizontal_blocks(new_grid, hold_grid);
            zero_hold_grid(hold_grid);
            break;
        case '0': 
            swap_vertical_blocks(new_grid, hold_grid);
            zero_hold_grid(hold_grid);
            break;
        default:
            break;
        }
    }
}

int level_select(){
    int lvl;

    std::cout << "Welcome to stern's sudoku!\n\nPlease select a level:\n  Level 1: 38 given numbers\n  Level 2: 30 given numbers\n  Level 3: 22 given numbers\n";
    std::cin >> lvl;

    return lvl;
}

void make_grid_playable(int lvl, int (&new_grid)[IN]){
    //Because i wanted it to be random which of the fields are excluded from the deletition
    //i used this code: https://stackoverflow.com/a/62378892 (The Standart C++ Way)
    int no_based_on_lvl;
    int check = -1;
    int check_arr[50];
    std::uint_least32_t rand_no;
    switch (lvl)
    {
    case 1:
        no_based_on_lvl = 38;
        break;
    case 2:
        no_based_on_lvl = 30;
        break;
    case 3:
        no_based_on_lvl = 22;
        break;
    default:
        break;
    }

    //generating random numbers
    std::random_device os_seed;
    const uint_least32_t seed = os_seed();
  
    std::mt19937 generator( seed );
    std::uniform_int_distribution< uint_least32_t > distribute( 0, 90 );

    //deleting everything except the generated numbers
    for(int i = 0; i < (90 - no_based_on_lvl); ++i){
        rand_no = distribute( generator );
        if (new_grid[rand_no] == 0){
            if(rand_no != 90)
                new_grid[rand_no+1] = 0;
            else
                new_grid[rand_no-1] = 0;
        }
        else{
            new_grid[rand_no] = 0;
        }
    } 

    //double checking if the right amount was deleted
    for (int i = 6; i < 9; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(new_grid[(j*10)+i] != 0){
                check++;
                check_arr[check] = (j*10)+i;
            }
        }
    }
    if(check+1 >no_based_on_lvl){
        std::mt19937 generator( seed );
        std::uniform_int_distribution< uint_least32_t > distribute(0, check);
        rand_no = distribute(generator);

        new_grid[check_arr[rand_no]] = 0;
    }
}

int main(){
    const int standart_grid[IN] = {2, 6, 5, 1, 9, 8, 7, 3, 4, 0,
                                   4, 3, 1, 6, 5, 7, 8, 2, 9, 0,
                                   7, 9, 8, 4, 2, 3, 5, 1, 6, 0,
                                   8, 2, 4, 3, 1, 9, 6, 7, 5, 0,
                                   6, 1, 7, 5, 8, 2, 4, 9, 3, 0,
                                   9, 5, 3, 7, 4, 6, 2, 8, 1, 0,
                                   3, 4, 6, 8, 7, 1, 9, 5, 2, 0,
                                   1, 7, 2, 9, 6, 5, 3, 4, 8, 0,
                                   5, 8, 9, 2, 3, 4, 1, 6, 7, 0};
    int new_grid[IN] = {0};
    int level;

    level = level_select();
    seed_handler(standart_grid, new_grid);
    make_grid_playable(level, new_grid);

    display_grid(new_grid);

    return 0;
};

//Difficulties i had:
//1) Find the right way to handle the sudoku grid data
//  First i thought i could use a 2D array. Because the sudoku grid itself looks kind of a 2D array it seemed like the right way to handle it but i had many difficulties with
//  passing it to the functions and change the values of it in them so i switched to a normal array. This had its problems too, because i still could not change the values in 
//  the functions but i figured a good solution with passing the reference of the array.
//2) How can i make it random which fields of the solution are shown
// 