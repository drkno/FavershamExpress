#include "Tower.h"

//-----Computes surface normal vector-------------------------------
void Tower::normal(float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3)
{
	float nx, ny, nz;
	nx = y1*(z2 - z3) + y2*(z3 - z1) + y3*(z1 - z2);
	ny = z1*(x2 - x3) + z2*(x3 - x1) + z3*(x1 - x2);
	nz = x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
	glNormal3f(nx, ny, nz);
}

Tower::Tower(float angle, float x, float z)
{
	rotationAngle = angle;
	xPos = x;
	zPos = z;
	txId = loadTexture("./textures/TowerTexture.bmp", GL_MODULATE);
}

void Tower::draw()
{
	glTranslatef(xPos, 0, zPos);
	glRotatef(rotationAngle, 0, 1, 0);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	const int N = 18;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txId);

	float lpos[4] = { -100., 100., 0., 1. };	//light's position
	float eye_x, eye_z;						//Camera position
	const float CDR = 3.14159265 / 180.0;		//Degrees to radians conversion factor

	float vx[N] = { 0., 8., 11., 11., 10.4, 9.5, 8., 6., 3., 0., -3., -6., -8., -9.5, -10.4, -11., -11., -8. };
	float vy[N] = { 0 };
	float vz[N] = { 19.4, 8., 5., 0., -4., -8., -11., -12., -12.4, -12.5, -12.4, -12., -11., -8., -4., 0., 5., 8. };
	float wx[N], wy[N], wz[N];

	float tc[N + 1] = { 0, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.4 + 0.2 / 6, 0.4 + 0.2 / 3, 0.5, 0.5 + 0.2 / 6, 0.5 + 0.2 / 3, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 1.0 };

	eye_x = 150.0 * sin(viewAngle*CDR);   //Update camera position
	eye_z = 150.0 * cos(viewAngle*CDR);

	glColor3f(1., 1., 1.);
	glScalef(2, 2, 2);

	for (int j = 0; j < 8; j++) {
		glBegin(GL_QUAD_STRIP);
		float angle = -10;
		float x = vx[0], y = vy[0], z = vz[0];
		for (int i = 0; i < N; i++) {
			wx[i] = vx[i] * cos(angle * CDR) + vz[i] * sin(angle * CDR);
			wy[i] = vy[i] + 20;
			wz[i] = -vx[i] * sin(angle * CDR) + vz[i] * cos(angle * CDR);

			if (i > 0) normal(vx[i - 1], vy[i - 1], vz[i - 1],
				vx[i], vy[i], vz[i],
				wx[i], wy[i], wz[i]);

			glTexCoord2f(tc[i], 0);
			glVertex3f(vx[i], vy[i], vz[i]);
			glTexCoord2f(tc[i], 1);
			glVertex3f(wx[i], wy[i], wz[i]);

			vx[i] = wx[i];
			vy[i] = wy[i];
			vz[i] = wz[i];
		}
		glTexCoord2f(tc[N], 0);
		glVertex3f(x, y, z);
		glTexCoord2f(tc[N], 1);
		glVertex3f(wx[0], wy[0], wz[0]);
		glEnd();
	}

	glDisable(GL_TEXTURE_2D);
}
