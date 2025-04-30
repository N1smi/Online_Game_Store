// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_TVECTOR_MY_VECTOR_H_
#define ONLINE_GAME_STORE_PROJECT_TVECTOR_MY_VECTOR_H_

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
  explicit TVector(size_t size = 0);
  TVector(std::initializer_list<T>);
  TVector(const TVector<T>& other);
  ~TVector();

  inline const State* states() const noexcept;  // for debugging

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
  void erase(T* frist, T* last);
  void erase(size_t pos);
  void erase(size_t first, size_t last);

  void replace(T* pos, const T& new_value);
  void replace(size_t pos, const T& new_value);

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
  _capacity = other._capacity;
  _deleted = other._deleted;
  _data = (_capacity == 0) ? nullptr : new T[_capacity];
  _states = (_capacity == 0) ? nullptr : new State[_capacity];

  if (_capacity != 0) {
    for (size_t i = 0; i < other._capacity; i++) {
      _data[i] = other._data[i];
      _states[i] = other._states[i];
    }
  }
}

template <class T>
TVector<T>::~TVector() {
  delete[] _data;
  delete[] _states;
}

template <class T>
inline const State* TVector<T>::states() const noexcept {
  return _states;
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
  if (is_empty()) {
    throw std::out_of_range("Use front() in empty vector!");
  }
  size_t it = real_pos(0);
  return _data[it];
}

template <class T>
inline T& TVector<T>::back() {
  if (is_empty()) {
    throw std::out_of_range("Use back() in empty vector!");
  }
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
  for (size_t i = 0; i < _size + _deleted; i++) {
    if (_states[i] != busy && _states[i + 1] == busy) {
      _data[i] = value;
      if (_states[i] == deleted) --_deleted;
      _states[i] = busy;
      _size++;
      return;
    }
    if (_states[i] == busy) {
      break;
    }
  }

  reallocate(_size + 1 + _deleted);

  for (size_t j = _size + _deleted; j > 0; j--) {
    _data[j] = _data[j - 1];
    _states[j] = _states[j - 1];
  }
  _data[0] = value;
  _states[0] = busy;
  _size++;
}

template <class T>
void TVector<T>::push_back(const T& value) {
  if (_size != 0) {
    size_t last_busy_pos = real_pos(_size - 1);

    if (last_busy_pos + 1 < _capacity
      && (_states[last_busy_pos + 1] != busy)) {
      size_t insert_pos = last_busy_pos + 1;
      _data[insert_pos] = value;
      _states[insert_pos] = busy;
      _size++;
      if (_states[insert_pos] == deleted) --_deleted;
      return;
    }
  }
  reallocate(_size + 1 + _deleted);
  _data[_size] = value;
  _states[_size] = busy;
  _size++;
}

template<class T>
void TVector<T>::insert(size_t pos, const T& value) {
  if (_size == 0 || pos == _size) {
    push_back(value);
    return;
  }

  if (pos > _size) {
    throw std::out_of_range("Inserting an index outside the range!");
  }

  size_t insert_pos = real_pos(pos);
  if (insert_pos != 0) {
    if (_states[insert_pos - 1] == deleted) {
      _data[insert_pos - 1] = value;
      _states[insert_pos - 1] = busy;
      --_deleted;
      _size += 1;
      return;
    }
  }

  reallocate(_size + 1 + _deleted);

  for (size_t j = _size + _deleted; j > insert_pos; j--) {
    _data[j] = _data[j - 1];
    _states[j] = _states[j - 1];
  }

  _data[insert_pos] = value;
  _states[insert_pos] = busy;
  _size++;
}

template<class T>
void TVector<T>::insert(size_t pos, size_t count, const T& value) {
  if (count == 0) {
    return;
  }

  if (_size == 0 || pos == _size) {
    for (size_t i = 0; i < count; i++) {
      push_back(value);
    }
    return;
  }

  if (pos > _size) {
    throw std::out_of_range("Inserting an index outside the range!");
  }

  size_t insert_pos = real_pos(pos);
  size_t start_pos = (pos == 0) ? 0 : real_pos(pos - 1) + 1;
  size_t count_deleted = 0;

  for (size_t i = start_pos; i < insert_pos && count_deleted < count; i++) {
    if (_states[i] == deleted) {
      count_deleted++;
    } else {
      count_deleted = 0;
      break;
    }
  }

  if (count_deleted >= count) {
    size_t insert_start = insert_pos - count_deleted;
    for (size_t i = 0; i < count; i++) {
      _data[insert_start + i] = value;
      _states[insert_start + i] = busy;
    }
    _size += count;
    _deleted -= count;
    return;
  }

  reallocate(_size + count + _deleted);
  insert_pos = real_pos(pos);

  for (size_t i = _size + _deleted + count - 1;
    i >= insert_pos + count; i--) {
    _data[i] = _data[i - count];
    _states[i] = _states[i - count];
  }

  for (size_t i = 0; i < count; ++i) {
    _data[insert_pos + i] = value;
    _states[insert_pos + i] = busy;
  }

  _size += count;
}

template<class T>
void TVector<T>::pop_front() {
  if (_size == 0) {
    throw std::logic_error("Delete element in empty vector!");
  }

  for (size_t i = 0; i < _capacity; i++) {
    if (_states[i] == busy) {
      _states[i] = deleted;
      _size--;
      _deleted++;
      reallocate_for_deleted();
      return;
    }
  }
}

template<class T>
void TVector<T>::pop_back() {
  if (_size == 0) {
    throw std::logic_error("Delete element in empty vector!");
  }

  for (size_t i = _size + _deleted - 1; i != static_cast<size_t>(-1); i--) {
    if (_states[i] == busy) {
      _states[i] = deleted;
      _size--;
      _deleted++;
      reallocate_for_deleted();
      return;
    }
  }
}

template<class T>
void TVector<T>::erase(T* first, T* last) {
  if (first < begin() || last > end()) {
    throw std::out_of_range("Pointer is out of Vector bounds!");
  }

  if (last <= first) {
    throw std::invalid_argument("last must be > first");
  }

  size_t first_pos = first - begin();
  size_t last_pos = last - begin();

  erase(first_pos, last_pos);
}

template<class T>
void TVector<T>::erase(size_t pos) {
  if (pos >= _size) {
    throw std::out_of_range("Erasing an index outside the range!");
  }

  size_t erase_pos = real_pos(pos);
  _states[erase_pos] = deleted;

  _size--;
  _deleted++;
  reallocate_for_deleted();
}

template<class T>
void TVector<T>::erase(size_t first, size_t last) {
  if (first >= last || last > _size) {
    throw std::out_of_range("Invalid erase range!");
  }

  size_t real_first = real_pos(first);
  size_t real_last = real_pos(last - 1);

  size_t busy_erased = 0;
  for (size_t i = real_first; i <= real_last; i++) {
    if (_states[i] == busy) {
      _states[i] = deleted;
      busy_erased++;
    }
  }

  _size -= busy_erased;
  _deleted += busy_erased;
  reallocate_for_deleted();
}

template<class T>
void TVector<T>::replace(T* pos, const T& new_value) {
  if (pos < begin() || pos >= end()) {
    throw std::out_of_range("Pointer is out of Vector bounds!");
  }

  size_t replace_pos = real_pos(pos - begin());
  _data[replace_pos] = new_value;
}

template<class T>
void TVector<T>::replace(size_t pos, const T& new_value) {
  if (pos >= _size) {
    throw std::out_of_range("Replacing an index outside the range!");
  }

  size_t replace_pos = real_pos(pos);
  _data[replace_pos] = new_value;
}

template<class T>
void TVector<T>::clear() noexcept {
  for (size_t i = 0; i < _size + _deleted; i++) {
    _states[i] = empty;
  }

  _size = 0;
  _deleted = 0;
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
  if (is_empty()) throw std::out_of_range("Use front() in empty vector!");
  size_t it = real_pos(0);
  return _data[it];
}

template <class T>
inline const T& TVector<T>::back() const {
  if (is_empty()) throw std::out_of_range("Use back() in empty vector!");
  size_t it = real_pos(_size - 1);
  return _data[it];
}

template <class T>
inline const T* TVector<T>::begin() const noexcept {
  T* main_address = real_address(0);
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
  for (size_t i = 0; i < _size + _deleted; i++) {
    if (_states[i] == busy) {
      if (busy_count == pos) {
        return i;
      }
      busy_count++;
    }
  }
  return -1;
}

template<class T>
T* TVector<T>::real_address(size_t pos) {
  size_t busy_count = 0;
  for (size_t i = 0; i < _size + _deleted; i++) {
    if (_states[i] == busy) {
      if (busy_count == pos) {
        return &_data[i];
      }
      busy_count++;
    }
  }
  return nullptr;
}

template<class T>
inline bool TVector<T>::is_full() const noexcept {
  return _size == _capacity;
}

template<class T>
void TVector<T>::reallocate(size_t new_size) {
  if (new_size <= _capacity) return;
  size_t new_capacity = (new_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;

  T* new_data = new T[new_capacity];
  State* new_states = new State[new_capacity];

  for (size_t i = 0; i < new_capacity; i++) {
    new_states[i] = empty;
  }

  if (_size != 0) {
    size_t busy_count = 0;
    for (size_t i = 0; i < _size + _deleted; i++) {
      if (_states[i] == busy) {
        new_data[busy_count] = _data[i];
        new_states[busy_count] = busy;
        busy_count++;
      }
    }
  }

  delete[] _data;
  delete[] _states;

  _data = new_data;
  _states = new_states;
  _capacity = new_capacity;
  _deleted = 0;
}

template<class T>
void TVector<T>::reallocate_for_deleted() {
  constexpr double DELETED_THRESHOLD = 0.15;
  constexpr size_t MAX_DELETED_COUNT = 1000;

  if (_size + _deleted == 0) {
    return;
  }

  if (_size == 0) {
    size_t new_capacity = (_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    T* new_data = new T[new_capacity];
    State* new_states = new State[new_capacity];

    for (size_t i = 0; i < new_capacity; i++) {
      new_states[i] = empty;
    }

    delete[] _data;
    delete[] _states;

    _data = new_data;
    _states = new_states;
    _capacity = new_capacity;
    _deleted = 0;
  }

  if (_deleted >= DELETED_THRESHOLD * (_size + _deleted)
    || _deleted >= MAX_DELETED_COUNT) {
    size_t new_capacity = (_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    T* new_data = new T[new_capacity];
    State* new_states = new State[new_capacity];

    for (size_t i = 0; i < new_capacity; i++) {
      new_states[i] = empty;
    }

    size_t busy_count = 0;
    for (size_t i = 0; i < _size + _deleted; i++) {
      if (_states[i] == busy) {
        new_data[busy_count] = _data[i];
        new_states[busy_count] = busy;
        busy_count++;
      }
    }

    delete[] _data;
    delete[] _states;

    _data = new_data;
    _states = new_states;
    _capacity = new_capacity;
    _deleted = 0;
  }
}

#endif  // ONLINE_GAME_STORE_PROJECT_TVECTOR_MY_VECTOR_H_
