#include "array.h"

Array *CreateArray(size_t initial_capacity, size_t element_size)
{
    Array *arr = malloc(sizeof(Array));
    if (arr == NULL)
        return NULL;

    arr->elements = malloc(initial_capacity * element_size);
    if (arr->elements == NULL)
    {
        free(arr);
        return NULL;
    }

    arr->element_size = element_size;
    arr->capacity = initial_capacity;
    arr->length = 0;

    return arr;
}

void FreeArray(Array *array)
{
    if (array->elements != NULL)
    {
        free(array->elements);
        array->elements = NULL;
    }
    array->capacity = 0;
    array->length = 0;
    array->element_size = 0;
}

void Display(const Array *arr, PrintFunction print_elem)
{
    if (arr == NULL || arr->elements == NULL)
    {
        printf("Array is NULL or empty\n");
        return;
    }

    printf("Array (length: %zu, capacity: %zu):\n", arr->length, arr->capacity);
    for (size_t index = 0; index < arr->length; index++)
    {
        void *elem = (char *)arr->elements + index * arr->element_size;
        printf("[%zu]: ", index);
        print_elem(elem);
        printf("\n");
    }
}

int Resize(Array *array, size_t new_capacity)
{
    void *new_elements = realloc(array->elements, new_capacity * array->element_size);
    if (!new_elements)
    {
        return -1;
    }
    array->elements = new_elements;
    array->capacity = new_capacity;
    return 0;
}

int Add(Array *array, const void *element)
{
    if (array->length == array->capacity)
    {
        size_t new_capacity = array->capacity == 0 ? 1 : array->capacity * 2;
        if (Resize(array, new_capacity) != 0)
        {
            return -1;
        }
    }

    void *target = (char *)array->elements + (array->length * array->element_size);

    memcpy(target, element, array->element_size);
    array->length++;
    return 0;
}

int Delete(Array *array, size_t index)
{
    if (index >= array->length)
    {
        return -1;
    }

    void *target = (char *)array->elements + (index * array->element_size);

    void *next = (char *)target + array->element_size;

    size_t num_bytes_to_move = (array->length - index - 1) * array->element_size;

    if (num_bytes_to_move > 0)
    {
        memmove(target, next, num_bytes_to_move);
    }

    array->length--;

    return 0;
}

int LinearSearch(const Array *array, const void *element)
{
    size_t index = 0;

    while (index < array->length)
    {
        void *elem = (char *)array->elements + index * array->element_size;

        if (memcmp(elem, element, array->element_size) == 0)
        {
            return index;
        }

        index++;
    }

    return -1;
}

void *GetAt(const Array *array, size_t index)
{
    void *elem = NULL;
    if (index <= array->length)
    {
        elem = (char *)array->elements + index * array->element_size;
    }
    return elem;
}

const void *ConstGetAt(const Array *array, size_t index)
{
    return (const void *)GetAt(array, index);
}

int SetAt(Array *array, size_t index, const void *element)
{

    if (index > array->length)
    {
        return -1;
    }

    if (array->length == array->capacity)
    {
        size_t new_capacity = array->capacity == 0 ? 1 : array->capacity * 2;
        if (Resize(array, new_capacity) != 0)
        {
            return -1;
        }
    }

    void *target = (char *)array->elements + (index * array->element_size);
    void *source = (char *)array->elements + (index + 1) * array->element_size;

    memmove(source, target, (array->length - index) * array->element_size);
    memcpy(target, element, array->element_size);
    array->length++;

    return 0;
}

// Max finder
const void *Max(const Array *array, CompareFunc cmp)
{
    if (array == NULL || array->elements == NULL || array->length == 0 || cmp == NULL)
    {
        return NULL;
    }

    const void *max_elem = array->elements;

    for (size_t index = 1; index < array->length; index++)
    {
        const void *current_elem = (const char *)array->elements + index * array->element_size;
        if (cmp(current_elem, max_elem) > 0)
        {
            max_elem = current_elem;
        }
    }

    return max_elem;
}

// Min finder
const void *Min(const Array *array, CompareFunc cmp)
{
    if (array == NULL || array->elements == NULL || array->length == 0 || cmp == NULL)
    {
        return NULL;
    }

    const void *min_elem = array->elements;

    for (size_t i = 1; i < array->length; i++)
    {
        const void *current_elem = (const char *)array->elements + i * array->element_size;
        if (cmp(current_elem, min_elem) < 0)
        {
            min_elem = current_elem;
        }
    }

    return min_elem;
}

// Reverse array
Array *Reverse(const Array *array)
{
    Array *reversed = CreateArray(array->capacity, array->element_size);

    for (size_t index = array->length; index > 0; index--)
    {
        void *elem = (char *)array->elements + (index - 1) * array->element_size;
        Add(reversed, elem);
    }

    return reversed;
}

int BinaryResearch(const Array *array, const void *element, CompareFunc cmp)
{
    int low = 0;
    int high = array->length - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        void *mid_elem = (char *)array->elements + mid * array->element_size;

        int result = cmp(element, mid_elem);

        if (result == 0)
        {
            return mid;
        }
        else if (result < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}