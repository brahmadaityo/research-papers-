#include<GL/glut.h> 
#include<math.h>
float xc = 960.0; // display resolution's x coordinate/2
float yc = 540.0; // display resolution's y coordinate/2
float g = 20.0; // grid spacing(pixel size) 
void myInit( void )
{
    glClearColor (1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-xc,xc,-yc,yc);
}
void grid(void)
{
	glBegin(GL_LINES);
	int i,j;
	for(i=-xc;i<=xc;i += g)
	{
		glVertex2f(i,-yc);
		glVertex2f(i,yc);
	}
	for(j=-yc;j<=yc;j += g)
	{
		glVertex2f(xc,j);
		glVertex2f(-xc,j);
	}
	glEnd();
	glFlush();
}

void fill(float x1,float x2,float y1,float y2)
{
    glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	int i,j;
	for(i=y1;i<=x2;i++)
	{
		glVertex2f(i,y1);
		glVertex2f(i,y2);
	}
	/*for(j=y1;j<=y2;j++)
	{
		glVertex2f(x1,j);
		glVertex2f(x2,j);
	}*/
	glEnd();
	glFlush();
	
} 
void writepixel(float x,float y)
{
	int kd = 8;
	float h = (int)(x)%(int)(g);
	float k = (int)(y)%(int)(g);
	float dx1 = x-h+(g/kd); //south west pixel
	float dy1 = y-k+(g/kd);
	float dx2 = dx1;
	float dy2 = y-k+(g-(g/kd)); //northwest pixel
	float dx3 = x-h+(g-(g/kd));
	float dy3 = dy1; //south east pixel
	float dx4 = dx3; 
	float dy4 = dy2;//northeast pixel
	float d = g;
	if(x<dx1 && y < dy1)
	{
		fill(x-h-d,x-h,y-k-d,y-k); //south west pixel
		return;
	}
	else if(x<dx1 && y>dy1 && y<dy2)
	{
		fill(x-h-d,x-h,y-k,y-k+d); //west pixel
		return;
	}
	else if (x< dx2 && y > dy2)
	{
		fill(x-h-d,x-h,y-k+d,y-k+2*d); //north west pixel
	}
	else if(x> dx1 && x < dx2 && y < dy1 )
	{
		fill(x-h,x-h+d,y-k-d,y-k);  // south pixel
	}
	else if (x > dx1 && x < dx2 && y>dy2)
	{
		fill(x-h,x-h+d,y-k+d,y-k+2*d); // north pixel
	}
	else if(x > dx3 && y < dy3 )
	{
		fill(x-h+d,x-h+2*d,y-k-d,y-k); //south east pixel
	}
	else if(x > dx3 && y > dy3 && y < dy4 )
	{
		fill(x-h+d,x-h+2*d,y-k,y-k+d); //east pixel
	}
	else if( x > dx4 && y > dy4)
	{
		fill(x-h+d,x-h+2*d,y-k+d,y-k+2*d); //north east pixel
	}
	else fill(x-h,x-h+d,y-k,y-k+d); //centre pixel
	return;
	
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.0f,0.0f);
    grid();
    writepixel(240.0,108.0);
    //fill(100,150,130,180);
    /*glBegin(GL_POINTS);
    int d;
    
    glEnd();
    glFlush();*/
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Template");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
