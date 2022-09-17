#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int size;

void MatrixChainOrder(int p[], vector<vector<int>> &mat1, vector<vector<int>> &mat2) { 
	int len = mat1.size();

	for (int i = 1; i < len; i++) {
		mat1[i][i] = 0;
	}

	for (int l = 2; l < len; l++) {
		for (int i = 1; i < len - l + 1; i++) {
			int j = i + l - 1;
			mat1[i][j] = INT_MAX; 

			for (int k = i; k <= j - 1; k++) {
				int q = mat1[i][k] + mat1[k + 1][j] + (p[i - 1] * p[k] * p[j]); 
				if (q < mat1[i][j]) {
					mat1[i][j] = q;
					mat2[i][j] = k;
				}
			}
		}
	}
}

void printOptimalParens(vector<vector<int>> mat2, int i, int j) {
	if (i == j) { cout << "A" << (i - 1); }
	else {
		cout << "(";
		printOptimalParens(mat2, i, mat2[i][j]); 
		printOptimalParens(mat2, mat2[i][j] + 1, j); 
		cout << ")";
	}
}

int main() {
	cin >> size;
	int val[size];

	for (int i = 0; i <= size; i++) {
		cin >> val[i]; 
	}

	vector<vector<int>> matrix1(size + 1, vector<int>(size + 1, 0)); 
	vector<vector<int>> matrix2(size + 1, vector<int>(size + 1, 0)); 

	MatrixChainOrder(val, matrix1, matrix2);
	cout << matrix1[1][size] << endl;

	printOptimalParens(matrix2, 1, size);
	cout << endl;

	return 0; 
}