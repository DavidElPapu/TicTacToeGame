#include <iostream>

using namespace std;

int main()
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

    while (true)
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
        cin >> casillaJ;
        if (casillaJ <= 0 || casillaJ > 9)
        {
            cout << "Espacio no valido" << endl;
            cout << "Escriba cualquier cosa para continuar" << endl;
            cin >> malo;
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
                                turnoJugador = 2;
                            }
                            else
                            {
                                tableroGame[i][j] = 'O';
                                turnoJugador = 1;
                            }
                        }
                        else
                        {
                            cout << "Espacio ya ocupado" << endl;
                            cout << "Escriba cualquier cosa para continuar" << endl;
                            cin >> malo;
                        }
                    }
                }
            }
        }
        //Aqui checa las columnas
        for (int i = 0; i < ROWS; i++)
        {
            if (tableroGame[i][0] == tableroGame[i][1] && tableroGame[i][0] == tableroGame[i][2] && tableroGame[i][0] != ' ')
            {
                cout << "Ganaste" << endl;
                cin >> malo;
            }
        }
        //Aqui las filas
        for (int i = 0; i < COLUMNS; i++)
        {
            if (tableroGame[0][i] == tableroGame[1][i] && tableroGame[0][i] == tableroGame[2][i] && tableroGame[0][i] != ' ')
            {
                cout << "Ganaste" << endl;
                cin >> malo;
            }
        }
    }
}

