#include <iostream>
#include <vector>;

using namespace std;

void tictactoeChafa();
void instrucciones();
char AskYesNo(string question);
char playerSymbol();
char opposite(char player);
char winner();

const int NUM_SQUARES = 9;
const char EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const char NO_ONE = 'N';
const char TIE = 'T';

int main()
{
    vector<char> board(NUM_SQUARES, EMPTY);
    char player = playerSymbol();
    char computer = opposite(player);
    char turn = X;

    while (winner() == NO_ONE)
    {

    }

    cout << player << endl;
    cout << computer << endl;
}

char winner(/*Aca deberia entrar board como referencia y constante para no editarlo*/)
{
    //si gana jugador = x, computadora = o, empate = t, ninguno = n
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
        return X;
    }
    else
    {
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