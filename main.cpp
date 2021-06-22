#include <iostream>
#include <vector>
#include <random>

using namespace std;

void bubble_sort(vector<int> bub) {
    int tr = 0;
    int comp = 0;
    for (int j = 0; j < bub.size() - 1; j++) {
        for (int i = 0; i < bub.size() - 1; i++) {
            comp++;
            if (bub[i] > bub[i + 1]) {
                swap(bub[i], bub[i + 1]);
                tr++;
            }
        }
    }
    for (int i : bub) {
        cout << i << " ";
    }
    cout << endl << "Bubble sorted array" << endl << "Number of comparisons: " << comp << endl
         << "Number of transpositions: " << tr;
}

vector<int> insertion_sort(vector<int> ins) {
    int comp = 0;
    for (int i = 1; i < ins.size(); i++) {
        int j = i - 1;
        int key = ins[i];
        comp++;
        while (j >= 0 && ins[j] > key) {
            comp++;
            ins[j + 1] = ins[j];
            j--;
        }
        ins[j + 1] = key;
    }
    for (int in : ins) {
        cout << in << " ";
    }
    cout << "\nInsertion sorted array" << "\nNumber of comparisons: " << comp << endl;
    return ins;
}

int main() {
    cout << "Enter the size of the array:" << endl;
    int n, move_counter = 0;
    cin >> n;
    vector<int> a(n);
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 10000);
    for (int i = 0; i < n; i++) {
        a[i] = dist(mt);
        cout << a[i] << " ";
    }
    cout << endl << "Original array" << endl << "Choose method:" << endl << "1 - bubble sort" << endl
         << "2 - insertion sort" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) bubble_sort(a);
    if (choice == 2) {
        auto sorted_array = insertion_sort(a);
        for (int i = 0; i < n; i++) {
            if (a[i] != sorted_array[i]) {
                move_counter++;
            }
        }
        cout << "Number of transpositions: " << move_counter;
    }
    return 0;
}
