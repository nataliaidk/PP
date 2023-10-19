// ConsoleApplication2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//



#include "zad1_2_3.h"

#include <iostream>
#include <string>

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY){

    if (iSizeX <= 0 || iSizeY <= 0) {
        return false; // Nieprawidłowe wymiary tablicy
    }

    *piTable = new int* [iSizeX];
    if (*piTable == NULL) {
        return false; // Błąd alokacji pamięci
    }

    // Alokuje pamięć dla każdego wiersza tablicy
    for (int i = 0; i < iSizeX; i++) {
        (*piTable)[i] = new int[iSizeY];
        if ((*piTable)[i] == NULL) {
            return false;
        }
    }
    return true;


}


bool b_dealloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {
    if (iSizeX <= 0 || iSizeY <= 0) {
        return false; // Nieprawidłowe wymiary tablicy
    }
    if (*piTable == NULL) {
        return false; // Wskaźnik nie wskazuje na żadną tablicę
    }


    for (int i = 0; i < iSizeX; i++)
    {
        delete[](*piTable)[i];
    }
    delete[](*piTable);
    *piTable = nullptr;

    return true;
    return true;
}

void v_alloc_table_fill_34(int iSize, bool *bError) {
    if (iSize <= 0) {
        return;
    }
    int* table = new int[iSize];
    if (table == NULL) {
        return;
    }

    for (int i = 0; i < iSize; i++) {
             table[i] = ITABLE_VALUE;
          }

    printf("Tablica po wypelnieniu wartosciami 34:\n");
    for (int i = 0; i < iSize; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
    *bError = true;

    delete[] table;
}



int main() {

    int** pi_table;
    int i_sizeX = 5;
    int i_sizeY = 3;
    bool bError = false; 
    int size = 10;
    v_alloc_table_fill_34(ISIZE, &bError);

    if (bError) {
        std::cout << "Prawidlowa alokacja pamieci dla tablicy jednowymiarowej i wypelnienie jej wartosciami." << std::endl;
    }
    else {
        std::cout << "Blad alokacji pamięci dla tablicy jednowymiarowej." << std::endl;
    }

    if (b_alloc_table_2_dim(&pi_table, ISIZE_X, ISIZE_Y)) {
        std::cout << "Prawidlowa alokacja pamieci dla tablicy dwuwymiarowej." << std::endl;
    }
    else {
        std::cout << "Blad alokacji pamięci dla tablicy dwuwymiarowej." << std::endl;
    }

  
   

    if (b_dealloc_table_2_dim(&pi_table, ISIZE_X, ISIZE_Y)) {
        std::cout << "Prawidlowa dealokacja pamieci dla tablicy dwuwymiarowej." << std::endl;
    }
    else {
        std::cout << "Blad dealokacji pamieci dla tablicy dwuwymiarowej." << std::endl;
    }
    
}
