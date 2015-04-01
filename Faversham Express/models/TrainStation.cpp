#include "TrainStation.h"

static const float station_points[] = { 0, 0, 32, 0, 32, 4, 32, 28, 16, 36, 0, 28, 21, 28, 21, 4, 0, 4 };
const float* TrainStation::points = station_points;

TrainStation::TrainStation(float rotationAngle, float x, float z, GLenum light)
{
	this->light = light;
	this->rotationAngle = rotationAngle;
	this->x = x;
	this->z = z;
	txId = loadTexture("./textures/station.bmp", GL_MODULATE);
	humanoid = new Humanoid();

	float grey[4] = { 0.2, 0.2, 0.2, 1.0 };
	float yellow[4] = { 1, 1, 0.0, 1.0 };

	glEnable(light);
	glLightfv(light, GL_DIFFUSE, yellow);
	glLightfv(light, GL_SPECULAR, yellow);
	glLightf(light, GL_SPOT_CUTOFF, 45.0);
	glLightf(light, GL_SPOT_EXPONENT, 0.1);
}

void TrainStation::end(float depth, float nz)
{
	float nx = 0, ny = 0;
	glBegin(GL_POLYGON);
		glNormal3f(nx, ny, nz);
		glVertex3f(points[0], points[1], depth);
		glVertex3f(points[2], points[3], depth);
		glVertex3f(points[4], points[5], depth);
		glVertex3f(points[16], points[17], depth);
	glEnd();
	glBegin(GL_POLYGON);
		glNormal3f(nx, ny, nz);
		glVertex3f(points[4], points[5], depth);
		glVertex3f(points[6], points[7], depth);
		glVertex3f(points[12], points[13], depth);
		glVertex3f(points[14], points[15], depth);
	glEnd();
	glBegin(GL_POLYGON);
		glNormal3f(nx, ny, nz);
		glVertex3f(points[6], points[7], depth);
		glVertex3f(points[8], points[9], depth);
		glVertex3f(points[10], points[11], depth);
	glEnd();
}

void TrainStation::body(float depth)
{
	float third = 1.0 / 3.0, twoThird = 2.0 / 3.0;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txId);
	glBegin(GL_QUAD_STRIP);
		glTexCoord2f(twoThird, 1);
		glNormal3f(0, -1, 0);
		glVertex3f(points[0], points[1], depth);
		glVertex3f(points[0], points[1], 0);
		glVertex3f(points[2], points[3], depth);
		glVertex3f(points[2], points[3], 0);
		glNormal3f(1, 0, 0);
		glVertex3f(points[6], points[7], depth);
		glVertex3f(points[6], points[7], 0);
		glNormal3f(16, -8, 0);
		glVertex3f(points[8], points[9], depth);
		glVertex3f(points[8], points[9], 0);
		glNormal3f(16, 8, 0);
		glVertex3f(points[10], points[11], depth);
		glVertex3f(points[10], points[11], 0);
		glNormal3f(0, -1, 0);
		glTexCoord2f(twoThird, 0);
		glVertex3f(points[12], points[13], depth);
		glTexCoord2f(third, 0);
		glVertex3f(points[12], points[13], 0);
		glNormal3f(-1, 0, 0);
		glTexCoord2f(twoThird, 0);
		glVertex3f(points[14], points[15], depth);
		glTexCoord2f(third, 0);
		glVertex3f(points[14], points[15], 0);
		glNormal3f(0, 1, 0);
		glTexCoord2f(twoThird, 1);
		glVertex3f(points[16], points[17], depth);
		glTexCoord2f(third, 1);
		glVertex3f(points[16], points[17], 0);
		glNormal3f(-1, 0, 0);
		glTexCoord2f(twoThird, 1);
		glVertex3f(points[0], points[0], depth);
		glTexCoord2f(third, 1);
		glVertex3f(points[0], points[0], 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void TrainStation::walkHuman()
{
	const float CDR = 3.14159265 / 180.0;		//Degrees to radians conversion factor

	angle++;
	if (angle >= 360) angle = 0;
	float x = (-5) * cos(angle * CDR);
	float z = 30 * sin(angle * CDR);

	glPushMatrix();
	glTranslatef(x + 6, 4, z + 32);
	glRotatef(angle, 0, 1, 0);
	humanoid->display();
	glPopMatrix();
}

void TrainStation::draw()
{
	glTranslatef(x, 0, z);
	glRotatef(rotationAngle, 0, 1, 0);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	walkHuman();
	glColor3f(0.36, 0.35, 0.33);
	end(0, -1);
	end(depth, 1);
	body(depth);

	glEnable(GL_LIGHTING);
	float lgt2_pos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float spotDir[] = { -0.5, -1.0, 0 };

	glTranslatef((points[10] + points[12]) / 2, points[11], depth / 2);

	glLightfv(light, GL_POSITION, lgt2_pos);
	glLightfv(light, GL_SPOT_DIRECTION, spotDir);
}