#include <iostream>
#include <vector>

int mergeAndCount(std::vector<int> &input, int start, int end) {
    int firstHalfIndex = start;
    int firstHalfBoundary = start + (end - start)/2 + 1;
    int secondHalfIndex = firstHalfBoundary;
    int secondHalfBoundary = end + 1;

    int tempIndex = 0;
    std::vector<int> temp = std::vector<int>(end - start + 1);

    int inversions = 0;
    while(firstHalfIndex < firstHalfBoundary && secondHalfIndex < secondHalfBoundary) {
        if(input[firstHalfIndex] <= input[secondHalfIndex]) {
            temp[tempIndex++] = input[firstHalfIndex++];
        } else {
            temp[tempIndex++] = input[secondHalfIndex++];
            inversions += firstHalfBoundary - firstHalfIndex;

        }
    }
    while(firstHalfIndex < firstHalfBoundary) {
        temp[tempIndex++] = input[firstHalfIndex++];
    }
    while(secondHalfIndex < secondHalfBoundary) {
        temp[tempIndex++] = input[secondHalfIndex++];
    }

    tempIndex = 0;
    int writerIndex = start;
    while(writerIndex < secondHalfBoundary) {
        input[writerIndex++] = temp[tempIndex++];
    }
    return inversions;
}

int sortAndCount(std::vector<int> &input, int start, int end) {
    if (start < end) {
        int c1 = sortAndCount(input, start, start + ((end - start)/2));
        int c2 = sortAndCount(input, start + ((end - start)/2) + 1, end);
        int c3 = mergeAndCount(input, start, end);
        return c1 + c2 + c3;
    }
    return 0;
}

int countInversions(std::vector<int> &input) {
    return sortAndCount(input, 0, input.size() - 1);
}

int main() {
    // std::vector<int> input = {1, 3, 5, 2, 4, 6};
    // std::vector<int> input = {1, 3, 2, 5, 4, 6};
    std::vector<int> input = {1, 3, 6, 2, 4, 5};
    std::cout << countInversions(input) << std::endl;
    return 0;
}