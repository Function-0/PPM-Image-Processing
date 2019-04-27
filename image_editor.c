#include <stdio.h>
#include <stdlib.h>

/*
 * Include the function prototypes of all those functions implemented in 
 * image_processing.c.
 * Do not remove or modify them in any way.
 */

// Argument 1's call
void remove_red();
// Argument 2's call 
void convert_to_black_and_white();
// Argument 3's call
void instagram_square();

int main(int argc, char *argv[]) {
  /* Task 1 needs to be completed here: Make sure that the command line
   * arguments are correct. In case an error exists, print the error 
   * message and terminate the program. Otherwise, invoke the 
   * corresponding image processing function. 
   */
  // Indicates if any errors occurred. Assume no errors occurs
  int status  = 0;
  // Holds the error message
  char *error_message = ("Error: Expecting one command-line argument, which "
                         "needs to be either 1, 2, or 3.\n");
  // If there is more than 1 and OR no command-line arguments(Explicit)
  if ((argc > 2) || (argc == 1)) {
    // Indicate an error
    printf("%s", error_message);
    status = 1;
  }
  // Else, obtain the argument value
  else {
    // Holds any un-parsed data from the argument value. The default value is
    // zero (NULL pointer)
    char *garbage_data = "\0";
    // Holds the argument value
    int arg_value = strtol(argv[1], &garbage_data, 10);
    // if the argument is not in {1, 2, 3} OR the entire argument was not 
    // parsed (i.e. we have garbage data)
    if ((!((arg_value == 1) || 
	   (arg_value == 2) || 
	   (arg_value == 3))) ||
	(*garbage_data != 0)) {
      // Indicate an error
      printf("%s", error_message);
      status = 1;
    }
    // Else, if the argument is 1
    else if (arg_value  == 1) {
      // Call the remove red function
      remove_red();
    }
    // Else, if the argument is 2
    else if (arg_value  == 2) {
      // Call the convert to black and white function
      convert_to_black_and_white();
    }
    // Else, the argument must be 3
    else {
      // Call the instagram square function
      instagram_square();
    }
  }
  // 0 -> Function ran as expected
  // 1 -> Function terminated prematurely
  return status;
}
