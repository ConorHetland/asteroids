#ifndef _ENTITY
#define _ENTITY

class entity {
	protected:
		float x, y, radius;

		entity() {}		

	public:
		entity(float, float, float);

		float getX(void);
		float getY(void);
		float getRadius(void);

		void setX(float);
		void setY(float);
		void setRadius(float);

		virtual void update(float) =0;
		virtual void draw(void) =0;
};

#endif