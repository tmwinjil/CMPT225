#include<cstdlib>
#include<time.h>
#include<iostream>
#include "Test.h"
#include "Unique.h"

using namespace std;

int main() {
    Test myTest;
    myTest.test(1,50);
    myTest.test(5,10);
    myTest.test(20,100);
    myTest.test(50,200);
}

void Test::test(int n, int max)
{
    bool test = false;
    Unique check;
    int* array = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % max;
        cout<<array[i]<<" ";
    }
    test = check.unique(array, n);
    cout<<endl<<"result: "<<test<<endl;
}