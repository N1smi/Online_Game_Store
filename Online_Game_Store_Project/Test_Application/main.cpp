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

bool test_29_check_pop_back_wuth_push_back() {
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
 /*   print_vect(vec_1);
    print_stat(vec_1);
    std::cout << vec_1.size() << std::endl;*/

    bool result = (TestSystem::check((size_t)17, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(3, vec_1[1])) && (TestSystem::check(18, vec_1.back()));
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
    TestSystem::start_test(test_29_check_pop_back_wuth_push_back, " TVector.test_29_check_pop_back_wuth_push_back");
    TestSystem::start_test(test_30_check_pop_back_with_insert, " TVector.test_30_check_pop_back_with_insert");
    TestSystem::start_test(test_31_check_erase, " TVector.test_31_check_erase");

    TestSystem::print_final_info();
    system("pause");
    return 0;
}
