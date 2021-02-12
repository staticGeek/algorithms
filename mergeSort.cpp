// merge sort algorithm
// Time Complexity: O(nlog n)
// Space Complexity: O(n)
// isStable: true

#include <iostream>
#include <vector>
using namespace std;

// merging function
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> arr2(high + 1);
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            arr2[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        arr2[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        arr2[k] = arr[j];
        j++;
        k++;
    }
    for (int c = low; c <= high; c++)
    {
        arr[c] = arr2[c];
    }
}

// merge sort function
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    // divide and conquer
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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

    int low = 0;
    int high = arr.size() - 1;

    // calling merge sort function
    mergeSort(arr, low, high);

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