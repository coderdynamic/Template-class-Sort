//Template functions which can sort numbers, characters and array of objects

#include<iostream>
#include<string.h>
using namespace std;
char t;

//class containig student credentials
class student
{
	public:

	int rollno;
	char name[30];
	int year;

	int operator > ( student& a)
	{
		if(t=='r')
			{
				if (rollno > a.rollno)
					return 1;
				else
				 	return 0;
			}
		else if(t=='y')
			{
				if (year > a.year)
					return 1;
				else
				 	return 0;
			}
		else if(t=='n')
			{
				if(strcmp(name,a.name)>0)
					return 1;
				else
					return 0;
			}
	}

	friend ostream& operator << (ostream& tempout, student& tempc);
	friend istream& operator >> (istream& tempin, student& tempc);
};

//template function for sorting where c is a user-defined datatype
template<class c>
void sort(int n)
{
	c a[n];
	for(int k=0;k<n;k++)
		cin>>a[k];

	int i,j;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				c item;
				item=a[i];
				a[i]=a[j];
				a[j]=item;
			}
		}
	}

	cout<<"Sorted elements are:"<<endl;
	for(int k=0;k<n;k++)
		cout<<a[k]<<" ";
	cout<<endl;
}

  // '<<' operator overloading function
    ostream& operator << (ostream& tempout, student& tempc)
    {
	cout<<"Name:\t";
	tempout<<tempc.name<<endl;
	cout<<"Roll Number:\t";
	tempout<<tempc.rollno<<endl;
	cout<<"Year:\t";
	tempout<<tempc.year<<endl<<endl;
        return tempout;
    }

    // '>>' operator overloading function
    istream& operator >> (istream& tempin, student& tempc)
    {
	cout<<"\nEnter name"<<endl;
	tempin>>tempc.name;
	cout<<"Enter roll number"<<endl;
	tempin>>tempc.rollno;
	cout<<"Enter year"<<endl;
	tempin>>tempc.year;
	cout<<endl;
        return tempin;
    }

int main(void)
{

	int n; //n is the length of the array
	char name,ch;
	do
	{
		cout<<"What array you want:"<<endl;
		cin>>name;
		cout<<"Enter the length of the array:"<<endl;
		cin>>n;
		switch(name)
		{
			case 'I': sort <int> (n);
			break;

			case 'F': sort <float> (n);
			break;

			case 'C': sort <char> (n);
			break;

			case 'D': sort <double> (n);
			break;

			case 'S': cout<<"Which sort you want:\t";
					cin>>t;
				  sort <student> (n);
			break;

		}
		cout<<endl<<"Do you want to run again?"<<endl;
		cin>>ch;

	}while(ch!='n');
	return 0;
}
