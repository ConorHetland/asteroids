#ifndef _HITBOX
#define _HITBOX

class hitbox {
	protected:
		float topLeft, topRight, bottomLeft, bottomRight;

		entity() {}		

	public:
		entity(float, float, float, float);

		hitbox makeHitbox(float* xVertices, float* yVertices, float* length);
};

#endif