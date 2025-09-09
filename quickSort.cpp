#include <iostream>
#include <vector>
#include <random>

using namespace std;

int randomIntInRange(int left, int right) {
    random_device rd;
    default_random_engine gen(rd());
    return uniform_int_distribution<int>{left, right}(gen);
}

pair<int, int> partition(vector<int> &input, int left, int right) {
    int pivotIdx = randomIntInRange(left, right);
    int pivotElement = input[pivotIdx];
    int smallerIndex = left;
    int mid = left;
    int biggerIndex = right;
    while(mid <= biggerIndex) {
        if(input[mid] < pivotElement) {
            swap(input[smallerIndex++], input[mid++]);
        } else if (input[mid] == pivotElement) {
            mid++;
        } else {
            swap(input[mid], input[biggerIndex--]);
        }
    }
    return pair{smallerIndex, biggerIndex};
}

void quickSort(vector<int> &input, int left, int right) {
    if(left < right) {
        pair<int, int> pivotIndices = partition(input, left, right);
        quickSort(input, left, pivotIndices.first - 1);
        quickSort(input, pivotIndices.second + 1, right);
    }
}

void quickSort(vector<int> &input) {
    return quickSort(input, 0, input.size() - 1);
}

int main() {
    vector<int> input = {12, 12, 12, 12, 12, 123123, -12, 23, 0};
    // {5,1,1,2,0,0};
    quickSort(input);
    for(const auto &i: input) {
        cout << i << ", ";
    }
    return 0;
}