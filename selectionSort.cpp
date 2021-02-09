// selection sort algorithm
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// isAdaptive: false
// isStable: false

#include <iostream>
#include <vector>
using namespace std;

// selection sort function
void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int temp = i, count = 0;
        for (int j = i + 1; j < arr.size(); j++) // selection of the least element
        {
            if (arr[temp] > arr[j])
            {
                temp = j;
                count = 1;
            }
        }
        if (count)
        {
            int k = arr[temp];
            arr[temp] = arr[i];
            arr[i] = k;
        }
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

    // calling selection sort function
    selectionSort(arr);

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