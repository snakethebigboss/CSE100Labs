#include <iostream>
#include <vector>

using namespace std;

int size;
int rodSize;

int cutRod(int values[], int A[]) {
	int val[size + 1];
	int lastRod[size + 1];
	val[0] = 0;
	int i, j;

	for (i = 1; i <= size; i++) {
		int ideal = -1;
		int max = -10000000;
		for (j = 0; j < i; j++) {
			if (max < values[j] + val[i - j - 1]) {
				ideal = j;
				max = values[j] + val[i - j - 1];
			}
		}
		val[i] = max;
		lastRod[i] = ideal + 1;
	}
	i = size;
	j = 0;
	while (i > 0) {
		A[j++] = lastRod[i];
		i -= lastRod[i];
	}
	rodSize = j;
	return val[size];
}

int main() {
    cin >> size;
    int values[size];

    for (int i = 0; i < size; i++) {
        cin >> values[i];
    }

    int A[size + 1];

    cout << cutRod(values, A) << "\n";
    cout << A[0];

    for (int i = 1; i < rodSize; i++) {
        cout << " " << A[i];
    }
    cout << " -1\n";
    return 0;
}