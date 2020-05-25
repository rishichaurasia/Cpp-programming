#include <iostream>
using namespace std;

int preIdx = 0;

int getIndex(int arr[], int start, int end, int item) {
    if(start > end)
        return -1;
    if(arr[start] == item)
        return start;
    return getIndex(arr, start+1, end, item);
}

void printPostorder(int in[], int pre[], int inLow, int inHigh) {
    if(inLow > inHigh)
        return;
    int searchIdx = getIndex(in, inLow, inHigh, pre[preIdx]);
    preIdx++;
    printPostorder(in, pre, inLow, searchIdx-1);
    printPostorder(in, pre, searchIdx+1, inHigh);
    cout << in[searchIdx] << " ";
}

int main() {
	int in[] = {4, 2, 5, 1, 6, 3, 7};
	int pre[] = {1, 2, 4, 5, 3, 6, 7};
	int n = sizeof(in)/sizeof(in[0]);
	printPostorder(in, pre, 0, n-1);
	return 0;
}
