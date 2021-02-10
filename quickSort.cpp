// quick sort algorithm taking the first element as pivot
// Worst Case Complexity: O(n^2)
// Best Case Complexity: O(nlog n)
// Space Complexity: O(1)
// isStable: false

#include <iostream>
#include <vector>
using namespace std;

// partitioning function
int partition(vector<int> &arr, int low, int high)
{
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= arr[low])
        {
            i++;
        }
        while (arr[j] > arr[low])
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

// quick sort function
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
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

    int low = 0;
    int high = arr.size() - 1;

    // calling quick sort function
    quickSort(arr, low, high);

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