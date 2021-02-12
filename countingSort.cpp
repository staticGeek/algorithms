// counting sort algorithm
// Time Complexity: O(n)
// Space Complexity: O(n)
// isStable: true

#include <iostream>
#include <vector>
using namespace std;

// function which returns the max element in an array
int maximum(vector<int> &arr, int size)
{
    int max = INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

// counting sort function // takes the array and its size as argument
void countingSort(vector<int> &arr, int size)
{
    // finding the max value in the array
    int max = maximum(arr, size);

    // creating count array and initialize with 0
    vector<int> count(max + 1);

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    int i, j;
    i = j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
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

    // calling counting sort function
    countingSort(arr, k);

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