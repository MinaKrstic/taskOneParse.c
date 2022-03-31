#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortArray(long int* array, int n)
{
    int i;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(array [i] > array [j])
            {
                int tmp = array [i];
                array [i] = array [j];
                array [j] = tmp;
            }
        }
    }
}

void printArray(long int* array, int n)
{
    printf(" Sortirani niz je: \n");
    printf(" [");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", array[i]);
        if (i != n-1)
        {
            printf(",");     
        }
    }
    printf("] \n");
}

int main(int argc, char* argv[])
{
    long int array[10];
    char str[100];
    char* cursor = str;
    int i = 0;
    int n = 0;
    char bufferArray [100];
    char finalArray [100];

    if( argc == 2 )//ako u terminalu unesemo dav argumenta tj ime fajla i neki niz kojim ce se manipulisati u programu, taj niz ce se smestiti u char str i nastavice se izvrsavanje programa
    {
        printf(" Navedeni argument je %s\n", argv[1]);
        strcpy(str, argv[1]);
    }
   else if( argc > 2 ) 
    {
        printf(" Navedeno je previše argumenata.\n");
        exit(0);
    }
   else //ako u terminalu nije prosladjen drugi argument tj niz karaktera onda ce se ucitavati niz preko scanf
    {
        printf(" Unesi niz elemenata u formi primera (56,6,1,20,7):");
        scanf("%s", str);
    }

    printf(" Elementi niza su: \n");
    while (cursor != str + strlen(str)) // Provrava da li je dosao do kraja niza, tako sto pita da li nije kursor(pokazivac cursor) na poziciji (velicina prvog elementa+ duzina naseg niza)
    {
        long int x = strtol (cursor, &cursor, 10);
        array[i] = x;
        printf(" %d \n", array[i]);
        i++;
        n++;
        while (*cursor == ' ' || *cursor == ',') 
        {
            cursor ++;
        } 
    }

    sortArray(array, n);
    printArray(array, n);

    printf(" Niz karaktera: [");
    for (i = 0; i < n; i++)
    {
        sprintf(bufferArray, "%d ", array[i]);   
        strcat(finalArray, bufferArray);
    }
    printf("%s ", finalArray);
    printf(" ] \n");
    
return 0;// znaci da funkcija ne vraca nikakvu vrednost. Return 0 govori procesoru da je izvršenje programa završeno i da se može otpustiti.
}
