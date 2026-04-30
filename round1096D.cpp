#include <bits/stdc++.h>
using namespace std;

void solveTestCase() {
    int arraySize;
    cin >> arraySize;

    int totalLength = 2 * arraySize;
    vector<int> inputArray(totalLength);
    for (int index = 0; index < totalLength; ++index) cin >> inputArray[index];

    vector<int> oddPalindromeRadius(totalLength);
    int leftBoundary = 0, rightBoundary = -1;

    for (int centerIndex = 0; centerIndex < totalLength; ++centerIndex) {
        int expansionRadius = (centerIndex > rightBoundary) ? 1 : min(oddPalindromeRadius[leftBoundary + rightBoundary - centerIndex], rightBoundary - centerIndex + 1);

        while (centerIndex - expansionRadius >= 0 &&
               centerIndex + expansionRadius < totalLength &&
               inputArray[centerIndex - expansionRadius] == inputArray[centerIndex + expansionRadius]) {
            expansionRadius++;
        }

        oddPalindromeRadius[centerIndex] = expansionRadius;

        if (centerIndex + expansionRadius - 1 > rightBoundary) {
            leftBoundary = centerIndex - expansionRadius + 1;
            rightBoundary = centerIndex + expansionRadius - 1;
        }
    }

    vector<int> evenPalindromeRadius(totalLength);
    leftBoundary = 0, rightBoundary = -1;

    for (int centerIndex = 0; centerIndex < totalLength; ++centerIndex) {
        int expansionRadius = (centerIndex > rightBoundary) ? 0 : min(evenPalindromeRadius[leftBoundary + rightBoundary - centerIndex + 1], rightBoundary - centerIndex + 1);

        while (centerIndex - expansionRadius - 1 >= 0 &&
               centerIndex + expansionRadius < totalLength &&
               inputArray[centerIndex - expansionRadius - 1] == inputArray[centerIndex + expansionRadius]) {
            expansionRadius++;
        }

        evenPalindromeRadius[centerIndex] = expansionRadius;

        if (centerIndex + expansionRadius - 1 > rightBoundary) {
            leftBoundary = centerIndex - expansionRadius;
            rightBoundary = centerIndex + expansionRadius - 1;
        }
    }

    vector<vector<int>> palindromeQueries(totalLength);

    for (int centerIndex = 0; centerIndex < totalLength; ++centerIndex) {
        int leftIndex = centerIndex - oddPalindromeRadius[centerIndex] + 1;
        int rightIndex = centerIndex + oddPalindromeRadius[centerIndex] - 1;
        palindromeQueries[leftIndex].push_back(rightIndex);
    }

    for (int centerIndex = 0; centerIndex < totalLength; ++centerIndex) {
        if (evenPalindromeRadius[centerIndex] > 0) {
            int leftIndex = centerIndex - evenPalindromeRadius[centerIndex];
            int rightIndex = centerIndex + evenPalindromeRadius[centerIndex] - 1;
            palindromeQueries[leftIndex].push_back(rightIndex);
        }
    }

    const int largeValue = totalLength;
    vector<int> segmentTree(4 * arraySize, largeValue);

    function<void(int,int,int,int,int)> updateSegmentTree =
    [&](int nodeIndex, int segmentLeft, int segmentRight, int position, int value) {
        if (segmentLeft == segmentRight) {
            segmentTree[nodeIndex] = value;
            return;
        }
        int middle = (segmentLeft + segmentRight) / 2;
        if (position <= middle)
            updateSegmentTree(nodeIndex * 2, segmentLeft, middle, position, value);
        else
            updateSegmentTree(nodeIndex * 2 + 1, middle + 1, segmentRight, position, value);

        segmentTree[nodeIndex] = min(segmentTree[nodeIndex * 2], segmentTree[nodeIndex * 2 + 1]);
    };

    function<int(int,int,int,int)> querySegmentTree =
    [&](int nodeIndex, int segmentLeft, int segmentRight, int rightLimit) -> int {
        if (segmentTree[nodeIndex] > rightLimit) return segmentLeft;
        if (segmentLeft == segmentRight) return -1;

        int middle = (segmentLeft + segmentRight) / 2;
        int leftResult = querySegmentTree(nodeIndex * 2, segmentLeft, middle, rightLimit);
        if (leftResult != -1) return leftResult;
        return querySegmentTree(nodeIndex * 2 + 1, middle + 1, segmentRight, rightLimit);
    };

    int maximumMex = 0;

    for (int leftIndex = totalLength - 1; leftIndex >= 0; --leftIndex) {
        updateSegmentTree(1, 0, arraySize - 1, inputArray[leftIndex], leftIndex);

        for (int rightIndex : palindromeQueries[leftIndex]) {
            int currentMex = querySegmentTree(1, 0, arraySize - 1, rightIndex);
            if (currentMex == -1) currentMex = arraySize;
            maximumMex = max(maximumMex, currentMex);
        }
    }

    cout << maximumMex << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCaseCount;
    cin >> testCaseCount;

    while (testCaseCount--) {
        solveTestCase();
    }

    return 0;
}