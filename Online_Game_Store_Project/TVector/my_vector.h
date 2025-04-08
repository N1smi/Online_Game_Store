// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_MY_VECTOR_H_
#define ONLINE_GAME_STORE_PROJECT_MY_VECTOR_H_

#include <iostream>

enum State { empty, busy, deleted };

#define STEP_OF_CAPACITY 15

template <class T>
class TVector {
    T* _data;
    size_t _capacity;
    size_t _size;
    size_t _deleted;
    State* _states;
public:
    TVector(size_t size = 0, const T* data = nullptr);
    TVector(std::initializer_list<T>);
    TVector(const TVector<T>& other);
    ~TVector();

    inline bool is_empty() const noexcept;

    inline T* data() noexcept;

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

    template <typename... Args>
    void emplace(size_t pos, Args&&... args);

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
    inline const T& operator[](size_t pos) const;

    friend void shuffle(TVector<T>& vec);
    friend void sort(TVector<T>& vec);
    friend size_t find_first(const TVector<T>& vec, const T& value);
    friend size_t find_last(const TVector<T>& vec, const T& value);
    friend TVector<size_t> find(const TVector<T>& vec, const T& value);
private:
    inline bool is_full() const noexcept;
    void reallocate();
    void reallocate_for_deleted();

    friend int rand_generation(int min, int max);
    friend void swap(T* first_elem, T* second_elem);
    friend void reallocate_for_sort(TVector<T>& vec);
};

#endif  // ONLINE_GAME_STORE_PROJECT_MY_VECTOR_H_