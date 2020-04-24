#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using  namespace std;

//text variables
int i, s, m, y; //i is loop variable, s is space, m in index var for msg[], y axis value
string ins[5] = { "This is an example of displaying","text on screen one character at a time","by specifying the (x,y) coordinates","for each character and the spacing","between them."};
string t;

void welcome()
{
	m = 0;
	y = 500;
	s = 15;
	while (m < 5)
	{
		t = ins[m];
		for (i = 0; i < t.length(); i++)
		{
			glColor3f(1,1,1);
			glRasterPos2i((i * s) + 20, y);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t.at(i));
		}
		m++;
		y = y - 30; //y value for next sentence
	}
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void myDisplay(void)
{
	welcome();
	glFlush();
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Welcome");
	glutDisplayFunc(myDisplay);
	init();
	glutMainLoop();
}