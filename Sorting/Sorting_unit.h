#pragma once
#include <iostream>
#include <algorithm>

///Функция вывода массива на экран
///arr - выводимый массив
///len - длина массива
template<typename T>
void array_out(T* arr, size_t len) {
	for (size_t i = 0;i < len; i++) {
		std::cout << arr[i]<< " ";
	}
}

///Производит слияние двух половин области массива а между begin и end
///a - обрабатываемый массив
///begin - левая граница рассматриваемой области
///end - правая граница рассматриваемой области
template<typename T>
void merging(T* a,size_t begin, size_t end) {
	T* c = new T[end - begin];					//буфер для хранения результата слияния

	size_t mid = (begin + end)/2,				//середина рассматриваемой области
		   left = begin,						//индекс элемента из левой области
		   right = mid,							//индекс элемента из правой области
		   i = 0;								//индекс массива c 
	
	while (left < mid && right < end) {			//пока не достигнут конец одной из областей
		if (a[left] <= a[right]) {				//сравниваются значения из областей
			
			c[i] = a[left];						// если left меньше right, то в индекс i массива с помещаем значение из левой области
			left++;
		}
		else {
			c[i] = a[right];					//в противном случае из правой
			right++;
		}
		i++;
	}
	//помещаем оставшиеся значения в массив c
	if (left == mid) {							//если был достигнут конец левой части
		
		while (right < end) {					//то помещаем значения из правой

			c[i] = a[right];
			right++;
			i++;
		}
	}else if (right == end) {					//если же был достигнут конец правой части
			
			while (left < mid) {				// то помеащем знаяения из левой

				c[i] = a[left];
				left++;
				i++;
			}
	}

	size_t j = 0;
	while (j < end - begin) {					//помещение значений из массива с в массив а
		a[begin + j] = c[j];
		j++;
	}
	delete[] c;
}

///рекурсивная функция сортировки слиянием
/// a - сортируемыймассив
///left - левая граница сортировки
/// right - правая граница сортировки
template<typename T>
void MergeSort(T* a,size_t left, size_t right) {
	if (left < right-1){
		MergeSort(a, left, (left + right) / 2 );	//сортировка левой половины сортируемой области
		MergeSort(a, (left + right) / 2  , right);  //сортировка правйо половины сортируемой области
		merging(a, left,right);
	}
}

///Функция пузырьковой сортировки 
///a - сортируемый массив 
/// len - длига массива
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

///Функция сортировки вставками
///a - сортируемый массив 
/// len - длига массива
template<typename T>
void insertion_sort(T* a, size_t len) {
	for (size_t i = 1; i < len;i++) {
		for (size_t j = i; j > 0 && a[j] < a[j-1];j--) {
				std::swap(a[j-1], a[j]);
			
		}
	}
}

///Функция сортировки выбором
///a - сортируемый массив 
/// len - длига массива
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