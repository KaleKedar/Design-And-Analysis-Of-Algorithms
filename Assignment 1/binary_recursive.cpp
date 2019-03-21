#include <iostream>
using namespace std;

int BinarySearch(int list[], int low, int high, int key);


int BinarySearch(int list[], int low, int high, int key)
{
    if(low > high)
    {
        return -1;
    }
    int mid= low + (high - low)/2;

        if (list[mid] == key)
        {
            return mid;
        }
        else if (list[mid] <key)
            return BinarySearch(list,low,mid -1, key);
        else
            return BinarySearch(list,mid + 1, high, key);
}


int main()
{
    int SIZE;
    int Array[SIZE];
    int value;
    int i,j,temp;
    cout << "Enter the size of your array. \n";
    cin >> SIZE;
    cout<< "\n";

    cout << "Enter the numbers of your array. \n";
    for(int i= 0; i< SIZE; i++)
        {
            cout << "Element " <<i+1 <<": ";
            cin>> Array[i];
        }
        
    for(i=1;i<SIZE;i++)
	{
		for(j=0;j<(SIZE-i);++j)
			if(Array[j]>Array[j+1])
			{
				temp=Array[j];
				Array[j]=Array[j+1];
				Array[j+1]=temp;
			}
	}
	
	cout<<"\nArray after sorting:";
	for(i=0;i<SIZE;i++){
		cout<<" "<<Array[i];
	}
    
    
    cout << "\nEnter a number to find from the above list of numbers. \n";
    cin >> value;
    cout << "\n\n";

    int Loc = BinarySearch(Array, 0, SIZE- 1, value);

    if(Loc >= 0)
        {
        cout<< "Number is found.\n";
        cout << "The number is: " <<Loc +1 << ".\n";
        }
        else
            cout<< "Number is not found.\n";

    return 0;
}

/*
Output:
Enter the size of your array.                                                                                                          
6                                                                                                                                      
                                                                                                                                       
Enter the numbers of your array.                                                                                                       
Element 1: 12                                                                                                                          
Element 2: 33                                                                                                                          
Element 3: 44                                                                                                                          
Element 4: 5                                                                                                                           
Element 5: 4                                                                                                                           
Element 6: 33                                                                                                                          
                                                                                                                                       
Array after sorting: 4 5 12 33 33 44                                                                                                   
Enter a number to find from the above list of numbers.                                                                                 
12                                                                                                                                     
                                                                                                                                       
                                                                                                                                       
Number is found.                                                                                                                       
The number is: 3.
*/

