#include <iostream>

using namespace std;

namespace my
{
    void bubble_sort(int* arr, int N, int version)
    {
        int temp = 0;
        if (version == 1) // 오름차순.
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
        else // 내림차순
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
        if (version == 1) // 오름차순.
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
        else // 내림차순
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
        if (version == 1) // 오름차순.
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
        else // 내림차순
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
            if (version == 1) //오름차순
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
        if (left >= right) // 원소가 1개인 경우 그대로 두기
            return;

        int pivot = left; // 피봇은 첫번째 원소 / 중간도 상관없음
        int i = left + 1;
        int j = right;
        int temp;

        while (i <= j) { // 엇갈릴 때까지 반복
            while (i <= right && (arr[i] <= arr[pivot])) { // 피봇보다 큰 값을 찾을 때까지
                i++;
            }
            while (j > left && (arr[j] >= arr[pivot])) { // 피봇보다 작은 값을 찾을 때까지
                j--;
            }

            if (i > j) { // 엇갈린 상태. 피봇보다 작은 값과 피봇과 교체
                temp = arr[j];
                arr[j] = arr[pivot];
                arr[pivot] = temp;
            }
            else { // 엇갈리지 않았다면 i와 j를 교체
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
    std::cout << "\"1\" 입력시 오름차순 정렬. \"2\" 입력시 내림차순 정렬" << endl
        << "\n============= 1과 2 중에 선택하세요.=============\n>>>";
    int version = 0;
    cin >> version;

    if (version != 1 && version != 2)
    {
        std::cout << "1 또는 2 둘 중 하나만 입력할 것.\n";
        return 0;
    }

    int N;
    std::cout << "배열의 크기를 입력.\n>>>";
    cin >> N;

    int* arr = new int[N];
    std::cout << "배열의 원소를 입력.\n";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    std::cout << "정렬 전의 배열:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << " ";
    }
    //my::bubble_sort(arr, N, version);
    //my::selection_sort(arr, N, version);
    //my::insertion_sort(arr, N, version);
    //my::merge_sort(arr, 0, N - 1, version);
    //my::quick_sort(arr, 0, N - 1, version);

    std::cout << "\n정렬 후의 배열:\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << " ";
    }
    delete[] arr;

    return 0;
}
