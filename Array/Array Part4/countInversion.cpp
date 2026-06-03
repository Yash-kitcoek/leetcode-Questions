#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    long long cnt = 0;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);

            cnt += (mid - left + 1);

            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

long long mergeSort(vector<int>& arr, int low, int high)
{
    if(low >= high)
        return 0;

    long long cnt = 0;

    int mid = low + (high - low) / 2;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);

    cnt += merge(arr, low, mid, high);

    return cnt;
}

long long countInversions(vector<int> arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {2, 1, 3, 1, 2};

    cout << "Inversions = " << countInversions(arr) << endl;

    return 0;
}