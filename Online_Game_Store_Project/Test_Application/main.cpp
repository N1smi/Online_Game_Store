// Copyright 2025 Smirnov Nikita

#include <iostream>
#include <windows.h>
#include "my_vector.h"
#include "User.h"
#include "Administrator.h"
#include "Client.h"
#include "Game.h"
#include "Feedback.h"
#include "Gamestore.h"

void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}

namespace TestSystem {
    int count_success = 0, count_failed = 0;

    void start_test(bool(*test)(), const char* name_of_test) {
        set_color(2, 0);
        std::cout << "[ RUN      ]";
        set_color(7, 0);
        std::cout << name_of_test << std::endl;

        bool status = test();

        if (status == true) {
            set_color(2, 0);
            std::cout << "[       OK ]" << std::endl;
            count_success++;
        }
        else {
            set_color(4, 0);
            std::cout << "[  FAILED  ]" << std::endl;
            count_failed++;
        }
        set_color(7, 0);
    }

    template <class T>
    bool check(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        else {
            std::cerr << "Expected result is " << expected << ", but actual is " << actual << "." << std::endl;
            return false;
        }
    }

    void print_init_info() {
        set_color(2, 0);
        std::cout << "[==========] " << std::endl;
        set_color(7, 0);
    }

    void print_final_info() {
        set_color(2, 0);
        std::cout << "[==========] ";
        set_color(7, 0);
        std::cout << count_success + count_failed << " test" << (count_success + count_failed > 1 ? "s" : "") << " ran." << std::endl;
        set_color(2, 0);
        std::cout << "[  PASSED  ] ";
        set_color(7, 0);
        std::cout << count_success << " test" << (count_success > 1 ? "s" : "") << std::endl;
        if (count_failed > 0) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] ";
            set_color(7, 0);
            std::cout << count_failed << " test" << (count_failed > 1 ? "s." : ".") << std::endl;
        }
    }
};

template < class T>
void print_vect(TVector<T> vec_1) {
    for (size_t i = 0; i < vec_1.size(); i++) {
        std::cout << vec_1[i] <<" ";
    }
    std::cout << std::endl;
}

template < class T>
void print_stat(TVector<T> vec_1) {
    for (size_t i = 0; i < vec_1.capacity(); i++) {
        if (vec_1.states()[i] == 0) {
            std::cout << "E ";
        }
        if (vec_1.states()[i] == 1) {
            std::cout << "B ";
        }
        if (vec_1.states()[i] == 2) {
            std::cout << "D ";
        }
    }
    std::cout << std::endl;
}

bool test_1_check_create_default_vector() {
    TVector<int> vec_1;

    bool result = (TestSystem::check((size_t)0, vec_1.size())) && (TestSystem::check((size_t)0, vec_1.capacity()))
        && (TestSystem::check((int*)nullptr, vec_1.data()));

    return result;
}

bool test_2_check_create_vector_with_initialization() {
    TVector<char> vec_1(3);
     //print_vect(vec_1);
     //print_stat(vec_1);
    bool result = (TestSystem::check((size_t)3, vec_1.size())) && (TestSystem::check((size_t)3, vec_1.capacity())) &&
        (TestSystem::check('\0', vec_1[0])) && (TestSystem::check('\0', vec_1[1])) &&
        (TestSystem::check('\0', vec_1[2]));
    return result;
}

bool test_3_check_create_vector_with_initialization_list() {
    TVector<float> vec_1({ 1.0f, 0.0f, 2.356f });
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check((size_t)3, vec_1.size())) && (TestSystem::check((size_t)3, vec_1.capacity())) &&
        (TestSystem::check(1.0f, vec_1[0])) && (TestSystem::check(0.0f, vec_1[1])) &&
        (TestSystem::check(2.356f, vec_1[2]));
    return result;
}

bool test_4_check_check_create_vector_with_copy() {
    TVector<int> vec_1({ -1, 2, 3 });
    TVector<int> vec_2(vec_1);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check(vec_1.size(), vec_2.size())) && (TestSystem::check(vec_1.capacity(), vec_2.capacity())) &&
        (TestSystem::check(vec_1[0], vec_2[0])) && (TestSystem::check(vec_1[1], vec_2[1])) &&
        (TestSystem::check(vec_1[2], vec_2[2]));
    return result;
}

bool test_5_throw_when_try_applying_for_position_abroad() {
    TVector<double> vec_1(100);
    bool expected_result = false;
    bool actual_result = true;
    try {
        //print_vect(vec_1);
        //print_stat(vec_1);
        double error = vec_1[100];
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_6_check_is_empty() {
    TVector<char> vec_1;
    bool expected_result = true;
    bool actual_result = vec_1.is_empty();

    return TestSystem::check(expected_result, actual_result);
}

bool test_7_check_front_back_begin_end() {
    TVector<int> vec_1({ 1000,2,456,777 });
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check(1000, vec_1.front())) && (TestSystem::check(777, vec_1.back())) && 
        (TestSystem::check(1000, *vec_1.begin())) && (TestSystem::check(777, *(vec_1.end() - 1)));
    return result;
}

bool test_8_throw_when_try_use_front_in_empty_vector() {
    TVector<double> vec_1;
    bool expected_result = false;
    bool actual_result = true;
    try {
        double error = vec_1.front();
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_9_throw_when_try_use_back_in_empty_vector() {
    TVector<double> vec_1;
    bool expected_result = false;
    bool actual_result = true;
    try {
        double error = vec_1.back();
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_10_check_begin_and_end_in_empty_vector() {
    TVector<int> vec_1;
    bool expected_result = true;
    bool actual_result = true;

    if (vec_1.begin() != nullptr || vec_1.end() != nullptr) {
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_11_check_push_front() {
    TVector<char> vec_1({ '$','2','3' });
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.push_front('5');
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check((size_t)4, vec_1.size())) && (TestSystem::check((size_t)15, vec_1.capacity())) &&
        (TestSystem::check('5', vec_1.front())) && (TestSystem::check('3', vec_1.back())) &&
        (TestSystem::check('$', vec_1[1])) && (TestSystem::check('2',vec_1[2]));
    return result;
}

bool test_12_check_push_front_in_empty_vector() {
    TVector<int> vec_1({});
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.push_front(2000);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check((size_t)1, vec_1.size())) && (TestSystem::check((size_t)15, vec_1.capacity())) &&
        (TestSystem::check(2000, vec_1.front())) && (TestSystem::check(2000, vec_1.back()));
    return result;
}

bool test_13_check_push_back() {
    TVector<int> vec_1({ 1, 2, 3 });
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.push_back(4);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check((size_t)4, vec_1.size())) && (TestSystem::check((size_t)15, vec_1.capacity())) &&
        (TestSystem::check(1, vec_1.front())) && (TestSystem::check(4, vec_1.back())) &&
        (TestSystem::check(2, vec_1[1])) && (TestSystem::check(3, vec_1[2]));
    return result;
}

bool test_14_check_push_back_in_empty_vector() {
    TVector<float> vec_1;
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.push_back(2.7f);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check((size_t)1, vec_1.size())) && (TestSystem::check((size_t)15, vec_1.capacity())) &&
        (TestSystem::check(2.7f, vec_1.front())) && (TestSystem::check(2.7f, vec_1.back()));
    return result;
}

bool test_15_check_several_push() {
    TVector<int> vec_1(15);
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.push_back(3);
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.push_front(2);
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.push_back(9);
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.push_front(5);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check((size_t)19, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(5, vec_1.front())) && (TestSystem::check(9, vec_1.back()));
    return result;
}

bool test_16_check_insert() {
    TVector<int> vec_1({ 1, 2, 3, 10 });
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.insert(3, 111);
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.insert(4, 222);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check((size_t)6, vec_1.size())) && (TestSystem::check((size_t)15, vec_1.capacity())) &&
        (TestSystem::check(111, vec_1[3])) && (TestSystem::check(222, vec_1[4]));
    return result;
}

bool test_17_throw_when_insert_in_non_existent_position() {
    TVector<int> vec_1({ 1, 4 , 10 });
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec_1.insert(5, 10);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_18_check_insert_in_empty_vector() {
    TVector<int> vec_1;
    vec_1.insert(22, 42);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check((size_t)1, vec_1.size())) && (TestSystem::check((size_t)15, vec_1.capacity())) &&
        (TestSystem::check(42, vec_1[0]));
    return result;
}

bool test_19_check_pop_front() {
    TVector<int> vec_1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
        16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 });
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.pop_front();
    //print_vect(vec_1);
    //print_stat(vec_1);
    for (size_t i = 0; i < 4; i++) {
        vec_1.pop_front();
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    bool result = (TestSystem::check((size_t)25, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(6, vec_1[0]));
    return result;
}

bool test_20_check_pop_front_whith_push_front() {
    TVector<int> vec_1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
    16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 });
    //print_vect(vec_1);
    //print_stat(vec_1);
    for (size_t i = 0; i < 2; i++) {
        vec_1.pop_front();
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    for (size_t i = 0; i < 3; i++) {
        vec_1.push_front(999);
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    for (size_t i = 0; i < 2; i++) {
        vec_1.pop_front();
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    for (size_t i = 0; i < 2; i++) {
        vec_1.push_front(1001 + i);
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    bool result = (TestSystem::check((size_t)31, vec_1.size())) && (TestSystem::check((size_t)45, vec_1.capacity())) &&
        (TestSystem::check(1002, vec_1[0]));
    return result;
}

bool test_21_check_pop_front_whith_push_back() {
    TVector<int> vec_1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
    16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 });
    //print_vect(vec_1);
    //print_stat(vec_1);
    for (size_t i = 0; i < 2; i++) {
        vec_1.pop_front();
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    for (size_t i = 0; i < 1; i++) {
        vec_1.push_back(111 + i);
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    for (size_t i = 0; i < 2; i++) {
        vec_1.pop_front();
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    for (size_t i = 0; i < 2; i++) {
        vec_1.push_back(112 + i);
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    bool result = (TestSystem::check((size_t)29, vec_1.size())) && (TestSystem::check((size_t)45, vec_1.capacity())) &&
        (TestSystem::check(113, vec_1[28]));
    return result;
}

bool test_22_check_pop_front_whith_insert() {
    TVector<int> vec_1(15);
    //print_vect(vec_1);
    //print_stat(vec_1);
    for (size_t i = 0; i < 1; i++) {
        vec_1.push_front(111);
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }

    for (size_t i = 0; i < 2; i++) {
        vec_1.pop_front();
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    vec_1.insert(0, 111);
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.insert(7, 222);
    //print_vect(vec_1);
    //print_stat(vec_1);

    bool result = (TestSystem::check((size_t)16, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
      (TestSystem::check(111, vec_1[0])) && (TestSystem::check(222, vec_1[7]));;
    return result; print_vect(vec_1);
  
}

bool test_23_throw_when_pop_front_in_empty_vector() {
    TVector<int> vec_1;
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec_1.pop_front();
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_24_check_pop_back() {
    TVector<int> vec_1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
       16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 });
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.pop_back();
    //print_vect(vec_1);
    //print_stat(vec_1);
    for (size_t i = 0; i < 5; i++) {
        vec_1.pop_back();
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    bool result = (TestSystem::check((size_t)24, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(24, vec_1.back()));
    return result;
}

bool test_25_throw_when_pop_back_in_empty_vector() {
    TVector<int> vec_1;
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec_1.pop_back();
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_26_check_pop_back_with_pop_front() {
    TVector<int> vec_1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
   16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 });
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.pop_front();
    //print_vect(vec_1);
    //print_stat(vec_1);
    for (size_t i = 0; i < 6; i++) {
        vec_1.pop_back();
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    for (size_t i = 0; i < 5; i++) {
        vec_1.pop_front();
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    bool result = (TestSystem::check((size_t)18, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(24, vec_1.back())) && (TestSystem::check(7, vec_1.front()));
    return result;
}

bool test_27_delete_all_and_check_push_and_insert() {
    TVector<int> vec_1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 });
    for (size_t i = 0; i < 30; i++) {
        vec_1.pop_back();
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    vec_1.push_back(111);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool first_check = false;
    if (vec_1[0] == 111) {
        first_check = true;
    }
    vec_1.pop_back();
    //print_vect(vec_1);
    //print_stat(vec_1);

    vec_1.push_front(222);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool second_check = false;
    if (vec_1[0] == 222) {
        second_check = true;
    }
    vec_1.pop_back();
    //print_vect(vec_1);
    //print_stat(vec_1);

    vec_1.insert(2,333);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool third_check = false;
    if (vec_1[0] == 333) {
        third_check = true;
    }
    vec_1.pop_back();
    //print_vect(vec_1);
    //print_stat(vec_1);

    bool result = false;
    if (first_check && second_check && third_check) {
        result = true;
    }
    return result;
}

bool test_28_check_pop_back_with_push_front() {
    TVector<int> vec_1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
      16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 });
    //print_vect(vec_1);
    //print_stat(vec_1);
    for (size_t i = 0; i < 2; i++) {
        vec_1.pop_back();
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    for (size_t i = 0; i < 3; i++) {
        vec_1.push_front(999);
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    for (size_t i = 0; i < 2; i++) {
        vec_1.pop_back();
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    for (size_t i = 0; i < 2; i++) {
        vec_1.push_front(1001 + i);
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    bool result = (TestSystem::check((size_t)31, vec_1.size())) && (TestSystem::check((size_t)45, vec_1.capacity())) &&
        (TestSystem::check(1002, vec_1[0])) && (TestSystem::check(26, vec_1.back()));
    return result;
}

bool test_29_check_pop_back_with_push_back() {
    TVector<int> vec_1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 });
    //print_vect(vec_1);
    //print_stat(vec_1);
    for (size_t i = 0; i < 2; i++) {
        vec_1.pop_back();
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    for (size_t i = 0; i < 1; i++) {
        vec_1.push_back(111 + i);
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    for (size_t i = 0; i < 2; i++) {
        vec_1.pop_back();
        //print_vect(vec_1);
        //print_stat(vec_1);
    }
    for (size_t i = 0; i < 2; i++) {
        vec_1.push_back(112 + i);
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    bool result = (TestSystem::check((size_t)29, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(112, vec_1[27])) && (TestSystem::check(113, vec_1[28]));;
    return result;

}

bool test_30_check_pop_back_with_insert() {
    TVector<int> vec_1(15);
    //print_vect(vec_1);
    //print_stat(vec_1);
    for (size_t i = 0; i < 1; i++) {
        vec_1.push_front(111);
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }

    for (size_t i = 0; i < 2; i++) {
        vec_1.pop_back();
        //print_vect(vec_1);
        //print_stat(vec_1);
        //std::cout << vec_1.size() << std::endl;
    }
    vec_1.insert(14, 111);
    //print_vect(vec_1);
    //print_stat(vec_1);
    vec_1.insert(13, 222);
    //print_vect(vec_1);
    //print_stat(vec_1);

    bool result = (TestSystem::check((size_t)16, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(111, vec_1[15])) && (TestSystem::check(222, vec_1[13]));;
    return result;
}

bool test_31_check_erase() {
    TVector<int> vec_1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 });
    vec_1.push_front(111);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;
    vec_1.pop_front();
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;
    vec_1.pop_back();
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;
    vec_1.erase(18);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;
    vec_1.erase(1);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    bool result = (TestSystem::check((size_t)17, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(3, vec_1[1])) && (TestSystem::check(18, vec_1.back()));
    return result;

}

bool test_32_throw_when_erase_in_empty_vector() {
    TVector<int> vec_1;
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec_1.erase(5);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_33_throw_when_erase_for_a_non_existent_position() {
    TVector<int> vec_1(10);
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec_1.erase(10);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);

}

bool test_34_check_several_push_insert_and_erase() {
    TVector<int> vec_1;
    for (size_t i = 0; i < 50; i++) {
        vec_1.insert(i, i + 1);
   }
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    for (size_t i = 0; i < 3; i++) {
        vec_1.erase(0);
    }
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    for (size_t i = 0; i < 3; i++) {
        vec_1.push_front(0);
    }
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    for (size_t i = 0; i < 3; i++) {
        vec_1.erase(24);
    }
    vec_1.erase(46);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.push_back(999);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.insert(24,1111);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    bool result = (TestSystem::check((size_t)48, vec_1.size())) && (TestSystem::check((size_t)60, vec_1.capacity())) &&
        (TestSystem::check(0, vec_1[0])) && (TestSystem::check(1111, vec_1[24])) && (TestSystem::check(999, vec_1.back()));
    return result;
}

bool test_35_check_insert_whith_count_in_empty_vector() {
    TVector<int> vec_1;
    vec_1.insert(150, 50, 1);
    //print_vect(vec_1);
    //print_stat(vec_1);
    bool result = (TestSystem::check((size_t)50, vec_1.size())) && (TestSystem::check((size_t)60, vec_1.capacity())) &&
        (TestSystem::check(1, vec_1[0])) && (TestSystem::check(1, vec_1[49]));
    return result;
}

bool test_36_check_insert_whith_count_and_deleted() {
    TVector<int> vec_1;
    vec_1.insert(0, 50, 1);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    for (size_t i = 0; i < 3; i++) {
        vec_1.erase(1);
    }
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.insert(1, 2, 3);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    bool result = (TestSystem::check((size_t)49, vec_1.size())) && (TestSystem::check((size_t)60, vec_1.capacity())) &&
        (TestSystem::check(3, vec_1[1])) && (TestSystem::check(3, vec_1[2]));
    return result;
}

bool test_37_check_insert_whith_count_whithout_deleted() {
    TVector<int> vec_1;
    vec_1.insert(0, 50, 2);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.insert(25, 3 , 5);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    bool result = (TestSystem::check((size_t)53, vec_1.size())) && (TestSystem::check((size_t)60, vec_1.capacity())) &&
        (TestSystem::check(5, vec_1[25])) && (TestSystem::check(5, vec_1[26])) && (TestSystem::check(5, vec_1[27]));
    return result;
}

bool test_38_check_insert_whith_zero_count() {
    TVector<int> vec_1(90);
    vec_1.insert(2, 0, 2);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    bool result = (TestSystem::check((size_t)90, vec_1.size())) && (TestSystem::check((size_t)90, vec_1.capacity())) &&
        (TestSystem::check(0, vec_1[2])) && (TestSystem::check(0, vec_1[2]));
    return result;
}

bool test_39_throw_when_insert_whith_count_in_non_existent_position() {
    TVector<int> vec_1({ 1, 4 , 10 });
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec_1.insert(4, 10, 10);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_40_throw_when_erase_with_range_in_empty_vector() {
    TVector<int> vec_1;
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec_1.erase(5, 9);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_41_throw_when_erase_with_incorrect_range() {
    TVector<int> vec_1(90);
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec_1.erase(5, 91);
        //vec_1.erase(5, 5);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_42_check_erase_whith_range_without_deleted() {
    TVector<int> vec_1;
    for (size_t i = 0; i < 50; i++) {
        vec_1.insert(i, i + 1);
    }
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;
    vec_1.erase(1, 6);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    bool result = (TestSystem::check((size_t)45, vec_1.size())) && (TestSystem::check((size_t)60, vec_1.capacity())) &&
        (TestSystem::check(7, vec_1[1])) && (TestSystem::check(8, vec_1[2]));
    return result;
}

bool test_43_check_erase_whith_range_and_deleted() {
    TVector<int> vec_1;
    for (size_t i = 0; i < 50; i++) {
        vec_1.insert(i, i + 1);
    }
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.pop_front();
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.erase(0, 6);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;


    bool result = (TestSystem::check((size_t)43, vec_1.size())) && (TestSystem::check((size_t)60, vec_1.capacity())) &&
        (TestSystem::check(8, vec_1[0])) && (TestSystem::check(9, vec_1[1])) && (TestSystem::check(50, vec_1.back()));
    return result;
}

bool test_44_check_erase_whith_pointers() {
    TVector<int> vec_1;
    for (size_t i = 0; i < 50; i++) {
        vec_1.insert(i, i + 1);
    }
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.erase(vec_1.begin() + 1, vec_1.begin() + 8);

    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    bool result = (TestSystem::check((size_t)43, vec_1.size())) && (TestSystem::check((size_t)60, vec_1.capacity())) &&
        (TestSystem::check(1, vec_1[0])) && (TestSystem::check(9, vec_1[1])) && (TestSystem::check(50, vec_1.back()));
    return result;
}

bool test_45_check_erase_whith_pointers_and_deleted() {
    TVector<int> vec_1;
    for (size_t i = 0; i < 50; i++) {
        vec_1.insert(i, i + 1);
    }
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;


    vec_1.pop_front();
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.erase(vec_1.begin() + 1, vec_1.begin() + 7);

    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    bool result = (TestSystem::check((size_t)43, vec_1.size())) && (TestSystem::check((size_t)60, vec_1.capacity())) &&
        (TestSystem::check(2, vec_1[0])) && (TestSystem::check(9, vec_1[1])) && (TestSystem::check(50, vec_1.back()));
    return result;
}

bool test_46_throw_when_replace_for_non_existent_position() {
    TVector<int> vec_1(10);
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec_1.replace(10,100);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_47_throw_when_replace_in_empty_vector() {
    TVector<int> vec_1;
    bool expected_result = false;
    bool actual_result = true;
    try {
        vec_1.replace((size_t)0, 100);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_48_check_replace() {
    TVector<int> vec_1;
    for (size_t i = 0; i < 30; i++) {
        vec_1.insert(i, i + 1);
    }
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.replace(5, 999);
    //print_vect(vec_1);
    //print_stat(vec_1);

    vec_1.pop_front();
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.replace(10, 1000);
    //print_vect(vec_1);
    //print_stat(vec_1);

    bool result = (TestSystem::check((size_t)29, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(999, vec_1[4])) && (TestSystem::check(1000, vec_1[10]));
    return result;
}

bool test_49_throw_when_erase_with_pointers_out_of_range_error() {
    TVector<int> vec_1(30);
    for (int i = 0; i < 30; i++) vec_1[i] = i;

    bool expected_result = false;
    bool actual_result = true;

    try {
        int* invalid_ptr = vec_1.begin() + 30;
        vec_1.erase(invalid_ptr, invalid_ptr + 1);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test_50_throw_when_erase_with_pointers_invalid_range_error() {
    TVector<int> vec(30);

    bool expected_result = false;
    bool actual_result = true;

    try {
        int* first = vec.begin() + 15;
        int* last = vec.begin() + 10;
        vec.erase(first, last);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test_51_throw_when_erase_with_pointers_empty_range() {
    TVector<int> vec(30);

    bool expected_result = false;
    bool actual_result = true;

    try {
        int* p = vec.begin() + 10;
        vec.erase(p, p);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test_52_check_replace_with_pointers() {
    TVector<int> vec_1;
    for (size_t i = 0; i < 30; i++) {
        vec_1.insert(i, i + 1);
    }
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.replace(vec_1.begin() + 5, 42);
    //print_vect(vec_1);
    //print_stat(vec_1);

    vec_1.pop_front();
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    vec_1.replace(vec_1.begin() + 10, 142);
    //print_vect(vec_1);
    //print_stat(vec_1);

    bool result = (TestSystem::check((size_t)29, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(42, vec_1[4])) && (TestSystem::check(142, vec_1[10]));
    return result;

}

bool test_53_throw_when_replace_with_pointers_nullptr() {
    TVector<int> vec(5);
    bool expected_result = false;
    bool actual_result = true;

    try {
        vec.replace(nullptr, 123);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test_54_throw_when_replace_with_pointers_out_of_range_left() {
    TVector<int> vec(5);
    bool expected_result = false;
    bool actual_result = true;

    try {
        int* invalid_pos = vec.begin() - 1;
        vec.replace(invalid_pos, 100);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test_55_throw_when_replace_with_pointers_out_of_range_right() {
    TVector<int> vec(10);
    bool expected_result = false;
    bool actual_result = true;

    try {
        int* invalid_pos = vec.begin() + 15;
        vec.replace(invalid_pos, 100);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        std::cout << std::endl;
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test_56_check_clear() {
    TVector<int> vec_1(100);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;
    vec_1.push_back(101);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;
    vec_1.erase(0, 10);
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;
    vec_1.clear();
    //print_vect(vec_1);
    //print_stat(vec_1);
    //std::cout << vec_1.size() << std::endl;

    bool result = (TestSystem::check((size_t)0, vec_1.size())) && (TestSystem::check((size_t)105, vec_1.capacity()))
        && (TestSystem::check(vec_1.is_empty(), true));
    return result;

}

int main() {
    User user_1;
    Client client_1;
    Administrator administartor_1;
    Game game_1;
    Feedback feedback_1;
    GameStore gamestore_1;

    TestSystem::start_test(test_1_check_create_default_vector, " TVector.test_1_check_create_default_vector");
    TestSystem::start_test(test_2_check_create_vector_with_initialization, " TVector.test_2_check_create_vector_with_initialization");
    TestSystem::start_test(test_3_check_create_vector_with_initialization_list," TVector.test_3_check_create_vector_with_initialization_list");
    TestSystem::start_test(test_4_check_check_create_vector_with_copy, " TVector.test_4_check_check_create_vector_with_copy");
    TestSystem::start_test(test_5_throw_when_try_applying_for_position_abroad, " TVector.test_5_throw_when_try_applying_for_position_abroad");
    TestSystem::start_test(test_6_check_is_empty, " TVector.test_6_check_is_empty");
    TestSystem::start_test(test_7_check_front_back_begin_end, " TVector.test_7_check_front_back_begin_end");
    TestSystem::start_test(test_8_throw_when_try_use_front_in_empty_vector, " TVector.test_8_throw_when_try_use_front_in_empty_vector");
    TestSystem::start_test(test_9_throw_when_try_use_back_in_empty_vector, " TVector.test_9_throw_when_try_use_back_in_empty_vector");
    TestSystem::start_test(test_10_check_begin_and_end_in_empty_vector, " TVector.test_10_check_begin_and_end_in_empty_vector");
    TestSystem::start_test(test_11_check_push_front," TVector.test_11_check_push_front");
    TestSystem::start_test(test_12_check_push_front_in_empty_vector, " TVector.test_12_check_push_front_in_empty_vector");
    TestSystem::start_test(test_13_check_push_back, " TVector.test_13_check_push_back");
    TestSystem::start_test(test_14_check_push_back_in_empty_vector, " TVector.test_14_check_push_back_in_empty_vector");
    TestSystem::start_test(test_15_check_several_push, " TVector.test_15_check_several_push");
    TestSystem::start_test(test_16_check_insert, " TVector.test_16_check_insert");
    TestSystem::start_test(test_17_throw_when_insert_in_non_existent_position, " TVector.test_17_throw_when_insert_in_non_existent_position");
    TestSystem::start_test(test_18_check_insert_in_empty_vector, " TVector.test_18_check_insert_in_empty_vector");
    TestSystem::start_test(test_19_check_pop_front, " TVector.test_19_check_pop_front");
    TestSystem::start_test(test_20_check_pop_front_whith_push_front, " TVector.test_20_check_pop_front_whith_push_front");
    TestSystem::start_test(test_21_check_pop_front_whith_push_back, " TVector.test_21_check_pop_front_whith_push_back");
    TestSystem::start_test(test_22_check_pop_front_whith_insert, " TVector.test_22_check_pop_front_whith_insert");
    TestSystem::start_test(test_23_throw_when_pop_front_in_empty_vector, " TVector.test_23_throw_when_pop_front_in_empty_vector");
    TestSystem::start_test(test_24_check_pop_back, " TVector.test_24_check_pop_back");
    TestSystem::start_test(test_25_throw_when_pop_back_in_empty_vector, " TVector.test_25_throw_when_pop_back_in_empty_vector");
    TestSystem::start_test(test_26_check_pop_back_with_pop_front, " TVector.test_26_check_pop_back_with_pop_front");
    TestSystem::start_test(test_27_delete_all_and_check_push_and_insert, " TVector.test_27_delete_all_and_check_push_and_insert");
    TestSystem::start_test(test_28_check_pop_back_with_push_front, " TVector.test_28_check_pop_back_with_push_front");
    TestSystem::start_test(test_29_check_pop_back_with_push_back, " TVector.test_29_check_pop_back_with_push_back");
    TestSystem::start_test(test_30_check_pop_back_with_insert, " TVector.test_30_check_pop_back_with_insert");
    TestSystem::start_test(test_31_check_erase, " TVector.test_31_check_erase");
    TestSystem::start_test(test_32_throw_when_erase_in_empty_vector, " TVector.test_32_throw_when_erase_in_empty_vector");
    TestSystem::start_test(test_33_throw_when_erase_for_a_non_existent_position, " TVector.test_33_throw_when_erase_for_a_non_existent_position");
    TestSystem::start_test(test_34_check_several_push_insert_and_erase, " TVector.test_34_check_several_push_insert_and_erase");
    TestSystem::start_test(test_35_check_insert_whith_count_in_empty_vector, " TVector.test_35_check_insert_whith_count_in_empty_vector");
    TestSystem::start_test(test_36_check_insert_whith_count_and_deleted, " TVector.test_36_check_insert_whith_count_and_deleted");
    TestSystem::start_test(test_37_check_insert_whith_count_whithout_deleted, " TVector.test_37_check_insert_whith_count_whithout_deleted");
    TestSystem::start_test(test_38_check_insert_whith_zero_count, " TVector.test_38_check_insert_whith_zero_count");
    TestSystem::start_test(test_39_throw_when_insert_whith_count_in_non_existent_position, 
        " TVector.test_39_throw_when_insert_whith_count_in_non_existent_position");
    TestSystem::start_test(test_40_throw_when_erase_with_range_in_empty_vector,
        " TVector.test_40_throw_when_erase_with_range_in_empty_vector");
    TestSystem::start_test(test_41_throw_when_erase_with_incorrect_range,
        " TVector.test_41_throw_when_erase_with_incorrect_range");
    TestSystem::start_test(test_42_check_erase_whith_range_without_deleted,
        " TVector.test_42_check_erase_whith_range_without_deleted");
    TestSystem::start_test(test_43_check_erase_whith_range_and_deleted,
        " TVector.test_43_check_erase_whith_range_and_deleted");
    TestSystem::start_test(test_44_check_erase_whith_pointers, " TVector.test_44_check_erase_whith_pointers");
    TestSystem::start_test(test_45_check_erase_whith_pointers_and_deleted, " TVector.test_45_check_erase_whith_pointers_and_deleted");
    TestSystem::start_test(test_46_throw_when_replace_for_non_existent_position, " TVector.test_46_throw_when_replace_for_non_existent_position");
    TestSystem::start_test(test_47_throw_when_replace_in_empty_vector, " TVector.test_47_throw_when_replace_in_empty_vector");
    TestSystem::start_test(test_48_check_replace, " TVector.test_48_check_replace");
    TestSystem::start_test(test_49_throw_when_erase_with_pointers_out_of_range_error,
        " TVector.test_49_throw_when_erase_with_pointers_out_of_range_error");
    TestSystem::start_test(test_50_throw_when_erase_with_pointers_invalid_range_error,
        " TVector.test_50_throw_when_erase_with_pointers_invalid_range_error");
    TestSystem::start_test(test_51_throw_when_erase_with_pointers_empty_range,
        " TVector.test_51_throw_when_erase_with_pointers_empty_range");
    TestSystem::start_test(test_52_check_replace_with_pointers,
        " TVector.test_52_check_replace_with_pointers");
    TestSystem::start_test(test_53_throw_when_replace_with_pointers_nullptr,
        " TVector.test_53_throw_when_replace_with_pointers_nullptr");
    TestSystem::start_test(test_54_throw_when_replace_with_pointers_out_of_range_left,
        " TVector.test_54_throw_when_replace_with_pointers_out_of_range_left");
    TestSystem::start_test(test_55_throw_when_replace_with_pointers_out_of_range_right,
        " TVector.test_55_throw_when_replace_with_pointers_out_of_range_right");
    TestSystem::start_test(test_56_check_clear, " TVector.test_56_check_clear");
    TestSystem::print_final_info();
    system("pause");
    return 0;
}
