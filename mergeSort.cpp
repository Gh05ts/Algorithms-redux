#include <vector>
#include <iostream>

void merge(std::vector<int> &input, int start, int end) {
    int firstHalfIndex = start;
    int firstHalfBoundary = start + (end-start)/2 + 1;
    int secondHalfIndex = firstHalfBoundary;
    int secondHalfBoundary = end + 1;

    // used for storing merged result 
    std::vector<int> temp = std::vector<int>(end - start + 1);
    int tempIndex = 0;

    // merging the vectors
    while(firstHalfIndex < firstHalfBoundary && secondHalfIndex < secondHalfBoundary) {
        if(input[firstHalfIndex] <= input[secondHalfIndex]) {
            temp[tempIndex++] = input[firstHalfIndex++]; 
        } else {
            temp[tempIndex++] = input[secondHalfIndex++];
        }
    }

    // deadling with leftovers
    while(firstHalfIndex<firstHalfBoundary) {
        temp[tempIndex++] = input[firstHalfIndex++];
    }
    while(secondHalfIndex<secondHalfBoundary) {
        temp[tempIndex++] = input[secondHalfIndex++];
    }

    // transfer output from temp to original vector 
    int writerIndex = start;
    tempIndex = 0;
    while(writerIndex < secondHalfBoundary) {
        input[writerIndex++] = temp[tempIndex++];
    }
}

void mergeSort(std::vector<int> &input, int start, int end) {
    if(start < end) {
        mergeSort(input, start, start + ((end-start)/2));
        mergeSort(input, start + ((end-start)/2) + 1, end);
        merge(input, start, end);
    }
}

int main() {
    std::vector<int> input = {1234, 1, -1, 1, 0, 0, 93492, 23};
    mergeSort(input, 0, input.size() - 1);
    for(const auto &i: input) {
        std::cout << i << ", ";
    }
    return 0;
}