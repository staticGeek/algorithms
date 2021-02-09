// insertion sort algorithm
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// isAdaptive: true // i.e. time complexity O(n) for already sorted array
// isStable: true // i.e. maintains same element order

#include <iostream>
#include <vector>
using namespace std;

// insertion sort function
void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++) // for each element starting from index 1
    {
        // inserting the element in the right position
        int element = arr[i];
        int j = i - 1;
        while(arr[j]>element && j>=0) 
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = element;
    }
}

int main()
{
    // making the i/o faster
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> arr;
    int n;

    cout << "How many numbers do you wanna input? ";
    cin >> n;
    int k = n;

    while (n--) // taking values of the array
    {
        int element;
        cout << "\nEnter element of the array: ";
        cin >> element;
        arr.push_back(element);
    }

    // calling insertion sort function
    insertionSort(arr);

    // printing the array after sorting
    cout << "\nThe sorted array is : ";

    for (auto iter : arr)
    {
        cout << iter;
        if (iter != arr[k - 1])
            cout << ", ";
    }

    return 0;
}