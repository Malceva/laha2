//
// Created by Daria on 13.10.2022.
//

#include "library.h"
#include <iostream>
#include "Array.h"


Matrix::Matrix(){
    rank = 0;
    matrix = nullptr;
}

Matrix::Matrix(int ranked) {
    rank = ranked;

    Array b(rank);
    //cout<<b.get(1)<<endl;

    matrix = new Array [100];
    for (int i = 0; i < rank; i++)
        for (int j = 0; j < rank; j++)
            matrix[i].set(j, b.get(j));
}
float Matrix::getMatrix(int i, int j) {
    return matrix[i].get(j);
}
Matrix::~Matrix() {
    delete [] matrix;
}

Matrix::Matrix(const Matrix &Copy) {
    rank =Copy.rank;
    matrix = new Array [Copy.rank];
    for (int i = 0; i < Copy.rank; i++)
        for (int j = 0; j < Copy.rank; j++) {
            matrix[i].set(j, Copy.matrix[i].get(j));
        }
}


void Matrix::setMatrix(int i, int j, float v) {
    matrix[i].set(j,v);

}

int Matrix::strSave(char *buf, int len, char e) {
    return std::sprintf(buf + len * sizeof(char), "%c", e);
}


char* Matrix::toString() const {
    int l, len;
    if (matrix == nullptr) return nullptr;
    l = dCount(matrix, rank);
    char *buf = new char[l + rank * rank];
    len = 0;
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            len += std::sprintf(buf + len * sizeof(char), "%f", matrix[i].get(j));
            if (j != rank - 1) {
                len += strSave(buf, len, (' '));
            }
        }
        if (i != rank - 1) {
            len += Matrix::strSave(buf, len, ('\n'));

        } else {
            len += Matrix::strSave(buf, len, ('\0'));
        }
    }
    return buf;
}

Matrix Matrix::operator=(const Matrix &Copy) {
    if (this != &Copy) {
        delete[] matrix;
        rank = Copy.rank;
        matrix = new Array [Copy.rank];

        for (int i = 0; i < Copy.rank; i++) {
            for (int j = 0; j < Copy.rank; j++) {
                matrix[i].set(j, Copy.matrix[i].get(j));
            }
        }
    }
    return *this;
}


Matrix Matrix::operator+(const Matrix &Copy) {
    Matrix temp (rank);
    for (int i = 0; i < rank; i++){
        for (int j = 0; j < rank; j++) {
            temp.matrix[i].set(j, matrix[i].get(j) + Copy.matrix[i].get(j));
        }
    }
    return temp;
}

int Matrix::dCount(Array* mat, int r) {
    Matrix dif(r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            dif.matrix[i].set(j, mat[i].get(j));

        }
    }
    int len;
    len = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            while (dif.matrix[i].get(j) > 0) {
                len++;
                dif.matrix[i].set(j, dif.matrix[i].get(j)/10);
            }
        }
    }
    return len;
}

void Matrix::transpose()  {
    Matrix other(rank);
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            other.matrix[i].set(j, matrix[i].get(j));
        }
    }
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            matrix[i].set(j, other.matrix[i].get(j));

        }
    }
}

void Matrix::solve(Matrix *mat, Array *b, int position, int position2) {

}

