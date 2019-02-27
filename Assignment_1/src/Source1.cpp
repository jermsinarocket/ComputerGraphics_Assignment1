#include <iostream> 
#include <GL/glew.h> 
#include <GL/freeglut.h>
#include <GL/gl.h> 

using namespace std;

int main(int argc, char** argv) {
	glutInit(&argc, argv); glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); glutInitWindowSize(500, 500); glutInitWindowPosition(100, 100); glutCreateWindow(argv[0]); init();
	glutDisplayFunc(display); glutReshapeFunc(reshape); glutIdleFunc(moveObjects); glutMainLoop(); return 0;
}

typedef struct rect { float x; float y; float width; float height; } rect; rect     rectangle;
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0); glShadeModel(GL_FLAT);
	rectangle.x = 0.1; rectangle.y = 0.1; rectangle.width = 0.1; rectangle.height = 0.15;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); glBegin(GL_LINE_LOOP); glVertex2f(rectangle.x, rectangle.y); glVertex2f(rectangle.x, rectangle.y + rectangle.width); glVertex2f(rectangle.x + rectangle.height, rectangle.y + rectangle.width); glVertex2f(rectangle.x + rectangle.height, rectangle.y); glEnd();
	glutSwapBuffers();
}
void reshape(int w, int h) { glViewport(0, 0, (GLsizei)w, (GLsizei)h); glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluOrtho2D(0, 1, 0, 1); glMatrixMode(GL_MODELVIEW); glLoadIdentity(); }
void moveObjects() {
	rectangle.x += 0.001; rectangle.y += 0.001;
	glutPostRedisplay();
}
