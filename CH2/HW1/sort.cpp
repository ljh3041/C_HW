#include <iostream>

using namespace std;

namespace my
{
    void bubble_sort(int* arr, int N, int version)
    {
        int temp = 0;
        if (version == 1) // ��������.
        {
            for (int i = 0; i < N - 1; i++)
            {
                for (int j = i; j < N - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
        else // ��������
        {
            for (int i = 0; i < N - 1; i++)
            {
                for (int j = i; j < N - 1; j++)
                {
                    if (arr[j] < arr[j + 1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
    }


    void selection_sort(int* arr, int N, int version)
    {
        if (version == 1) // ��������.
        {
            for (int t = 0; t < N - 1; t++)
            {
                int min = 2147483647;
                int min_index = -1;

                for (int i = t; i < N; i++)
                {
                    if (arr[i] < min)
                    {
                        min = arr[i];
                        min_index = i;
                    }
                }

                if (t != min_index)
                {
                    int temp = arr[t];
                    arr[t] = arr[min_index];
                    arr[min_index] = temp;
                }

            }
        }
        else // ��������
        {
            for (int t = 0; t < N - 1; t++)
            {
                int max = -2147483648;
                int max_index = -1;

                for (int i = t; i < N; i++)
                {
                    if (arr[i] > max)
                    {
                        max = arr[i];
                        max_index = i;
                    }
                }

                if (t != max_index)
                {
                    int temp = arr[t];
                    arr[t] = arr[max_index];
                    arr[max_index] = temp;
                }

            }
        }
    }


    void insertion_sort(int* arr, int N, int version)
    {
        if (version == 1) // ��������.
        {
            for (int t = 1; t < N; t++)
            {
                int key = t;
                int front = t - 1;
                while (arr[key] < arr[front] && key > 0)
                {
                    int temp = arr[key];
                    arr[key] = arr[front];
                    arr[front] = temp;
                    key--;
                    front--;
                }
            }
        }
        else // ��������
        {
            for (int t = 1; t < N; t++)
            {
                int key = t;
                int front = t - 1;
                while (arr[key] > arr[front] && key > 0)
                {
                    int temp = arr[key];
                    arr[key] = arr[front];
                    arr[front] = temp;
                    key--;
                    front--;
                }
            }
        }
    }


    void merge(int* arr, int left, int mid, int right, int version)
    {
        int i, j, k;
        i = left;
        j = mid + 1;
        k = 0;

        int* sorted_arr = new int[right - left + 1];
        for (int i = 0; i < right - left + 1; i++)
        {
            sorted_arr[i] = 0;
        }
        while (i <= mid && j <= right && (k < right - left + 1))
        {
            if (version == 1) //��������
            {
                arr[i] <= arr[j] ?
                    sorted_arr[k++] = arr[i++] : sorted_arr[k++] = arr[j++];
            }
            else
            {
                arr[i] > arr[j] ?
                    sorted_arr[k++] = arr[i++] : sorted_arr[k++] = arr[j++];
            }
        }
        if (i > mid)
        {
            while (j <= right && (k < right - left + 1))
            {
                sorted_arr[k++] = arr[j++];
            }
        }
        else
        {
            while (i <= mid && (k < right - left + 1))
            {
                sorted_arr[k++] = arr[i++];
            }
        }
        int index = 0;
        for (int i = left; i <= right; i++)
        {
            arr[i] = sorted_arr[index];
            index++;
        }

        delete[] sorted_arr;
    }

    void merge_sort(int* arr, int left, int right, int version)
    {
        int mid;

        if (left < right)
        {
            mid = (left + right) / 2;
            merge_sort(arr, left, mid, version);
            merge_sort(arr, mid + 1, right, version);
            merge(arr, left, mid, right, version);
        }
    }


    void quick_sort(int* arr, int left, int right, int version)
    {
        if (left >= right) // ���Ұ� 1���� ��� �״�� �α�
            return;

        int pivot = left; // �Ǻ��� ù��° ���� / �߰��� �������
        int i = left + 1;
        int j = right;
        int temp;

        while (i <= j) { // ������ ������ �ݺ�
            while (i <= right && (arr[i] <= arr[pivot])) { // �Ǻ����� ū ���� ã�� ������
                i++;
            }
            while (j > left && (arr[j] >= arr[pivot])) { // �Ǻ����� ���� ���� ã�� ������
                j--;
            }

            if (i > j) { // ������ ����. �Ǻ����� ���� ���� �Ǻ��� ��ü
                temp = arr[j];
                arr[j] = arr[pivot];
                arr[pivot] = temp;
            }
            else { // �������� �ʾҴٸ� i�� j�� ��ü
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        quick_sort(arr, left, j - 1, version);
        quick_sort(arr, j + 1, right, version);
    }

}



int main() {
    std::cout << "\"1\" �Է½� �������� ����. \"2\" �Է½� �������� ����" << endl
        << "\n============= 1�� 2 �߿� �����ϼ���.=============\n>>>";
    int version = 0;
    cin >> version;

    if (version != 1 && version != 2)
    {
        std::cout << "1 �Ǵ� 2 �� �� �ϳ��� �Է��� ��.\n";
        return 0;
    }

    int N;
    std::cout << "�迭�� ũ�⸦ �Է�.\n>>>";
    cin >> N;

    int* arr = new int[N];
    std::cout << "�迭�� ���Ҹ� �Է�.\n";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    std::cout << "���� ���� �迭:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << " ";
    }
    //my::bubble_sort(arr, N, version);
    //my::selection_sort(arr, N, version);
    //my::insertion_sort(arr, N, version);
    //my::merge_sort(arr, 0, N - 1, version);
    //my::quick_sort(arr, 0, N - 1, version);

    std::cout << "\n���� ���� �迭:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << " ";
    }
    delete[] arr;

    return 0;
}
