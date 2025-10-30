#include <iostream>
#include <string>
using namespace std;

// -------------------- MaxHeap --------------------
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
            } else break;
        }
    }

    void heapifyDown(int i) {
        while (i < size) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && arr[left] > arr[largest]) largest = left;
            if (right < size && arr[right] > arr[largest]) largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else break;
        }
    }

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
        for (int i = 1; i < size; i++)
            if (arr[i] < arr[mini]) mini = i;

        int minVal = arr[mini];
        arr[mini] = arr[size - 1];
        size--;
        heapifyDown(mini);
        return minVal;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class PriorityQueue {
private:
    MaxHeap heap;
    string* value;
    int* priorities;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) : heap(cap) {
        capacity = cap;
        size = 0;
        value = new string[capacity];
        priorities = new int[capacity];
    }

    void enqueue(string element, int priority) {
        if (size == capacity) {
            cout << "Priority Queue is full!" << endl;
            return;
        }
        value[size] = element;
        priorities[size] = priority;
        heap.insert(priority);
        size++;
    }

    string dequeue() {
        if (heap.isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return "";
        }

        int highestPriority = heap.extractMax();
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (priorities[i] == highestPriority) {
                index = i;
                break;
            }
        }

        if (index == -1) return "";
        string element = value[index];

        for (int i = index; i < size - 1; i++) {
            value[i] = value[i + 1];
            priorities[i] = priorities[i + 1];
        }
        size--;

        return element;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << "(" << value[i] << ", " << priorities[i] << ") ";
        cout << endl;
    }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main() {
    int mainChoice;
    do {
        cout << "\n==== MAIN MENU ====\n";
        cout << "1. Max Heap\n";
        cout << "2. Priority Queue\n";
        cout << "3. Heap Sort\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            MaxHeap heap(10);
            int option;
            do {
                cout << "\n--- Max Heap Menu ---\n";
                cout << "1. Insert\n2. Extract Max\n3. Extract Min\n4. Display\n5. Exit\n";
                cout << "Enter option: ";
                cin >> option;

                if (option == 1) {
                    int val;
                    cout << "Enter value: ";
                    cin >> val;
                    heap.insert(val);
                } else if (option == 2) {
                    cout << "Extracted Max: " << heap.extractMax() << endl;
                } else if (option == 3) {
                    cout << "Extracted Min: " << heap.extractMin() << endl;
                } else if (option == 4) {
                    cout << "Heap elements: ";
                    heap.display();
                }
            } while (option != 5);
        }

        else if (mainChoice == 2) {
            PriorityQueue pq(10);
            int option;
            do {
                cout << "\n--- Priority Queue Menu ---\n";
                cout << "1. Enqueue (insert)\n2. Dequeue (extract highest priority)\n3. Display\n4. Exit\n";
                cout << "Enter option: ";
                cin >> option;

                if (option == 1) {
                    string name;
                    int priority;
                    cout << "Enter element name: ";
                    cin >> name;
                    cout << "Enter priority: ";
                    cin >> priority;
                    pq.enqueue(name, priority);
                } else if (option == 2) {
                    cout << "Dequeued element: " << pq.dequeue() << endl;
                } else if (option == 3) {
                    cout << "Priority Queue elements: ";
                    pq.display();
                }
            } while (option != 4);
        }

        else if (mainChoice == 3) {
            int n;
            cout << "\nEnter number of elements: ";
            cin >> n;
            int* arr = new int[n];
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];

            heapSort(arr, n);

            cout << "Sorted array (ascending): ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;

            delete[] arr;
        }

        else if (mainChoice == 4) {
            cout << "Exiting program..." << endl;
        }

        else {
            cout << "Invalid choice!" << endl;
        }

    } while (mainChoice != 4);

    return 0;
}
