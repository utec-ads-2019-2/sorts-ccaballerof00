#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for(int i = 0; i< size; i++)
            {
                int min = *(min_element(elements+i,elements+size));
                int valor =*(find(elements+i,elements+size,min));
                swap(elements[i],valor);
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif