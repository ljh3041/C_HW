#include <iostream>

using namespace std;


int sum(int arr[], int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    return sum;
}

float mean(int arr[], int N)
{
    return (float)sum(arr, N) / N;
}



int main() {
    cout << "����� ������ ������ �Է��ϼ���.\n";
    int N;
    cin >> N;

    int* arr = new int[N];
    
    cout << N << "���� ���ڸ� �Է��ϼ���.\n";

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    cout << "��: " << sum(arr, N) << " ���: " << mean(arr, N) << endl;

    delete[] arr;
    return 0;
}
