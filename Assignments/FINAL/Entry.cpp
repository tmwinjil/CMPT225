#include "Entry.h"

using namespace std;

Entry::Entry()
{
    month = 0;
    day = 0;
    for (int i =0; i <3; i++) {
        initials[i] = '\0';
    }
}
Entry::Entry(const Entry & e)
{
    month = e.month;
    day = e.day;
    for (int i =0; i <3; i++) {
        initials[i] = e.initials[i];
    }
}
Entry::Entry(int m, int d, string s)
{
    month = m;
    day = d;
    for (int i =0; i <3; i++) {
        initials[i] = s[i];
    }

}

Entry::Entry(int m, int d, char* word)
{
    month = m;
    day = d;
    for (int i =0; i < 3; i++) {
        initials[i] = word[i];
    }

}
void Entry::printEntry()
{
    cout<<month<<","<<day<<',';
    for (int i =0; i < 3; i++) {
        cout<<initials[i];
    }

}