#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int aux_left[n1], aux_right[n2];

    for (int i = 0; i < n1; i++)
        aux_left[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        aux_right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (aux_left[i] <= aux_right[j]) {
            arr[k] = aux_left[i];
            i++;
        } else {
            arr[k] = aux_right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = aux_left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = aux_right[j];
        j++;
        k++;
    }
}

void sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        sort(arr, left, mid);
        sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void print_array(const int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int MAX_LEN = 100;
    int arr[MAX_LEN], len;

    cout << "What's the length of the array? Maximum length is " << MAX_LEN << endl;
    cin >> len;

    cout << "Enter the " << len << " elements: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    cout << "Unsorted array: ";
    print_array(arr, len);

    sort(arr, 0, len - 1);

    cout << "Sorted array: ";
    print_array(arr, len);

    return 0;
}

