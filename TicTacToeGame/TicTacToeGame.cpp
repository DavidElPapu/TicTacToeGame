#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void tictactoeChafa();
void instrucciones();
char AskYesNo(string question);
char playerSymbol();
char opposite(char player);
char winner(const vector<char>& board);
void playerMove(vector<char>& board, char player);
void displayBoard(vector<char>& board);
void showInstructionBoard();
string askPairOrInpair(string question);
void ExamenP2Ejercicio2();
void ExamenP2Ejercicio1();
void diceAnimation(int diceNumber);

//Global Constants
const int NUM_SQUARES = 9;
const char EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const char TIE = 'T';
const char NO_ONE = 'N';

//Function main
int main()
{
    ExamenP2Ejercicio2();
    ExamenP2Ejercicio1();
    vector<char> board(NUM_SQUARES, EMPTY);
    char player = playerSymbol();
    char computer = opposite(player);
    char turn = X;
    
    
    //while (winner(board) == NO_ONE)
    //{
    //    //if (turn == player)
    //    //{
    //        showInstructionBoard();
    //        playerMove(board, player);
    //    //}
    //    displayBoard(board);
    //}
}

void diceAnimation(int diceNumber)
{
    int minSpins = 5;
    int spins = 0;
    while (spins < minSpins)
    {
        spins++;
        system("cls");
        cout << " ___________ " << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|     ?     |" << endl;
        cout << "|           |" << endl;
        cout << "|___________|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "||          |" << endl;
        cout << "||          |" << endl;
        cout << "||    ?     |" << endl;
        cout << "||          |" << endl;
        cout << "||__________|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "| |         |" << endl;
        cout << "| |         |" << endl;
        cout << "|?|    ?    |" << endl;
        cout << "| |         |" << endl;
        cout << "|_|_________|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "|  |        |" << endl;
        cout << "|  |        |" << endl;
        cout << "|? |    ?   |" << endl;
        cout << "|  |        |" << endl;
        cout << "|__|________|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "|   |       |" << endl;
        cout << "|   |       |" << endl;
        cout << "| ? |   ?   |" << endl;
        cout << "|   |       |" << endl;
        cout << "|___|_______|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "|    |      |" << endl;
        cout << "|    |      |" << endl;
        cout << "| ?  |   ?  |" << endl;
        cout << "|    |      |" << endl;
        cout << "|____|______|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "|     |     |" << endl;
        cout << "|     |     |" << endl;
        cout << "|  ?  |  ?  |" << endl;
        cout << "|     |     |" << endl;
        cout << "|_____|_____|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "|      |    |" << endl;
        cout << "|      |    |" << endl;
        cout << "|   ?  |  ? |" << endl;
        cout << "|      |    |" << endl;
        cout << "|______|____|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "|       |   |" << endl;
        cout << "|       |   |" << endl;
        cout << "|  ?    | ? |" << endl;
        cout << "|       |   |" << endl;
        cout << "|_______|___|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "|        |  |" << endl;
        cout << "|        |  |" << endl;
        cout << "|   ?    | ?|" << endl;
        cout << "|        |  |" << endl;
        cout << "|________|__|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "|         | |" << endl;
        cout << "|         | |" << endl;
        cout << "|    ?    |?|" << endl;
        cout << "|         | |" << endl;
        cout << "|_________|_|" << endl;
        system("cls");
        cout << "____________ " << endl;
        cout << "|          ||" << endl;
        cout << "|          ||" << endl;
        cout << "|     ?    ||" << endl;
        cout << "|          ||" << endl;
        cout << "|__________||" << endl;
    }
    minSpins = 10;
    spins = 0;
    while (spins < minSpins)
    {
        spins++;
        system("cls");
        cout << "  ___________ " << endl;
        cout << " |           |" << endl;
        cout << " |           |" << endl;
        cout << " |     ?     |" << endl;
        cout << " |           |" << endl;
        cout << " |___________|" << endl;
        system("cls");
        cout << "   ___________ " << endl;
        cout << "  |           |" << endl;
        cout << "  |           |" << endl;
        cout << "  |     ?     |" << endl;
        cout << "  |           |" << endl;
        cout << "  |___________|" << endl;
        system("cls");
        cout << "  ___________ " << endl;
        cout << " |           |" << endl;
        cout << " |           |" << endl;
        cout << " |     ?     |" << endl;
        cout << " |           |" << endl;
        cout << " |___________|" << endl;
        system("cls");
        cout << " ___________ " << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|     ?     |" << endl;
        cout << "|           |" << endl;
        cout << "|___________|" << endl;
    }
    system("cls");
    cout << "  ___________ " << endl;
    cout << " |           |" << endl;
    cout << " |           |" << endl;
    cout << " |     " << diceNumber << "     | " << endl;
    cout << " |           |" << endl;
    cout << " |___________|" << endl;
}

void ExamenP2Ejercicio1()
{
    srand(time(NULL));
    int randomNumber;
    int diceRandomNumber;
    string playerPairOrInpair;

    //Pregunta par o impar
    playerPairOrInpair = askPairOrInpair("Eliga, Par o Impar");
    //cout << playerPairOrInpair << endl;
    //Selecciona el numero del dado random
    randomNumber = rand();
    diceRandomNumber = (randomNumber % 6) + 1;
    //cout << diceRandomNumber << endl;
    //Reproduce la animacion
    diceAnimation(diceRandomNumber);
    //Ve si es par o impar
    if (((diceRandomNumber / 2) * 2) == diceRandomNumber)
    {
        if (playerPairOrInpair == "PAR")
        {
            cout << "Le atinaste!, el numero es par, entonces el jugador es X" << endl;
        }
        else
        {
            cout << "Perdiste!, el numero es par, entonces el jugador es O" << endl;
        }
    }
    else
    {
        if (playerPairOrInpair == "IMPAR")
        {
            cout << "Le atinaste!, el numero es impar, entonces el jugador es X" << endl;
        }
        else
        {
            cout << "Perdiste!, el numero es impar, entonces el jugador es O" << endl;
        }
    }

}

void ExamenP2Ejercicio2()
{
    int matrix[3][4] =
    {
        1, 3, 1, 4,
        9, 8, 7, 9,
        3, 2, 1, 5
    };
    vector<int> xPos;
    vector<int> yPos;
    vector<int> PairNumbers;
    int sumaDePairs = 0;
    int sumaDePositions = 0;

    cout << "Primero, aqui esta la matriz:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j]<< " ";
        }
        cout << endl;
    }
    //Aqui vamos a guardar las posiciones de los numeros pares
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((matrix[i][j] / 2) * 2 == matrix[i][j])
            {
                xPos.push_back(i);
                yPos.push_back(j);
                PairNumbers.push_back(matrix[i][j]);
            }
        }
    }
    cout << "Posiciones de los numeros pares: " << endl;
    for (int i = 0; i < xPos.size(); i++)
    {
        cout << "(" << xPos[i] << ", " << yPos[i] << ")" << endl;
    }
    //Calcular la suma de los numeros pares
    for (int i = 0; i < PairNumbers.size(); i++)
    {
        sumaDePairs = sumaDePairs + PairNumbers[i];
    }
    //Ahora la suma de las posiciones
    for (int i = 0; i < xPos.size(); i++)
    {
        sumaDePositions = sumaDePositions + ((xPos[i] * 10) + yPos[i]);
    }
    cout << "Resultado de la operacion: " << endl;
    cout << sumaDePairs - sumaDePositions << endl;
}

string askPairOrInpair(string question)
{
    string input;
    cout << question << endl;
    cin >> input;
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    while (true)
    {
        if (input == "PAR")
        {
            return input;
        }
        else if (input == "IMPAR")
        {
            return input;
        }
        else
        {
            cout << "Respuesta invalida, porfavor " << question << endl;
            cin >> input;
            transform(input.begin(), input.end(), input.begin(), ::toupper);
        }
    }
}

void showInstructionBoard() 
{
    cout << endl;
    cout << "| 0 | 1 | 2 |" << endl;
    cout << "| 3 | 4 | 5 |" << endl;
    cout << "| 6 | 7 | 8 |" << endl;
}

bool isLegal(vector<char>& board, int move)
{
    if (*(board.begin() + move) == X || *(board.begin() + move) == O)
    {
        cout << "Casilla ocupada" << endl;
        return false;
    }
    else
    {
        //cout << "Bien" << endl;
        return true;
    }
}

int askNumber(string question, int high, int low)
{
    string input;
    bool isValid = false;
    bool isRangeValid = false;
    int number = 0;

    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do {
        cout << question << "entre " << low << " y " << high << endl;

        getline(cin, input);

        for (char c : input)
        {
            if (!isdigit(c))
            {
                isValid = false;
                break;
            }
            else
            {
                isValid = true;
                break;
            }
        }

        if (!isValid)
        {
            cout << "\nEntrada inválida, por favor elige solo números.\n";
        }
        else if (input.empty())
        {
            cout << "\nEntrada vacia, por favor escribe un numero.\n";
        }
        else
        {
            number = stoi(input);
            isRangeValid = number <= high && number >= low;
        }

        if (!isRangeValid && isValid)
        {
            cout << "\nEntrada inválida, elige un número dentro del rango establecido.\n";
        }

    } while (!isValid || input.empty() || !isRangeValid);

    return number;
}

void displayBoard(vector<char>& board)
{
    system("cls");
    cout << "Board:" << endl;
    cout << "| " << *(board.begin() + 0) << " | " << *(board.begin() + 1) << " | " << *(board.begin() + 2) << " | " << endl;
    cout << "| " << *(board.begin() + 3) << " | " << *(board.begin() + 4) << " | " << *(board.begin() + 5) << " | " << endl;
    cout << "| " << *(board.begin() + 6) << " | " << *(board.begin() + 7) << " | " << *(board.begin() + 8) << " | " << endl;
}

void playerMove(vector<char>& board, char player)
{
    vector<char>::iterator iter;
    int move;
    do {
        move = askNumber("Que casilla quieres poner ", 8, 0);
    } while (!isLegal(board, move));
    //*(board.begin() + move) = player;
    iter = board.begin() + move;
    *iter = player;
}

char winner(const vector<char>& board)
{
    const int WINNING_POS[8][3] = { {0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {2, 4, 6},
                                    {0, 4, 8} };

    const int TOTAL_ROWS = 8;

    //Return the winner
    for (int row = 0; row < TOTAL_ROWS; row++)
    {
        if ((board[WINNING_POS[row][0]] != EMPTY) &&
            (board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) &&
            (board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]]))
        {
            return board[WINNING_POS[row][0]];
        }
    }

    //Return a Tie
    if (count(board.begin(), board.end(), EMPTY) == 0) {
        return TIE;
    }

    //Return that no one is the winner yet
    return NO_ONE;
}

char opposite(char player)
{
    if (player == 'X')
    {
        return O;
    }
    return X;
}

char playerSymbol()
{
    char gofirst = AskYesNo("Quieres empezar?");
    if (gofirst == 'y')
    {
        cout << "Vas" << endl;
        return X;
    }
    else
    {
        cout << "Voy" << endl;
        return O;
    }
}

char AskYesNo(string question)
{
    char answer;

    do {
        cout << "\n" << question << "(y/n)";
        cin >> answer;
    } while (answer != 'y' && answer != 'n');

    return answer;
}

void instrucciones()
{
    cout << "Bienvenido al juego del tiktok!" << endl;
    cout << "Elige una buena casilla para empezar el combate a muerte" << endl;
    cout << "| 0 | 1 | 2 |" << endl;
    cout << "| 3 | 4 | 5 |" << endl;
    cout << "| 6 | 7 | 8 |" << endl;
}

void tictactoeChafa()
{
    const int ROWS = 3;
    const int COLUMNS = 3;

    int casillaJ = 0;

    int tableroShow[ROWS][COLUMNS] =
    {
        1,2,3,
        4,5,6,
        7,8,9
    };
    char tableroGame[ROWS][COLUMNS] =
    {
        ' ',' ',' ',
        ' ',' ',' ',
        ' ',' ',' '
    };

    string malo = "soyMalo";
    unsigned int turnoJugador = 1;
    int winner = 0;
    bool casillaValida = false;
    bool hayEspacio = false;

    while (winner == 0)
    {
        system("cls");
        cout << "Referencia de casillas" << endl;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                cout << "| " << tableroShow[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "Juego Actual" << endl;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                cout << "| " << tableroGame[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "Jugador #" << turnoJugador << "," << endl;
        cout << "Escriba el numero de la casilla donde quiera poner x" << endl;
        while (casillaValida == false)
        {
            cin >> casillaJ;
            if (casillaJ <= 0 || casillaJ > 9)
            {
                cout << "Espacio no valido" << endl;
                /*cout << "Escriba cualquier cosa para continuar" << endl;
                cin >> malo;*/
            }
            else
            {
                for (int i = 0; i < ROWS; i++)
                {
                    for (int j = 0; j < COLUMNS; j++)
                    {
                        if (tableroShow[i][j] == casillaJ)
                        {
                            if (tableroGame[i][j] == ' ')
                            {
                                if (turnoJugador == 1)
                                {
                                    tableroGame[i][j] = 'X';
                                    //turnoJugador = 2;
                                    casillaValida = true;
                                }
                                else
                                {
                                    tableroGame[i][j] = 'O';
                                    //turnoJugador = 1;
                                    casillaValida = true;
                                }
                            }
                            else
                            {
                                cout << "Espacio ya ocupado" << endl;
                                /*cout << "Escriba cualquier cosa para continuar" << endl;
                                cin >> malo;*/
                            }
                        }
                    }
                }
            }
        }

        //Aqui checa si ya acabo el juego
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                if (tableroGame[i][j] == ' ')
                {
                    hayEspacio = true;
                }
            }
        }
        if (hayEspacio == false)
        {
            winner = 3;
        }
        //Aqui checa las columnas
        for (int i = 0; i < ROWS; i++)
        {
            if (tableroGame[i][0] == tableroGame[i][1] && tableroGame[i][0] == tableroGame[i][2] && tableroGame[i][0] != ' ')
            {
                winner = turnoJugador;
            }
        }
        //Aqui las filas
        for (int i = 0; i < COLUMNS; i++)
        {
            if (tableroGame[0][i] == tableroGame[1][i] && tableroGame[0][i] == tableroGame[2][i] && tableroGame[0][i] != ' ')
            {
                winner = turnoJugador;
            }
        }
        //Aqui la diagonal
        if (tableroGame[0][0] == tableroGame[1][1] && tableroGame[0][0] == tableroGame[2][2] && tableroGame[0][0] != ' ')
        {
            winner = turnoJugador;
        }
        //Aqui la diagonal invertida
        if (tableroGame[0][2] == tableroGame[1][1] && tableroGame[0][2] == tableroGame[2][0] && tableroGame[0][2] != ' ')
        {
            winner = turnoJugador;
        }



        //Orden
        casillaValida = false;
        hayEspacio = false;
        if (turnoJugador == 1)
        {
            turnoJugador = 2;
        }
        else
        {
            turnoJugador = 1;
        }
    }
    system("cls");
    if (winner == 3)
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                cout << "| " << tableroGame[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "Nadie ha ganado" << endl;
    }
    else
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                cout << "| " << tableroGame[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "El jugador " << winner << " ha ganado" << endl;
    }
}