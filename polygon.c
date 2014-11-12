/********************
JOSEPH GALLAGHER
********************/

/*
Vertex data should be in a file called "polygon.txt" with the x and y coordinates of each vertex on their own line, separated by whitespace. e.g:

0 0
0 1
1 1
1 0

The above represents a unit square in the plane. CCW or CW order doesn't matter.
*/

//INCLUDE THE HEADER "polygon.h" IN THE MAIN METHOD SO WE CAN USE THE FUNCTION DEFINED THEREIN...
#include "polygon.h"


int main()
{


	char point1[100], point2[100];
	float x, y;
	int number_of_points = 0;
	float p, q;

	FILE *ifp;
	//OPEN THE FILE FOR READING: IF NECESSARY, CHANGE "polygon.txt" TO WHATEVER FILENAME HOLDS THE VERTEX DATA
	ifp = fopen("polygon.txt", "r");

	//DETERMINE THE NUMBER OF POINTS (LINES) IN THE POLYGON FILE
	while (fscanf(ifp, "%f %f", &p, &q) != EOF)
	{
		number_of_points++;		
	}
	//CLOSE INPUT STREAM
	fclose(ifp);




	//INITIALIZE AN ARRAY OF POINTS TO PASS TO THE FUNCTION IN "polygon.h" AS X AND Y COORDINATES
	float xcoord[number_of_points-1];
	float ycoord[number_of_points-1];

	int i = 0;

	//OPEN THE FILE AGAIN FOR READING
	ifp = fopen("polygon.txt", "r");

	//POPULATE THE ARRAY xcoord[] WITH THE X COORDINATES OF THE POLYGON, AND THE ARRAY ycoord[] WITH THE Y COORDINATES
	while (fscanf(ifp, "%f %f", &p, &q) != EOF)
	{
		xcoord[i] = p;
		ycoord[i] = q;
		i++;
	}
	//CLOSE INPUT STREAM
	fclose(ifp);


	

	//GET POINTS AS USER INPUT AND PASS THEM TO THE FUNCTION 
	printf("\n\n   **********DETERMINE IF A POINT IS WITHIN THE POLYGON**********\n\n   Enter x coordinate and hit ENTER:\n   ");
	fgets(point1, sizeof(point1), stdin);
	sscanf(point1, "%f", &x);
	printf("   Enter y coordinate and hit ENTER:\n   ");
	fgets(point2, sizeof(point2), stdin);
	sscanf(point2, "%f", &y);
	//FUNCTION CALL TO "polygon.h WITH TEST POINT (x,y) AND POLYGONAL LINE POINT POINTER (&x, &y)..."
	//printf("%d\n", detect_point(x, y, &xcoord[0], &ycoord[0], number_of_points));
	int test_point = detect_point(x, y, &xcoord[0], &ycoord[0], number_of_points);

	if (test_point == 1)
		printf ("Point in polygon: \tTrue\n");
		
	else if (test_point == -1)
		printf ("Point in polygon: \tFalse\n");


	return(0);
}







