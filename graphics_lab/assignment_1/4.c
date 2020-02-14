
#include<GL/glut.h> 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define loop(i,j,k) for(i=j;i<=k;i++)
double x01,x02,y01,y02;
void myInit( void )
{
    glClearColor (100.0/255.0,255.0/255.0,150.0/255.0,0.8);
    //glColor3f(255.0f,25.0f,0.0f);
    glPointSize(13.4);
    glLineWidth(0.8);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
}

void myDisplay()
{
	srand(time(0));
	 double x1,x2,y1,y2,i,j;
	x1 = -800.0;
	x2 = 800.0;
	y1 = -600.0;
	y2 = 600.0;
     double d = 15.0; 
	double m;
    glClear(GL_COLOR_BUFFER_BIT);
    //printf("enter the values of x1,y1(start points) & x2,y2(""end points"")\n");
    //scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    glBegin(GL_LINES);
	for(i=x1;i<=x2;i += d)
	{
		 glColor3f(0.0f,0.0f,0.0f);
		glVertex2i(i,y1); //*********grid construction*****************//
		glVertex2i(i,y2);
	}
	for(j=y1;j<=y2;j += d)
	{
		 glColor3f(0.0f,0.0f,0.0f);
		glVertex2i(x1,j);
		glVertex2i(x2,j);
	}
    glEnd();
    ///this is the DDA line generation algorithm
    glBegin(GL_POINTS);
	//y2 = 500.00f;
	//x2 = 750.00f;
	//y1 = 100.00f;
	//x1 = 120.00f;
	m =(double)((double)(y02-y01)/(double)(x02-x01));
	j = y01;
	float x,y,z;
	for(i=x01;i<=x02;i += 2.0*d)
	{
	glColor3f(255.0f,18.0f,0.0f);
	glVertex2d(i,j);
	j = (double)j+(double)m*2.0*d;
	}
    glEnd();
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-800,800,-600,600);
glFlush();
}
void main(int argc,char** argv)
{
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,50);
    printf("enter the values of x1,y1(start points) & x2,y2(""end points"")\n");
    scanf("%lf %lf %lf %lf",&x01,&y01,&x02,&y02);
    
    glutCreateWindow("           DDA line generation algorithm       ");
    
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}



