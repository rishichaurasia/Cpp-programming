#include <iostream>
using namespace std;

int getIndex(int arr[], int start, int end, int item) {
    if(start > end)
        return -1;
    if(arr[start] == item)
        return start;
    return getIndex(arr, start+1, end, item);
}

void printPreorder(int in[], int post[], int inLow, int inHigh, int postIdx) {
    if(inLow > inHigh)
        return;
    int searchIdx = getIndex(in, inLow, inHigh, post[postIdx]);
    cout << in[searchIdx] << " ";
    printPreorder(in, post, inLow, searchIdx-1, postIdx- (inHigh - searchIdx) - 1);
    printPreorder(in, post, searchIdx+1, inHigh, postIdx-1);
}

int main() {
	int in[] = {4, 2, 5, 1, 6, 3, 7};
	int post[] = {4, 5, 2, 6, 7, 3, 1};
	int n = sizeof(in)/sizeof(in[0]);
	cout << "Postorder : ";
	printPreorder(in, post, 0, n-1, n-1);
	return 0;
}
