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
    cout << "계산할 숫자의 갯수를 입력하세요.\n";
    int N;
    cin >> N;

    int* arr = new int[N];
    
    cout << N << "개의 숫자를 입력하세요.\n";

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    cout << "합: " << sum(arr, N) << " 평균: " << mean(arr, N) << endl;

    delete[] arr;
    return 0;
}
