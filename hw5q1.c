#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DELTA 'k'
#define ARR_LEN 'n'
#define ARR (arr + i)
#define ARR_J (arr + i + j)
#define ARR_K (arr + i * (n / (k + 1)) + k)
#define IN_ARR (i + j < n) && (j <= k)
#define TMP_M (tmp_arr + m)
#define SMALL_DELTA n - i <= k
#define TMP_SMALL (tmp_arr + (n - i - 1) - (j - 1))
#define TMP_END (tmp_arr + k - (j - 1))
#define FINAL_DIG (j == k) || (i + j == n - 1)
#define IN_TMP (j <= k) && (j <= (n-i-1))
#define TMP_J (tmp_arr + j)


void print_arr(int arr[], int n);
void print_scan_int_request(char ch);
void print_scan_arr_request();
int scan_int(char ch);
void scan_arr(int* arr, int n);
void sort_arr(int* arr, int n, int k, int *tmp_arr);
int delta_sort(int* arr, int n, int k, int* tmp_arr, int i);

int main() {
	int k = scan_int(DELTA), n = scan_int(ARR_LEN), * arr = NULL, *tmp_arr = NULL;
	arr = (int*)malloc(sizeof(int) * n);
	tmp_arr = (int*)malloc(sizeof(int) * (k+1));
	if (arr == NULL || tmp_arr == NULL) return 1;
	scan_arr(arr, n);
	sort_arr(arr, n, k, tmp_arr);
	print_arr(arr, n);
	free(arr);
	free(tmp_arr);
	return 0;
}

int delta_sort(int* arr, int n, int k, int* tmp_arr, int i) {
	if (k <= 0) return 0;
	int m = 0;
	for (int j = 1; IN_ARR ; ++j) { 
		if (*ARR > * ARR_J) {
			*TMP_M = *ARR_J;
			++m;
		}
		else {
			if (SMALL_DELTA) *TMP_SMALL = *ARR_J;
			else *TMP_END = *ARR_J;
		}
		if (FINAL_DIG) *TMP_M = *ARR;
	}
	for (int j = 0; IN_TMP ; ++j) {
		*ARR_J = *TMP_J;
	}
	delta_sort(arr, n, m - 1, tmp_arr, i);
	return m + 1;
}

void sort_arr(int* arr, int n, int k, int *tmp_arr) {
	for (int i = 0; i < n - 1; ) {
		i += delta_sort(arr, n, k, tmp_arr, i);
		if (i == 0) return;
		}
}

void scan_arr(int* arr, int n) {
	print_scan_arr_request();
	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &arr[i]) == 0) exit(1);
	}
}

int scan_int(char ch) {
	int tmp;
	do {
		print_scan_int_request(ch);
		if (scanf("%d", &tmp) == 0) exit(1);
	} while (tmp < 0);
	return tmp;

}

void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
}

void print_scan_int_request(char ch)
{
	printf("Please enter a non negative integer (%c):", ch);
}

void print_scan_arr_request()
{
	printf("Please enter n integer values with the special characteristic:\n");
}