#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
    const int numeros_maximo = 100;
    int numeros[numeros_maximo];
    int cantidad_de_intentos = 0;

    int min, max, aleatorio, intentos = 0, adivinar;

    cout << "Ingrese un numero minimo" << endl;
    cin >> min;

    cout << "Ingrese un numero maximo" << endl;
    cin >> max;

    cout << "Ingrese la cantidad de intentos" << endl;
    cin >> intentos;

    srand(time(NULL));
    aleatorio = rand() % (max - min + 1) + min;

    while (intentos > 0) {
        cout << "Intente adivinar el numero:" << endl;
        cin >> adivinar;

        bool numero_ya_ingresado = false;
        for (int i = 0; i < cantidad_de_intentos; ++i) {
            if (numeros[i] == adivinar) {
                numero_ya_ingresado = true;
                break;
            }
        }

        if (numero_ya_ingresado) {
            cout << "Este numero ya fue ingresado, intente otro" << endl;
            continue;
        }

        numeros[cantidad_de_intentos++] = adivinar;

        if (aleatorio == adivinar) {
            cout << "Felicidades, te pasaste el juego" << endl;
            break;
        } else if (aleatorio < adivinar) {
            cout << "El numero es menor" << endl;
        } else {
            cout << "El numero es mayor" << endl;
        }

        intentos--;

        if (intentos > 0) {
            cout << "Te quedan " << intentos << " intentos " << endl;
            cout << "Estas en el intento " << cantidad_de_intentos << endl;
        } else {
            cout << "Perdiste, ya no tiene intentos disponibles." << endl;
            cout << "El numero que intentaste adivinar era " << aleatorio << " " << endl;
        }
    }
    for (int i = 0; i < cantidad_de_intentos - 1; ++i) {
        for (int j = 0; j < cantidad_de_intentos - i - 1; ++j) {
            int temp = numeros[j];
            numeros[j] = numeros[j + 1];
            numeros[j + 1] = temp;
        }
    }

    cout << "Tus intentos fueron: ";
    for (int i = 0; i < cantidad_de_intentos; ++i) {
        cout << numeros[i] << " ";
    }

    return 0;
}
