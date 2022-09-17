#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
string a = "";
string b = "";
string c = "";
string d = "";
string e = "";
string f = "";

struct Node{

	char name;
	int freq;
	Node* left;
	Node* right;

	Node(char name, int freq){

		this->name = name;
		this->freq = freq;
		left = NULL;
		right = NULL;

	}

	~Node(){

	}

};

struct compare{

	bool operator()(Node* l, Node* r){
	
		return(l->freq > r->freq);

	}

};

void print(struct Node* root, string s){

	if(root == NULL){

		return;

	}

	if(root->name != 'g'){

		if(root->name == 'A'){

			a += "A:" + s;
	
		}

		else if(root->name == 'B'){

			b += "B:" + s;

		}

		else if(root->name == 'C'){

			c += "C:" + s;

		}

		else if(root->name == 'D'){

			d += "D:" + s;

		}

		else if(root->name == 'E'){

			e += "E:" + s;

		}

		else if(root->name == 'F'){

			f += "F:" + s;

		}

	}

	print(root->left, s + "0");
	print(root->right, s + "1");

}

void Huffman(char name[], int freq[]){

	struct Node *left, *right, *top;
	priority_queue<Node*, vector<Node*>, compare> Heap;

	for(int i = 0; i < 6; i++){

		Heap.push(new Node(name[i], freq[i]));

	}

	while(Heap.size() != 1){

		left = Heap.top();
		Heap.pop();
		right = Heap.top();
		Heap.pop();
		top = new Node('g', left->freq + right->freq);
		top->left = left;
		top->right = right;
		Heap.push(top);

	}

	print(Heap.top(), "");

}

int main(){

	int freq[6];
	
	for(int i = 0; i < 6; i++){

		cin >> freq[i];

	}

	Huffman(arr, freq);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;

}