#include <iostream>

using namespace std;

int partition (int arr[], int s, int f)
{
  int pivot = arr[f];
  int ref = s - 1;

  for (int i = s; i < f; i++)
    {
      if (arr[i] <= pivot)
	{
	  ref++;
	  swap (arr[ref], arr[i]);
	}

    }


  swap (arr[ref + 1], arr[f]);
  return ref + 1;
}

void quicksort (int arr[], int s, int f)
{
  if (s < f)
    {
      int q = partition (arr, s, f);
      quicksort (arr, s, q - 1);
      quicksort (arr, q + 1, f);
    }

}

void printArray (int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << "\n";
}

int main ()
{
  int arr[] = {5,4,3,2,1};
  int n = sizeof (arr) / sizeof (arr[0]);
  quicksort (arr, 0, n - 1);
  printArray (arr, n);
  return 0;
}
