#include <stdio.h>

// Holds the maximum amount of characters that can fit on one line of output
int static const CHAR_MAX = 60;
// Holds the amount of space a single output data number takes
int static const DATA_SPACE = 4;

/*
 * Read an image from the standard input and set the red value of each pixel
 * to zero.
 */
void remove_red() {
  // Obtain the 1st number ("Magic number") and output it
  char magic_num[3];
  scanf("%s", magic_num);
  printf("%s\n", magic_num);
  // Obtain the 2nd number ("Number of columns") and output it
  int num_columns;
  scanf("%d", &num_columns);
  printf("%d ", num_columns);
  // Obtain the 3rd number ("Number of rows") and output it
  int num_rows;
  scanf("%d", &num_rows); 
  printf("%d\n", num_rows);
  // Obtain the 4th number ("Maximum colour value") and output it
  int max_colour_value;
  scanf("%d", &max_colour_value);
  printf("%d\n", max_colour_value);
  // Compute the number of individual numbers left to parse. 3 infers to the
  // three colour types: RED, GREEN, and BLUE
  int data_left  = (num_rows * num_columns) * 3;
  // Holds the number of characters used on the current line
  int chars_used = 0;
  // Go through the rest of the numbers ("Pixel data")
  int data_num;
  for (data_num = 0; data_num < data_left; data_num++) {  
    // Instantiate a new variable to hold the data
    int some_data;
    // Obtain the pixel data number
    scanf("%d", &some_data);
    // If this pixel holds RED data 
    // (i.e. every 3rd pixel [including the 1st]) 
    if ((data_num % 3) == 0) {
      // Void the RED data
      some_data = 0;
    }
    // If the current line is about to be filled
    if (chars_used == CHAR_MAX) {
      // We move on to the next line for this output
      printf("\n");
      // And reset the number of characters used
      chars_used = 0;
    }
    // If the data only has 1 digit
    if (some_data < 10) {
      // Add additonal spaces to have the data occupy 3 spaces when outputted
      printf(" %d  ", some_data);
    }
    // Else, if the data only has 2 digits
    else if (some_data < 100) {
      // Add additonal spaces to have the data occupy 3 spaces when outputted
      printf("%d  ", some_data);
    }
    // Else, output the number as is
    else {
      printf("%d ", some_data);
    }
    // Increment the amount of characters used on this line
    chars_used += DATA_SPACE;
  }
}

/*
 * Read an image from the standard input and convert it from colour to black 
 * and white.
 */
void convert_to_black_and_white() {
  // Obtain the 1st number ("Magic number") and output it
  char magic_num[3];
  scanf("%s", magic_num);
  printf("%s\n", magic_num);
  // Obtain the 2nd number ("Number of columns") and output it
  int num_columns;
  scanf("%d", &num_columns);
  printf("%d ", num_columns);
  // Obtain the 3rd number ("Number of rows") and output it
  int num_rows;
  scanf("%d", &num_rows); 
  printf("%d\n", num_rows);
  // Obtain the 4th number ("Maximum colour value") and output it
  int max_colour_value;
  scanf("%d", &max_colour_value);
  printf("%d\n", max_colour_value);
  // Compute the number of individual numbers left to parse. 3 infers to the
  // three colour types: RED, GREEN, and BLUE
  int data_left  = (num_rows * num_columns) * 3;
  // Holds the number of characters used on the current line
  int chars_used = 0;
  // Go through the rest of the numbers ("Pixel data"), in clusters of 3
  // pixels
  int data_num;
  for (data_num = 0; data_num < data_left; data_num += 3) {  
    // Instantiate the cluster of 3 pixel values
    int pix_val_1;
    int pix_val_2;
    int pix_val_3;
    // Obtain the 3 pixel values
    scanf("%d", &pix_val_1);
    scanf("%d", &pix_val_2);
    scanf("%d", &pix_val_3);
    // Holds the average of the 3 pixel values
    int pix_avg = (pix_val_1 + pix_val_2 + pix_val_3) / 3;
    // For each new pixel value
    int i;
    for (i = 0; i < 3; i++) {
      // If the current line is about to be filled
      if (chars_used == CHAR_MAX) {
	// We move on to the next line for this output
	printf("\n");
	// And reset the number of characters used
	chars_used = 0;
      }
      // If the data only has 1 digit
      if (pix_avg < 10) {
	// Add additonal spaces to have the data occupy 3 spaces when
	// outputted
	printf(" %d  ", pix_avg);
      }
      // Else, if the data only has 2 digits
      else if (pix_avg < 100) {
	// Add additonal spaces to have the data occupy 3 spaces when
	// outputted
	printf("%d  ", pix_avg);
      }
      // Else, output the number as is
      else {
	printf("%d ", pix_avg);
      }
      // Increment the amount of characters used on this line
      chars_used += DATA_SPACE;
    }
  }
}

/*
 * Read an image from the standard input and convert it to a square image.
 */
void instagram_square() {
  // Obtain the 1st number ("Magic number") and output it
  char magic_num[3];
  scanf("%s", magic_num);
  printf("%s\n", magic_num);
  // Obtain the 2nd number ("Number of columns")
  int num_columns;
  scanf("%d", &num_columns);
  // Keep the original total column number
  int orig_num_columns = num_columns;
  // Obtain the 3rd number ("Number of rows")
  int num_rows;
  scanf("%d", &num_rows);
  // Keep the original total row number
  int orig_num_rows = num_rows;
  // If we have more columns than rows
  if (num_columns > num_rows) {
    // Have the number of columns equal to that of rows
    num_columns = num_rows;
  }
  // Else, if we have more rows than columns
  else if (num_rows > num_columns) {
    // Have the number of rows equal to that of columns
    num_rows = num_columns;
  }
  // Else, no change is required for the rows or columns:
  // Output the 2nd ("Number of columns") and 3rd ("Number of rows") numbers
  printf("%d ", num_columns);
  printf("%d\n", num_rows);
  // Obtain the 4th number ("Maximum colour value") and output it
  int max_colour_value;
  scanf("%d", &max_colour_value);
  printf("%d\n", max_colour_value);
  // Compute the number of individual numbers left to parse. 3 infers to the
  // three colour types: RED, GREEN, and BLUE:
  int data_left;
  // If we originally had more rows than colmuns, or they were both equal
  if (orig_num_rows >= orig_num_columns) {
    // The amount of data left to parse is based from the adjusted values of
    // total rows and total columns
    data_left = (num_rows * num_columns) * 3;
  }
  // Else, we must of had more columns than rows 
  else {
    // The amount of data left to parse is based from the original values of
    // total rows and total columns
    data_left = (orig_num_rows * orig_num_columns) * 3;
  }
  // THE FOLLOWING IS APPLICABLE ONLY TO WHEN num_columns > num_rows:
  // =======================================================================
  // If we had more columns than rows we need to specify when we skip pixel 
  // data:
  // Holds the max amount of pixel data we are supposed to obtain for each 
  // line (In reference to the actual image [i.e. .jpg] pixel line)
  int max_pix_data = num_columns * 3;
  // Indicates the value required to skip to the next set of required pixel
  // data
  int skip_pix_data = (orig_num_columns * 3) - (num_columns * 3);
  // Indicates the amount of pixel data used for this line
  int curr_pix_data = 0;
  // =======================================================================
  // Holds the number of characters used on the current line
  int chars_used = 0;
  // Go through the rest of the numbers ("Pixel data")
  int data_num;
  for (data_num = 0; data_num < data_left; data_num++) {
    // THE FOLLOWING IS APPLICABLE ONLY TO WHEN num_columns > num_rows:
    // =====================================================================
    // If we originally had more columns than rows
    if (orig_num_columns > orig_num_rows) {
      // Increment our current pixel data position
      curr_pix_data++;
    }
    // =====================================================================
    // Instantiate a new variable to hold the data
    int some_data;
    // Obtain the pixel data number
    scanf("%d", &some_data);
    // If the current line is about to be filled
    if (chars_used == CHAR_MAX) {
      // We move on to the next line for this output
      printf("\n");
      // And reset the number of characters used
      chars_used = 0;
    }
    // If the data only has 1 digit
    if (some_data < 10) {
      // Add additonal spaces to have the data occupy 3 spaces when
      // outputted
      printf(" %d  ", some_data);
    }
    // Else, if the data only has 2 digits
    else if (some_data < 100) {
      // Add additonal spaces to have the data occupy 3 spaces when
      // outputted
      printf("%d  ", some_data);
    }
    // Else, output the number as is
    else {
      printf("%d ", some_data);
    }
    // THE FOLLOWING IS APPLICABLE ONLY TO WHEN num_columns > num_rows:
    // =====================================================================
    // If we originally had more columns than rows
    if (orig_num_columns > orig_num_rows) {
      // If we have reached the maximum pixel data for this line
      // (In reference to the actual image [i.e. .jpg pixel line])
      if (curr_pix_data == max_pix_data) {
	// Skip to the next required pixel
	data_num += skip_pix_data;
	int i;
	for (i = 0; i < skip_pix_data; i++) {
	  int garbage_data;
	  scanf("%d", &garbage_data);
	}
	// And reset our current pixel data count
	curr_pix_data = 0;
      }
    }
    // =====================================================================
    // Increment the amount of characters used on this line
    chars_used += DATA_SPACE;
  }
}
