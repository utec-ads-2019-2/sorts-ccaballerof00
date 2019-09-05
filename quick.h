#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

    void Quicksort(int inicio, int final)
    {
        if(inicio >= final)return;
        int cont = inicio;
        int pivote = elements[final];
        for(int i = inicio; i < final; i++)
        {
            if(elements[i] < pivote)
            {
                swap(elements[i],elements[cont]);
                cont++;
            }
        }
        swap(elements[cont],elements[final]);
        Quicksort(inicio,cont-1);
        Quicksort(cont+1,final);
    }

    void execute() {
            Quicksort(0,size-1);
        }

        inline string name() { return "QuickSort"; }
};

#endif