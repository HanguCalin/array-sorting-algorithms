#include <iostream>

using namespace std;

const int NMAX = 105;

int v[NMAX], n;

void bubble_sort() {
	bool sorted;
	do {
		sorted = true;
		for(int i = 0; i < n - 1; ++i) {
			if(v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
				sorted = false;
			}
		}
	}while(!sorted);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	bubble_sort();

	for(int i = 0; i < n; ++i)
		cout << v[i] << ' ';
      	return 0;
}	
