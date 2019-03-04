#ifndef BACKGROUND_H
#define BACKGROUND_H


class Background
{
public:
	/** Default constructor */
	Background();
	void render();

	void sun();
	void cloud();

	float sunScale, cloudFarX, cloudNearX;

	/** Default destructor */
	virtual ~Background();
protected:
private:
};

#endif // BACKGROUND_H