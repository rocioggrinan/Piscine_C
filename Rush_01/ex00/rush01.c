/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalarra <dgalarra@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:06:10 by dgalarra          #+#    #+#             */
/*   Updated: 2024/11/17 20:06:58 by dgalarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void    print_matrix(int matrix[4][4])
{
    int i = 0;
    int j;

    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            char num = matrix[i][j] + '0';
            write(1, &num, 1);
            if (j < 3)
                write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

void    apply_rules(int matrix[4][4], int *restrictions)
{
    int i = 0;

    // Aplicar regla de "4": completar fila o columna con 1, 2, 3, 4
    while (i < 4)
    {
        if (restrictions[i] == 4) // colXup
        {
            int j = 0;
            while (j < 4)
            {
                matrix[j][i] = j + 1;
                j++;
            }
        }
        if (restrictions[i + 4] == 4) // colXdown
        {
            int j = 0;
            while (j < 4)
            {
                matrix[3 - j][i] = j + 1;
                j++;
            }
        }
        if (restrictions[i + 8] == 4) // rowXleft
        {
            int j = 0;
            while (j < 4)
            {
                matrix[i][j] = j + 1;
                j++;
            }
        }
        if (restrictions[i + 12] == 4) // rowXright
        {
            int j = 0;
            while (j < 4)
            {
                matrix[i][3 - j] = j + 1;
                j++;
            }
        }
        i++;
    }

    // Aplicar regla de "1": colocar 4 en la posición visible
    i = 0;
    while (i < 4)
    {
        if (restrictions[i] == 1) // colXup
            matrix[0][i] = 4;
        if (restrictions[i + 4] == 1) // colXdown
            matrix[3][i] = 4;
        if (restrictions[i + 8] == 1) // rowXleft
            matrix[i][0] = 4;
        if (restrictions[i + 12] == 1) // rowXright
            matrix[i][3] = 4;
        i++;
    }
}

int main(int argc, char *argv[])
{
    int matrix[4][4];
    int i = 0;
    int j;

    // Asegurarse de que haya 16 parámetros
    if (argc != 17)
    {
        write(1, "Error: Se requieren exactamente 16 restricciones como parámetros\n", 67);
        return (1);
    }

    // Inicializar la matriz a ceros
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            matrix[i][j] = 0;
            j++;
        }
        i++;
    }

    // Convertir los parámetros de entrada en un arreglo de enteros
    int restrictions[16];
    i = 1; // Empezamos desde 1 porque argv[0] es el nombre del programa
    while (i < argc)
    {
        restrictions[i - 1] = atoi(argv[i]); // Convertir cada parámetro a entero
        i++;
    }

    // Aplicar reglas a la matriz
    apply_rules(matrix, restrictions);

    // Imprimir matriz resultante
    print_matrix(matrix);

    return (0);
}
