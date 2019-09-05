#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

    void execute() {
        int min = *(min_element(elements,elements+size));
        int min2 = min;
        int max = *(max_element(elements,elements+size));
        int cuenta[max-min];
        int index[max-min];
        for(int i = 0; min<max+1;i++,min++)
        {
            index[i] = min;
            cuenta[i] = count(elements,elements+size,min);
        }
        int repeticiones = 0;
        for(int m = 0, n = 0; n < max-min2+1; n++) {
            repeticiones = cuenta[n];
            if(repeticiones != 0)
            {
                for(int s = 0; s<repeticiones; s++)
                {
                    elements[m+s] = index[n];
                }
                m = m + repeticiones;
            }
        }
    }

        inline string name() { return "CountingSort"; }
};

#endif