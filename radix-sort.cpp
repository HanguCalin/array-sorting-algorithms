#include <iostream>

using namespace std;

const int NMAX = 105;

int v[NMAX],  n;

int getMax(int array[], int n) {
  	int max = array[0];
  	for (int i = 1; i < n; i++)
    		if (array[i] > max)
      	max = array[i];
  	return max;
}

void countingSort(int array[], int size, int place) {
  	const int max = 10;
  	int output[size];
  	int count[max];

  	for (int i = 0; i < max; ++i)
    		count[i] = 0;

  	for (int i = 0; i < size; i++)
    		count[(array[i] / place) % 10]++;

  	for (int i = 1; i < max; i++)
    		count[i] += count[i - 1];

  	for (int i = size - 1; i >= 0; i--) {
    		output[count[(array[i] / place) % 10] - 1] = array[i];
    		count[(array[i] / place) % 10]--;
  	}

  	for (int i = 0; i < size; i++)
    		array[i] = output[i];
}

void radixsort(int array[], int size) {
  	int max = getMax(array, size);

    	for (int place = 1; max / place > 0; place *= 10)
    		countingSort(array, size, place);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> v[i];

  	radixsort(v, n);
  	
	for (int i = 0; i < n; i++)
    		cout << v[i] << " ";
  	cout << endl;
}
