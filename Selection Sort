
// This file contains the functions that implement the Selection Sort.

template<class ItemType>
inline void Swap(ItemType& item1, ItemType& item2)
// Post: Contents of item1 and item2 have been swapped.
{
    ItemType tempItem;

    tempItem = item1;
    item1 = item2;
    item2 = tempItem;
}

template<class ItemType>
int MinIndex(ItemType values[], int startIndex, int endIndex)
// Post: Function value = index of the smallest value in
// values[startIndex]..values[endIndex].
{
    int indexOfMin = startIndex;
    for (int index = startIndex + 1; index <= endIndex; index++)
        if (values[index] < values[indexOfMin])
            indexOfMin = index;
    return indexOfMin;
}

template<class ItemType>
void SelectionSort(ItemType values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
    int endIndex = numValues-1;

    for (int current = 0; current < endIndex; current++)
        Swap(values[current], values[MinIndex(values, current, endIndex)]);
}
