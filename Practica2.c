#include <stdio.h>

// Función para imprimir el tablero con la pieza en la casilla (x,y)
// y los movimientos válidos marcados con un asterisco (X)
void imprimir_tablero(int tablero[][8], int x, int y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == x && j == y) {
                printf("Q "); // para la Reina
            } else if (i == x || j == y || (i - x) == (j - y) || (i - x) == -(j - y)) {
                printf("X "); // marca los movimientos válidos con un asterisco (X)
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    int opcion = 0;
    while (opcion != 3) {
        printf("\n--- MENU ---\n");
        printf("1. Reina\n");
        printf("2. Rey\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) { // Reina
            int x, y;
            printf("Ingrese la coordenada x (0-7): ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y (0-7): ");
            scanf("%d", &y);
            int tablero[8][8] = {0}; // inicializa el tablero con ceros
            imprimir_tablero(tablero, x, y);
        } else if (opcion == 2) { // Rey
            int x, y;
            printf("Ingrese la coordenada x (0-7): ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y (0-7): ");
            scanf("%d", &y);
            int tablero[8][8] = {0}; // inicializa el tablero con ceros
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i != 0 || j != 0) { // se asegura de no considerar la casilla actual
                        int nx = x + i;
                        int ny = y + j;
                        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) { // se asegura de no salirse del tablero
                            tablero[nx][ny] = 1; // marca los movimientos válidos con un 1
                        }
                    }
                }
            }
            imprimir_tablero(tablero, x, y);
        }
    }

    printf("Hasta luego.\n");
    return 0;
}
