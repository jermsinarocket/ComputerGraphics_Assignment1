#ifndef BACKGROUND_H
#define BACKGROUND_H


class Background
{
public:
	/** Default constructor */
	Background();
	void render();

	void hills();
	void smallHills();
	void sun();
	void cloud();

	float hillX, sunScale, smallHillX, cloudFarX, cloudNearX;
	bool sunScalerH;

	/** Default destructor */
	virtual ~Background();
protected:
private:
};

#endif // BACKGROUND_H