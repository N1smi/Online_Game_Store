// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_MY_VECTOR_H_
#define ONLINE_GAME_STORE_PROJECT_MY_VECTOR_H_

#include <iostream>

enum State { empty, busy, deleted };

#define STEP_OF_CAPACITY 15

template <class T>
class TVector {
    T* _data;
    size_t _size;
    size_t _capacity;
    size_t _deleted;
    State* _states;
public:
    TVector(size_t size = 0);
    TVector(std::initializer_list<T>);
    TVector(const TVector<T>& other);
    ~TVector();

    inline bool is_empty() const noexcept;

    inline T* data() noexcept;
    inline T& front();
    inline T& back();
    inline T* begin() noexcept;
    inline T* end() noexcept;

    inline const T* data() const noexcept;
    inline size_t size() const noexcept;
    inline size_t capacity() const noexcept;
    inline const T& front() const;
    inline const T& back() const;
    inline const T* begin() const noexcept;
    inline const T* end() const noexcept;

    void push_front(const T& value);
    void push_back(const T& value);
    void insert(size_t pos, const T& value);
    void insert(size_t pos, size_t count, const T& value);

    void pop_front();
    void pop_back();
    void erase(size_t pos);
    void erase(size_t first, size_t last);

    void replace(size_t pos, const T& new_value);
    void replace(T* pos, const T& new_value);

    void assign(size_t size, const T& value);
    inline const T& at(size_t pos) const;
    void clear() noexcept;

    void shrink_to_fit() noexcept;
    void reserve(size_t new_capacity);
    void resize(size_t size);
    void resize(size_t size, const T& value);

    TVector<T>& operator=(const TVector<T>& other);
    bool operator==(const TVector<T>& other) const;
    bool operator!=(const TVector<T>& other) const;

    const T& operator[](size_t pos) const;
    T& operator[](size_t pos);

    friend void shuffle(TVector<T>& vec);
    friend void sort(TVector<T>& vec);
    friend T* find_first(const TVector<T>& vec, const T& value);
    friend T* find_last(const TVector<T>& vec, const T& value);
    friend TVector<T*> find(const TVector<T>& vec, const T& value);
private:
    inline bool is_full() const noexcept;
    void reallocate();
    void reallocate_for_deleted();

    friend int rand_generation(int min, int max);
    friend void swap(T* first_elem, T* second_elem);
    friend void reallocate_for_sort(TVector<T>& vec);
};

template <class T>
TVector<T>::TVector(size_t size) {
    _size = size;
    _capacity = _size;
    _deleted = 0;
    _data = (_capacity == 0) ? nullptr : new T[_capacity];
    _states = (_capacity == 0) ? nullptr : new State[_capacity];

    for (size_t i = 0; i < _size; i++) {
        _data[i] = T();
        _states[i] = busy;
    }
}

template <class T>
TVector<T>::TVector(std::initializer_list<T> init_list) {
    _size = init_list.size();
    _capacity = _size;
    _deleted = 0;
    _data = (_capacity == 0) ? nullptr : new T[_capacity];
    _states = (_capacity == 0) ? nullptr : new State[_capacity];

    if (_capacity != 0) {
        size_t i = 0;
        for (const auto& item : init_list) {
            _data[i] = item;
            _states[i] = busy;
            i++;
        }
    }
}

template <class T>
TVector<T>::TVector(const TVector<T>& other) {
    _size = other._size;
    _capacity = _size;
    _deleted = 0;
    _data = (_capacity == 0) ? nullptr : new T[_capacity];
    _states = (_capacity == 0) ? nullptr : new State[_capacity];

    if (_capacity != 0) {
        size_t j = 0;
        for (size_t i = 0; i < other._capacity; i++) {
            if (other._states[i] == busy) {
                _data[j] = other._data[i];
                _states[j] = busy;
                j++;
            }
        }
    }
}

template <class T>
TVector<T>::~TVector() {
    delete[] _data;
    delete[] _states;
}

template <class T>
inline bool TVector<T>::is_empty() const noexcept {
    return _size == 0;
}

template <class T>
inline T* TVector<T>::data() noexcept {
    return _data;
}

template<class T>
inline const T* TVector<T>::data() const noexcept {
    return _data;
}

template<class T>
inline size_t TVector<T>::size() const noexcept {
    return _size;
}

template<class T>
inline size_t TVector<T>::capacity() const noexcept {
    return _capacity;
}

template<class T>
const T& TVector<T>::operator[](size_t pos) const {
    if (pos >= _size) {
        throw std::logic_error("Index out of range");
    }

    size_t busy_count = 0;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == busy) {
            if (busy_count == pos)
            {
                return _data[i];
            }
            busy_count++;
        }
    }
}

template<class T>
T& TVector<T>::operator[](size_t pos) {
    return const_cast<T&>(std::as_const(*this)[pos]);
}

#endif  // ONLINE_GAME_STORE_PROJECT_MY_VECTOR_H_