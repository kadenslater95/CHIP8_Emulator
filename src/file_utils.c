
/**
 * @copyright  Copyright (C) 2025 Kaden Slater. All Rights Reserved.
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

#include "include/file_utils.h"


#define BLOCKLENGTH 1024


/**
 * Read the file from the given file path and malloc an array for its content which the user of the function
 * will then be responsible for freeing
 * 
 * @param filePath char*, the path to the file to read
 * @param content char*, a pointer placeholder that will be pointed to a malloced array of file content
 * @param length int*, a pointer placehold that will be set to have the size of the file in bytes
*/
void read_file(const char *filePath, char **content, unsigned int *length) {
  FILE *filePointer = fopen(filePath, "r");
  if (!filePointer) {
    perror("Failed to open file for reading! Error: ");

    *content = NULL;
    *length = 0;

    return;
  }

  char block[BLOCKLENGTH];
  unsigned int readLength = 0;
  unsigned int fileLength = 0;

  // Make a first pass through the file to determine the length
  while ((readLength = fread(
    block,
    1,
    BLOCKLENGTH, filePointer)) == BLOCKLENGTH) {
    fileLength += readLength;
  }
  fileLength += readLength;

  if (fileLength == 0) {
    printf("Filepath provided to read_file was empty!");

    *content = NULL;
    *length = 0;

    fclose(filePointer);

    return;
  }

  rewind(filePointer);

  // For adding the null terminator I will need to add 1 to the end
  // of the fileLength
  fileLength += 1;
  *length = fileLength;
  *content = (char*) malloc(sizeof(char) * fileLength);
  unsigned int offset = 0;

  // In this pass put contents into the file
  while ((readLength = fread(
    block,
    1,
    BLOCKLENGTH - 1,
    filePointer)) == BLOCKLENGTH - 1) {
    block[BLOCKLENGTH - 1] = '\0';

    if (offset > 0) {
      // offset - 1 to overwrite the previous \0
      snprintf(&content[0][offset - 1], sizeof(block), block);
    } else {
      snprintf(&content[0][offset], sizeof(block), block);
    }

    // Add 1 to account for the null terminator added on
    offset += readLength + 1;
  }

  if (readLength > 0) {
    block[readLength + 1] = '\0';

    if (offset > 0) {
      // offset - 1 to overwrite the previous \0
      snprintf(&content[0][offset - 1], sizeof(block), block);
    } else {
      snprintf(&content[0][offset], sizeof(block), block);
    }
  }

  fclose(filePointer);
}
