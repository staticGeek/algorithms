// bubble sort algorithm
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// isAdaptive: true // i.e. time complexity O(n) for already sorted array
// by nature bubble sort is not adaptive but here it is made adaptive by using isSorted

// isStable: true // i.e. maintains same element order

#include <iostream>
#include <vector>
using namespace std;

// bubble sort function
void bubbleSort(vector<int> &arr)
{
    int size = arr.size();
    bool isSort = 0; // for checking if the array is already sorted
    for (int i = 0; i < size - 1; i++) // for number of passes
    {
        isSort = 1;
        for (int j = 0; j < size - 1 - i; j++) // for each pass
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSort = 0;
            }
        }
        if (isSort)
            return;
    }
}

int main()
{
    // making the i/o faster
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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

    // bubbleSorting the array
    bubbleSort(arr);

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