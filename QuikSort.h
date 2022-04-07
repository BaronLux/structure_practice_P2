#pragma once
#include "Algorithm.h"
class QuickSort :
    public Algorithm
{

    int* quickSort(int* numbers, int left, int right)
    {
        int pivot; // разрешающий элемент
        int l_hold = left; //лева€ граница
        int r_hold = right; // права€ граница
        pivot = numbers[left];
        while (left < right) // пока границы не сомкнутс€
        {
            while ((numbers[right] >= pivot) && (left < right))
            {
                this->comparison_count++;
                this->iter_count++;

                right--;
            }// сдвигаем правую границу пока элемент [right] больше [pivot]
            if (left != right) // если границы не сомкнулись
            {
                numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
                left++; // сдвигаем левую границу вправо
            }
            while ((numbers[left] <= pivot) && (left < right))
            {
                this->comparison_count++; // количество сравнений
                this->iter_count++; // количество итераций

                left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
            }
            if (left != right) // если границы не сомкнулись
            {
                numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
                right--; // сдвигаем правую границу влево
            }
        }
        numbers[left] = pivot; // ставим разрешающий элемент на место
        pivot = left;
        left = l_hold;
        right = r_hold;
        if (left < pivot) // –екурсивно вызываем сортировку дл€ левой и правой части массива
            quickSort(numbers, left, pivot - 1);
        if (right > pivot)
            quickSort(numbers, pivot + 1, right);

        
        return numbers;
    }
    int* Alg(int *arr, int n) final // 
    {
        return quickSort(arr, 0, n - 1);
    }
public:
    QuickSort():Algorithm()
    {
        name = "quick";
    }

    void Print() final
    {
        //string name = typeid(*this).name() + '\n';
        cout << delimiter + name << endl;
        cout << "iter_count=" << iter_count << endl;
        cout << "comparison_count=" << comparison_count << endl;
        cout << "elapsed[ns]=" << elapsed << endl;
        cout << delimiter;
    }
    //void Print()
    //{
    //    //string name = typeid(*this).name() + '\n';
    //    auto delimiter = "-------------------------------------------------------------\n";
    //    cout << delimiter + name
    //        << "iter_count=" + iter_count << endl
    //        << "comparison_count=" + comparison_count << endl
    //        << "elapsed[ms]=" + elapsed << endl;
    //}
};

