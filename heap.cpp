#include <iostream>
using namespace std;
class MaxHeap {
private:
    int* arr;
    int capacity;
    int size;

    void heapifyUp(int i) {
        while (i > 0) {
            int parenti = (i - 1) / 2;
            if (arr[i] > arr[parenti]) {
                swap(arr[i], arr[parenti]);
                i = parenti;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        while (i < size) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right < size && arr[right] > arr[largest]) {
                largest = right;
            }
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }
};
public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }
    void insert(int key) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        arr[size] = key;
        size++;
        heapifyUp(size - 1);
    }

    int extractMax() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int maxVal = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return maxVal;
    }
    int extractMin() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int mini = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[mini]) {
                mini = i;
            }
        }
        int minVal = arr[mini];
        arr[mini] = arr[size - 1];
        size--;
        heapifyDown(mini);
        return minVal;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
int main() {
    MaxHeap heap(10);
    heap.insert(3);
    heap.insert(1);
    heap.insert(5);
    heap.insert(2);
    heap.insert(4);

    cout << "Heap elements: ";
    heap.display();

    cout << "Extracted Max: " << heap.extractMax() << endl;
    cout << "Heap after extracting max: ";
    heap.display();

    cout << "Extracted Min: " << heap.extractMin() << endl;
    cout << "Heap after extracting min: ";
    heap.display();

    return 0;
}
