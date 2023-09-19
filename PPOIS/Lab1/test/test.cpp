#include <gtest/gtest.h>
#include "../inc/cube.h"

TEST(Cube_Test, RotateLeftSideTest) {
  Cube cube_test_left("byybyybyyrrrrrrrrryggyggyggooooooooobbwbbwbbwgwwgwwgww"),cube_t("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube_t.rotate_the_left_edge_clockwise();
  EXPECT_TRUE(cube_t==cube_test_left);
}

TEST(Cube_Test, RotateRightSideTest) {
 Cube cube_test_right("yygyygyygrrrrrrrrrggwggwggwoooooooooybbybbybbwwbwwbwwb"),cube("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube.rotate_the_right_edge_clockwise();
  EXPECT_TRUE(cube==cube_test_right);
}

TEST(Cube_Test, RotateFrontSideTest) {
  Cube cube_test_front("yyyyyyrrrrrwrrwrrwgggggggggyooyooyoobbbbbbbbbooowwwwww"),cube("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube.rotate_the_front_edge_clockwise();
  EXPECT_TRUE(cube==cube_test_front);
}

TEST(Cube_Test, RotateTopSideTest) {
  Cube cube_test_top("yyyyyyyyygggrrrrrroooggggggbbboooooorrrbbbbbbwwwwwwwww"),cube("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube.rotate_the_top_edge_clockwise();
  EXPECT_TRUE(cube==cube_test_top);
}

TEST(Cube_Test, RotateBackSideTest) {
  Cube cube_test_back("oooyyyyyyyrryrryrrgggggggggoowoowoowbbbbbbbbbwwwwwwrrr"),cube_t("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube_t.rotate_the_back_edge_clockwise();
  EXPECT_TRUE(cube_t==cube_test_back);
}

TEST(Cube_Test, RotateBottomSideTest) {
  Cube cube_test_bottom("yyyyyyyyyrrrrrrbbbggggggrrroooooogggbbbbbbooowwwwwwwww"),cube_t("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube_t.rotate_the_bottom_edge_clockwise();
  EXPECT_TRUE(cube_t==cube_test_bottom);
}

TEST(Cube_Test, CounterRotateBottomSideTest) {
  Cube cube_test_bottom("yyyyyyyyyrrrrrrgggggggggooooooooobbbbbbbbbrrrwwwwwwwww"),cube_t("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube_t.rotate_the_bottom_edge_counter_clockwise();
  EXPECT_TRUE(cube_t==cube_test_bottom);
}

TEST(Cube_Test, CounterRotateBackSideTest) {
  Cube cube_test_back("rrryyyyyywrrwrrwrrgggggggggooyooyooybbbbbbbbbwwwwwwooo"),cube_t("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube_t.rotate_the_back_edge_counter_clockwise();
  EXPECT_TRUE(cube_t==cube_test_back);
}

TEST(Cube_Test, CounterRotateRightSideTest) {
  Cube cube_test_right("yybyybyybrrrrrrrrrggyggyggyooooooooowbbwbbwbbwwgwwgwwg"),cube_t("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube_t.rotate_the_right_edge_counter_clockwise();
  EXPECT_TRUE(cube_t==cube_test_right);
}

TEST(Cube_Test, CounterRotateFrontSideTest) {
  Cube cube_test_front("yyyyyyooorryrryrrygggggggggwoowoowoobbbbbbbbbrrrwwwwww"),cube_t("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube_t.rotate_the_front_edge_counter_clockwise();
  EXPECT_TRUE(cube_t==cube_test_front);
}

TEST(Cube_Test, CounterRotateLeftSideTest) {
  Cube cube_test_left("gyygyygyyrrrrrrrrrwggwggwggooooooooobbybbybbybwwbwwbww"),cube_t("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube_t.rotate_the_left_edge_counter_clockwise();
  EXPECT_TRUE(cube_t==cube_test_left);
}

TEST(Cube_Test, CounterRotateTopSideTest) {
  Cube cube_test_top("yyyyyyyyybbbrrrrrrrrrgggggggggooooooooobbbbbbwwwwwwwww"),cube_t("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  cube_t.rotate_the_top_edge_counter_clockwise();
  EXPECT_TRUE(cube_t==cube_test_top);
}

TEST(Cube_Test, WinTest){
  Cube cube_t("yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww");
  EXPECT_TRUE(cube_t.win_check());
}