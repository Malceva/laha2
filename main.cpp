#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <cstring>
#include "Array.h"
#include "library.h"


using namespace std;

int main() {
    Array a(10);
    //LinkedList list(4);
    //list.print();
    //cout<<"----------------"<<endl;
    //list.remove(0);
    //list.add(3);
    //list.subList(1, 3);
    //list.isEmpty();
    //list.set(2, 4);
    //list.contains(2);
    //list.insert(2, 10);
    //list.clear();
    //cout<<list.get(2)<<endl;
    //list.print();




    /*a.insert(2, 8);
    cout<<a.get(11)<<endl;
    cout<<a.cStr()<<endl;
*/



    Kramer k(3);

    k.set(0,0, 1);
    k.set(0,1, 2);
    k.set(0,2, 3);
    k.set(1,0, 4);
    k.set(1,1, 5);
    k.set(1,2, 6);
    k.set(2,0, 7);
    k.set(2,1, 6);
    k.set(2,2, 8);


    Array b(3);
    b.set(0, 4);
    b.set(1, 2);
    b.set(2, 1);

    cout<<k.toString()<<endl;
    //k.opr(&k, 3);
    cout<<"----------------"<<endl;

    //k.Gauss(&k, &b, 0, 0 );
    k.solve(&k, &b, 0, 0);
    //cout<<"----------------"<<endl;
    //cout<<k.toString()<<endl;
    //k.kramer(&k, &b);
    //k.setMatrix(1, 1, 50);
    //cout<<k.getMatrix(1, 1)<<endl;
    //Matrix b(k);
    //cout<<b.getMatrix(1,1)<<endl;
    //cout<<b.toString()<<endl;
    // a.deleteArray(2);
    //cout<<a.get(2)<<endl;

    //cout<<a.getArrayPart(2, 5)<<endl;
    //cout<<a.Count<<endl;
    //a.existArray(14);

    //cout<<k.getMatrix(1, 0)<<endl;
    //cout<<l.getMatrix(1,1)<<endl;
    //Matrix c;
    //c = k + b;
    //cout<<c.getMatrix(0, 2)<<endl;
    //Matrix t;
    //t = k;
    //cout<<t.getMatrix(1,0)<<endl;

}