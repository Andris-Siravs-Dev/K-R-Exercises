#include <stdio.h>
#include <time.h>
#define MAX 2000
#define TIMES 5000000

int binsearch(int x, int v[], int n);
int fill (int v[]);
int main(void)
{
	int v[MAX];
	int n = fill(v);

	clock_t start, end;
	double duration;

	start = clock();

	for (int i = 0; i < TIMES; i++)
	{
		binsearch(42, v, n);
	}

	end = clock();
	duration = (double) (end-start) / CLOCKS_PER_SEC;

	printf("The search took %f seconds for %d times.\n", duration, TIMES);
	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low < high)
	{
		mid = (low+high) / 2;
		if (x <= v[mid])
			high = mid;
		else
			low = mid+1;
	}

	if (v[high] == x)
		return high;

	return -1;

}

int fill (int v[])
{
	int i;
	for (i = 0;  i < MAX; i++)
		v[i] = i+1;
	return i;
}
