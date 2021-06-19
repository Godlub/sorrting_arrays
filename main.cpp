#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> bub) {                             // bubble sort
    int tr = 0;
    int comp = 0;
    for (int j = 0; j < bub.size() - 1; j++) {
        for (int i = 0; i < bub.size() - 1; i++) {
            comp++;
            if (bub[i] > bub[i + 1]) {
                swap (bub[i], bub[i + 1]);
                tr++;
            }
        }
    }
    for (int i : bub) {
        cout << i << " ";
        }
    cout << endl << "Bubble sorted array" << endl << "Number of comparisons: " << comp << endl <<  "Number of transpositions: " << tr;
}

void insertion_sort (vector<int> ins) {                          // insertion sort
    int tr = 0;
    int comp = 0;
    for (int i = 0; i < ins.size(); i++) {
        int j = i - 1;
        int key = ins[i];
        comp++;
        while (j > 0 && ins[j] > key) {
            comp++;
            ins[j + 1] = ins[j];
            tr++;
            j--;
        }
        ins[j + 1] = key;
    }
    for (int in : ins) {
        cout << in << " ";
    }
    cout << endl << "Insertion sorted array" << endl << "Number of comparisons: " << comp << endl << "Number of transpositions: " << tr;
}

int main() {
    cout << "Enter the size of the array:" << endl;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int & i : a) {
        i = rand();
        cout << i << " ";
    }
    cout << endl << "Original array" << endl << "Choose method:" << endl << "1 - bubble sort" << endl << "2 - insertion sort" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) bubble_sort (a);
    if (choice == 2) insertion_sort (a);
    return 0;
}