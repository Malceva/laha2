//
// Created by Daria on 13.10.2022.
//

#include "Array.h"


Array::Array()
{
    this-> size = 50;
    this-> length = 0;
    this->array = new float[this->size];
}


Array::Array(int size)
{
    this->size = size;
    this->length = 0;
    this->size2 = size;
    this->array = new float[this->size];
    for(int i=0; i<size;i++){
        add(i);
    }

}

Array::Array(const Array &other){
    this->size2 = other.size2;
    this->array = new float[other.size2];
    for(int i=0;i <other.size2; i++)
    {
        this->array[i] = other.array[i];
    }
};

Array::~Array(){
    delete[] array;
};

void Array::add(float  val)
{
    this-> array [this-> length] = val;
    this-> length ++;
}

void Array::remove(int index) {
    int k = this->size;
    for(int i = index;i< this->size-1; i++)
    {
        this->array[i] = this->array[i+1];
    }
    this->array[this->size-1] = 0;
}

void  Array::insert(int index, float val) {
    int size2 = this->size +1;
    float * newArr = new float [size2];

    memcpy( newArr, array, size * sizeof(int) );

    this->size = size2;
    delete [] array;
    array = newArr;
    for (int i = size; i > index; i--)
    {
        this->array[i] = this->array[i-1];

    }
    this->array[index] = val;
}

void Array::clear() {
    for(int i = 0; i< this->size; i++)
    {
        this->array[i] = 0;
    }

}
void  Array::contains(float val) {
    int value = 0;
    for (int i = 0; i < this->size; i ++)
    {
        if (this->array[i] == val)
        {
            cout<<"Exist"<<endl;

        }
        else{
            value ++;
        }
        if (value== this->size)
        {
            cout<< "Not Found"<<endl;

        }
    }
}

float Array::get(int index)
{
    return this->array[index];
}

void Array::set(int index, float val){

    this-> array [index] = val;
}

void Array::isEmpty() {
    int val = 0;
    for(int i =0; i< this->size; i++)
    {
        if (this->array[i] == 0)
        {
            val ++;
        }

    }
    if (val == size){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }
}
void Array::subList(int index, int index2) {

    for(int i = index; i < index2; i ++)
    {
        cout<< array[i]<<endl;

    }
}


char* Array::cStr() const{
    int len;
    int l;
    if (array == nullptr) return nullptr;
    l = digitCount(array, size);
    char *buf = new char[l + size * size];
    len = 0;
    for (int i = 0; i < size; i++) {
        len += std::sprintf(buf + len * sizeof(char), "%f", array[i]);
        if (i != size - 1) {
            len += strCat(buf, len, (' '));
        }
        else {
            len += strCat(buf, len, ('\0'));
        }
    }
    return buf;

}
int Array::digitCount(float *array, float order2) {
    Array other(order2);

    for (int i = 0; i < order2; i++) {
        other.array[i] = array[i];
    }
    int len;
    len = 0;
    for (int i = 0; i < order2; i++) {
        while (other.array[i] > 0) {
            len++;
            other.array[i] = other.array[i] / 10;
        }
    }
    return len;
}

int Array::strCat(char *buf, int len, char elem) {
    return std::sprintf(buf + len * sizeof(char), "%c", elem);
}