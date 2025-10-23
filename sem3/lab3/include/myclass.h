class myClass
{
private:
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;

public:
    class iterator
    {
    private:
        int *ptr;

    public:
        iterator(int *p = nullptr) : ptr(p) {}

        int &operator*() { return *ptr; }

        iterator operator++()
        {
            ++ptr;
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        bool operator!=(const iterator &other)
        {
            return ptr != other.ptr;
        }
    };

    iterator begin() { return iterator(arr); }
    iterator end() { return iterator(arr + size); }
};