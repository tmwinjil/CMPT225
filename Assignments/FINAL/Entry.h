#ifndef ENTRY_H
#define ENTRY_H
#include<string.h>
#include<iostream>
using namespace std;

class Entry {
public:
    Entry();
    Entry(const Entry & e);//Copy Constructor
    Entry(int m, int d, string s);
    Entry(int m, int d, char* word);

    void printEntry();
    int month;
    int day;
    char initials[3];
};
#endif