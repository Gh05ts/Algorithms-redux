#include <iostream>
#include <vector>
#include <random>

using namespace std;

int randomIntInRange(int left, int right) {
    random_device rd;
    default_random_engine gen(rd());
    return uniform_int_distribution<int>{left, right}(gen);
}

// this implementation while correct can't handle the case where all elements are same and it goes to n*n algorithm
int partition(vector<int> &input, int left, int right) {
    int pivotIdx = randomIntInRange(left, right);
    swap(input[pivotIdx], input[right]);
    int pivotElement = input[right];
    int countSmaller = left;
    for(int i = left; i < right; i++) {
        if(input[i] <= pivotElement) {
            swap(input[countSmaller], input[i]);
            countSmaller++;
        }
    }
    swap(input[right], input[countSmaller]);
    return countSmaller;
}

void quickSort(vector<int> &input, int left, int right) {
    if(left < right) {
        int pivotIdx = partition(input, left, right);
        quickSort(input, left, pivotIdx - 1);
        quickSort(input, pivotIdx + 1, right);
    }
}

void quickSort(vector<int> &input) {
    return quickSort(input, 0, input.size() - 1);
}

int main() {
    vector<int> input = {12, 12, 123123, -12, 23, 0};
    quickSort(input);
    for(const auto &i: input) {
        cout << i << ", ";
    }
    return 0;
}