#include<iostream>

using namespace std;


using namespace std;
int *readarray(int);
void printarray(int a[], int size);
void sortarray(int a[],int size);

int main()
{
        int *check, length;
        check = NULL;
	cout<<"Please enter the number of integers in the array followed by the array"<<endl;
	if(cin>>length)
	{
		check = readarray(length);
	} else
	{
		cout<<"Cannot read empty array"<<endl;
		check = NULL;
	}

	printarray(check, length);
	cout<<endl;
	sortarray(check, length);
	printarray(check, length);
}

int *readarray(int size)
{
	int *numarray;

	numarray = new int[size];

	for(int i = 0; i < size; i++)
	{
		cin>>numarray[i];
	}
	return numarray;
}

void printarray(int a[], int size)
{
	if (size == 0)
	{
		cout<<"[]"<<endl;
		return;
	}
	else
		cout<<"[";
	for (int i = 0; i < size; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\b]"<<endl;
	
}

void sortarray(int a[], int size)
{
	bool check = false;
	int temp = 0;

	for (int j = 0; j < size; j++)
	{
		check = false;
		for(int i = 0; i < size -j - 1; i++)
		{
			if (a[i] < a[i+1])
			{
				check = true;
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;	
			}
		}
		if (check == false)
			break;

	}
}
