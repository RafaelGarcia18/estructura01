#include <stdio.h>

int main(void)
{
    int tamanom;
    printf("Ingrese el tamaño de la matriz\n");
    scanf("%d", &tamanom);
    int matriz1[tamanom][tamanom],matriz2[tamanom][tamanom],matriz3[tamanom][tamanom];
    for (int i = 0; i < tamanom; i++)
    {
        for (int o = 0; o < tamanom; o++)
        {
            printf("Ingrese el valor para la matriz en la posicion %d, %d\n", (i + 1), (o + 1));
            scanf("%d", &matriz1[i][o]);
        }
    }
    for (int i = 0; i < tamanom; i++)
    {
        for (int o = 0; o < tamanom; o++)
        {
            printf("Ingrese el valor para la matriz en la posicion %d, %d\n", (i + 1), (o + 1));
            scanf("%d", &matriz2[i][o]);
        }
    }
    //llena la matriz3 con el resultado de las multiplicaciones
    printf("\nLa matriz resultante es:\n");
    for (int i = 0; i < tamanom; i++)
    {
        for (int o = 0; o < tamanom; o++)
        {
            matriz3[i][o] = matriz1[i][o]*matriz2[i][o];
            printf("%d\t",matriz3[i][o]);
        }
        printf("\n");
    }
    //contar lo numeros primos para generar un vector de un tamano justo
    int tamanov = 0;
    for (int i = 0; i < tamanom; i++)
    {
        for (int o = 0; o < tamanom; o++)
        {
            //calcula si es primo
            int contador=0;
            for(int u=1; u<=matriz3[i][o]; u++)
            {
                //un primo solo se puede dividir entre 1 y entre el mismo
                if(matriz3[i][o]%u==0)
                {
                    contador++;
                }
            }
            if(contador ==2)
            {
                tamanov ++;
            }
        }
    }

    //llena el vector con los primos
    if(tamanov >=1)
    {
        int vector[tamanov],iteracionv = 0;
        for (int i = 0; i < tamanom; i++)
        {
            for (int o = 0; o < tamanom; o++)
            {
                //calcula si es primo, otra vez
                int contador=0;
                for(int u=1; u<=matriz3[i][o]; u++)
                {
                    //un primo solo se puede dividir entre 1 y entre el mismo
                    if(matriz3[i][o]%u==0)
                    {
                        contador ++;
                    }
                }
                if(contador ==2)
                {
                    vector[iteracionv] = matriz3[i][o];
                    printf("Primo encontrado en la posicion %d, %d y es: %d\n",(i+1),(o+1), vector[iteracionv]);
                    iteracionv++;
                }
            }
        }
        //se ordena el vector
        printf("ordenando de forma ascendente el vector...\n");
        if(tamanov>1)
        {
            int burbuja;
            //si el vector solo es de una posicion se salta el ordenamiento
            for (int i =0; i<(tamanov-1); i++)
            {
                if(vector[i]>vector[i+1])
                {
                    burbuja = vector[i];
                    vector[i] = vector [i+1];
                    vector[i+1] = burbuja;
                }
            }
        }
        printf("el vector ordenado de numeros primos es:\n");
        for (int i=0; i<tamanov; i++)
        {
            printf("%d \t",vector[i]);
        }
    }
    else
    {
        printf("No existen numeros primos");
    }
}

