// binary search algorithm
// Time Complexity: O(log n) 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// binary search function
bool binarySearch(vector<int> arr, int element)
{    
    int left = 0;
    int right = arr.size()-1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if (element == left || element == right) return true;

        if (element > arr[mid]) left = mid + 1;
        else if (element < arr[mid]) right = mid - 1;
        else return true;
    }
    return false;
}

int main()
{
    // making the i/o faster
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr;
    int size, element;

    cout << "Enter size of the array: ";
    cin >> size;

    while (size--) // taking values of the array
    {
        int input;
        cout << "\nEnter element: ";
        cin >> input;
        arr.push_back(input);
    }

    cout << "\n\nEnter element to search in the array: "; // target element
    cin >> element;
    
    // Time Complexity: O(nlog n) 
    sort(arr.begin(), arr.end()); // Sorting the given array in order to perform binarySearch on it

    bool isPresent;

    isPresent = binarySearch(arr, element); // true when the element is present in the vector and false otherwise

    if(isPresent) cout << "The element is present in the input!!";
    else cout << "The element is not present in the input!!";

    return 0;
}