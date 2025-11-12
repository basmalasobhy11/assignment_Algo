#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int recBinarySearch(vector<int> arr, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return recBinarySearch(arr, left, mid - 1, target);
        }

        return recBinarySearch(arr, mid + 1, right, target);
    }
    return -1;
}

int binarySearch(vector<int> arr, int target) {
    int low = 0; int high = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int recSequentialSearch(vector<int> arr,int low,int target) {
    int high = arr.size();
    if (low == high) {
        return -1;
    }
    if (arr[low] == target) {
        return low;
    }
    return recSequentialSearch(arr, low + 1,target);
}

int sequentialSearch(vector<int> arr, int target) {
    for (int low = 0 ; low < arr.size() ; low++) {
        if (arr[low] == target) {
            return low;
        }
    }
    return -1;
}

int main() {

    cout << "Enter the size of the array: "; int size; cin >> size;

    cout << "Enter the elements in array: "; vector<int> arr;
    for (int i = 0; i < size; i++) {
        int temp; cin >> temp;
        arr.push_back(temp);
    }
    cout << "Enter the element you're looking for: "; int target; cin >> target;


    cout << "choose which searching algorithm you want: \n 1)Sequential Search \n 2)Recursive Sequential Search \n 3)Binary Search \n 4)Recursive Binary Search \n 5)exit\n";
    int choice; cin >> choice;
    int result;
    while (choice != 5) {
        switch (choice) {
            case 1:
                result = sequentialSearch(arr,target);
                if (result == -1) {
                    cout << "Element not found" << endl;
                }
                else {
                    cout <<"Element found at index (" << result << ") using Sequential Search";
                }
            break;
            case 2:
                result = recSequentialSearch(arr,0,target);
                if (result == -1) {
                    cout << "Element not found" << endl;
                }
                else {
                    cout <<"Element found at index (" << result << ") using Sequential Search";
                }
            break;
            case 3:
                sort(arr.begin(), arr.end());
                result = binarySearch(arr,target);
                if (result == -1) {
                    cout << "Element not found" << endl;
                }else {
                    cout <<"Element found at index (" << result << ") using Sequential Search";
                }
            break;
            case 4:
                sort(arr.begin(), arr.end());
                result = recBinarySearch(arr, 0, size - 1, target);
                if (result == -1) {
                    cout << "Element not found" << endl;
                }else {
                    cout <<"Element found at index (" << result << ") using Sequential Search";
                }
            break;
            default:
                cout << "Invalid Input";
            break;
        }
        cout << "\nchoose which searching algorithm you want: \n 1)Sequential Search \n 2)Recursive Sequential Search \n 3)Binary Search \n 4)Recursive Binary Search \n 5)exit\n";
        cin >> choice;
    }

    return 0;
}
