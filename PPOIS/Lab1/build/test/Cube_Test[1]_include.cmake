if(EXISTS "/Users/user/Desktop/projects/laba1/build/test/Cube_Test[1]_tests.cmake")
  include("/Users/user/Desktop/projects/laba1/build/test/Cube_Test[1]_tests.cmake")
else()
  add_test(Cube_Test_NOT_BUILT Cube_Test_NOT_BUILT)
endif()
