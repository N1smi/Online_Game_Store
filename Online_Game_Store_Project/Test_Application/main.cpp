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
void print(TVector<T> vec_1) {
    for (size_t i = 0; i < vec_1.size(); i++) {
        std::cout << vec_1[i] << std::endl;
    }
}

bool test_1_try_create_default_vector() {
    bool expected_result = true;
    bool actual_result = true;
    try {
        TVector<Client> vec_1();
    }
    catch (const std::exception& ex) {
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_2_try_create_vector_with_initialization() {
    bool expected_result = true;
    bool actual_result = true;
    try {
        TVector<int> vec_1(5);
    }
    catch (const std::exception& ex) {
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_3_check_basic_values_in_initialization() {
    size_t test_size = 3;
    const char basic = '\0';
    TVector<char> vec_1(test_size);
    bool result = (TestSystem::check(test_size, vec_1.size())) && (TestSystem::check(test_size, vec_1.capacity())) &&
        (TestSystem::check(basic, vec_1[0])) && (TestSystem::check(basic, vec_1[1])) && 
        (TestSystem::check(basic, vec_1[2]));
    return result;
}

bool test_4_throw_when_try_applying_for_position_abroad() {
    TVector<double> vec_1(100);
    bool expected_result = false;
    bool actual_result = true;
    try {
        double error = vec_1[100];
    }
    catch (const std::exception& ex) {
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_5_try_create_vector_with_initialization_list() {
    bool expected_result = true;
    bool actual_result = true;
    try {
        TVector<float> vec_1({ 1.0f, 0.0f, 2.356f });
        TVector<char> vec_2({});
    }
    catch (const std::exception& ex) {
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_6_check_values_in_initialization_list() {
    size_t test_size = 3;
    const char value_1 = '5';
    const char value_2 = '\0';
    const char value_3 = '$';
    TVector<char> vec_1({'5', '\0', '$'});
    bool result = (TestSystem::check(test_size, vec_1.size())) && (TestSystem::check(test_size, vec_1.capacity())) &&
        (TestSystem::check(value_1, vec_1[0])) && (TestSystem::check(value_2, vec_1[1])) &&
        (TestSystem::check(value_3, vec_1[2]));
    return result;
}

bool test_7_try_create_vector_with_copy() {
    bool expected_result = true;
    bool actual_result = true;
    TVector<int> vec_1(5);
    try {
        TVector<int> vec_2(vec_1);
    }
    catch (const std::exception& ex) {
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_8_check_values_in_copy() {
    TVector<int> vec_1({ -1, 2, 3 });
    TVector<int> vec_2(vec_1);
    bool result = (TestSystem::check(vec_1.size(), vec_2.size())) && (TestSystem::check(vec_1.capacity(), vec_2.capacity())) &&
        (TestSystem::check(vec_1[0], vec_2[0])) && (TestSystem::check(vec_1[1], vec_2[1])) &&
        (TestSystem::check(vec_1[2], vec_2[2]));
    return result;
}

bool test_9_check_is_empty() {
    TVector<char> vec_1;
    bool expected_result = true;
    bool actual_result = vec_1.is_empty();

    return TestSystem::check(expected_result, actual_result);
}

bool test_10_check_front_back_begin_end() {
    TVector<int> vec_1({ 1000,2,456,777 });
    bool result = (TestSystem::check(1000, vec_1.front())) && (TestSystem::check(777, vec_1.back())) && 
        (TestSystem::check(1000, *vec_1.begin())) && (TestSystem::check(777, *(vec_1.end() - 1)));
    return result;
}

bool test_11_throw_when_try_use_front_in_empty_vector() {
    TVector<double> vec_1;
    bool expected_result = false;
    bool actual_result = true;
    try {
        double error = vec_1.front();
    }
    catch (const std::exception& ex) {
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_12_throw_when_try_use_back_in_empty_vector() {
    TVector<double> vec_1;
    bool expected_result = false;
    bool actual_result = true;
    try {
        double error = vec_1.back();
    }
    catch (const std::exception& ex) {
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_13_check_begin_and_end_in_empty_vector() {
    TVector<int> vec_1;
    bool expected_result = true;
    bool actual_result = true;

    if (vec_1.begin() != nullptr || vec_1.end() != nullptr) {
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_14_check_push_front() {
    TVector<char> vec_1({ '$','2','3' });
    vec_1.push_front('5');
    bool result = (TestSystem::check((size_t)4, vec_1.size())) && (TestSystem::check((size_t)15, vec_1.capacity())) &&
        (TestSystem::check('5', vec_1.front())) && (TestSystem::check('3', vec_1.back())) &&
        (TestSystem::check('$', vec_1[1])) && (TestSystem::check('2',vec_1[2]));
    return result;
}

bool test_15_check_push_front_in_empty_vector() {
    TVector<int> vec_1({});
    vec_1.push_front(2000);
    bool result = (TestSystem::check((size_t)1, vec_1.size())) && (TestSystem::check((size_t)15, vec_1.capacity())) &&
        (TestSystem::check(2000, vec_1.front())) && (TestSystem::check(2000, vec_1.back()));
    return result;
}

bool test_16_check_push_back() {
    TVector<int> vec_1({ 1, 2, 300 });
    vec_1.push_back(4000);
    bool result = (TestSystem::check((size_t)4, vec_1.size())) && (TestSystem::check((size_t)15, vec_1.capacity())) &&
        (TestSystem::check(1, vec_1.front())) && (TestSystem::check(4000, vec_1.back())) &&
        (TestSystem::check(2, vec_1[1])) && (TestSystem::check(300, vec_1[2]));
    return result;
}

bool test_17_check_push_back_in_empty_vector() {
    TVector<float> vec_1;
    vec_1.push_back(2.0f);
    bool result = (TestSystem::check((size_t)1, vec_1.size())) && (TestSystem::check((size_t)15, vec_1.capacity())) &&
        (TestSystem::check(2.0f, vec_1.front())) && (TestSystem::check(2.0f, vec_1.back()));
    return result;
}

bool test_18_check_several_push() {
    TVector<int> vec_1(15);
    vec_1.push_back(23);
    vec_1.push_front(22);
    bool result = (TestSystem::check((size_t)17, vec_1.size())) && (TestSystem::check((size_t)30, vec_1.capacity())) &&
        (TestSystem::check(22, vec_1.front())) && (TestSystem::check(23, vec_1.back()));
    return result;
}
int main() {
    User user_1;
    Client client_1;
    Administrator administartor_1;
    Game game_1;
    Feedback feedback_1;
    GameStore gamestore_1;

    TestSystem::start_test(test_1_try_create_default_vector, " TVector.test_1_try_create_default_vector");
    TestSystem::start_test(test_2_try_create_vector_with_initialization, " TVector.test_2_try_create_vector_with_initialization");
    TestSystem::start_test(test_3_check_basic_values_in_initialization, " TVector.test_3_check_basic_values_in_initialization");
    TestSystem::start_test(test_4_throw_when_try_applying_for_position_abroad, 
        " TVector.test_4_throw_when_try_applying_for_position_abroad");
    TestSystem::start_test(test_5_try_create_vector_with_initialization_list,
        " TVector.test_5_try_create_vector_with_initialization_list");
    TestSystem::start_test(test_6_check_values_in_initialization_list,
        " TVector.test_6_check_values_in_initialization_list");
    TestSystem::start_test(test_7_try_create_vector_with_copy, " TVector.test_7_try_create_vector_with_copy");
    TestSystem::start_test(test_8_check_values_in_copy, " TVector.test_8_check_values_in_copy");
    TestSystem::start_test(test_9_check_is_empty, " TVector.test_9_check_is_empty");
    TestSystem::start_test(test_10_check_front_back_begin_end, " TVector.test_10_check_front_back_begin_end");
    TestSystem::start_test(test_11_throw_when_try_use_front_in_empty_vector,
        " TVector.test_11_throw_when_try_use_front_in_empty_vector");
    TestSystem::start_test(test_12_throw_when_try_use_back_in_empty_vector,
        " TVector.test_12_throw_when_try_use_back_in_empty_vector");
    TestSystem::start_test(test_13_check_begin_and_end_in_empty_vector,
        " TVector.test_13_check_begin_and_end_in_empty_vector");
    TestSystem::start_test(test_14_check_push_front," TVector.test_14_check_push_front");
    TestSystem::start_test(test_15_check_push_front_in_empty_vector, 
        " TVector.test_15_check_push_front_in_empty_vector");
    TestSystem::start_test(test_16_check_push_back, " TVector.test_16_check_push_back");
    TestSystem::start_test(test_17_check_push_back_in_empty_vector, " TVector.test_17_check_push_back_in_empty_vector");
    TestSystem::start_test(test_18_check_several_push, " TVector.test_18_check_several_push");

    TestSystem::print_final_info();
    system("pause");
    return 0;
}
