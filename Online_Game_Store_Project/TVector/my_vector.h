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
    size_t real_pos(size_t pos);
    T* real_address(size_t pos);
    inline bool is_full() const noexcept;
    void reallocate(size_t new_size);
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

    size_t i;
    auto it = init_list.begin();
    for (i = 0; it != init_list.end(); i++, it++) {
         _data[i] = *it;
        _states[i] = busy;
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
        size_t busy_count = 0;
        for (size_t i = 0; i < other._capacity; i++) {
            if (other._states[i] == busy) {
                _data[busy_count] = other._data[i];
                _states[busy_count] = busy;
                busy_count++;
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

template <class T>
inline T& TVector<T>::front() {
    if (is_empty()) throw std::out_of_range("Vector is empty");
    size_t it = real_pos(0);
    return _data[it];
}

template <class T>
inline T& TVector<T>::back() {
    if (is_empty()) throw std::out_of_range("Vector is empty");
    size_t it = real_pos(_size - 1);
    return _data[it];
}

template <class T>
inline T* TVector<T>::begin() noexcept {
    T* main_address = real_address(0);
    return main_address;
}

template <class T>
inline T* TVector<T>::end() noexcept {
    T* main_address = nullptr;
    if (!is_empty()) {
        main_address = (real_address(_size - 1) + 1);
    }
    return main_address;
}

template <class T>
void TVector<T>::push_front(const T& value) {
    reallocate(_size + 1);
    _size += 1;
    for (size_t i = _size - 1; i > 0; i--) {
        _data[i] = _data[i - 1];
        _states[i] = _states[i - 1];
    }
    _data[0] = value;
    _states[0] = busy;
}

template <class T>
void TVector<T>::push_back(const T& value) {
    reallocate(_size + 1);
    _size += 1;
    _data[_size - 1] = value;
    _states[_size - 1] = busy;
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

template <class T>
inline const T& TVector<T>::front() const {
    if (is_empty()) throw std::out_of_range("Vector is empty");
    size_t it = real_pos(0);
    return _data[it];
}

template <class T>
inline const T& TVector<T>::back() const {
    if (is_empty()) throw std::out_of_range("Vector is empty");
    size_t it = real_pos(_size - 1);
    return _data[it];
}

template <class T>
inline const T* TVector<T>::begin() const noexcept {
    T* main_address = real_address(_data, 0);
    return main_address;
}

template <class T>
inline const T* TVector<T>::end() const noexcept {
    T* main_address = nullptr;
    if (!is_empty()) {
        main_address = (real_address(_size - 1) + 1);
    }
    return main_address;
}

template<class T>
const T& TVector<T>::operator[](size_t pos) const {
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    size_t it = real_pos(pos);
    return _data[it];
}

template<class T>
T& TVector<T>::operator[](size_t pos) {
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    size_t it = real_pos(pos);
    return _data[it];
}

template<class T>
size_t TVector<T>::real_pos(size_t pos) {
    size_t busy_count = 0;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == busy) {
            if (busy_count == pos)
            {
                return i;
            }
            busy_count++;
        }
    }
}

template<class T>
T* TVector<T>::real_address(size_t pos) {
    size_t busy_count = 0;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == busy) {
            if (busy_count == pos)
            {
                return &_data[i];
            }
            busy_count++;
        }
    }
    return nullptr;
}

template<class T>
void TVector<T>::reallocate(size_t new_size) {
    if (new_size <= _capacity) return;
    size_t new_capacity = (new_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;

    T* new_data = new T[new_capacity];
    State* new_states = new State[new_capacity];

    size_t busy_count = 0;
    for (size_t i = 0; i < _capacity; i++) {
        if (_states[i] == busy) {
            new_data[busy_count] = _data[i];
            new_states[busy_count] = busy;
            busy_count++;
        }
    }

    for (size_t i = new_size; i < new_capacity; i++) {
        new_states[i] = empty;
    }

    delete[] _data;
    delete[] _states;

    _data = new_data;
    _states = new_states;
    _capacity = new_capacity;
}

#endif  // ONLINE_GAME_STORE_PROJECT_MY_VECTOR_H_