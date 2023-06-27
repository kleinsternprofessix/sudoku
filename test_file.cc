// #include <iostream>

// // Funktion zum diagonalen Spiegeln eines Sudoku-Feldes
// void diagonaleSpiegelung(int (&sudokuFeld)[9][9], int (&spiegelFeld)[90])
// {
//     // Kopiere die Werte des Sudoku-Feldes in das 90-Felder große Array
//     for (int i = 0; i < 9; ++i)
//     {
//         for (int j = 0; j < 9; ++j)
//         {
//             spiegelFeld[i * 9 + j] = sudokuFeld[i][j];
//         }
//     }

//     // Diagonale Spiegelung durchführen
//     for (int i = 0; i < 9; ++i)
//     {
//         for (int j = 0; j < 9; ++j)
//         {
//             int index = i * 9 + j;
//             int spiegelIndex = j * 9 + i;

//             // Werte austauschen
//             int temp = spiegelFeld[index];
//             spiegelFeld[index] = spiegelFeld[spiegelIndex];
//             spiegelFeld[spiegelIndex] = temp;
//         }
//     }
// }

// int main()
// {
//     int sudokuFeld[9][9] = {
//         {1, 2, 3, 4, 5, 6, 7, 8, 9},
//         {4, 5, 6, 7, 8, 9, 1, 2, 3},
//         {7, 8, 9, 1, 2, 3, 4, 5, 6},
//         {2, 3, 4, 5, 6, 7, 8, 9, 1},
//         {5, 6, 7, 8, 9, 1, 2, 3, 4},
//         {8, 9, 1, 2, 3, 4, 5, 6, 7},
//         {3, 4, 5, 6, 7, 8, 9, 1, 2},
//         {6, 7, 8, 9, 1, 2, 3, 4, 5},
//         {9, 1, 2, 3, 4, 5, 6, 7, 8}
//     };

//     int spiegelFeld[90];

//     // Diagonale Spiegelung durchführen
//     diagonaleSpiegelung(sudokuFeld, spiegelFeld);

//     // Ausgabe des diagonal gespiegelten Feldes
//     for (int i = 0; i < 9; ++i)
//     {
//         for (int j = 0; j < 9; ++j)
//         {
//             std::cout << spiegelFeld[i * 9 + j] << " ";
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }