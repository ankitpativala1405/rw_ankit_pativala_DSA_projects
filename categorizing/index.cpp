#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[50], R[50]; 

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void linearSearch(int arr[], int n, int key) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index: " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element not found." << endl;
    }
}

void binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            cout << "Element found at index: " << mid << endl;
            found = true;
            break;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Element not found." << endl;
    }
}

void display(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[50], n, choice, key;

    cout << "Enter number of elements (max 50): ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Merge Sort" << endl;
        cout << "3. Linear Search" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Display Array" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            selectionSort(arr, n);
            cout << "Array sorted using Selection Sort." << endl;
            display(arr, n);
            break;

        case 2:
            mergeSort(arr, 0, n - 1);
            cout << "Array sorted using Merge Sort." << endl;
            display(arr, n);
            break;

        case 3:
            cout << "Enter element to search: ";
            cin >> key;
            linearSearch(arr, n, key);
            break;

        case 4:
            cout << "Enter element to search: ";
            cin >> key;
            binarySearch(arr, n, key);
            break;

        case 5:
            display(arr, n);
            break;

        case 6:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
