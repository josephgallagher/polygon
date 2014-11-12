/********************
JOSEPH GALLAGHER
********************/

/*How this works: 
Given a dataset, that is a list of "points" in the plane, we can make an abstraction to allow these points to represent the vertices of a polygon. Furthermore,
notice that each edge of a polygon is just a line a segment.  In fact, a polygon in the plane is just the space bounded by the intersection of a bunch of lines.

Now, consider any point in the plane and any old polygon.  If we extend a ray from that point in ANY direction, we may first say that that ray will either hit 
our polygon or it won't.  We are also free to choose any ray (drawing a couple of cases can convince you of that), so for the sake of simplicity, let our ray 
extend from our input point to positive infinity parallel to the x-axis. Again, drawing a couple of examples implies that if our ray strikes an even number (zero
inclusive) of polygonal edges, then the test point must lie outside of the polygon.  If odd, then it must lie inside!  I've taken topology, so fortunately I've 
seen similar problems before....

Anyway, the algorithm simply cycles through each adjacent set of vertices, and determines for each whether the y value of our test point is between the y values
of the adjacent vertices. If it is, then we need only determine the slope of the line through them, and, using the equation of a line, y - y_1 = m(x - x_1), we can
easily determine the x value of the intersection point of our abstract ray! We then just check whether the x value of our input point is less than (to the left of) the x value of the intersection point. If so, then our infinite ray MUST cross that edge...*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int detect_point(float x, float y, float *crdsx, float *crdsy, int n)
{


	   int indicator = -1;
	   int i = 0, j;
	   //int k = 0;

	   float slope, x_intersect;


	   for (j = n-1; i < n; j = i++)
	   {    //DETERMINE IF THE Y-VALUE OF THE INPUT POINT IS BETWEEN THE Y VALUES OF ALL ADJACENT VERTICES OF THE POLYGON:
		if (  ((crdsy[i] <= y) && (crdsy[j] > y))  ||  ((crdsy[i] > y) && (crdsy[j] <= y))  )
		
		{ 	
			//THE SLOPE OF THE POLYGON EDGE(WHICH IS, OF COURSE, JUST A LINE SEGMENT)
			slope = (crdsy[i]-crdsy[j]) / (crdsx[i]-crdsx[j]);

			//THE X-COORDINATE OF THE RAY WHERE IT INTERSECTS THE POLYGON EDGE (ACTUALLY, THIS UNIQUELY DETERMINES OUR RAY)
			x_intersect = (y - crdsy[j])/slope + crdsx[j];


			//THAT IS, IF YOUR INPUT POINT IS "TO THE LEFT OF" THE INTERSECTION POINT ON THE POLYGON EDGE..
			if ( x < x_intersect )
			{
				
				indicator = -indicator;	
				//ARTIFACT: UNCOMMENT THIS SECTION, "k" INSTANTIATOR AND THE RETURN STATEMENT TO SEE # OF BOUNDARY CROSSINGS!			
				//++k; 
				//USE TO TEST
				//printf("(%d, %d) : (%f, %f), (%f, %f) : %f !!!!!\n", i, j, crdsx[i], crdsy[i], crdsx[j], crdsy[j], x_intersect);
			}
			
		}


	   }
	
//return k;
return indicator;

}

