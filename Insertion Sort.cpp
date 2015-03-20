// This file contains the function definitions for the Insertion Sort.

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
void InsertItem(ItemType values[], int startIndex, int endIndex)
// Post: values[startIndex]..values[endIndex] are now sorted.
{
    bool finished = false;
    int current = endIndex;
    bool moreToSearch = (current != startIndex);

    while (moreToSearch && !finished)
    {
	if (values[current] < values[current-1])
	{
	    Swap(values[current], values[current-1]);
	    current--;
	    moreToSearch = (current != startIndex);
	}
	else
	    finished = true;
    }
}

template<class ItemType>
void InsertionSort(ItemType values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
    for (int count = 1; count < numValues; count++)
	    InsertItem(values, 0, count);
}
