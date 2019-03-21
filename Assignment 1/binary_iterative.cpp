#include<iostream>
 
using namespace std;
 

int main()
{
	int a[50],n,i,j,temp,f,l,m,search;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the array elements: "; 
	
	for(i=0;i<n;i++)
		cin>>a[i];
		
	for(i=1;i<n;i++)
	{
		for(j=0;j<(n-i);++j)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	}
	
	cout<<"\nArray after sorting:";
	for(i=0;i<n;i++){
		cout<<" "<<a[i];
	}
	cout<<"\nEnter value to find\n";
   	cin>>search;
	f = 0;
   	l = n - 1;
   	m = (f+l)/2;
 
   	while (f <= l) {
      	if (a[m] < search)
         f = m + 1;    
      	else if (a[m] == search) {
         cout<<"\nfound at location \n"<<m+1;
         break;
      	}
      	else
         l = m - 1;
 
         m = (f + l)/2;
   	}
   	if (f > l)
      	cout<<"\nNot found! isn't present in the list \n"<<search;
	return 0;
}


/*
Output:
Enter the size of array: 8                                                                                                             
Enter the array elements: 345                                                                                                          
3                                                                                                                                      
56                                                                                                                                     
4                                                                                                                                      
2                                                                                                                                      
4                                                                                                                                      
2                                                                                                                                      
55                                                                                                                                     
                                                                                                                                       
Array after sorting: 2 2 3 4 4 55 56 345                                                                                               
Enter value to find                                                                                                                    
345                                                                                                                                    
                                                                                                                                       
found at location                                                                                                                      
8                 
*/

