#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(int n) {                             // bubble sort
    vector<int> bub(n);
    int tr = 0;
    int comp = 0;
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1; i++) {
            comp++;
            if (bub[i] > bub[i + 1]) {
                swap (bub[i], bub[i + 1]);
                tr++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << bub[i] << " ";
        }
    cout << endl << "Bubble sorted array" << endl << "Number of comparisons: " << comp << endl <<  "Number of transpositions: " << tr;
}

void insertion_sort (int n) {                          // insertion sort
    vector<int> ins(n);
    int tr = 0;
    int comp = 0;
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        int key = ins[i];
        comp++;
        while (j > 0 && ins[j] > key) {
            ins[j + 1] = ins[j];
            j--;
            tr++;
        }
        ins[j + 1] = key;
    }
    for (int i = 0; i < n; i++) {
        cout << ins[i] << " ";
    }
    cout << endl << "Insertion sorted array" << endl << "Number of comparisons: " << comp << endl << "Number of transpositions: " << tr;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand();
        cout << a[i] << " ";
    }
    cout << endl << "Original array" << endl << "Choose method:" << endl << "1 - bubble" << endl << "2 - insertion" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) bubble_sort (n);
    if (choice == 2) insertion_sort (n);
    return 0;
}