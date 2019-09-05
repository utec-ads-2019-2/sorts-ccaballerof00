#ifndef RADIX_H
#define RADIX_H

#include "sort.h"
#include <math.h>

class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int maximo = *max_element(elements,elements+size);
            for(int i = 0; i <= log10(maximo);i++)
            {
                for(int m = 0; m < size; m++) {
                    for (int s = 0; s < size-1; s++) {
                        int a = elements[s] / pow(10, i);
                        int b = elements[s + 1] / pow(10, i);
                        if (a % 10 > b % 10) {
                            swap(elements[s], elements[s + 1]);
                        }
                    }
                }
            }
        }

        inline string name() { return "RadixSort"; }
};

#endif