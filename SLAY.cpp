//
// Created by Daria on 03.12.2022.
//
#include "library.h"
#include <iostream>
#include "Array.h"


Kramer::Kramer(){
    rank = 0;
    matrix = nullptr;

}

Kramer::Kramer(int ranked) {
    rank = ranked;

    Array b(rank);
    //cout<<b.get(1)<<endl;

    matrix = new Array [rank];
    for (int i = 0; i < rank; i++)
        for (int j = 0; j < rank; j++)
            matrix[i].set(j, b.get(j));
}

Kramer::~Kramer()  {
    delete [] matrix;
}
float Kramer::get(int i, int j) {
    return matrix[i].get(j);
}
void Kramer::set(int i, int j, float v) {
    matrix[i].set(j,v);
}

int Kramer::strSave(char *buf, int len, char e) {
    return std::sprintf(buf + len * sizeof(char), "%c", e);
}

char* Kramer::toString() const {
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
            len += Kramer::strSave(buf, len, ('\n'));

        } else {
            len += Kramer::strSave(buf, len, ('\0'));
        }
    }
    return buf;
}

int Kramer::dCount(Array* mat, int r) {
    Kramer dif(r);
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


void Kramer:: solve(Matrix* mat, Array *b, int position, int position2) {
    Kramer p(this->rank);
    for (int i =0; i < this->rank; i++)
    {
        for(int j = 0; j < this->rank; j++)
        {
            p.set(i, j, mat->getMatrix(i, j));
        }
    }

    int l;
    int k = p.opr(mat, this->rank);
    for (int i = 0; i < this->rank; i++)
    {
        l = mat->column(mat, i, b)/k;
        cout<<l<<endl;
    }

}


int Matrix::column(Matrix *mat, int h, Array *b) {
    Kramer p(this->rank);
    for (int i =0; i < this->rank; i++)
    {
        for(int j = 0; j < this->rank; j++)
        {
            p.set(i, j, mat->getMatrix(i, j));
        }
    }
    int d;
    for(int j = 0; j < this->rank; j ++)
    {

        p.setMatrix(j, h, b->get(j));

    }
    return d = p.opr(&p, this->rank);
}


int  Matrix::opr(Matrix* mat, int order) {
    int i, j, d, k, n;
    Matrix p(order);
    j = 0; d = 0;
    k = 1;
    n = order - 1;
    if (order<1) cout << "NO!";
    if (order == 1) {
        d = mat->getMatrix(0, 0);
        return d;
    }
    if (order == 2) {
        d = mat->getMatrix(0,0) *mat->getMatrix(1,1) - (mat->getMatrix(1,0)*mat->getMatrix(0,1));
        return d;
    }
    if (order>2) {
        for (i = 0; i<order; i++) {
            GetMatr(mat, &p, i, 0, order);
            d = d + k * mat->getMatrix(i, 0)* opr(&p, n);

            k = -k;
        }
    }
    return d;


}
void Matrix::GetMatr(Matrix *mat, Matrix *p, int i, int j, int order) {

    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki<order - 1; ki++) {
        if (ki == i) {di = 1;
            dj = 0;
        }
        for (kj = 0; kj<order - 1; kj++) {
            if (kj == j) {
                dj = 1;
            }
            p->setMatrix(ki, kj, mat->getMatrix(ki+di, kj+dj));

        }

    }


}
/*
float SLAY::Gauss(Matrix* mat, Array *b, int position, int position2) {
    Array x(3);
    for(int i = 0; i < rank; i++)
    {
        x.set(i, b->get(i));

    }

    Matrix p(this->rank);
    for (int i =0; i < this->rank; i++)
    {
        for(int j = 0; j < this->rank; j++)
        {
            p.setMatrix(i, j, mat->getMatrix(i, j));
        }
    }
    if(position == rank -1){
        x.set(position, x.get(position)/ p.getMatrix(position,position2));
        p.setMatrix(position, position2, p.getMatrix(position,position2)/p.getMatrix(position,position2));
        cout<<"-------"<<endl;
        cout<<p.toString()<<endl;
        cout<<x.cStr()<<endl;
        int d;
        for (int i = rank-1; i != -1; i--){
            if(i == rank-1){
                cout<<x.get(rank-1)<<endl;
            }
            else{
                d = x.get(i);
                for(int j = rank-1; j >i; j--)
                {
                    d = d -x.get(j) * p.getMatrix(i,j);
                }
                cout<<d<<endl;
            }
        }
    }
    else{
        float k = mat->getMatrix(position, position2);

        for (int i = position+1; i< this->rank; i++)
        {
            if (k <mat->getMatrix(i, position2))
            {
                k = mat->getMatrix(i, position2);
            }
        }

        for(int i = position; i < rank; i ++)
        {
            if(k == mat->getMatrix(i, position2))
            {
                for(int l=position; l <rank; l++)
                {
                    p.setMatrix(position,l,mat->getMatrix(i, l));
                    p.setMatrix(i,l,mat->getMatrix(position, l));


                    //cout<<"-------"<<endl;
                    //cout<<p.toString()<<endl;

                }
                x.set(position, b->get(i));
                x.set(i, b->get(position));
                //cout<<"-------"<<endl;
                //cout<<x.cStr()<<endl;

            }
        }
        cout<<"Posle Perestanovki"<<endl;
        cout<<"-------"<<endl;
        cout<<p.toString()<<endl;
        cout<<x.cStr()<<endl;

        for (int i =position; i< rank; i++)
        {
            float u = p.getMatrix(i,position2);
            for (int j = position2; j< rank; j ++){


                p.setMatrix(i, j, p.getMatrix(i,j)/u);
                //cout<<"-------"<<endl;
                //cout<<p.toString()<<endl;
            }
            x.set(i, x.get(i)/u);
            //cout<<x.cStr()<<endl;
        }
        cout<<"Posle Delenya"<<endl;
        cout<<"-------"<<endl;
        cout<<p.toString()<<endl;
        cout<<x.cStr()<<endl;

        for (int i = position + 1; i < rank; i ++)
        {
            for (int j = position2; j<rank; j++)
            {
                float y = p.getMatrix(position, j);
                p.setMatrix(i, j, p.getMatrix(i, j)-y);
            }
            x.set(i, x.get(i)-x.get(position));
            cout<<"Itog"<<endl;
            cout<<p.toString()<<endl;
            cout<<x.cStr()<<endl;

        }
        position ++;
        position2 ++;
        //p.Gauss(&p, &x, position, position2);

    }

}*/
