#include <GL/glut.h>


void init(){
	GLfloat light_position[]={1,1,1,0}; // {derecha,arriba,adelante,atras}
	
	glEnable(GL_BLEND); //activar el blend para usar el alpha
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); //permitir efecto de transp en 2 colores, pero en realidad mezcla colores
	glEnable(GL_LIGHTING); //activar luz
	glEnable(GL_LIGHT0);//prender la luz0
	glLightfv(GL_LIGHT0,GL_POSITION,light_position); //
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINES); //GL_FILL para solido, GL_LINES para malla
	
}

void esferanaranja(){
	GLfloat material_ambiente[]={0.75,0.44,0.1,0.7};
	GLfloat material_diffuse[]={0.75,0.44,0,0.8};
	GLfloat material_specular[]={1,1,1,1};
	GLfloat material_shininess[]={120};//menor valor es más grande
	
	glMaterialfv(GL_FRONT,GL_AMBIENT,material_ambiente);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,material_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,material_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,material_shininess);
	
	glutSolidSphere(300,100,100);	//tetera
	glLoadIdentity();
	
}

void esferaazul(){
	GLfloat material_ambiente2[]={0,0,1,1};
	GLfloat material_diffuse2[]={0,0,1,1};
	GLfloat material_specular2[]={1,1,1,1};
	GLfloat material_shininess2[]={100};//menor valor es más grande
	
	glMaterialfv(GL_FRONT,GL_AMBIENT,material_ambiente2);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,material_diffuse2);
	glMaterialfv(GL_FRONT,GL_SPECULAR,material_specular2);
	glMaterialfv(GL_FRONT,GL_SHININESS,material_shininess2);
	
	glutSolidSphere(300,100,100);
	
	glLoadIdentity();
	
}

void esferaroja(){
	GLfloat material_ambiente3[]={1,0,0,0.5};
	GLfloat material_diffuse3[]={1,0,0,0.5};
	GLfloat material_specular3[]={1,1,1,1};
	GLfloat material_shininess3[]={120};//menor valor es más grande
	
	glMaterialfv(GL_FRONT,GL_AMBIENT,material_ambiente3);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,material_diffuse3);
	glMaterialfv(GL_FRONT,GL_SPECULAR,material_specular3);
	glMaterialfv(GL_FRONT,GL_SHININESS,material_shininess3);
	
	glutSolidSphere(300,100,100);	//tetera
	glLoadIdentity();
	
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW_MATRIX);
	glLoadIdentity();
		

	glViewport(250,200,350,350);	
	esferaazul();
	glViewport(80,200,350,350);
	esferanaranja();
	glViewport(160,30,350,350);	
	esferaroja();

	glFlush();
	
}

void reshape(int ancho,int altura){
	glViewport(0,0,(GLsizei)ancho,(GLsizei)altura); //(GLsizei) es tipo de dato para tamaños
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLint t=400;
	glOrtho(-t,t,-t,t,-t,t);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 27: exit(0);break;
		case ' ': exit(0);break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(50,50);
	glutCreateWindow("LabSem13");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	
	return 0;
}
