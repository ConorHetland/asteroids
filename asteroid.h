#include "entity.h"

#ifndef _ASTEROID
#define _ASTEROID

class asteroid : public entity {
	protected:
		int vertexes;
		float dx, dy;
		float* vertexX;
		float* vertexY;

		asteroid() {}

	public:
		asteroid(float, float, float, float);

		float getDx(void);
		float getDy(void);

		void setDx(float);
		void setDy(float);

		void update(float);
		void draw(void);
};

#endif