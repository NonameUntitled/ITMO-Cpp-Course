cmake_minimum_required(VERSION 2.7)

project(tests)

add_executable(test1 test1.cpp)
add_executable(test2 test2.cpp)
add_executable(test3 test3.cpp)
add_executable(test4 test4.cpp)
add_executable(test5 test5.cpp)

include_directories(../Rational/lib_rational ../Rational/rational_poly)

target_link_libraries(test1 lib_rational rational_poly)
target_link_libraries(test2 lib_rational rational_poly)
target_link_libraries(test3 lib_rational rational_poly)
target_link_libraries(test4 lib_rational rational_poly)
target_link_libraries(test5 lib_rational rational_poly)

add_test(
        NAME test_1
        COMMAND test1
)

add_test(
        NAME test_2
        COMMAND test2
)

add_test(
        NAME test_3
        COMMAND test3
)

add_test(
        NAME test_4
        COMMAND test4
)

add_test(
        NAME test_5
        COMMAND test5
)


