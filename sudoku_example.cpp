//GLFW: https://www.glfw.org/docs/latest/quick.html
//OpenGL 3: https://www.freecodecamp.org/news/how-to-create-3d-and-2d-graphics-with-opengl-and-cpp/
//Dear ImGui: https://blog.conan.io/2019/06/26/An-introduction-to-the-Dear-ImGui-library.html

//Udemy Kurs: https://www.udemy.com/course/interaktive-gui-mit-c-und-imgui-praktische-beispiele/

// #include <iostream>
// using namespace std;

// // Size of the Sudoku grid
// #define N 9
// #define WINDOW_SIZE 500
// #define CELL_SIZE (WINDOW_SIZE / N)

// // Function to print the Sudoku grid
// void printGrid(int grid[N][N]) {
//     for (int row = 0; row < N; row++) {
//         for (int col = 0; col < N; col++)
//             cout << grid[row][col] << " ";
//         cout << endl;
//     }
// }

// // Function to check if a given digit is safe to place in a given row
// bool isSafeRow(int grid[N][N], int row, int num) {
//     for (int col = 0; col < N; col++) {
//         if (grid[row][col] == num)
//             return false;
//     }
//     return true;
// }

// // Function to check if a given digit is safe to place in a given column
// bool isSafeCol(int grid[N][N], int col, int num) {
//     for (int row = 0; row < N; row++) {
//         if (grid[row][col] == num)
//             return false;
//     }
//     return true;
// }

// // Function to check if a given digit is safe to place in a given 3x3 box
// bool isSafeBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
//     for (int row = 0; row < 3; row++) {
//         for (int col = 0; col < 3; col++) {
//             if (grid[row + boxStartRow][col + boxStartCol] == num)
//                 return false;
//         }
//     }
//     return true;
// }

// // Function to check if a digit can be placed at a given position
// bool isSafe(int grid[N][N], int row, int col, int num) {
//     return isSafeRow(grid, row, num) &&
//            isSafeCol(grid, col, num) &&
//            isSafeBox(grid, row - row % 3, col - col % 3, num);
// }

// // Function to find an empty position in the grid
// bool findEmptyPosition(int grid[N][N], int &row, int &col) {
//     for (row = 0; row < N; row++) {
//         for (col = 0; col < N; col++) {
//             if (grid[row][col] == 0)
//                 return true;
//         }
//     }
//     return false;
// }

// // Sudoku solver function
// bool solveSudoku(int grid[N][N]) {
//     int row, col;

//     if (!findEmptyPosition(grid, row, col))
//         return true;  // Puzzle solved

//     // Try all digits from 1 to 9
//     for (int num = 1; num <= 9; num++) {
//         if (isSafe(grid, row, col, num)) {
//             grid[row][col] = num;

//             if (solveSudoku(grid))
//                 return true;

//             grid[row][col] = 0;  // Backtracking
//         }
//     }

//     return false;  // No solution found
// }

// // Function to draw the Sudoku grid on the window
// void drawGrid(RenderWindow &window, int grid[N][N]) {
//     for (int row = 0; row < N; row++) {
//         for (int col = 0;

// col < N; col++) {
//             // Create a rectangle shape for each cell
//             RectangleShape cell(Vector2f(CELL_SIZE, CELL_SIZE));
//             cell.setOutlineThickness(2);
//             cell.setOutlineColor(Color::Black);

//             // Set the position of the cell
//             cell.setPosition(col * CELL_SIZE, row * CELL_SIZE);

//             // Set the cell color based on the value in the grid
//             if (grid[row][col] != 0) {
//                 cell.setFillColor(Color::White);
//             } else {
//                 cell.setFillColor(Color::Yellow);
//             }

//             // Draw the cell on the window
//             window.draw(cell);

//             // Create a text object for the value in the cell
//             Text text;
//             Font font;
//             if (!font.loadFromFile("arial.ttf")) {
//                 cout << "Font file not found!" << endl;
//                 return;
//             }
//             text.setFont(font);
//             text.setCharacterSize(30);
//             text.setFillColor(Color::Black);

//             // Set the position and value of the text object
//             if (grid[row][col] != 0) {
//                 text.setString(to_string(grid[row][col]));
//                 text.setPosition(col * CELL_SIZE + CELL_SIZE / 3, row * CELL_SIZE + CELL_SIZE / 4);
//             }

//             // Draw the text object on the window
//             window.draw(text);
//         }
//     }
// }

// // Main function
// int main() {
//     int grid[N][N] = {
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0}
//     };

//     RenderWindow window(VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Sudoku");

//     // Solve the Sudoku puzzle
//     if (solveSudoku(grid)) {
//         cout << "\nSudoku solved:\n";
//         printGrid(grid);
//     } else {
//         cout << "\nNo solution exists for the given Sudoku grid.\n";
//     }

//     // Game loop
//     while (window.isOpen()) {
//         Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == Event::Closed) {
//                 window.close();
//             }
//         }

//         window.clear(Color::White);

//         // Draw the Sudoku grid on the window
//         drawGrid(window, grid);

//         window.display();
//     }

//     return 0;
// }
