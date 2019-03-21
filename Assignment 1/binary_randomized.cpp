#include <iostream>
#include <ctime>
using namespace std;
// To generate random number
// between x and y ie.. [x, y]
int getRandom(int x, int y)
{
srand(time(NULL));
return (x + rand() % (y-x+1));
}
// A recursive randomized binary search function.
// It returns location of x in
// given array arr[l..r] is present, otherwise -1
int randomizedBinarySearch(int arr[], int l,
int r, int x)
{
if (r >= l)
{
// Here we have defined middle as
// random index between l and r ie.. [l, r]
int mid = getRandom(l, r);
// If the element is present at the
// middle itself
if (arr[mid] == x)
return mid;
// If element is smaller than mid, then
// it can only be present in left subarray
if (arr[mid] > x)
return randomizedBinarySearch(arr, l,
mid-1, x);
// Else the element can only be present
// in right subarray
return randomizedBinarySearch(arr, mid+1,
r, x);
}
// We reach here when element is not present
// in array
return -1;
}
// Driver code
int main()
{
int arr[50];
int n,i;
int x,v;
cout<<"\nEnter the size of the array ";
cin>>n;
cout<<"\nEnter the elements into the array \n";
for(i=0;i<n;i++){

cout<<"Element "<<i+1<<" ";
cin>>arr[i];
}
cout<<"\nEnter the element that you want to search ";
cin>>x;
v = x;
int result = randomizedBinarySearch(arr, 0, n, v);
(result == -1)? cout<<"Element is not present in array"
: cout<<"Element is present at index "<<result + 1;
return 0;
}

/*
Output:
Enter the size of the array 5

Enter the elements into the array
Element 1 33
Element 2 22
Element 3 3
Element 4 2
Element 5 678
Enter the element that you want to search 3
Element is present at index 3
*/
