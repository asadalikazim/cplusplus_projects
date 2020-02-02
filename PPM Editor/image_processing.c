#include <stdio.h>

/*
 * Read an image from the standard input and set the red value of each pixel to
 * zero.
 */
void remove_red()
{

	char header[64];
	int cols;
	int rows;
	int max_value;
	int current_color;
	
	scanf("%s %d %d %d", header, &cols, &rows, &max_value);
	printf("%s\n%d %d\n%d\n", header, cols, rows, max_value);
	
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			for (int k = 0; k < 3; k++){
				scanf("%d", &current_color);
				if (k == 0){
					printf("0\n");
				} else {
					printf("%d\n", current_color);
				}
			}
		}		
	}
   
}

/*
 * Read an image from the standard input and convert it from colour to black and white.
 */
void convert_to_black_and_white()
{
	
	char header[64];
	int cols;
	int rows;
	int max_value;
	int color_r;
	int color_g;
	int color_b;
	int average;
	
	scanf("%s %d %d %d", header, &cols, &rows, &max_value);
	printf("%s\n%d %d\n%d\n", header, cols, rows, max_value);
	
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			scanf("%d %d %d", &color_r, &color_g, &color_b);
			average = (color_r + color_g + color_b) / 3;
			printf("%d\n%d\n%d\n", average, average, average);
		}		
	}
  
}

/*
 * Read an image from the standard input and convert it to a square image.
 */
void instagram_square()
{
	char header[64];
	int cols;
	int rows;
	int max_value;
	int current_color;
	
	scanf("%s %d %d %d", header, &cols, &rows, &max_value);
	
	
	if (rows == cols){
		printf("%s\n%d %d\n%d\n", header, cols, rows, max_value);
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				for (int k = 0; k < 3; k++){
					scanf("%d", &current_color);				
					printf("%d\n", current_color);
				}
			}
		}		
	} else if (rows > cols){
		printf("%s\n%d %d\n%d\n", header, cols, cols, max_value);
		for (int i = 0; i < cols; i++){
			for (int j = 0; j < cols; j++){
				for (int k = 0; k < 3; k++){
					scanf("%d", &current_color);				
					printf("%d\n", current_color);
				}
			}
		}	
	} else { //rows < cols
		printf("%s\n%d %d\n%d\n", header, rows, rows, max_value);
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				for (int k = 0; k < 3; k++){
					scanf("%d", &current_color);
					if (j < rows){
						printf("%d\n", current_color);
					}					
				}
			}
		}	
	}
	
}

