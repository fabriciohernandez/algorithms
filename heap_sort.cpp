#include <iostream>

using namespace std;

void
max_heapify (int arr[], int n, int i)
{
  int largest = i;		// Inicializamos largest como la raiz del subarbol
  int l = 2 * i + 1;		// hijo izquierdo 2*i + 1
  int r = 2 * i + 2;		// hijo derecho 2*i + 2

  // Si el hijo izquierdo es mayor que la raiz
  if (l<n && arr[l] > arr[largest])
    largest = l;

  // Si el hijo derecho es mayor que el mas grande
  if (r < n && arr[r] > arr[largest])
    largest = r;

  // si el mas grande no es la raiz
  if (largest != i)
    {
      swap (arr[i], arr[largest]);
      max_heapify (arr, n, largest);
    }
}

void build_max_heap (int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    {
      max_heapify (arr, n, i);
    }

  // Mandamos el primer elemento al final del arreglo
  for (int i = n - 1; i > 0; i--)
    {
      // Move current root to end
      swap (arr[0], arr[i]);

      // Volvemos a arreglar la propiedad max heap
      max_heapify (arr, i, 0);
    }
}

void heapsort(int arr[], int n)
{
   build_max_heap (arr, n);
}

void printArray (int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << "\n";
}


int main ()
{
  int arr[] = { 12, 11, 13, 5, 6, 7 };
  int n = sizeof (arr) / sizeof (arr[0]);

  heapsort (arr, n);

  printArray (arr, n);

  return 0;
}
