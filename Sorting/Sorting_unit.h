#pragma once
#include <iostream>
#include <algorithm>

///������� ������ ������� �� �����
///arr - ��������� ������
///len - ����� �������
template<typename T>
void array_out(T* arr, size_t len) {
	for (size_t i = 0;i < len; i++) {
		std::cout << arr[i]<< " ";
	}
}

///���������� ������� ���� ������� ������� ������� � ����� begin � end
///a - �������������� ������
///begin - ����� ������� ��������������� �������
///end - ������ ������� ��������������� �������
template<typename T>
void merging(T* a,size_t begin, size_t end) {
	T* c = new T[end - begin];					//����� ��� �������� ���������� �������

	size_t mid = (begin + end)/2,				//�������� ��������������� �������
		   left = begin,						//������ �������� �� ����� �������
		   right = mid,							//������ �������� �� ������ �������
		   i = 0;								//������ ������� c 
	
	while (left < mid && right < end) {			//���� �� ��������� ����� ����� �� ��������
		if (a[left] <= a[right]) {				//������������ �������� �� ��������
			
			c[i] = a[left];						// ���� left ������ right, �� � ������ i ������� � �������� �������� �� ����� �������
			left++;
		}
		else {
			c[i] = a[right];					//� ��������� ������ �� ������
			right++;
		}
		i++;
	}
	//�������� ���������� �������� � ������ c
	if (left == mid) {							//���� ��� ��������� ����� ����� �����
		
		while (right < end) {					//�� �������� �������� �� ������

			c[i] = a[right];
			right++;
			i++;
		}
	}else if (right == end) {					//���� �� ��� ��������� ����� ������ �����
			
			while (left < mid) {				// �� �������� �������� �� �����

				c[i] = a[left];
				left++;
				i++;
			}
	}

	size_t j = 0;
	while (j < end - begin) {					//��������� �������� �� ������� � � ������ �
		a[begin + j] = c[j];
		j++;
	}
	delete[] c;
}

///����������� ������� ���������� ��������
/// a - �����������������
///left - ����� ������� ����������
/// right - ������ ������� ����������
template<typename T>
void MergeSort(T* a,size_t left, size_t right) {
	if (left < right-1){
		MergeSort(a, left, (left + right) / 2 );	//���������� ����� �������� ����������� �������
		MergeSort(a, (left + right) / 2  , right);  //���������� ������ �������� ����������� �������
		merging(a, left,right);
	}
}

///������� ����������� ���������� 
///a - ����������� ������ 
/// len - ����� �������
template<typename T>
void bubble_sort(T* a, size_t len) {
	for (size_t i = 0; i < len;i++) {
		for (size_t j = i; j < len;j++) {
			if (a[i] > a[j]) {
				std::swap(a[i], a[j]);
			}
		}
	}
}

///������� ���������� ���������
///a - ����������� ������ 
/// len - ����� �������
template<typename T>
void insertion_sort(T* a, size_t len) {
	for (size_t i = 1; i < len;i++) {
		for (size_t j = i; j > 0 && a[j] < a[j-1];j--) {
				std::swap(a[j-1], a[j]);
			
		}
	}
}

///������� ���������� �������
///a - ����������� ������ 
/// len - ����� �������
template<typename T>
void selection_sort(T* a, size_t len) {
	T min ;
	size_t n_min;
	for (size_t i = 0; i < len;i++) {
		min = a[i];
		n_min = i;
		for (size_t j = i + 1; j < len;j++) {
			if (a[j] < min) {
				min = a[j];
				n_min = j; 
			}
		}
		std::swap(a[n_min], a[i]);
	}
}