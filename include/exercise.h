float get_average(int x, int y, int z);

#define munit_case(type, name, body) \
  MunitResult name(const MunitParameter params[], void *user_data) body