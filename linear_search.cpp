// simple linear search algorithm
// time complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

// linear search function
vector<int> linear_search(vector<int> arr, int element)
{
    int size = arr.size();
    vector<int> index;
    for (int i = 0; i < size; i++)
    {
        if (element == arr[i])
            index.push_back(i + 1);
    }
    return index; // returns vector of zero size if the desired element is not found
}

// Alternative function
// vector<int> linear_search(vector<int> arr, int element)
// {
//     int size = arr.size();
//     vector<int> index;
//     for (int i = 0; i < size; i++)
//     {
//         if (element == arr[i])
//         {
//             index.push_back(i + 1);
//         }
//         if (element == arr[size - 1])
//         {
//             index.push_back(size);
//         }
//         size--;
//     }
//     return index; // returns vector of zero size if the desired element is not found
// }

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

    vector<int> index;

    index = linear_search(arr, element); // performing the linear search to get the index number of the given element


    // printing the index

    if(index.size()==0)
    {
        cout<<"\nThe element is not present in the array!!";
        return 0;
    }

    cout << "\nThe position of " << element << " is at ";

    for (int i = 0; i < index.size(); i++)
    {
        cout << index[i];
        if(i!=index.size()-1)
        {
            cout<<", ";
        }
    }

    return 0;
}