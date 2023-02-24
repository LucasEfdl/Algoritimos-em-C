#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m, n, qtdCostas = 0;
    printf("Digite o numero de linhas e colunas da matriz:");
    scanf("%d %d", &m, &n);
    if (m < 1 || n > 1000)
    {
        printf("Entrada invalida.\nVerifique os dados inseridos");
    }
    else
    {
        char **matriz = (char **)malloc(m * sizeof(char *));
        if (matriz == NULL)
        {
            exit(1);
        }

        for (int i = 0; i < m; i++)
        {
            matriz[i] = (char *)malloc(n * sizeof(char *));
            if (matriz[i] == NULL)
            {
                exit(1);
            }
        }

        printf("Preencha o mapa:\n");
        for (int i = 0; i < m; i++)
        {
            scanf(" %[^\n]s", matriz[i]);
        }

        printf("Mapa:\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%c\t", matriz[i][j]);
            }
            printf("\n");
        }

        // Verifica a prieira linha e coluna da matriz
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matriz[i][j] == '#')
                {

                    if (matriz[i][j + 1] == '.' || matriz[i + 1][j] == '.')
                    {
                        qtdCostas++;
                    }

                    else if ((j != 0) && (j != n - 1))
                    {
                        if (matriz[i][j + 1] == '.' || matriz[i + 1][j] == '.' || matriz[i][j - 1] == '.')
                        {
                            qtdCostas++;
                        }
                    }

                    else if (j == n - 1)
                    {
                        if (matriz[i + 1][j] == '.' || matriz[i][j - 1] == '.')
                        {
                            qtdCostas++;
                        }
                    }
                }
            }
        }

        // For que verifica o meio da matriz
        for (int i = 1; i <= (m - 2); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matriz[i][j] == '#')
                {
                    if (j == 0)
                    {
                        if (matriz[i][j + 1] == '.' || matriz[i - 1][j] == '.' || matriz[i + 1][j] == '.')
                        {
                            qtdCostas++;
                        }
                    }
                    else if ((j != 0) && (j != n - 1))
                    {
                        if (matriz[i][j - 1] == '.' || matriz[i][j + 1] == '.' || matriz[i - 1][j] == '.' || matriz[i + 1][j] == '.')
                        {
                            qtdCostas++;
                        }
                    }
                    else if (j == n - 1)
                    {
                        if (matriz[i][j - 1] == '.' || matriz[i - 1][j] == '.' || matriz[i + 1][j] == '.')
                        {
                            qtdCostas++;
                        }
                    }
                }
            }
        }

        // For que verifica a ultima linha
        for (int i = (m - 1); i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matriz[i][j] == '#')
                {
                    if (j == 0)
                    {
                        if (matriz[i][j + 1] == '.' || matriz[i - 1][j] == '.')
                        {
                            qtdCostas++;
                        }
                    }
                    else if ((j != 0) && (j != n - 1))
                    {
                        if (matriz[i][j - 1] == '.' || matriz[i][j + 1] == '.' || matriz[i - 1][j] == '.')
                        {
                            qtdCostas++;
                        }
                    }
                    else if (j == n - 1)
                    {
                        if (matriz[i][j - 1] == '.' || matriz[i - 1][j] == '.')
                        {
                            qtdCostas++;
                        }
                    }
                }
            }
        }

        printf("%d", qtdCostas);
        for (int i = 0; i < m; i++)
        {
            free(matriz[i]);
        }
        free(matriz);
    }
}