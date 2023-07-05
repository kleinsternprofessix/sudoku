#include <iostream>
#include <cctype>
#include <random>
#include <set>

#define N 9             //For loop index
#define IN 81           //Array length index
#define seed_length 10  //seed length index

void zero_hold_grid(int (&hold_grid)[IN]){
    //Funktion um das "hold_grid" Array zu nullen, um Ungenauigkeiten zu vermeiden
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            hold_grid[(i*9)+j] = 0;
        }
    }
}

void display_grid(int *new_grid){
    //Funktion um das Spielfeld in der Konsole auszugeben
    std::string test;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << new_grid[(9 * i) + j] << ' ';
        }
        std::cout << '\n';
    }
}

void copy_grid(int (&grid_one)[IN], const int (&grid_two)[IN]){
    //Funktion um ein Array in das andere zu kopieren
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid_one[(i*9)+j] = grid_two[(i*9)+j];
        }
    }
}

void mirror_vertically(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //1
    //Funktion um das ganze Array vertikal zu spiegeln
    int j = 8;

    for (int i = 0; i < N; i++)//Reihe die bewegt werden muss
    {
        for (int k = 0; k < N; k++)//Durch Reihe iterieren
        {
            hold_grid[(i * 9)+k] = new_grid[(j * 9) + k];
        };
        j--; //Ziel in der hold_grid Variable
    };

    copy_grid(new_grid, hold_grid);
}

void mirror_horizontally(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //2
    //Funktion um das ganze Array horizontal zu spiegeln
    int j = 8;

    for (int i = 0; i < N; i++)//Spalte die bewegt werden muss
    {
        for (int k = 0; k < N; k++)//Durch Spalte iterieren
        {
            hold_grid[(k * 9)+i] = new_grid[(k * 9) + j];
        };
        j--; //Ziel in der hold_grid Variable
    };

    copy_grid(new_grid, hold_grid);
}

void mirror_diagonally(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //3
    //Funktion um das ganze Array diagonal zu spiegeln

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Werte tauschen
            hold_grid[(i * 9)+j] = new_grid[(j * 9)+i];
            hold_grid[(j * 9)+i] = new_grid[(i * 9)+j];
        }
    }

    copy_grid(new_grid, hold_grid);
}

void permutation(int first, int second, int (&new_grid)[IN]){
    //4,5,6
    //Hier werden Zahlenpaare vertauscht (1 und 9, 2 und 8, 3 und 7)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {  
            if (new_grid[(i * 9)+j] == first)// Ersten Wert tauschen
            {
                new_grid[(i * 9)+j] = second;
            }
            else
                if (new_grid[(i * 9)+j] == second)// Zweiten Wert tauschen
                {
                    new_grid[(i * 9)+j] = first;
                }
        }
    }
}

void swap_columns(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //7
    //Tausche Spalte 1 und 3 in jedem 3x9 Block
    int col_1 = 0;
    int col_2 = 2;

    //Nur kopieren: 1,4,7
    for (int i = 1; i < 8; i+=3)//Spalte auswählen
    {
        for (int j = 0; j < N; j++)//Durch Spalte iterieren
        {
            hold_grid[(j*9)+i] = new_grid[(j*9)+i];
        }
    }
    //Also werden vertauscht: 0,2..3,5..6,8 
    for (int i = 0; i < 3; i++)//Es werden drei Täusche gemacht
    {
        for (int j = 0; j < N; j++)//Durch Spalten iterieren
        {
            hold_grid[(j*9)+col_1] = new_grid[(j*9)+col_2];
            hold_grid[(j*9)+col_2] = new_grid[(j*9)+col_1];
        }
        col_1 += 3;
        col_2 += 3;
    }
    
    copy_grid(new_grid, hold_grid);
}

void swap_rows(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //8
    //Tausche Reihe 1 und 3 in jedem 9x3 Block
    int row_1 = 0;
    int row_2 = 2;

    //Nur kopieren: 1,4,7
    for (int i = 1; i < 8; i+=3)//Reihe auswählen
    {
        for (int j = 0; j < N; j++)//durch Reihe iterieren
        {
            hold_grid[(i*9)+j] = new_grid[(i*9)+j];
        }
    }
    //Also werden vertauscht: 0,2..3,5..6,8 
    for (int i = 0; i < 3; i++)//Drei Täusche werden gemacht
    {
        for (int j = 0; j < N; j++)//Durch Reihen iterieren
        {
            hold_grid[(row_1*9)+j] = new_grid[(row_2*9)+j];
            hold_grid[(row_2*9)+j] = new_grid[(row_1*9)+j];
        }
        row_1 += 3;
        row_2 += 3;
    }

    copy_grid(new_grid, hold_grid);
}

void swap_horizontal_blocks(int (&new_grid)[IN], int (&hold_grid)[IN]){ 
    //9
    //Vertausche die 3x9 Blöcke 1(Reihen 0,1,2) und 2 (Reihen 3,4,5)
    int k = 2;

    //Nicht vertauschte Reihen füllen
    for (int i = 6; i < N; i++)
    {
        for (int j = 0; j < N; j++)//Durch Reihen iterieren
        {
            hold_grid[(i*9)+j] = new_grid[(i*9)+j];
        }
    }
    //Reihen vertauschen
    for (int i = 0; i < 6; i++)
    {
        if (k < 5)
            k++;
        else
            k = 0;
        for (int j = 0; j < N; j++)//Durch Reihen iterieren
        {
            hold_grid[(i*9)+j] = new_grid[(k*9)+j];
        }
    }

    copy_grid(new_grid, hold_grid);
}

void swap_vertical_blocks(int (&new_grid)[IN], int (&hold_grid)[IN]){
    //0
    //Vertausche die 9x3 Blöcke 1(Spalten 0,1,2) und 2 (Spalten 3,4,5)
    int k = 2;

    //Nicht vertauschte Spalten füllen
    for (int i = 6; i < N; i++)
    {
        for (int j = 0; j < N; j++)//Durch Spalten iterieren
        {
            hold_grid[(j*9)+i] = new_grid[(j*9)+i];
        }
    }
    //Spalten vertauschen
    for (int i = 0; i < 6; i++)
    {   
        if (k < 5)
            k++;
        else
            k = 0;
        for (int j = 0; j < N; j++)//Durch Spalten iterieren
        {
            hold_grid[(j*9)+i] = new_grid[(j*9)+k];
        }
    }

    copy_grid(new_grid, hold_grid);
}

void seed_handler(const int (&standard_grid)[IN], int (&new_grid)[IN]){
    //Hier muss der Spieler einen 10 Zahlen langen Seed eingeben. Basierend auf diesem werden die Funktionen ausgeführt die das Standart Feld kontrolliert vertauschen
    char seed[seed_length];
    int hold_grid[IN] = {0};
    
    copy_grid(new_grid, standard_grid);

    std::cout << "Dieses Programm generiert ein Sudoku basierend auf einem 10 Ziffern langen Seed.\nBitte gib deinen Seed an: \n";
    std::cin >> seed;

    //Funktionsaufruf basierend auf den Werten des Seeds
    for(int i = 0; i < seed_length; i++){
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
    //Hier wird das Level ausgewählt. Dieses entscheidet darüber wie viele Zahlen im Feld bereits ausgefüllt sind
    int lvl;

    std::cout << "Welcome to stern's sudoku!\n\nPlease select a level:\n  Level 1: 38 given numbers\n  Level 2: 30 given numbers\n  Level 3: 22 given numbers\n";
    std::cin >> lvl;

    return lvl;
}

void make_grid_playable(int (&new_grid)[IN], std::uint_least32_t(&rand_no)[50], std::uint_least32_t no_based_on_lvl, std::set<uint_least32_t> (&generatedNumbers)){
    //Ich wollte, dass die Felder die im Feld gegeben sind zufällig ausgewählt werden und
    //habe mich dafür an folgendem Code orientiert: https://stackoverflow.com/a/62378892 (The Standart C++ Way)

    std::random_device os_seed;
    const uint_least32_t seed = os_seed();
  
    std::mt19937 generator( seed );
    std::uniform_int_distribution< uint_least32_t > distribute( 0, 80 );

    //Zufällige Zahlen generieren und in Liste eintragen
    for(std::uint_least32_t i = 0; i < no_based_on_lvl; ++i){
        do{
            rand_no[i] = distribute( generator );
        }while(generatedNumbers.count(rand_no[i]) > 0); //
        generatedNumbers.insert(rand_no[i]);
    } 
    //Alles bisauf diese Zahlen löschen
    for(std::uint_least32_t i = 0; i < IN; ++i){
        if(!(generatedNumbers.count(i) > 0))
            new_grid[i] = 0;
    }
}

bool is_given(std::set<uint_least32_t> (&generatedNumbers), std::uint_least32_t row, std::uint_least32_t col){
    if(generatedNumbers.count((row*9)+col) > 0)
    {
        std::cout << "Die von dir ausgewählte Koordinate war bereits gegeben! Wähle eine neue\n";
        return true;
    };
    return false;
}

bool is_valid(int (&new_grid)[IN], int input, std::uint_least32_t row, std::uint_least32_t col){
    std::uint_least32_t block_no;
    switch ((row*9)+col)
    {
    //TODO
    //Block 1
    case 0:
    case 1:
    case 2:
    case 9:
    case 10:
    case 11:
    case 18:
    case 19:
    case 20:
        block_no = 0;
        break;
    //Block 2
    case 3:
    case 4:
    case 5:
    case 12:
    case 13:
    case 14:
    case 21:
    case 22:
    case 23:
        block_no = 3;
        break;
    //Block3
    case 6:
    case 7:
    case 8:
    case 15:
    case 16:
    case 17:
    case 24:
    case 25:
    case 26:
        block_no = 6;
        break;
    //Block 4
    case 27:
    case 28:
    case 29:
    case 36:
    case 37:
    case 38:
    case 45:
    case 46:
    case 47:
        block_no = 27;
        break;
    //Block 5
    case 30:
    case 31:
    case 32:
    case 39:
    case 40:
    case 41:
    case 48:
    case 49:
    case 50:
        block_no = 30;
        break;
    //Block 6
    case 33:
    case 34:
    case 35:
    case 42:
    case 43:
    case 44:
    case 51:
    case 52:
    case 53:
        block_no = 33;
        break;
    //Block 7
    case 54:
    case 55:
    case 56:
    case 63:
    case 64:
    case 65:
    case 72:
    case 73:
    case 74:
        block_no = 54;
        break;
    //Block 8
    case 57:
    case 58:
    case 59:
    case 66:
    case 67:
    case 68:
    case 75:
    case 76:
    case 77:
        block_no = 57;
        break;
    //Block 9
    case 60:
    case 61:
    case 62:
    case 69:
    case 70:
    case 71:
    case 78:
    case 79:
    case 80:
        block_no = 60;
        break;
    default:
        break;
    }

    for (std::uint_least32_t i = 0; i < N; i++)
    {
        if(new_grid[(row*9)+i] == input){
            std::cout << "Deine Eingabe ist ungueltig, weil sie in der Reihe bereits existiert.";
            return true;
        }
        if(new_grid[(i*9)+col] == input){
            std::cout << "Deine Eingabe ist ungueltig, weil sie in der Spalte bereits existiert.";
            return true;
        }
    }
    for (std::uint_least32_t i = 0; i < 3; i++)
    {
        for (std::uint_least32_t j = 0; j < 3; j++)
        {
            if (new_grid[block_no+((i*9)+j)] == input)     //Die Variable block_no wird als Startpunkt genutzt, um durch den Block zu iterieren
            {
                std::cout << "Deine Eingabe ist ungueltig, weil sie im 3x3 Block bereits existiert.";
                return true;
            }
        }        
    }
    return false;
}

bool grid_complete_check(int (&new_grid)[IN]){
    //Hier wird überprüft, ob das Sudoku gelöst ist oder nicht
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(new_grid[(i*9)+j] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void user_input(std::set<uint_least32_t> (&generatedNumbers), int (&new_grid)[IN]){
    //Hier gibt der User an welches Feld er ändern will und welchen Wert er diesem zuweisen will
    std::uint_least32_t row, col;
    int input;

    do{
        std::cout << "\nWelches Feld möchtest du fuellen?" << "\nReihe: ";
        std::cin >> row;
        std::cout << "Spalte: ";
        std::cin >> col;
    } while (is_given(generatedNumbers, row, col));     //Prüfung, ob das gewollte Feld schon von vorhinein gefüllt war

    do{
        std::cout << "\nWelche Zahl möchtest du eintragen?";
        do{
            std::cin >> input;
        } while (input < 1 || input > 9);
    } while (is_valid(new_grid, input, row, col));              //Prüfung, ob der eingegebene Wert mit Hinblick auf die Reihe, die Spalte und den 3x3 Block gültig ist
    new_grid[(row*9)+col] = input;
}

int main(){
    const int standart_grid[IN] = {2, 6, 5, 1, 9, 8, 7, 3, 4,
                                   4, 3, 1, 6, 5, 7, 8, 2, 9,
                                   7, 9, 8, 4, 2, 3, 5, 1, 6,
                                   8, 2, 4, 3, 1, 9, 6, 7, 5,
                                   6, 1, 7, 5, 8, 2, 4, 9, 3,
                                   9, 5, 3, 7, 4, 6, 2, 8, 1,
                                   3, 4, 6, 8, 7, 1, 9, 5, 2,
                                   1, 7, 2, 9, 6, 5, 3, 4, 8,
                                   5, 8, 9, 2, 3, 4, 1, 6, 7};
    int new_grid[IN] = {0};
    std::uint_least32_t rand_no[50] = {0};
    int level;
    std::uint_least32_t no_based_on_lvl = 0;
    std::set<uint_least32_t> generatedNumbers = {0};
    
    level = level_select();                                    //Levelauswahl
    switch (level)
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
    seed_handler(standart_grid, new_grid);                     //Festlegung des Seeds mit dem das Spielfeld erstellt wird & Erstellung des Spielfeldes
    make_grid_playable(new_grid, rand_no, no_based_on_lvl, generatedNumbers);    //Löschung von allen Zahlen bis auf denen, die das Level festlegt

    //Spielverlauf
    do{
        display_grid(new_grid);                                //Darstellung des Spielfeldes
        user_input(generatedNumbers, new_grid);        //Eingabe der Koordinaten und des neuen Werts durch den Spieler
    } while (grid_complete_check(new_grid));                   //Prüfung, ob das Sudoku schon gelöst ist
    
    std::cout << "\n Herzlichen Glueckwunsch! Du hast das Sudoku geloest!";
    return 0;
};

//Dinge die mir Schwierigkeiten bereitet haben:
//1) Den richtigen Weg finden das Sudoku Spielfeld zu speichern und damit umzugehen
//  Zuerst dachte ich dabei an ein 2D Array, weil eine Sudoku Tabelle selbst ja zweidimensional ist und habe begonnen damit zu arbeiten. Die Handhabung damit, 
//  vor allem wenn es darum ging dieses in Funktionen zu bearbeiten ist mir jedoch sehr schwer gefallen bzw. hat nicht funktioniert weshalb ich mich dann zu einem 
//  eindimensionalen Array umentschieden habe. Auch damit hatte ich zuerst meine Probleme, weil ich es wegen der Beschaffenheit des Spielfeldes ja doch wie ein 2D-
//  Array behandeln musste ich habe aber eine, wie ich finde gute Lösung gefunden indem ich in den Indexklammern jedes Mal den Index errechne und es wirklich behandle 
//  als hätte es zwei Dimensionen. Auch bei der Übergabe an die Funktionen hatte ich anfangs Probleme aber das Arbeiten mit Referenzen hat diese für mich gelöst, auch
//  wenn sie vermutlich nicht die performanteste Lösung darstellen.
//2) How can i make it random which fields of the solution are shown
// 