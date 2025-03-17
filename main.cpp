#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void customSwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void heapify(vector<T>& arr, int n, int i, bool ascending) {
    while (true) {
        int extreme = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && ((ascending && arr[left] > arr[extreme]) || (!ascending && arr[left] < arr[extreme])))
            extreme = left;

        if (right < n && ((ascending && arr[right] > arr[extreme]) || (!ascending && arr[right] < arr[extreme])))
            extreme = right;

        if (extreme != i) {
            customSwap(arr[i], arr[extreme]);
            i = extreme;
        } else {
            break;
        }
    }
}

template <typename T>
void heapSort(vector<T>& arr, bool ascending = true) {
    int n = 0;
    for (T& _ : arr) n++;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, ascending);

    for (int i = n - 1; i > 0; i--) {
        customSwap(arr[0], arr[i]);
        heapify(arr, i, 0, ascending);
    }
}

template <typename T>
void printArray(const vector<T>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    printArray(arr);

    heapSort(arr, true);
    cout << "Sorted array (Ascending Order): ";
    printArray(arr);

    heapSort(arr, false);
    cout << "Sorted array (Descending Order): ";
    printArray(arr);

    return 0;
}
