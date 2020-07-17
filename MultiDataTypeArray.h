#ifndef MULTIDATATYPEARRAY_MULTIDATATYPEARRAY_H
#define MULTIDATATYPEARRAY_MULTIDATATYPEARRAY_H
#include <typeinfo>

class MDTArray{

private:
    void** data;
    int size;
    char* types;

public:
    MDTArray(int size){
        types = new char[size];
        this->size = size;
        data = new void*[size];

        for(int i = 0; i<size; i++)
            types[i] = 'x';

    }

    char getTypes(int index){
        return types[index];
    }

    template <class dataType>
    void setValue(int index, dataType value){

        if(types[index] != 'x'){
            switch (types[index]) {
                case 'i':
                    delete static_cast<int*>(data[index]);
                    break;
                case 'c':
                    delete static_cast<char*>(data[index]);
                    break;
                case 'd':
                    delete static_cast<double*>(data[index]);
                    break;
                case 'f':
                    delete static_cast<float*>(data[index]);
                    break;
            }
        }

        data[index] = new decltype(value);
        *static_cast<decltype(value)*>(data[index]) = value;
        types[index] = typeid(value).name()[0];
    }

    template <class datatype>
    auto getValue(int index){
        datatype dummy;
        return *static_cast<decltype(dummy)*>(data[index]);
    }

    ~MDTArray(){
        for(int i=0; i<size; i++){

            switch (types[i]) {
                case 'i':
                    delete static_cast<int*>(data[i]);
                    break;
                case 'c':
                    delete static_cast<char*>(data[i]);
                    break;
                case 'd':
                    delete static_cast<double*>(data[i]);
                    break;
                case 'f':
                    delete static_cast<float*>(data[i]);
                    break;
                default:
                    continue;
            }

        }
        delete [] data;
        delete [] types;
    }
};

#endif //MULTIDATATYPEARRAY_MULTIDATATYPEARRAY_H
