#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <vector>
#include "Elt.h"
using namespace std;

namespace webRenderer
{
	string rendererElt(Elt*);

	string rendererInfo(EltInfo*);
	string rendererText(TextInfo*);
	string rendererVideo(VideoInfo*);
	string rendererAudio(AudioInfo*);
	string rendererMedia(MediaInfo*);

	using namespace c2D;
	string rendererPoint2D(Point2D*);
	string rendererShape(Shape*);
	string rendererLine(Line*);
	string rendererRectangle(Rectangle*);
	string rendererCircle(Circle*);
}

namespace phaserRenderer
{

}

namespace threeRenderer
{

}

#endif 
