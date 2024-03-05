#include <iostream>
#include "Sorting_unit.h"
int main()
{
    int* a = new int[8] {8,5,6,2,12,3,4,1};
    int* b = new int[4] {8, 4, 7, 3};

    int* c = new int[4] {8, 4,5,3};

    
    selection_sort(a,8);
    array_out(a, 8);
}
