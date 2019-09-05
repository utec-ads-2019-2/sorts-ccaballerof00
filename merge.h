#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}


    void execute() {
        mergesort(0,size-1);
    }

    void merge(int izquierda, int derecha)
    {
        int* minimo;
        for(int i = izquierda; i <= derecha; i++)
        {
            minimo = min_element(elements+i,elements+derecha+1);
            swap(*minimo,elements[i]);
        }
    }

    void mergesort(int izquierda, int derecha)
    {
        if(izquierda<derecha)
        {
            int medio = (izquierda + derecha)/2;
            mergesort(izquierda,medio);
            mergesort(medio+1,derecha);

            merge(izquierda,derecha);
        }
    }

        inline string name() { return "MergeSort"; }
};

#endif