
///DDA ALGO

/*

#include<GL/glut.h>
#include <Windows.h>
#include <iostream>
using namespace std;

void line() {
	glColor3f(1.0, 0.0, 1.0);
	glPointSize(2.0);
	int x1, y1, x2, y2;
	cout << "Enter the starting coordinates:";
	cin >> x1 >> y1;
	cout << "Enter the ending coordinates:";
	cin >> x2 >> y2;
	int step, dx = x2 - x1, dy = y2 - y1;
	if (abs(dx) > abs(dy)) {
		step = abs(dx);
	}
	else {
		step = abs(dy);
	}
	float xInc = (float)dx / (float)step;
	float yInc = (float)dy / (float)step;
	float x = x1, y = y1;
	glBegin(GL_POINTS);
	for (int i = 0; i < step; i++) {
		glVertex2i(x, y);
		x += xInc;
		y += yInc;
	}
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Line Draw OpenGL");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_PROJECTION);// hta dene se frk nhi padtha
	glViewport(0, 0, 500, 500);// hta dene se frk nhi padtha

	glutDisplayFunc(line);
	glutMainLoop();
	return 0;
}




//ujjwal dda





#include<gl/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

GLdouble x1, yfirst, x2, y2;

void dda()
{
    GLdouble dx, dy, steps, xinc, yinc, x, y;
    dx = x2 - x1;
    dy = y2 - yfirst;
    x = x1;
    y = yfirst;
    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    xinc = dx / steps;
    yinc = dy / steps;

    glPointSize(4.0);

    glBegin(GL_POINTS);
        glVertex2f(x, y);
        for (int k = 0; k < steps; k++)
        {
            x = x + xinc;
            y = y + yinc;
            glVertex2f(x, y);
        }
    glEnd();
    glFlush();
}


void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Line using DDA");

    glClearColor(1.0, 1.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);
    gluOrtho2D(0, 200, 0, 200);
}

int main(int argc, char** argv)
{
    cout << "Enter two points for line drawing...\n";
    cout << "Enter the starting co-ordinate(x1, yfirst): ";
    cin >> x1 >> yfirst;
    cout << "Enter the end co-ordinate(x2, y2): ";
    cin >> x2 >> y2;

    glutInit(&argc, argv);

    init();
    //glutDisplayFunc(dda);
    //glutMainLoop();
    return 0;
}





// BREHSEM LINE ALGO




include<iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>

using namespace std;
int x1, y1, x2, y2;

void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2)
{
	int dx, dy, i, e;
	int xinc, yinc, inc1, inc2;
	int x, y;
	dx = x2 - x1;
	dy = y2 - y1;

	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;

	xinc = 1;
	if (x2 < x1)
		xinc = -1;
	yinc = 1;
	if (y2 < y1)
		yinc = -1;
	x = x1; y = y1;

	if (dx > dy)
	{
		draw_pixel(x, y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++)
		{
			if (e >= 0)
			{
				y += yinc;
				e += inc1;
			}
			else
				e += inc2;
			x += xinc;
			draw_pixel(x, y);
		}
	}
	else
	{
		draw_pixel(x, y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++)
		{
			if (e >= 0)
			{
				x += xinc;
				e += inc1;
			}
			else
				e += inc2;
			y += yinc;
			draw_pixel(x, y);
		}
	}
}

void display()
{
	draw_line(x1, x2, y1, y2);
	glFlush();
}

void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);

	glOrtho(0, 300, 0, 300, -1, 1);
}

int main(int argc, char** argv)
{
	cout << "Enter the value of x1: ";
	cin >> x1;
	cout << "Enter the value of x2: ";
	cin >> x2;
	cout << "Enter the value of y1: ";
	cin >> y1;
	cout << "Enter the value of y2: ";
	cin >> y2;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}





// CIRCLE midpoint  ALGO




#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + pntX1, y + pntY1);
	glEnd();
}


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 5 / 4 - r;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++;
			decision += 2 * x + 1;
		}
		else
		{
			y--;
			x++;
			decision += 2 * (x - y) + 1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointCircleAlgo();

	glFlush();
}

void main(int argc, char** argv)
{
	cout << "Enter the coordinates of the center:\n\n" << endl;

	cout << "X-coordinate   : "; cin >> pntX1;
	cout << "\nY-coordinate : "; cin >> pntY1;
	cout << "\nEnter radius : "; cin >> r;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

}


// ELIPSE ALGO




#include <GL/glut.h>
#include<iostream>
using namespace std;
int rx, ry;//semi-Major axis & semi Minor Axis
int xCenter, yCenter;//center of ellipse
void myinit(void)
{
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void ellipseMidPoint()
{
	//int xCenter = 250;
	//int yCenter = 300;
	//int rx = 200;
	//int ry = 200;

	//plotting for 1st region of 1st quardant and the slope will be < -1
	 //----------------------Region-1------------------------//
	float x = 0;
	float y = ry;//(0,ry) ---
	float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);
	//slope
	float dx = 2 * (ry * ry) * x;
	float dy = 2 * (rx * rx) * y;
	while (dx < dy)
	{
		//plot (x,y)
		setPixel(xCenter + x, yCenter + y);
		setPixel(xCenter - x, yCenter + y);
		setPixel(xCenter + x, yCenter - y);
		setPixel(xCenter - x, yCenter - y);
		if (p1 < 0)
		{
			x = x + 1;
			dx = 2 * (ry * ry) * x;
			p1 = p1 + dx + (ry * ry);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			dx = 2 * (ry * ry) * x;
			dy = 2 * (rx * rx) * y;
			p1 = p1 + dx - dy + (ry * ry);
		}
	}
	//ploting for 2nd region of 1st quardant and the slope will be > -1
	 //----------------------Region-2------------------------//
	float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);


	while (y > 0)
	{
		//plot (x,y)
		setPixel(xCenter + x, yCenter + y);
		setPixel(xCenter - x, yCenter + y);
		setPixel(xCenter + x, yCenter - y);
		setPixel(xCenter - x, yCenter - y);     //glEnd();
		if (p2 > 0)
		{
			x = x;
			y = y - 1;
			dy = 2 * (rx * rx) * y;
			//dy = 2 * rx * rx *y;
			p2 = p2 - dy + (rx * rx);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			dy = dy - 2 * (rx * rx);
			dx = dx + 2 * (ry * ry);
			p2 = p2 + dx -
				dy + (rx * rx);
		}
	}

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
	glColor3f(1.0, 0.0, 1.0);          // red foreground
	glPointSize(2.0);               // size of points to be drawin (in pixel)

	//establish a coordinate system for the image

	ellipseMidPoint();
	glFlush(); // send all output to the display
}

int main(int argc, char** argv)
{
	cout << "\n\nEnter Center Of Ellipse  \n\n";
	cout << "\n x = ";
	cin >> xCenter;

	cout << "\n y = ";
	cin >> yCenter;

	cout << " Enter a Semi Major Axix : ";
	cin >> rx;
	cout << " \nEnter a Semi Minor Axis: ";
	cin >> ry;
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480); // set the size of the window
	glutInitWindowPosition(10, 10); // the position of the top-left of window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
	myinit();
	glutDisplayFunc(display); // set the gl display callback function
	glutMainLoop(); // enter the GL event loop

}

*/




//#ifdef __APPLE__
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

void init();
void display();
void reshape(int, int);
void draw_pixel(int, int);
void circle(int, int, int);
void bresenhamLine(int, int, int, int, int, int);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(300, 200);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL Task 1");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();

	glutMainLoop();
	return 0;
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0); //Black Screen

}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(x, y);
	glEnd();
}

void circle(int r, int cx, int cy) {
	int x, y;
	float p = 5.0 / 4 - r;
	x = r;
	y = 0;
	if (r == 0) {
		draw_pixel(0, 0);
		return;
	}

	while (x != y) {
		draw_pixel(x + cx, y + cy);
		draw_pixel(x + cx, -y + cy);
		draw_pixel(-x + cx, y + cy);
		draw_pixel(-x + cx, -y + cy);
		draw_pixel(y + cx, x + cy);
		draw_pixel(-y + cx, x + cy);
		draw_pixel(y + cx, -x + cy);
		draw_pixel(-y + cx, -x + cy);
		if (p <= 0) {
			p += 2 * (y + 1) + 1;
		}
		else {
			x--;
			p += 2 * (y - x + 2) + 1;
		}
		y++;
	}

}
void bresenhamLine(int x0, int y0, int x1, int y1, int cx, int cy) {
	int dy, dx, incx, incy, x, y, p, inc1, inc2;
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x1 < x0) incx = -1;
	incy = 1;
	if (y1 < y0) incy = -1;
	x = x0; y = y0;
	if (dx > dy) {
		p = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (int i = 0; i <= dx; i++) {
			draw_pixel(x + cx, y + cy);
			if (p >= 0) {
				y += incy;
				p += inc1;
			}
			else
				p += inc2;
			x += incx;
		}

	}
	else {
		p = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (int i = 0; i <= dy; i++) {
			draw_pixel(x + cx, y + cy);
			if (p >= 0) {
				x += incx;
				p += inc1;
			}
			else
				p += inc2;
			y += incy;

		}
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glPointSize(3.0);
	int r;
	r = 20;
	circle(r, 50, 100);
	circle(2 * r, 3 * r + 50, 100);
	bresenhamLine(0, r, 3 * r, 0, 50, 100);
	bresenhamLine(0, -r, 3 * r, 0, 50, 100);
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200, 0, 200);
	glMatrixMode(GL_MODELVIEW);
}
