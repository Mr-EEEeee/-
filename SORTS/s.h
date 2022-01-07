#pragma once

#include<sstream>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>

using namespace std;
const int L = 30000;
const int chu1 = 245000;
const int chu2 = 28800;
const float chu3 = 1.1;
const double pi = 3.14159265358979323846;
int a[L]; string s;  int n, m;//n是比较次数，m是移动次数
CString ss1,ss2,ss3,ss4,ss5,ss6,xs1,xs2,xs3,xs4,xs5,xs6;
int n1, n2, n3, n4, n5, n6,m1,m2,m3,m4,m5,m6,t1,t2,t3,t4,t5,t6;

void create(int x[]) {
	for (int i = 0; i < L; i++) {
		x[i] = rand() % 9990;
	}
}
void InsertSort(int x[]) {//直接插入排序
	int b[L]; n = 0; m = 0;
	for (int i = 0; i < L; i++)
		b[i] = x[i];
	long start = clock();
	for (int i = 1; i < L; i++) {
		n++;
		if(b[i-1]>b[i]){
		int t = b[i];
		int j = i - 1;
		while (n++,j >= 0 && b[j] > t) {
			b[j + 1] = b[j]; m++;
			j--;
		}
		b[j + 1] = t; m++;
		}
	}
	long end = clock();
	ss1.Format(_T("%d"), n);
	xs1.Format(_T("%d"), m);
	ostringstream cout;
	n1 = log(n / chu1); m1 = log(m / chu2); t1 = log((end - start) / chu3);
	cout <<"直接插入排序: "<< end - start <<" ms"<< endl;
	s = cout.str();
}//O(n*n) S(n)=O(1) 稳定

void ShellSort(int x[]) {//希尔排序（序列/2
	int b[L]; n = 0; m = 0;
	for  (int i = 0; i < L; i++)
		b[i] = x[i];
	int k = L / 2;
	long start = clock();
	while (k >= 1) {
		for (int i = k; i < L; i++) {
			int j = i;
			while (n++,j >= k && b[j - k] > b[j])
			{
				int t = b[j];
				b[j] = b[j - k];
				b[j - k] = t;
				j -= k; m++;
			}
		}
		if (k == 1)break;
		k = k / 2;
	}
	long end = clock();
	ss2.Format(_T("%d"), n);
	xs2.Format(_T("%d"), m);
	ostringstream cout;
	n2 = log(n/chu1); m2 = log(m / chu2); t2 = log((end - start) / chu3);
	cout <<"希尔排序: "<< end - start << " ms" << endl;
	s = cout.str();

}//O(nlog2 n)？ O(1) 不稳定

void BubbleSort(int x[]) {//冒泡排序
	int b[L]; n = 0; m = 0;
	for (int i = 0; i < L; i++)
		b[i] = x[i];
	long start = clock();
	for (int i = 0; i < L; i++) {
		for (int j = L - 1; j > i; j--) {
			if (n++,b[j] < b[j - 1]) {
				int t = b[j]; b[j] = b[j - 1]; b[j - 1] = t; m++;
			}
		}
	}
	long end = clock();
	ss3.Format(_T("%d"), n);
	xs3.Format(_T("%d"), m);
	ostringstream cout;
	n3 = log(n/chu1); m3 = log(m / chu2); t3 = log((end - start) / chu3);
	cout << "冒泡排序: " << end - start << " ms" << endl;
	s = cout.str();
}//O(n*n) 0(1) 稳定

void QuickSort(int x[], int low, int high) {//快速排序
	if (low < high) {
		int i = low; int j = high; int key = x[i];
		while (i < j) {
			while (n++,i < j && x[j] >= key) j--;
			if (i < j) { x[i] = x[j]; m++; }
			while (n++,i < j && x[i] <= key) i++;
			if (i < j) { x[j] = x[i]; m++; }
		}
		x[i] = key; m++;
		QuickSort(x, low, i - 1);
		QuickSort(x, i + 1, high);
	}
}//0(nlog2 n) O(nlog2 n) 不稳定

void down(int arr[], int root, int size)
{
	int parent = root;
	int left = root * 2 + 1;
	int right = left + 1;
	while (left < size) {
		int max = left;
		if (n++,right<size && arr[right]>arr[max]) {
			max = right;
		}
		if (n++,arr[max] > arr[parent]) {
			int key = arr[max];
			arr[max] = arr[parent];
			arr[parent] = key; m++;
			parent = max;
			left = parent * 2 + 1;
			right = left + 1;
		}
		else {
			break;
		}
	}
}
void heapSort(int x[]) {
	int b[L]; n = 0; m = 0;
	for (int i = 0; i < L; i++)
		b[i] = x[i];
	long start = clock();
	for (int i = L / 2 - 1; i >= 0; i--) {
		down(b, i,L);
	}
	for (int i = L - 1; i > 0; i--) {
		int key = b[0];
		b[0] = b[i];
		b[i] = key; m++;
		down(b, 0,i);
	}
	long end = clock();
	ss5.Format(_T("%d"), n);
	xs5.Format(_T("%d"), m);
	ostringstream cout;
	n5 = log(n/chu1); m5 = log(m / chu2); t5 = log((end - start) / chu3);
	cout << "堆排序: " << end - start << " ms" << endl;
	s = cout.str();
}
void easySort(int x[]) {
	int b[L]; n = 0; m = 0;
	for (int i = 0; i < L; i++)
		b[i] = x[i];
	long start = clock();
	for (int i = 0; i < L; i++) {
		int k = i;
		for (int j = i + 1; j < L; j++) {
			if (n++,b[j] < b[k]) {
				k = j;
			}
		}
		if (k != i) {
			int temp = b[k];
			b[k] = b[i];
			b[i] = temp; m++;
		}
	}
	long end = clock();
	ss6.Format(_T("%d"), n);
	xs6.Format(_T("%d"), m);
	ostringstream cout;
	n6 = log(n/chu1); m6 = log(m / chu2); t6 = log((end - start) / chu3);
	cout << "简单排序: " << end - start << " ms" << endl;
	s = cout.str();
}

struct pl1 {
	int x, y; 
	pl1(int n) {
		long double sum = n1 + n2 + n3 + n4+ n5+ n6;
		double p = n / sum * 2*pi;
		x = 800 + 300 * cos(p);
		y = 500 - 300 * sin(p);
	}
};
struct pl2 {
	int x, y;
	pl2(int m) {
		long double sum = m1 + m2 + m3 + m4 + m5 + m6;
		double p = m / sum * 2 * pi;
		x = 200 + 300 * cos(p);
		y = 500 - 300 * sin(p);
	}
};
struct pl3 {
	int x, y;
	pl3(int t) {
		long double sum = t1 + t2 + t3 + t4 + t5 + t6;
		double p = t / sum * 2 * pi;
		x = 500 + 300 * cos(p);
		y = 540 - 300 * sin(p);
	}
};