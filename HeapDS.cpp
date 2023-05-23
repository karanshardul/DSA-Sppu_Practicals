#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to heapify the array
void heapify(int arr[], int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to build a max heap from the array
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to find the maximum and minimum marks using heap data structure
void findMinMaxMarks(int arr[], int n) {
    // Build a max heap
    buildMaxHeap(arr, n);

    // Maximum mark is at the root of the max heap
    int maxMark = arr[0];

    // Swap the root with the last element
    swap(arr[0], arr[n - 1]);

    // Rebuild the max heap with the remaining elements
    heapify(arr, n - 1, 0);

    // Minimum mark is at the root of the max heap (after the swap)
    int minMark = arr[0];

    cout << "Maximum mark: " << maxMark << endl;
    cout << "Minimum mark: " << minMark << endl;
}

int main() {
    int arr[] = { 92, 78, 85, 91, 88 };
    int n = sizeof(arr) / sizeof(arr[0]);

    findMinMaxMarks(arr, n);

    return 0;
}
