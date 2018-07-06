#ifndef __GRAPHICSINTERFACE_HPP__
#define __GRAPHICSINTERFACE_HPP__

class GraphicsInterface {

public:
	virtual ~GraphicsInterface() {};
	
	virtual int initialize(int with, int height) = 0;
	virtual void wait(int milliseconds) = 0;
	virtual int loop(void) = 0;
};

#endif