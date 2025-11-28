#include "exercise.h"
#include "munit.h"
munit_case(RUN, test_get_average, {
  float result = get_average(3, 4, 5);
  munit_assert_double_equal(result, 4.0, 6);
});
munit_case(RUN, test_non_integer, {
  float result = get_average(3, 3, 5);
  munit_assert_double_equal(result, 11.0 / 3.0, 6);
});
munit_case(SUBMIT, test_average_of_same, {
  float result2 = get_average(10, 10, 10);
  munit_assert_double_equal(result2, 10.0, 6);
});
munit_case(SUBMIT, test_average_of_some_big_numbers, {
  float result3 = get_average(1050, 2050, 2075);
  munit_assert_double_equal(result3, 1720.0, 6);
});
int main(int argc, char *argv[]) {
  MunitTest tests[] = {{"/test_get_average", test_get_average, NULL, NULL,
                        MUNIT_TEST_OPTION_NONE, NULL},
                       {"/test_non_integer", test_non_integer, NULL, NULL,
                        MUNIT_TEST_OPTION_NONE, NULL},
                       {"/test_average_of_same", test_average_of_same, NULL,
                        NULL, MUNIT_TEST_OPTION_NONE, NULL},
                       {"/test_average_of_some_big_numbers",
                        test_average_of_some_big_numbers, NULL, NULL,
                        MUNIT_TEST_OPTION_NONE, NULL},
                       {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};
  MunitSuite suite = {"/suite", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};
  return munit_suite_main(&suite, NULL, argc, argv);
}
