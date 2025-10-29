#include <cmath>
#include <iostream>
using namespace std;

//index      0, 1, 2, 3,4,5,6,7,8,9
//maxHeapify 16,4,10,14,7,9,3,2,8,1

//index 0,1,2,3, 4,5,6, 7, 8,9
//build 4,1,3,2,16,9,10,14,8,7

//output 16,14,10,8,7,9,3,2,4,1


class heapPriorityQueue {
    public:
    heapPriorityQueue() = default;

    void maxHeapify(int A[], int index, int size) {
        int left = 2 * index + 1;  // 0-based index
        int right = 2 * index + 2; // 0-based index
        int max = index;

        if (left < size && A[left] > A[index]) {
            max = left;
        }
        if (right < size && A[right] > A[max]) {
            max = right;
        }
        if (max != index) {
            swap(A[index], A[max]);
            maxHeapify(A, max, size);
        }
    }

    void buildMaxHeap(int A[], int size) {
        for (int index = size/2 - 1; index >= 0; index--) {
            maxHeapify(A, index, size);
        }
    }

    void heapSort(int A[], int size) {
         buildMaxHeap(A, size);
         for (int i = size-1; i >= 1; i--) {
             swap(A[0], A[i]);
             maxHeapify(A, 0, i);
         }
     }

    static int heapMaximum(int A[]) {
        return A[0];
    }

    int extractHeapMax(int A[],int& size) {
        int max = A[0];
        A[0] = A[size-1];
        maxHeapify(A, 0, --size);
        return max;
    }

    static void increaseKey(int* A,int index, int key) {
        A[index] = key;
        while (index > 0){
            //18,8,14,4,7,10,3,2,1,
            int parentIndex = (index - 1) / 2;
            if (A[parentIndex] >= A[index]){ break;}
            swap(A[index], A[parentIndex]);
            index = parentIndex;
        }
    }

    static void insertKey(int A[], int key, int& size) {
        A[++size] = 0;
        increaseKey(A, size - 1, key);
    }

};


// int main() {
//     int A[] = {16,4,10,14,7,9,3,2,8,1};
//     int B[] = {4,1,3,2,16,9,10,14,8,7};
//     int C[] = {7,4,3,1,2};
//     static int size = sizeof(A) / sizeof(int);
//
//     heapPriorityQueue heap;
//
//
//     heap.maxHeapify(A, 1, size); // 0-based index
//
//     heap.buildMaxHeap(B, size);
//
//     heap.heapSort(C, 5);
//
//     cout << "After maxHeapify: ";
//     for (int i = 0; i < size; i++) {
//         cout << A[i] << " ";
//     }
//     cout << endl;
//
//     cout << "After buildMaxHeap: ";
//     for (int i = 0; i < size; i++) {
//         cout << B[i] << " ";
//     }
//     cout << endl;
//
//     cout << "After heapSort: ";
//     for (int i = 0; i < 5; i++) {
//         cout << C[i] << " ";
//     }
//     cout << endl;
//
//
//     cout << endl;
//     cout << "max: "<< heap.extractHeapMax(A,size) << endl;
//
//     cout << "After removing max" << endl;
//     for (int i = 0; i < size; i++) {
//         cout << A[i] << ",";
//     }
//     cout << endl;
//
//     heap.increaseKey(A, 5, 18);
//     cout << "After increaseKey" << endl;
//     for (int i = 0; i < size; i++) {
//         cout << A[i] << ",";
//     }
//     cout << endl;
//
//     heap.insertKey(A,9, size);
//     cout << "After insertKey" << endl;
//     for (int i = 0; i < size; i++) {
//         cout << A[i] << ",";
//     }
//
//     return 0;
// }