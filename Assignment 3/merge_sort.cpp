#include<iostream>
using namespace std;


int merge(int arr[],int low,int mid,int high){
	int b[100],i,j,k;
	i = low;
	j = mid + 1;
	k = low;	

	while((i<=mid)&&(j<=high)){
		if(arr[i]<arr[j]){
			b[k] = arr[i];			
			k++;
			i++;
		}
		else{
			b[k] = arr[j];
			k++;
			j++;
		}
	}

	if(i>mid){
		while(j<=high){
			b[k] = arr[j];
			k++;
			j++;		
		}	
	}
	else if(j>high){
		while(i<=mid){
			b[k] = arr[i];
			k++;
			i++;		
		}	
	}
	
	while(low<=high){
		arr[low] = b[low];
		low++;		
		}	
	
}


int mergesort(int arr[],int low,int high){
int mid;
	if(low<high){
		mid = (low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}



int main()
{
	int n, i, j, count;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int a[n],freq[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>a[i];
	}
 
	mergesort(a, 0, n-1);
 

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<" "<<a[i];
        
    for(i=0; i<n; i++)
    {
        count = 1;
        for(j=i+1; j<n; j++)
        {
            if(a[i] == a[j])
            {
                count++;
                freq[j] = 0;
            }
        }
 
        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }
    
    cout<<"\nUnique elements in the array are: ";
    for(i=0; i<n; i++)
    {
        if(freq[i] == 1)
        {
            cout<<" "<<a[i];
        }
    }
	return 0;
}
