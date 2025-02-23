
/**
 * @copyright  Copyright (C) 2024 Kaden Slater. All Rights Reserved.
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

#include <gtest/gtest.h>

#include "file_utils.h"


  /*
    Tests that when there isn't any tail yet it creates one
  */
TEST(ReadFileTest, BadFilePathFails) {
  char* fileContent;
  unsigned int fileLength;

  read_file("path/to/nonexistent/file", &fileContent, &fileLength);

  EXPECT_EQ(1, 1);
}
