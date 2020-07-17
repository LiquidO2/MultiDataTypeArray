#include <iostream>
#include "MultiDataTypeArray.h"

int main(){

    int size = 4;
    MDTArray arr(size);

    arr.setValue(0, 'A');
    arr.setValue(1, 1);
    arr.setValue(2, 3.14f);
    arr.setValue(3, 3.14159);

    std::cout<<arr.getValue<char>(0)<<std::endl;
    std::cout<<arr.getValue<int>(1)<<std::endl;
    std::cout<<arr.getValue<float>(2)<<std::endl;
    std::cout<<arr.getValue<double>(3)<<std::endl;

    // lets assign a different value of same datatype as the existing value in one of the indices
    arr.setValue(1, 5);
    std::cout<<arr.getValue<int>(1)<<std::endl;

    // lets assign a different value of different datatype in one of the indices
    arr.setValue(0, 1.1f);
    std::cout<<arr.getValue<float>(0)<<std::endl;

}
